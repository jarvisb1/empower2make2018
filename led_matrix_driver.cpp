#include "led_matrix_driver.h"

/*
Define a rotation matrix:

  [[ a, b ],
   [ c, d ]]
*/
struct Rotation {
  int a, b, c, d;
};

const Rotation rot_90 = {
  0, -1,
  1, 0
};

const Rotation rot_270 = {
  0, 1,
  -1, 0
};

int rotate(const Rotation& r, int& x, int& y, int size) {
  const auto offset = size / 2;
  const auto xn = x - offset;
  const auto yn = y - offset;
  const auto xt = (r.a * xn) + (r.b * yn);
  const auto yt = (r.c * xn) + (r.d * yn);
  x = xt + offset;
  y = yt + offset;
}

void DualMatrixDriver::init() {
  left.setBrightness(brightness);
  right.setBrightness(brightness);
  left.begin();
  right.begin();
}

static void set_pixel(Adafruit_NeoPixel& m, int n, const Rotation& r, int x, int y, uint32_t v) {
  rotate(r, x, y, 8);
  m.setPixelColor(y * n + x, v);
}

void DualMatrixDriver::draw(const bitmap::Image& img) {
  const auto mx = img.get_width();
  const auto my = num_pixels / mx;
  for (int y = 0; y < my; y++) {
    for (int x = 0; x < mx; x++) {
      const auto color = img.get_pixel(x, y);
      set_pixel(left, num_pixels, rot_90, x, y, color);
      set_pixel(right, num_pixels, rot_270, x, y, color);
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
