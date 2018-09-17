#pragma once

namespace joy {

// Base class for pin input.
struct Trigger {
  virtual void update() { }; // FIXME unused
  virtual bool read() const = 0;
};

struct Analog : Trigger {
  Analog(int pin, int threshold) :
    pin(pin), threshold(threshold) { }
  Analog(int pin, int threshold, bool invert) :
    pin(pin), threshold(threshold), invert(invert) { }
  bool read() const override;
  int pin;
  int threshold;
  bool invert = false;
};

struct Digital : Trigger {
  Digital(int pin) : pin(pin) { }
  Digital(int pin, bool invert) :
    pin(pin), invert(invert) { }
  bool read() const override;
  int pin;
  bool invert = false;
};

struct Options {
  unsigned long hold_time_ms;
  unsigned long debounce_time_ms;
};

enum State {
  WANT_TRIGGER,
  WANT_RESET,
  WANT_HOLD,
  DEBOUNCE
};

struct Data {
  bool is_expired(unsigned long now) const { return now > timeout; }
  State state = State::WANT_TRIGGER;
  unsigned long timeout;
};

using StateMachine = bool(*)(
  const Options&,
  const Trigger&,
  unsigned long now,
  Data&
);

struct Listener {
  Listener(Trigger& t, const Options& o, StateMachine sm) :
    trigger(t), options(o), sm(sm) { }

  bool is_firing();

  Trigger& trigger;
  const Options& options;
  const StateMachine sm;
  Data data { };
};

bool on_flick(const Options&, const Trigger&, unsigned long, Data&);
bool on_press(const Options&, const Trigger&, unsigned long, Data&);
bool on_hold(const Options&, const Trigger&, unsigned long, Data&);

} // namespace joy
