#pragma once

#include <Arduino.h>

void init_gamma_correction_table();

uint32_t make_color(uint8_t r, uint8_t g, uint8_t b, uint8_t w = 0);

namespace bitmap {

class Image {
public:
  virtual int get_size() const { return get_width() * get_height(); }
  virtual int get_width() const { return 0; }
  virtual int get_height() const { return 0; }
  virtual const void * get_data() const { return NULL; }
  virtual int get_pixel_size_bits() const { return 0; }
  virtual uint32_t get_pixel(int x, int y) const { return get_pixel(y * get_width() + x); }
  virtual uint32_t get_pixel(int i) const { return get_pixel(i % get_width(), i / get_width()); };
};

class Image24P : public Image {
public:
  Image24P(const uint8_t * pdata, int width, int height) :
    pdata(pdata), width(width), height(height), size(width * height) { }
  int get_size() const override { return size; }
  int get_width() const override { return width; }
  int get_height() const override { return height; }
  const void * get_data() const override { return pdata; }
  int get_pixel_size_bits() const { return 24; }
  uint32_t get_pixel(int i) const override;
private:
  const uint8_t * pdata;
  int width;
  int height;
  int size;
};

class ImageBitP : public Image {
public:
  ImageBitP(const uint8_t * pdata, int width, int height, uint32_t on = make_color(0, 0, 0, 255), uint32_t off = 0) :
    pdata(pdata), width(width), height(height), size(width * height), on(on), off(off) { }
  int get_size() const override { return size; }
  int get_width() const override { return width; }
  int get_height() const override { return height; }
  const void * get_data() const override { return pdata; }
  int get_pixel_size_bits() const { return 1; }
  uint32_t get_pixel(int i) const override;
private:
  const uint8_t * pdata;
  int width;
  int height;
  int size;
  uint32_t on;
  uint32_t off;
};

class ImageZero : public Image {
public:
  ImageZero(int width, int height) :
    width(width), height(height), size(width * height) { }
  int get_size() const override { return size; }
  int get_width() const override { return width; }
  int get_height() const override { return height; }
  const void * get_data() const override { return NULL; }
  int get_pixel_size_bits() const { return 0; }
  uint32_t get_pixel(int) const override { return 0; }
  uint32_t get_pixel(int, int) const override { return 0; }
private:
  int width;
  int height;
  int size;
};

} // namespace bitmap