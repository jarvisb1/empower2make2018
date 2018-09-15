#include <Eventually.h>

#include "joy.h"

joy::OnFlick::Options onFlickOptions { 500, 500 };
joy::AnalogInput joystickUp(A0, 800);
joy::AnalogInput joystickDown(A0, 200, true);
joy::AnalogInput joystickLeft(A1, 800);
joy::AnalogInput joystickRight(A1, 200, true);

EvtManager mgr;

void setup() {
  Serial.begin(9600);

  pinMode(joystickUp.pin, INPUT);
  pinMode(joystickLeft.pin, INPUT);

  mgr.addListener(new joy::OnFlick(joystickUp, onFlickOptions, (EvtAction)menu_up));
  mgr.addListener(new joy::OnFlick(joystickDown, onFlickOptions, (EvtAction)menu_down));
  mgr.addListener(new joy::OnFlick(joystickLeft, onFlickOptions, (EvtAction)menu_left));
  mgr.addListener(new joy::OnFlick(joystickRight, onFlickOptions, (EvtAction)menu_right));
}

void loop() {
  mgr.loopIteration();
  // Serial.println(analogRead(joystickLeft.pin));
  // delay(500);
}

void menu_up() { Serial.println("up"); }
void menu_down() { Serial.println("down"); }
void menu_left() { Serial.println("left"); }
void menu_right() { Serial.println("right"); }
