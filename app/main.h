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
  LED_MATRIX_SIZE, LEFT_LED_MATRIX_PIN, NEO_GRBW + NEO_KHZ800);

auto right_matrix = Adafruit_NeoPixel(
  LED_MATRIX_SIZE, RIGHT_LED_MATRIX_PIN, NEO_GRBW + NEO_KHZ800);

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
  DEBUG_PRINT(F("Setup complete"))
}

struct AppState {
  const Icon * selected_icon = &EmptyIcon;
  bool cur_frame = false;
  unsigned long frame_timeout = 0;
  bool dirty = false;

  void select_icon(const Icon& icon) {
    if (selected_icon == &icon) {
      return;
    }
    selected_icon = &icon;
    cur_frame = false;
    frame_timeout = millis() + icon.frame_rate_ms;
    dirty = true;
  }

  void advance_frame_pointer() {
    if (!selected_icon) { return; }
    if (!selected_icon->toggle) { return; }
    if (selected_icon->frame_rate_ms <= 0) { return; }
    const unsigned long now = millis();
    if (now < frame_timeout) { return; } // not ready to flip yet
    cur_frame = !cur_frame;
    frame_timeout = now + selected_icon->frame_rate_ms;
    DEBUG_PRINT(F("Advancing frame pointer"))
    DEBUG_PRINT(F("Now"))
    DEBUG_PRINT(now)
    DEBUG_PRINT(F("Frame Rate"))
    DEBUG_PRINT(selected_icon->frame_rate_ms)
    DEBUG_PRINT(F("Next Frame Timeout"))
    DEBUG_PRINT(frame_timeout)
    dirty = true;
  }

  void update() {
    advance_frame_pointer();
    if (!dirty || !selected_icon) {
      return;
    }
    DEBUG_PRINT(F("Updating"))
    DEBUG_PRINT(F("FrameIndex"))
    DEBUG_PRINT(cur_frame)
    oled_driver.draw(selected_icon->preview);
    if (!cur_frame) {
      matrix_driver.draw(*selected_icon->frame_a);
    } else {
      matrix_driver.draw(*selected_icon->frame_b);
    }
    oled_driver.show();
    matrix_driver.show();
    dirty = false;
  }
} app_menu;

void loop() {
  if (JOY_MODE::up_listener.is_firing()) {
    DEBUG_PRINT(F("Up selected"))
    app_menu.select_icon(AlertIcon);
  } else if (JOY_MODE::down_listener.is_firing()) {
    DEBUG_PRINT(F("Down selected"))
    app_menu.select_icon(EmptyIcon);
  } else if (JOY_MODE::left_listener.is_firing()) {
    DEBUG_PRINT(F("Left selected"))
    app_menu.select_icon(QuestionIcon);
  } else if (JOY_MODE::right_listener.is_firing()) {
    DEBUG_PRINT(F("Right selected"))
    app_menu.select_icon(LightIcon);
  }
  app_menu.update();
}
