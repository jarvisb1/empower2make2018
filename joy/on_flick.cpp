#include "on_flick.h"

namespace joy {

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


} // namespace joy