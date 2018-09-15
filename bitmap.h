#pragma once

#include "configuration.h"

struct Bitmap {
  const uint32_t * palette;
  uint8_t pixels[LED_MATRIX_SIZE];

  static constexpr uint32_t color(uint8_t r, uint8_t g, uint8_t b, uint8_t w = 0) {
    return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
  }
};
