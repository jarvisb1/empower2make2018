#pragma once

#include <Adafruit_NeoPixel.h>
#include <U8glib.h>

#include "configuration.h"
#include "image.h"
#include "led_matrix_driver.h"
#include "oled_driver.h"
#include "joystick_listeners.h"
#include "icons.h"

auto left_matrix = Adafruit_NeoPixel(
  LED_MATRIX_SIZE, LEFT_LED_MATRIX_PIN, NEO_RGBW + NEO_KHZ800);

auto right_matrix = Adafruit_NeoPixel(
  LED_MATRIX_SIZE, RIGHT_LED_MATRIX_PIN, NEO_RGBW + NEO_KHZ800);

auto matrix_driver = DualMatrixDriver(
  left_matrix, right_matrix, LED_MATRIX_SIZE, LED_MATRIX_BRIGHTNESS);

auto u8g = U8GLIB_SSD1306_128X64(U8G_I2C_OPT_NO_ACK);

auto oled_driver = oled::Driver(u8g);

void setup() {
#ifdef DEBUG_APP
  Serial.begin(9600);
#endif
  pinMode(JOY_LEFT_RIGHT_PIN, INPUT);
  pinMode(JOY_UP_DOWN_PIN, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  init_gamma_correction_table();
  oled_driver.init();
  matrix_driver.init();
  matrix_driver.show();
  DEBUG_PRINT("Setup complete")
}

struct AppState {
  const Icon * selected_icon = &EmptyIcon;
  bool dirty = false;

  void select_icon(const Icon& icon) {
    if (selected_icon == &icon) {
      return;
    }
    selected_icon = &icon;
    dirty = true;
  }

  void update() {
    if (!dirty || !selected_icon) {
      return;
    }
    oled_driver.draw(selected_icon->preview);
    matrix_driver.draw(selected_icon->image);
    oled_driver.show();
    matrix_driver.show();
    dirty = false;
  }
} app_menu;

void loop() {
  if (on_flick::up_listener.is_firing()) {
    DEBUG_PRINT("Up selected")
    app_menu.select_icon(AlertIcon);
  } else if (on_flick::down_listener.is_firing()) {
    DEBUG_PRINT("Down selected")
    app_menu.select_icon(EmptyIcon);
  } else if (on_flick::left_listener.is_firing()) {
    DEBUG_PRINT("Left selected")
    app_menu.select_icon(QuestionIcon);
  } else if (on_flick::right_listener.is_firing()) {
    DEBUG_PRINT("Right selected")
    app_menu.select_icon(LightIcon);
  }
  app_menu.update();
}