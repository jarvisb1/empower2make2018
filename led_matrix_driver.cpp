#include "led_matrix_driver.h"

void DualMatrixDriver::init() {
  left.setBrightness(brightness);
  right.setBrightness(brightness);
  left.begin();
  right.begin();
}

void DualMatrixDriver::draw(const bitmap::Image& img) {
  const auto n = max(0, min(num_pixels, img.get_size()));
  for (int i = 0; i < n; i++) {
    const auto color = img.get_pixel(i);
    left.setPixelColor(i, color);
    right.setPixelColor(i, color);
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
