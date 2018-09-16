#pragma once

#include <U8glib.h>

#include "image.h"

namespace oled {

struct Driver {
  Driver(U8GLIB& ctrl) : ctrl(ctrl), img(NULL) { }

  void init();

  void draw(const bitmap::Image& img) {
    this->img = &img;
    dirty = true;
  }

  void show();
  void render();

  U8GLIB& ctrl;
  int width;
  int height;
  const bitmap::Image * img;
  bool dirty = false;
};

} // namespace oled