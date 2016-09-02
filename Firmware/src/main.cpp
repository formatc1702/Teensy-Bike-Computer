#include <Arduino.h>

#include "config.h"
#include "debug.h"
#include "comm.h"
#include "accel.h"
#include "rpm.h"

void setup() {
  // Init pins
  pinMode (PIN_LED,        OUTPUT      );
  pinMode (PIN_RPM_SENSOR, INPUT_PULLUP);
  // Init comms
  Debug.begin(BAUD_DEBUG);
  // delay(5000); // give time for serial port to show up on host
  bt_config();
  bt_begin ();
  // Init modules
  acc_init();
  rpm_init();
  // Finished
  Debug.println("Setup finished.");
  blink_status (5);
}

void loop() {
  long now = millis();
  acc_exec(now);
  rpm_exec(now);
}
