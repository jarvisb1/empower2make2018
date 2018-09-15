#pragma once

#include <Adafruit_NeoPixel.h>
#include "bitmap.h"

namespace display {

struct DualMatrixDriver {
  DualMatrixDriver(Adafruit_NeoPixel& left, Adafruit_NeoPixel& right, int num_pixels, int brightness) :
    left(left), right(right), num_pixels(num_pixels), brightness(brightness) { }

  void init() {
    left.setBrightness(brightness);
    right.setBrightness(brightness);
    left.begin();
    right.begin();
  }

  void draw(const Bitmap& b) {
    for (int i = 0; i < num_pixels; i++) {
      const auto color = b.palette[b.pixels[i]];
      left.setPixelColor(i, color);
      right.setPixelColor(i, color);
    }
    dirty = true;
  }

  void show() {
    if (dirty) {
      left.show();
      right.show();
      dirty = false;
    }
  }

  Adafruit_NeoPixel& left;
  Adafruit_NeoPixel& right;
  int num_pixels;
  int brightness;
  bool dirty = true;
};

} // namespace displays
