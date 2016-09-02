#include <Arduino.h>

#include "Adafruit_Sensor.h"
#include "Adafruit_ADXL345_U.h"

#include "accel.h"
#include "config.h"
#include "comm.h"

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

float acc_x = 0;
float acc_y = 0;
float acc_z = 0;

const long acc_interval   = 10;
      long acc_last_check =  0;

boolean acc_init() {
  Debug.print("Init acc.");
  accel.begin();
  if(accel.begin()) {
    Debug.print(".");
    accel.setRange   (ADXL345_RANGE_16_G);
    Debug.print(".");
    accel.setDataRate(ADXL345_DATARATE_100_HZ);
    Debug.println("OK!");
    return true;
  } else {
    Debug.println("Error!");
    return false;
  }
}

void acc_read() {
  sensors_event_t event;
  accel.getEvent(&event);
  acc_x = event.acceleration.x;
  acc_y = event.acceleration.y;
  acc_z = event.acceleration.z;
}

void acc_exec(long now) {
  if (now - acc_last_check > acc_interval) {
    //    long A = millis();
    acc_read();
    //    long B = millis();
    BT.print('A');
    BT.print('\t');
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
    acc_last_check += acc_interval;
  }
}

float acc_getX() {
  return acc_x;
}

float acc_getY() {
  return acc_y;
}

float acc_getZ() {
  return acc_z;
}
