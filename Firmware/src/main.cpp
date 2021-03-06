#include <Arduino.h>

#include "config.h"
#include "debug.h"
#include "comm.h"
#include "accel.h"
#include "rpm.h"
#include "eeprom_.h"
#include "oled.h"

void setup() {
  // Init pins
  pinMode (PIN_LED,        OUTPUT      );
  pinMode (PIN_RPM_SENSOR, INPUT_PULLUP);
  pinMode (PIN_KEEPALIVE,  OUTPUT);
  digitalWrite (PIN_KEEPALIVE, HIGH);
  // Init comms
  Debug.begin(BAUD_DEBUG);
  bt_config();
  bt_begin ();
  // Init EEPROM
  eeprom_init();
  // Init modules
  acc_init();
  rpm_init();
  Debug.println("Ready.");
  blink_status(5);
}



void loop() {
  long now = millis();
  acc_exec(now);
  rpm_exec(now);
  // blip_autosave_exec(now);
}
