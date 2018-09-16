#pragma once

#include <U8glib.h>
#include "bitmap.h"

namespace oled {

struct Driver {
  Driver(U8GLIB& ctrl) :
    ctrl(ctrl), bmp(NULL) { }

  void init();

  // TODO delete
  void draw(const Bitmap * b) {
    bmp = b;
    dirty = true;
  }

  void draw(const bitmap::Image * img) {
    this->img = img;
    dirty = true;
  }

  void show();
  void render();

  U8GLIB& ctrl;
  int width;
  int height;
  // TODO delete
  const Bitmap * bmp;
  const bitmap::Image * img;
  bool dirty = false;
};

} // namespace oled