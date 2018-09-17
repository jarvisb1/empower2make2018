#pragma once

#include <Adafruit_NeoPixel.h>

#include "image.h"

struct DualMatrixDriver {
  DualMatrixDriver(Adafruit_NeoPixel& left, Adafruit_NeoPixel& right, int num_pixels, int brightness) :
    left(left), right(right), num_pixels(num_pixels), brightness(brightness) { }

  void init();
  void draw(const bitmap::Image&);
  void show();

  Adafruit_NeoPixel& left;
  Adafruit_NeoPixel& right;
  int num_pixels;
  int brightness;
  bool dirty = true;
};
