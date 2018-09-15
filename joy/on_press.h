#pragma once

#include <Eventually.h>

#include "pin.h"

namespace joy {

class OnPress : public EvtListener {
public:
  struct Options {
    unsigned long min_hold_time_ms;
    unsigned long debounce_time_ms;
  };

  enum State { WANT_TRIGGER, WANT_HOLD, WANT_RESET, DEBOUNCE };

  struct Data {
    State state = WANT_TRIGGER;
    unsigned long timeout;
  };

  OnPress(Input& pin, const Options& o, EvtAction a) :
    pin(&pin), options(&o) { triggerAction = a; }

  bool isEventTriggered() override;
private:
  bool step(bool, unsigned long, Data&) const;

  Input * pin;
  const Options * options;
  Data data;
};

} // namespace joy