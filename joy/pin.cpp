#include "pin.h"

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

} // namespace joy
