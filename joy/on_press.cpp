#include "on_press.h"

namespace joy {

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