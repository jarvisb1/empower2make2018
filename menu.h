#pragma once

#include "bitmap.h"

namespace menu {

struct Item {
  const char * label;
  const Bitmap * preview;
  const Bitmap * image;
};

} // namespace menu
