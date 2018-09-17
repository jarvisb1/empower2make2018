#pragma once

#include <U8glib.h>

#include "configuration.h"
#include "image.h"
#include "oled_driver.h"
#include "icons.h"

auto u8g = U8GLIB_SSD1306_128X64(U8G_I2C_OPT_NO_ACK);

auto oled_driver = oled::Driver(u8g);

void setup() {
#ifdef DEBUG_APP
  Serial.begin(9600);
#endif
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  init_gamma_correction_table();
  oled_driver.init();
  DEBUG_PRINT("Setup complete")
}

void loop() {
  oled_driver.draw(AlertIcon.preview);
  oled_driver.show();
  DEBUG_PRINT("tick 1 -- alert")
  delay(1000);
  oled_driver.draw(QuestionIcon.preview);
  oled_driver.show();
  DEBUG_PRINT("tick 2 -- question")
  delay(1000);
  oled_driver.draw(EmptyIcon.preview);
  oled_driver.show();
  DEBUG_PRINT("tick 3 -- empty")
  delay(1000);
}
