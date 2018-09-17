# Empower2Make 2018 Hand-raising Project

## Hardware

### Parts List

*TODO*

### Schematics

*TODO*

## Software

### Required Arduino Libraries

#### Adafruit NeoPixel

This is the library that controls the two LED displays.

```c++
#include <Adafruit_NeoPixel.h>
```

[Zip -- Version 1.1.6](https://github.com/adafruit/Adafruit_NeoPixel/archive/1.1.6.zip)

#### U8GLib (old version)

This is the library that controls the small OLED display.

```c++
#include <U8glib.h>
```

[Zip -- Version 1.19.1](https://codeload.github.com/olikraus/U8glib_Arduino/zip/1.19.1)

### Configuration

The following configuration values can be adjusted in `app/configuration.h`:

```c++
#define JOY_HIGH_THRESHOLD 800
// This is how far you need to move the joystick along one axis before motion is
// registered.
// Joystick values range from 0 to 1023 with 512 being roughly in the center.

#define JOY_LOW_THRESHOLD 200
// This is how far you need to move the joystick the opposite direction
// along the same axis before motion is registered.
// Currently, both Up/Down and Left/Right share the same thresholds.

#define JOY_LONG_TIMEOUT 1000
// This is the minimum length of time in milliseconds that you need to hold down
// the joystick in a particular direction before motion is detected when
// "Hold/Press" modes are active.

#define JOY_SHORT_TIMEOUT 500
// This is the maximum length of time in milliseconds that you need to hold down
// the joystick in a particular direction for motion detection when "Flick" mode is active.

#define JOY_DEBOUNCE_TIMEOUT 500
// This is the length of time in milliseconds after detecting motion that the joystick
// will stop responding to events.

#define JOY_MODE on_flick
// Valid joystick modes are "on_flick", "on_press", and "on_hold"

#define GAMMA_CORRECTION 8.0
// This is the gamma correction value for the RGB color curves for the LED displays.
// Roughly, a higher number translates to increased image contrast.


// Uncomment this line to turn on Serial port messages.
//#define DEBUG_APP
```

#### Joystick Modes

Joystick modes specify how the joystick responds to user input. There are three joystick modes.

> Note: Only the `on_flick` mode has been tested.

##### on_flick

When this mode is active, the joystick responds to short "flicks".
A flick is when the joystick is briefly moved in a direction and then quickly released.
The `JOY_SHORT_TIMEOUT` configuration setting controls the maximum time before the joystick must be released. 

##### on_press

When this mode is active, the joystick ignores short "flicks" and will only trigger when
you take more than a certain amount of time to return the release the joystick. 
The `JOY_LONG_TIMEOUT` configuration setting controls the minimum amount of time the joystick must be held in particular direction before being released.

##### on_hold

Unlike the other two modes, when this mode is active, it is not required to be release the joystick before the event is triggered.  All that is required is to hold down the joystick longer than the timeout.
The `JOY_LONG_TIMEOUT` configuration setting controls the minimum amount of time the joystick must be held down in order to be detected.
