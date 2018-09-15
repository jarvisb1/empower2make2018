#include "joy.h"

#include <Arduino.h>

namespace joy {

bool AnalogInput::read() const {
  return invert ?
    analogRead(pin) < threshold :
    analogRead(pin) > threshold;
}

bool DigitalInput::read() const {
  return invert ?
    digitalRead(pin) == 0 :
    digitalRead(pin) != 0;
}

OnFlick::OnFlick(Input& pin, const Options& o, EvtAction a) :
  pin(&pin), options(&o) { this->triggerAction = a; }
bool OnFlick::isEventTriggered() {
  return step(pin->read(), millis(), data);
}

bool OnFlick::step(bool triggered, unsigned long now, Data& d) const {
  switch (d.state) {
    case WANT_TRIGGER:
      if (triggered) {
        d.state = WANT_RESET;
        d.timeout = now + this->options->max_hold_time_ms;
      }
      break;
    case WANT_RESET:
      if (now > d.timeout) {
        // held too long, cancelled
        d.state = DEBOUNCE;
        d.timeout = now + this->options->debounce_time_ms;
      } else {
        if (!triggered) {
          d.state = DEBOUNCE;
          d.timeout = now + this->options->debounce_time_ms;
          return true;
        }
      }
      break;
    case State::DEBOUNCE:
      if (!triggered && now > d.timeout) {
        d.state = WANT_TRIGGER;
      }
      break;
  }
  return false;
}

bool OnHold::isEventTriggered() {
  return step(pin->read(), millis(), data);
}

bool OnHold::step(bool triggered, unsigned long now, Data& d) const {
  switch (d.state) {
    case WANT_TRIGGER:
      if (triggered) {
        d.state = WANT_HOLD;
        d.timeout = now + this->options->min_hold_time_ms;
      }
      break;
    case WANT_HOLD:
      if (triggered) {
        if (now > d.timeout) {
          d.state = DEBOUNCE;
          d.timeout = now + this->options->debounce_time_ms;
          return true;
        }
      } else {
        // cancelled
        d.state = DEBOUNCE;
        d.timeout = now + this->options->debounce_time_ms;
      }
    case DEBOUNCE:
      if (!triggered && now > d.timeout) {
        d.state = WANT_TRIGGER;
      }
      break;
  }
  return false;
}

bool OnPress::isEventTriggered() {
  return step(pin->read(), millis(), data);
}

bool OnPress::step(bool triggered, unsigned long now, Data& d) const {
  switch (d.state) {
    case WANT_TRIGGER:
      if (triggered) {
        d.state = WANT_HOLD;
        d.timeout = now + this->options->min_hold_time_ms;
      }
      break;
    case WANT_HOLD:
      if (triggered) {
        if (now > d.timeout) {
          d.state = WANT_RESET;
        }
      } else {
        // cancelled
        d.state = DEBOUNCE;
        d.timeout = now + this->options->debounce_time_ms;
      }
      break;
    case WANT_RESET:
      if (!triggered) {
        d.state = DEBOUNCE;
        d.timeout = now + this->options->debounce_time_ms;
        return true;
      }
      break;
    case DEBOUNCE:
      if (!triggered && now > d.timeout) {
        d.state = WANT_TRIGGER;
      }
      break;
  }
  return false;
}

} // namespace joy