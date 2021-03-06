#include "joystick_listeners.h"

#include "configuration.h"

joy::Analog joystick_up_input(JOY_UP_DOWN_PIN, JOY_HIGH_THRESHOLD);
joy::Analog joystick_down_input(JOY_UP_DOWN_PIN, JOY_LOW_THRESHOLD, true);
joy::Analog joystick_left_input(JOY_LEFT_RIGHT_PIN, JOY_LOW_THRESHOLD, true);
joy::Analog joystick_right_input(JOY_LEFT_RIGHT_PIN, JOY_HIGH_THRESHOLD);

namespace on_flick {

const joy::Options options { JOY_SHORT_TIMEOUT, JOY_DEBOUNCE_TIMEOUT };

joy::Listener up_listener(joystick_up_input, options, joy::on_flick);
joy::Listener down_listener(joystick_down_input, options, joy::on_flick);
joy::Listener left_listener(joystick_left_input, options, joy::on_flick);
joy::Listener right_listener(joystick_right_input, options, joy::on_flick);

} // namespace on_flick

namespace on_press {

const joy::Options options { JOY_LONG_TIMEOUT, JOY_DEBOUNCE_TIMEOUT };

joy::Listener up_listener(joystick_up_input, options, joy::on_press);
joy::Listener down_listener(joystick_down_input, options, joy::on_press);
joy::Listener left_listener(joystick_left_input, options, joy::on_press);
joy::Listener right_listener(joystick_right_input, options, joy::on_press);

} // namespace on_press

namespace on_hold {

const joy::Options options { JOY_LONG_TIMEOUT, JOY_DEBOUNCE_TIMEOUT };

joy::Listener up_listener(joystick_up_input, options, joy::on_hold);
joy::Listener down_listener(joystick_down_input, options, joy::on_hold);
joy::Listener left_listener(joystick_left_input, options, joy::on_hold);
joy::Listener right_listener(joystick_right_input, options, joy::on_hold);

} // namespace on_hold
