#include <Arduino.h>

#include "Adafruit_Sensor.h"
#include "Adafruit_ADXL345_U.h"


#include "config.h"
#include "debug.h"
#include "comm.h"
#include "accel.h"
#include "rpm.h"

// Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

long LastPolling     =  0;
long PollingInterval = 10;
//
// long lastrpm = 0;
// long rpminterval = 100;

void setup() {
  // Init pins
  pinMode (PIN_LED, OUTPUT);
  pinMode (PIN_RPM_SENSOR, INPUT_PULLUP);
  // Init comms
  Debug.begin(BAUD_DEBUG);
  delay(5000);
  if(BT_FORCE_SETUP) {
    bt_config();
  }
  bt_begin();
  acc_init();
  rpm_init();
  Debug.println("Setup finished.");
  blink_status (5);
  lastrpm = millis();
}

void loop() {
  long now = millis();
  acc_exec(now);
  // digitalWrite(PIN_LED, HIGH);
  // BT.println("BT hello!");  delay(100);
  // digitalWrite(PIN_LED, LOW);
  // delay(1000);
  rpm_exec(now);
}
