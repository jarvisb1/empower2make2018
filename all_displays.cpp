#include "all_displays.h"

#include "configuration.h"

Adafruit_NeoPixel left_matrix = Adafruit_NeoPixel(
  LED_MATRIX_SIZE, LEFT_LED_MATRIX_PIN, NEO_GRBW + NEO_KHZ800);

Adafruit_NeoPixel right_matrix = Adafruit_NeoPixel(
  LED_MATRIX_SIZE, RIGHT_LED_MATRIX_PIN, NEO_GRBW + NEO_KHZ800);

display::DualMatrixDriver matrix_driver(
  left_matrix,
  right_matrix,
  LED_MATRIX_SIZE,
  LED_MATRIX_BRIGHTNESS
);
