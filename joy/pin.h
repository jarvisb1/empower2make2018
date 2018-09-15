#pragma once

// Abstraction of pins, to allow both analog and digital inputs to represent PINs.

namespace joy {

class Input {
public:
  virtual void update() { }
  virtual bool read() const = 0;
};

class AnalogInput : public Input {
public:
  AnalogInput(int pin, int threshold) :
    pin(pin), threshold(threshold) { }
  AnalogInput(int pin, int threshold, bool invert) :
    pin(pin), threshold(threshold), invert(invert) { }
  bool read() const override;
private:
  int pin;
  int threshold;
  bool invert = false;
};

class DigitalInput : public Input {
public:
  DigitalInput(int pin) : pin(pin) { }
  DigitalInput(int pin, bool invert) :
    pin(pin), invert(invert) { }
  bool read() const override;
private:
  int pin;
  bool invert = false;
};

} // joy
