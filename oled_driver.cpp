#include "oled_driver.h"

namespace oled {

void Driver::init() {
  ctrl.begin();
  width = ctrl.getWidth();
  height = ctrl.getHeight();
}

void Driver::show() {
  if (!dirty) {
    return;
  }
  ctrl.firstPage();
  do { render(); } while (ctrl.nextPage());
  dirty = false;
}

void Driver::render() {
  ctrl.setRot90();
  // TODO delete
  if (bmp) {
    ctrl.drawXBMP(20, 40, 32, 32, (const uint8_t*)bmp->get_data());
  }
  // TODO calculate center
  if (img) {
    ctrl.drawXBMP(20, 40, img->get_width(), img->get_height(), (const uint8_t*)img->get_data());
  }
}

} // namespace oled
