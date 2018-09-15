#include <Adafruit_NeoPixel.h>

#define MATRIX1_PIN 5
#define MATRIX2_PIN 6
#define NUM_LEDS 64
#define BRIGHTNESS 50

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(NUM_LEDS, MATRIX1_PIN, NEO_GRBW + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(NUM_LEDS, MATRIX2_PIN, NEO_GRBW + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

uint8_t leds_question[64] = {0,0,1,1,1,1,0,0,
                             0,1,1,0,0,1,1,0,
                             0,1,1,0,0,1,1,0,
                             0,0,0,0,1,1,0,0,
                             0,0,0,1,1,0,0,0,
                             0,0,0,1,1,0,0,0,
                             0,0,0,0,0,0,0,0,
                             0,0,0,1,1,0,0,0};

uint8_t leds_exclamation[64] = {0,0,0,1,1,0,0,0,
                                0,0,0,1,1,0,0,0,
                                0,0,0,1,1,0,0,0,
                                0,0,0,1,1,0,0,0,
                                0,0,0,1,1,0,0,0,
                                0,0,0,0,0,0,0,0,
                                0,0,0,1,1,0,0,0,
                                0,0,0,1,1,0,0,0};

uint8_t leds_smiley[64] =      {0,0,1,1,1,1,0,0,
                                0,1,1,1,1,1,1,0,
                                1,1,2,1,1,2,1,1,
                                1,1,1,1,1,1,1,1,
                                1,2,1,1,1,1,2,1,
                                1,2,2,2,2,2,2,1,
                                0,1,2,2,2,2,1,0,
                                0,0,1,1,1,1,0,0};

uint8_t leds_heart[64] =       {0,1,1,0,0,1,1,0,
                                1,1,1,1,1,1,1,1,
                                1,1,1,1,1,1,1,1,
                                1,1,1,1,1,1,1,1,
                                0,1,1,1,1,1,1,0,
                                0,0,1,1,1,1,0,0,
                                0,0,0,1,1,0,0,0,
                                0,0,0,0,0,0,0,0};

uint8_t leds_angrybird[64] =   {1,1,1,1,1,1,1,1,
                                1,1,1,1,1,1,1,1,
                                1,1,1,1,1,1,1,1,
                                1,1,1,0,0,1,0,0,
                                1,1,1,0,0,1,0,0,
                                1,1,1,2,2,2,3,3,
                                1,1,1,2,2,2,3,3,
                                1,1,1,2,2,2,2,2};

/*
uint8_t leds_blank[64] =       {0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0,
                                0,0,0,0,0,0,0,0};

uint8_t leds_all[64] =         {1,1,1,1,1,1,1,1,
                                1,1,1,1,1,1,1,1,
                                1,1,1,1,1,1,1,1,
                                1,1,1,1,1,1,1,1,
                                1,1,1,1,1,1,1,1,
                                1,1,1,1,1,1,1,1,
                                1,1,1,1,1,1,1,1,
                                1,1,1,1,1,1,1,1};
*/

void setPixelColor2Strips(int pixel_index, uint32_t pixel_color) {
  strip1.setPixelColor(pixel_index, pixel_color);
  strip2.setPixelColor(pixel_index, pixel_color);
}

void show2Strips() {
  strip1.show();
  strip2.show();
}

void setAllPixels2Strips(uint32_t pixel_color) {
  uint8_t i;
  for(i=0; i< NUM_LEDS; i++) {
    setPixelColor2Strips(i, pixel_color);
  }
}

void paintPixels2Strips(uint8_t *led_matrix, uint32_t color_0, uint32_t color_1 = 0, uint32_t color_2 = 0, uint32_t color_3 = 0) {
  uint8_t i;
  for(i=0; i< NUM_LEDS; i++) {
    if (color_3 != 0 && led_matrix[i] == 3) {
      setPixelColor2Strips(i, color_3);
    }
    else if (color_2 != 0 && led_matrix[i] == 2) {
      setPixelColor2Strips(i, color_2);
    }
    else if (color_1 != 0 && led_matrix[i] == 1) {
      setPixelColor2Strips(i, color_1);
    }
    else {
      setPixelColor2Strips(i, color_0);
    }
  }
}

void setup() {
  strip1.setBrightness(BRIGHTNESS);
  strip2.setBrightness(BRIGHTNESS);
  strip1.begin();
  strip2.begin();
  show2Strips(); // Initialize all pixels to 'off'
}

void loop() {
  uint16_t i, j;
  uint32_t off_color = strip1.Color(0,0,0);
  uint32_t red_color = strip1.Color(255,0,0);
  uint32_t green_color = strip1.Color(0,255,0);
  uint32_t blue_color = strip1.Color(0,0,255);
  uint32_t white_color = strip1.Color(0,0,0,255);
  uint32_t yellow_color = strip1.Color(255,255,0);
  uint32_t brown_color = strip1.Color(165,42,42);
  
  uint32_t question_color = blue_color;
  uint32_t exclamation_color = red_color;
  uint32_t heart_color = red_color;
  
  uint32_t smiley_color_1 = yellow_color;
  uint32_t smiley_color_2 = blue_color;
  
  uint32_t angrybird_color_1 = red_color;
  uint32_t angrybird_color_2 = white_color;
  uint32_t angrybird_color_3 = yellow_color;

  setAllPixels2Strips(brown_color);
  show2Strips();
  delay(30000);
  
  setAllPixels2Strips(white_color);
  show2Strips();
  delay(3000);

  paintPixels2Strips(leds_question, off_color, question_color);
  show2Strips();
  delay(3000);

  paintPixels2Strips(leds_exclamation, off_color, exclamation_color);
  show2Strips();
  delay(3000);

  paintPixels2Strips(leds_smiley, off_color, smiley_color_1, smiley_color_2);
  show2Strips();
  delay(3000);
  
  paintPixels2Strips(leds_heart, off_color, heart_color);
  show2Strips();
  delay(3000);

  for(j=0; j < 4; j++) {
    setAllPixels2Strips(green_color);
    show2Strips();
    delay(70);
    setAllPixels2Strips(white_color);
    show2Strips();
    delay(70);
  }

  setAllPixels2Strips(green_color);
  show2Strips();
  delay(3000);

  paintPixels2Strips(leds_angrybird, off_color, angrybird_color_1, angrybird_color_2, angrybird_color_3);
  show2Strips();
  delay(3000);
}
