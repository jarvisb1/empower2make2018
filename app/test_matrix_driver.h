#pragma once

#include <Adafruit_NeoPixel.h>

#include "configuration.h"
#include "image.h"
#include "led_matrix_driver.h"
#include "icons.h"

auto left_matrix = Adafruit_NeoPixel(
  LED_MATRIX_SIZE, LEFT_LED_MATRIX_PIN, NEO_RGBW + NEO_KHZ800);

auto right_matrix = Adafruit_NeoPixel(
  LED_MATRIX_SIZE, RIGHT_LED_MATRIX_PIN, NEO_RGBW + NEO_KHZ800);

auto matrix_driver = DualMatrixDriver(
  left_matrix, right_matrix, LED_MATRIX_SIZE, LED_MATRIX_BRIGHTNESS);

const uint8_t data[] = {
  0, 1, 0, 1, 0, 1, 0, 1,
  1, 0, 1, 0, 1, 0, 1, 0,
  0, 1, 0, 1, 0, 1, 0, 1,
  1, 0, 1, 0, 1, 0, 1, 0,
  0, 1, 0, 1, 0, 1, 0, 1,
  1, 0, 1, 0, 1, 0, 1, 0,
  0, 1, 0, 1, 0, 1, 0, 1,
  1, 0, 1, 0, 1, 0, 1, 0,
};

const auto simple = bitmap::ImageSimpleMono(data, 8, 8, make_color(255, 0, 255, 0));

void setup() {
#ifdef DEBUG_APP
  Serial.begin(9600);
#endif
  init_gamma_correction_table();
  matrix_driver.init();
  matrix_driver.show();
  DEBUG_PRINT("Setup complete")
}

void loop() {
  matrix_driver.draw(AlertIcon.image);
  matrix_driver.show();
  DEBUG_PRINT("tick 1 -- alert")
  delay(1000);
  matrix_driver.draw(QuestionIcon.image);
  matrix_driver.show();
  DEBUG_PRINT("tick 2 -- question")
  delay(1000);
  matrix_driver.draw(EmptyIcon.image);
  matrix_driver.show();
  DEBUG_PRINT("tick 3 -- empty")
  delay(1000);
  matrix_driver.draw(simple);
  matrix_driver.show();
  DEBUG_PRINT("tick 4 -- simple")
  delay(1000);
}
