#include <Arduino.h>

#include "Adafruit_Sensor.h"
#include "Adafruit_ADXL345_U.h"


#include "config.h"
#include "debug.h"
#include "comm.h"
#include "accel.h"

// Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

long LastPolling     =  0;
long PollingInterval = 10;

void setup() {
  // Init pins
  pinMode (PIN_LED, OUTPUT);
  // Init comms
  Debug.begin(BAUD_DEBUG);
  delay(5000);
  if(BT_FORCE_SETUP) {
    bt_init(DEKOBOKO_SN);
  }
  BT.begin(115200);
  BT.println("BT hello!");
  // Init Accelerometer
  // if (!acc_init()) {
  //   Debug.println("# ADXL345 not found.");
  //   blink_error   (ERR_ADXL_NOT_FOUND);
  // }
  acc_init();
  // if (!accel.begin()) {
  //   Debug.println("# ADXL345 not found.");
  //   blink_error   (ERR_ADXL_NOT_FOUND);
  // }
  Debug.println("Setup finished.");
  blink_status (5);
}

void loop() {
  long now = millis();
  if (now - LastPolling > PollingInterval) {
    //    long A = millis();
    acc_read();
    //    long B = millis();
    BT.print(now);
    BT.print('\t');
    BT.print(acc_getX());
    BT.print('\t');
    BT.print(acc_getY());
    BT.print('\t');
    BT.print(acc_getZ());
    BT.println();
    //    long C = millis();
    //    BT.print("B-A:"); BT.println(B-A);
    //    BT.print("C-B:"); BT.println(C-B);
    LastPolling += PollingInterval;
  }
  // digitalWrite(PIN_LED, HIGH);
  // BT.println("BT hello!");  delay(100);
  // digitalWrite(PIN_LED, LOW);
  // delay(1000);
}
