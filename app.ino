#include <Adafruit_NeoPixel.h>
#include <U8glib.h>

#include "configuration.h"
#include "bitmap.h"
#include "led_matrix_driver.h"
#include "oled_driver.h"
#include "joystick_listeners.h"
#include "images.h"
#include "menu.h"

auto left_matrix = Adafruit_NeoPixel(
  LED_MATRIX_SIZE, LEFT_LED_MATRIX_PIN, NEO_RGBW + NEO_KHZ800);

auto right_matrix = Adafruit_NeoPixel(
  LED_MATRIX_SIZE, RIGHT_LED_MATRIX_PIN, NEO_RGBW + NEO_KHZ800);

auto matrix_driver = DualMatrixDriver(
  left_matrix, right_matrix, LED_MATRIX_SIZE, LED_MATRIX_BRIGHTNESS);

auto u8g = U8GLIB_SSD1306_128X64(U8G_I2C_OPT_NO_ACK);

auto oled_driver = oled::Driver(u8g);

void setup() {
  Serial.begin(9600);
  pinMode(JOY_LEFT_RIGHT_PIN, INPUT);
  pinMode(JOY_UP_DOWN_PIN, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  init_gamma_correction_table();
  matrix_driver.init();
  matrix_driver.show();
}

menu::Item up_item {
  "Attention",
  &BMP_PREVIEW_ONE,
  &BMP_ATTENTION
};
menu::Item left_item { "Question", &BMP_PREVIEW_FAST, &BMP_QUESTION };
menu::Item right_item { "Smiley", NULL, &BMP_SMILEY };
menu::Item down_item { "OFF", NULL, &BMP_NOTHING };

struct Menu {
  menu::Item * selected_item = &down_item;
  bool dirty = false;

  void set(menu::Item& mi) {
    if (selected_item == &mi) {
      return;
    }
    selected_item = &mi;
    dirty = true;
  }

  void update() {
    if (!dirty || !selected_item) {
      return;
    }
    oled_driver.draw(selected_item->preview);
    if (selected_item->image) {
      matrix_driver.draw(*selected_item->image);
    }
    oled_driver.show();
    matrix_driver.show();
    dirty = false;
  }
} app_menu;

void loop() {
  if (on_flick::up_listener.is_firing()) {
    app_menu.set(up_item);
  } else if (on_flick::down_listener.is_firing()) {
    app_menu.set(down_item);
  } else if (on_flick::left_listener.is_firing()) {
    app_menu.set(left_item);
  } else if (on_flick::right_listener.is_firing()) {
    app_menu.set(right_item);
  }
  app_menu.update();
}
