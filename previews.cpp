#include "images.h"

#include <U8glib.h>

const uint8_t previews[] U8G_PROGMEM = {
  160,234,174,10,240,255,255,15,160,251,191,10,208,255,255,13,170,238,238,174,255,255,255,255,186,251,255,171,253,255,255,223,234,224,14,174,255,240,15,255,251,240,15,191,255,240,15,255,238,238,174,238,255,255,255,255,251,251,187,255,255,255,255,255,14,160,10,224,15,240,15,240,15,176,11,240,15,240,15,240,238,0,0,174,255,0,0,255,251,0,0,187,255,0,0,255,170,14,224,170,255,15,240,255,186,15,240,171,253,15,240,223,160,238,174,10,240,255,255,15,160,251,187,10,208,255,255,13,
  0,224,14,0,0,240,15,0,0,240,15,0,0,240,15,0,0,174,170,0,0,95,245,0,0,171,186,0,0,223,253,0,0,174,234,0,0,95,245,0,0,175,250,0,0,223,253,0,160,174,234,10,240,95,245,15,176,175,250,11,240,223,253,15,224,174,234,14,240,255,255,15,240,191,251,15,240,255,255,15,224,175,234,15,240,95,245,15,240,175,250,15,240,223,253,15,234,174,234,174,255,95,245,255,251,175,250,191,255,223,253,255,239,174,238,238,255,255,255,255,255,191,251,255,255,255,255,255,
  160,170,170,10,80,117,127,5,160,170,170,10,80,221,221,5,170,170,170,170,85,247,247,87,170,170,170,170,213,221,221,93,170,160,10,170,117,240,15,127,170,160,10,170,221,208,13,221,170,170,170,170,247,247,87,247,170,170,170,170,221,221,221,221,170,10,160,170,255,15,240,127,170,10,160,170,221,13,208,221,170,0,0,170,247,0,0,87,170,0,0,170,221,0,0,221,170,160,10,170,117,112,5,85,170,160,10,170,213,208,13,93,160,170,170,10,80,247,87,5,160,170,170,10,80,221,221,5,
  0,224,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,160,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,224,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,160,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,160,10,0,0,240,15,0,0,176,10,0,0,240,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,160,10,0,0,240,15,0,0,176,11,0,0,240,15,0,
  0,224,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,224,14,0,0,240,15,0,0,176,11,0,0,240,15,0,0,224,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,224,14,0,0,240,15,0,0,176,11,0,0,240,15,0,0,160,10,0,0,240,15,0,0,176,10,0,0,240,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,224,10,0,0,240,15,0,0,176,11,0,0,240,15,0,0,160,10,0,0,240,15,0,0,176,11,0,0,240,15,0,
  174,174,14,0,255,255,15,0,175,175,15,0,255,255,15,0,175,175,15,0,255,255,15,0,175,175,15,0,255,255,15,0,174,174,14,14,255,255,15,15,175,175,15,15,255,255,15,15,175,175,15,15,255,255,15,15,175,175,15,15,255,255,15,15,238,238,238,14,255,255,255,15,255,255,255,15,255,255,255,15,239,239,239,15,255,255,255,15,255,255,255,15,255,255,255,15,238,238,254,10,255,255,255,15,255,255,255,10,255,255,255,15,224,239,175,0,240,255,255,0,240,255,175,0,240,255,255,0,
  160,238,234,10,240,255,255,15,176,187,187,11,240,255,255,15,224,238,238,14,240,255,255,15,240,251,255,11,240,255,255,79,0,32,226,10,80,85,245,31,0,168,250,11,64,85,245,79,0,174,238,14,80,255,255,31,0,187,251,11,80,255,255,79,0,238,238,0,16,255,255,5,0,251,255,0,64,255,255,5,0,0,0,0,0,85,85,0,0,128,0,0,64,84,69,0,0,238,0,0,0,255,0,0,0,191,0,0,0,255,4,0,0,174,0,0,0,255,0,0,0,187,0,0,0,255,0,0,
  0,238,238,0,0,255,255,0,0,255,255,0,0,255,255,0,224,255,255,14,240,255,255,15,240,255,255,11,240,255,255,15,254,255,255,239,255,255,255,255,255,255,255,255,255,255,255,255,254,255,255,239,255,255,255,255,255,255,255,255,255,255,255,255,254,255,255,239,255,255,255,255,255,255,255,255,255,255,255,255,254,255,255,239,255,255,255,255,251,255,255,255,255,255,255,255,224,255,255,14,240,255,255,15,176,255,255,15,240,255,255,15,0,238,238,0,0,255,255,0,0,251,255,0,0,255,255,0,
  0,0,0,0,0,16,21,0,0,0,0,0,0,68,68,0,0,224,239,0,16,245,255,5,0,240,255,0,64,245,255,4,0,254,254,14,80,255,255,31,0,251,255,11,84,255,255,79,224,242,242,226,241,245,245,245,240,250,250,250,244,245,245,245,32,254,254,14,85,255,255,95,128,251,251,15,84,255,255,79,224,238,239,0,241,255,255,5,240,251,255,0,244,255,255,69,240,46,0,0,240,95,85,1,240,139,8,0,244,95,85,4,239,0,0,0,255,81,1,0,255,0,0,0,255,68,68,0,
  42,42,10,0,95,95,15,0,171,171,11,0,95,95,15,0,174,174,14,0,95,95,15,0,171,171,11,0,95,95,15,0,42,42,10,10,95,95,15,15,171,171,11,11,95,95,15,15,174,174,14,14,95,95,15,15,171,171,11,11,95,95,15,15,234,234,234,10,255,255,255,15,187,187,187,11,255,255,255,15,238,174,238,14,255,255,255,15,187,187,187,11,255,255,255,15,234,234,234,10,255,255,255,5,187,187,187,10,255,255,255,5,160,238,174,0,240,255,95,0,176,187,171,0,240,255,95,0
};

const MonochromeBitmapImpl BMP_PREVIEW_SMILEY = MonochromeBitmapImpl(previews, 0);
const MonochromeBitmapImpl BMP_PREVIEW_ONE = MonochromeBitmapImpl(previews + 128, 0);

const uint8_t fast[] = {
  160,234,174,10,240,255,255,15,160,251,191,10,208,255,255,13,170,238,238,174,255,255,255,255,186,251,255,171,253,255,255,223,234,224,14,174,255,240,15,255,251,240,15,191,255,240,15,255,238,238,174,238,255,255,255,255,251,251,187,255,255,255,255,255,14,160,10,224,15,240,15,240,15,176,11,240,15,240,15,240,238,0,0,174,255,0,0,255,251,0,0,187,255,0,0,255,170,14,224,170,255,15,240,255,186,15,240,171,253,15,240,223,160,238,174,10,240,255,255,15,160,251,187,10,208,255,255,13
};

const MonochromeBitmapImpl BMP_PREVIEW_FAST = MonochromeBitmapImpl(fast, 0);