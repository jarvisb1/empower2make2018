#ifndef JOY_H
#define JOY_H

#include <Eventually.h> // EvtAction

namespace joy {

struct Input {
  virtual void update() { }
  virtual bool read() const = 0;
};

struct AnalogInput : Input {
  AnalogInput(int pin, int threshold) :
    pin(pin), threshold(threshold) { }
  AnalogInput(int pin, int threshold, bool invert) :
    pin(pin), threshold(threshold), invert(invert) { }
  bool read() const override;
  int pin;
  int threshold;
  bool invert = false;
};

struct DigitalInput : Input {
  DigitalInput(int pin) : pin(pin) { }
  DigitalInput(int pin, bool invert) :
    pin(pin), invert(invert) { }
  bool read() const override;
  int pin;
  bool invert = false;
};

class OnFlick : public EvtListener {
public:
  struct Options {
    unsigned long max_hold_time_ms;
    unsigned long debounce_time_ms;
  };

  enum State { WANT_TRIGGER, WANT_RESET, DEBOUNCE }; 

  struct Data {
    State state = WANT_TRIGGER;
    unsigned long timeout;
  };

  OnFlick(Input&, const Options&, EvtAction);
  bool isEventTriggered() override;
private:
  bool step(bool, unsigned long, Data&) const;

  Input * pin;
  const Options * options;
  Data data;
};

class OnHold : public EvtListener {
public:
  struct Options {
    unsigned long min_hold_time_ms;
    unsigned long debounce_time_ms;
  };

  enum State { WANT_TRIGGER, WANT_HOLD, DEBOUNCE };

  struct Data {
    State state = WANT_TRIGGER;
    unsigned long timeout;
  };

  OnHold(Input& pin, const Options& o, EvtAction a) :
    pin(&pin), options(&o) { triggerAction = a; }

  bool isEventTriggered() override;
private:
  bool step(bool, unsigned long, Data&) const;

  Input * pin;
  const Options * options;
  Data data;
};

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

} // joy

#endif