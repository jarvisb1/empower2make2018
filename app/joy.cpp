#include "joy.h"

#include <Arduino.h>

namespace joy {

bool Analog::read() const {
  return invert ?
    analogRead(pin) < threshold :
    analogRead(pin) > threshold;
}

bool Digital::read() const {
  return invert ?
    digitalRead(pin) == 0 :
    digitalRead(pin) != 0;
}

bool Listener::is_firing() {
  return sm(options, trigger, millis(), data);
}

bool on_flick(const Options& o, const Trigger& t, unsigned long now, Data& d) {
  switch (d.state) {
    case State::WANT_TRIGGER:
      if (t.read()) {
        d.state = State::WANT_RESET;
        d.timeout = now + o.hold_time_ms;
      }
      break;
    case State::WANT_RESET:
      if (d.is_expired(now)) {
        // held too long, cancelled
        d.state = State::DEBOUNCE;
        d.timeout = now + o.debounce_time_ms;
      } else {
        if (!t.read()) {
          d.state = State::DEBOUNCE;
          d.timeout = now + o.debounce_time_ms;
          return true;
        }
      }
      break;
    case State::DEBOUNCE:
      if (!t.read() && d.is_expired(now)) {
        d.state = State::WANT_TRIGGER;
      }
      break;
  }
  return false;
}

bool on_press(const Options& o, const Trigger& t, unsigned long now, Data& d) {
  switch (d.state) {
    case State::WANT_TRIGGER:
      if (t.read()) {
        d.state = State::WANT_HOLD;
        d.timeout = now + o.hold_time_ms;
      }
      break;
    case State::WANT_HOLD:
      if (t.read()) {
        if (d.is_expired(now)) {
          // held for long enough
          d.state = State::WANT_RESET;
        }
      } else {
        // cancelled
        d.state = State::DEBOUNCE;
        d.timeout = now + o.debounce_time_ms;
      }
      break;
    case State::WANT_RESET:
      if (!t.read()) {
        d.state = State::DEBOUNCE;
        d.timeout = now + o.debounce_time_ms;
        return true;
      }
      break;
    case State::DEBOUNCE:
      if (!t.read() && d.is_expired(now)) {
        d.state = State::WANT_TRIGGER;
      }
      break;
  }
  return false;
}

bool on_hold(const Options& o, const Trigger& t, unsigned long now, Data& d) {
  switch (d.state) {
    case State::WANT_TRIGGER:
      if (t.read()) {
        d.state = State::WANT_HOLD;
        d.timeout = now + o.hold_time_ms;
      }
      break;
    case State::WANT_HOLD:
      if (t.read()) {
        if (d.is_expired(now)) {
          d.state = State::DEBOUNCE;
          d.timeout = now + o.debounce_time_ms;
          return true;
        }
      } else {
        // cancelled
        d.state = State::DEBOUNCE;
        d.timeout = now + o.debounce_time_ms;
      }
    case State::DEBOUNCE:
      if (!t.read() && d.is_expired(now)) {
        d.state = State::WANT_TRIGGER;
      }
      break;
  }
  return false;
}

} // namespace joy
