#pragma once

#define LED_MATRIX_SIZE 64
#define LED_MATRIX_BRIGHTNESS 100
#define NUM_LEDS_PER_RING 16

#define LEFT_LED_MATRIX_PIN 5
#define RIGHT_LED_MATRIX_PIN 6
#define LED_RING_PIN 11

#define JOY_UP_DOWN_PIN A0 
#define JOY_LEFT_RIGHT_PIN A1
#define JOY_HIGH_THRESHOLD 800
#define JOY_LOW_THRESHOLD 200
#define JOY_LONG_TIMEOUT 1000
#define JOY_SHORT_TIMEOUT 500
#define JOY_DEBOUNCE_TIMEOUT 500

#define GAMMA_CORRECTION 4.0

/* 

To construct the matrix controller:

    Adafruit_NeoPixel controller = Adafruit_NeoPixel(
      LED_MATRIX_SIZE,
      LEFT_LED_MATRIX_PIN,
      NEO_GRBW + NEO_KHZ800
    );

To construct the OLED controller:

    U8GLIB_SSD1306_128X64 u8g (U8G_I2C_OPT_NO_ACK);

*/
