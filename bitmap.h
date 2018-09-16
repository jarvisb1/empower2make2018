#pragma once

constexpr uint32_t make_color(uint8_t r, uint8_t g, uint8_t b, uint8_t w = 0) {
  return ((uint32_t)w << 24) | ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b;
}

void init_gamma_correction_table();

struct Bitmap {
  virtual const void * get_data() const { return NULL; }
  virtual int get_size() const { return 0; }
  virtual uint32_t get_pixel(int) const = 0;
};

struct BitmapImpl : Bitmap {
  BitmapImpl(const uint8_t * data, int size) :
    data(data), size(size) { }
  const void * get_data() const override { return data; }
  int get_size() const override { return size; }
  uint32_t get_pixel(int) const override;
  const uint8_t * data;
  int size;
};

struct MonochromeBitmapImpl : Bitmap {
  MonochromeBitmapImpl(const uint8_t * data, int size, uint32_t on = make_color(0, 0, 0, 255), uint32_t off = 0) :
    data(data), size(size), on(on), off(off) { }
  const void * get_data() const override { return data; }
  int get_size() const override { return size; }
  uint32_t get_pixel(int) const override;
  const uint8_t * data;
  int size;
  uint32_t on, off;
};

struct CompressedBitmapImpl : Bitmap {
  CompressedBitmapImpl(const uint32_t * palette, const uint8_t * data, int size) :
    palette(palette), data(data), size(size) { }
  const void * get_data() const override { return data; }
  int get_size() const override { return size; }
  uint32_t get_pixel(int) const override;
  const uint32_t * palette;
  const uint8_t * data;
  int size;
};

struct ZeroBitmapImpl : Bitmap {
  int get_size() const override { return 64; }
  uint32_t get_pixel(int) const override { return 0; }
};

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

} // namespace bitmap