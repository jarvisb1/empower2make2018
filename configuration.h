#pragma once

#include <Arduino.h>

#define LED_MATRIX_SIZE 64
#define LED_MATRIX_BRIGHTNESS 25
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