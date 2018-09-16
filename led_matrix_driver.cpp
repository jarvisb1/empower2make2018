#include "led_matrix_driver.h"

#include "configuration.h"

#define ROT_SIZE 7

int rotate_90_x(int x, int y) { return -y + ROT_SIZE; }

int rotate_90_y(int x, int y) { return x; }

int rotate_270_x(int x, int y) { return y; }

int rotate_270_y(int x, int y) { return -x + ROT_SIZE; }

void DualMatrixDriver::init() {
  left.setBrightness(brightness);
  right.setBrightness(brightness);
  left.begin();
  right.begin();
}

static int to_index(int x, int y, int side = 8) { return y * side + x; }

void DualMatrixDriver::draw(const bitmap::Image& img) {
  DEBUG_PRINT(F("Drawing Matrix"))
  DEBUG_PRINT(uint16_t(&img))
  const auto mx = img.get_width();
  const auto my = num_pixels / mx;
  for (int y = 0; y < my; y++) {
    for (int x = 0; x < mx; x++) {
      const auto color = img.get_pixel(x, y);
      left.setPixelColor(
        to_index(rotate_270_x(x, y), rotate_270_y(x, y)),
        color
      );
      right.setPixelColor(
        to_index(rotate_90_x(x, y), rotate_90_y(x, y)),
        color
      );
    }
  }
  dirty = true;
}

void DualMatrixDriver::show() {
  if (dirty) {
    left.show();
    right.show();
    dirty = false;
  }
}
