#include "Arduino.h"
#include "config.h"
#include "pins.h"
// #include "test.h"

void setup() {
  // Init pins
  pinMode (PIN_LED, OUTPUT);
  // Init comms
  Serial .begin(BAUD_DEBUG);
  BT     .begin(BAUD_BT   );
}

void loop() {
  digitalWrite(PIN_LED, HIGH);
  BT.println("BT hello!");
  delay(100);
  digitalWrite(PIN_LED, LOW);
  delay(1000);
}
