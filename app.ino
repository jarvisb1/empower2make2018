#include "configuration.h"
#include "all_bitmaps.h"
#include "listeners.h"
#include "all_displays.h"

void setup() {
  Serial.begin(9600);
  pinMode(JOY_UP_DOWN_PIN, INPUT);
  matrix_driver.init();
  matrix_driver.show();
}

void loop() {
  if (on_flick::up_listener.is_firing()) {
    matrix_driver.draw(BMP_EXCLAMATION);
  } else if (on_flick::down_listener.is_firing()) {
    matrix_driver.draw(BMP_QUESTION);
  }
  matrix_driver.show();
}
