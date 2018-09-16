#pragma once

#include <Adafruit_NeoPixel.h>

#include "bitmap.h"

struct DualMatrixDriver {
  DualMatrixDriver(Adafruit_NeoPixel& left, Adafruit_NeoPixel& right, int num_pixels, int brightness) :
    left(left), right(right), num_pixels(num_pixels), brightness(brightness) { }

  void init() {
    left.setBrightness(brightness);
    right.setBrightness(brightness);
    left.begin();
    right.begin();
  }

  // TODO delete
  void draw(const Bitmap& b) {
    const auto n = max(0, min(num_pixels, b.get_size()));
    for (int i = 0; i < n; i++) {
      const auto color = b.get_pixel(i);
      left.setPixelColor(i, color);
      right.setPixelColor(i, color);
    }
    dirty = true;
  }

  void draw(const bitmap::Image& img) {
    const auto n = max(0, min(num_pixels, img.get_size()));
    for (int i = 0; i < n; i++) {
      const auto color = img.get_pixel(i);
      left.setPixelColor(i, color);
      right.setPixelColor(i, color);
    }
    dirty = true;
  }

  void clear() {
    left.clear();
    right.clear();
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
