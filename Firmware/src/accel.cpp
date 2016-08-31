#include <Arduino.h>

#include "Adafruit_Sensor.h"
#include "Adafruit_ADXL345_U.h"

#include "comm.h"

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

float acc_x = 0;
float acc_y = 0;
float acc_z = 0;

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

float acc_getX() {
  return acc_x;
}

float acc_getY() {
  return acc_y;
}

float acc_getZ() {
  return acc_z;
}
