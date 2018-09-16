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
  if (!img) {
    return;
  }
  const auto data = (const uint8_t*)(img->get_data());
  if (!data) {
    return;
  }
  ctrl.setRot90();
  // TODO center in display
  ctrl.drawXBMP(20, 40, img->get_width(), img->get_height(), (const uint8_t*)img->get_data());
}

} // namespace oled
