#pragma once

#include "image.h"

// Icon completely describes a display option.
struct Icon {
  const bitmap::Image * frame_a;
  const bitmap::Image * frame_b;
  const bool toggle;
  const unsigned long frame_rate_ms;
  const bitmap::Image& preview;
};

extern const Icon HappyIcon;
extern const Icon SadIcon;
extern const Icon BlueExclamationIcon;
extern const Icon QuestionIcon;
extern const Icon SpeechBubbleIcon;
extern const Icon AlertIcon;
extern const Icon GreenExclamationIcon;
extern const Icon GreenHandIcon;
extern const Icon LightIcon;
extern const Icon RedHandIcon;
extern const Icon EmptyIcon;
