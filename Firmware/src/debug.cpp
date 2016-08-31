#include <Arduino.h>

#include "debug.h"
#include "config.h"

void blink_error(int errorcode) {
  while(true)
    blink(errorcode, BLINK_ERR_BLIP, BLINK_ERR_INTERVAL);
}

void blink_status(int statuscode) {
  blink(statuscode, BLINK_STATUS, 0);
}

void blink(int times, int between, int after) {
  for (int i = 0; i < times; i++) {
    digitalWrite(PIN_LED, HIGH);
    delay(between);
    digitalWrite(PIN_LED, LOW);
    delay(between);
  }
  delay(after);
}
