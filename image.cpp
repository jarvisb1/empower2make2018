#include "image.h"

#include "configuration.h"

#define NUM_COLOR_CHANNELS 3
#define NUM_COLOR_CHANNEL_VALUES 64

#define GAMMA_TABLE_COMPRESSION 4

#define GAMMA_R 0
#define GAMMA_G 1
#define GAMMA_B 2

#define GCR 255.0
#define GCG 240.0
#define GCB 220.0

static byte gamma_correction_table[3][NUM_COLOR_CHANNEL_VALUES];

void init_gamma_correction_table() {
  for (int i = 0; i < NUM_COLOR_CHANNEL_VALUES; i++) {
    float f = pow((float)i / NUM_COLOR_CHANNEL_VALUES, GAMMA_CORRECTION);
    gamma_correction_table[0][i] = (byte)(f * GCR); //Red
    gamma_correction_table[1][i] = (byte)(f * GCG); //Green
    gamma_correction_table[2][i] = (byte)(f * GCB); //Blue
  }
}

uint32_t make_color(uint8_t r, uint8_t g, uint8_t b, uint8_t w) {
  return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

namespace {

float saturation(uint8_t r, uint8_t g, uint8_t b) {
  float low = min(r,min(g,b)), high = max(r,max(g,b));
  return (high - low) / high;
}

uint8_t calc_white(uint8_t r, uint8_t g, uint8_t b) {
  return (1 - saturation(r,g,b)) * ((r + g + b) / 3);
}

} // namespace

namespace bitmap {

uint32_t Image24P::get_pixel(int i) const {
  const auto offset = uint16_t(pdata) + uint16_t(i * 3);
  const auto r = uint8_t(pgm_read_byte(offset));
  const auto g = uint8_t(pgm_read_byte(offset + 1));
  const auto b = uint8_t(pgm_read_byte(offset + 2));
  if (gamma_enable) {
    return make_color(
      gamma_correction_table[GAMMA_R][r/GAMMA_TABLE_COMPRESSION],
      gamma_correction_table[GAMMA_G][g/GAMMA_TABLE_COMPRESSION],
      gamma_correction_table[GAMMA_B][b/GAMMA_TABLE_COMPRESSION],
      0 // calc_white(r, g, b)
    );
  }
  return make_color(r, g, b, 0);
}

uint32_t ImageBitP::get_pixel(int i) const {
  const auto index = uint8_t(i) / 0x08;
  const auto mask = 0x01 << (uint8_t(i) & 0x04);
  return (uint8_t(pgm_read_byte(pdata + index)) & mask) ? on : off;
}

} // namespace bitmap