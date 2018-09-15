#include "all_bitmaps.h"

const uint32_t DEFAULT_PALETTE[] = {
  Bitmap::color(0,   0,   0  ),
  Bitmap::color(255, 0,   0  ), // red
  Bitmap::color(0,   255, 0  ), // green
  Bitmap::color(0,   0,   255), // blue
};

const Bitmap BMP_QUESTION = {
  DEFAULT_PALETTE,
  {
    0,0,1,1,1,1,0,0,
    0,1,1,0,0,1,1,0,
    0,1,1,0,0,1,1,0,
    0,0,0,0,1,1,0,0,
    0,0,0,1,1,0,0,0,
    0,0,0,1,1,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,1,1,0,0,0
  }
};

const Bitmap BMP_EXCLAMATION = {
  DEFAULT_PALETTE,
  {
    0,0,0,2,2,0,0,0,
    0,0,0,2,2,0,0,0,
    0,0,0,2,2,0,0,0,
    0,0,0,2,2,0,0,0,
    0,0,0,2,2,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,2,2,0,0,0,
    0,0,0,2,2,0,0,0
  }
};
