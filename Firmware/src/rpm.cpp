#include <Arduino.h>

#include "config.h"
#include "rpm.h"

// volatile long blips = 0;
volatile long blips[]  = {0,0,0,0,0,0,0,0,0,0};
volatile int  curblip  = 0;
volatile int  allblips = 0;

const long rpm_interval   = 100;
      long rpm_last_check =   0;

boolean blipstatus = false;

void rpm_init() {
  attachInterrupt (PIN_RPM_SENSOR, countBlip, FALLING);
}

void rpm_exec(long now) {
  if(now - rpm_last_check > rpm_interval) {
    incBlip();
    rpm_log(now);
    rpm_last_check += rpm_interval;
  }
}

void countBlip() {
  blips[curblip]++;
  blipstatus = !blipstatus;
  digitalWrite(PIN_LED, blipstatus);
}

void incBlip() {
  allblips += blips[curblip];
  curblip ++;
  if (curblip == 10)
    curblip = 0;
  blips[curblip] = 0;
}

long get_bps() {
  long allblips = 0;
  for (int i = 0; i < 10; i++) {
    allblips += blips[i];
  }
  return allblips;
}

float get_rpm() {
  return 0; // TODO
}

float get_kph() {
  // float res;
  // //     blips/sec              * rev/blip = (blib/rev)^-1
  // return (float)(getAllBlips()) / (DYNAMO_NUM_POLES/2);

/*
  res = (float)(getAllBlips());      // blips / sec
  res *= 3600.0;                     // sec   / h
  res *= 3.1416 * WHEEL_DIAMETER_MM; // mm    / rev
  res *= 2.0 / DYNAMO_NUM_POLES;     // rev   / blip
  res /= 1000000.0;                  // km    / mm
// */
  const float top_const    = 3600.0 * 3.14159 * 2.0;
  const float bottom_const = 1000000.0;
  // const float factor_const = top_const / bottom_const;

  // float top    = (float)(getAllBlips()) * WHEEL_DIAMETER_MM * top_const;
  // float bottom = (float)DYNAMO_NUM_POLES * bottom_const;

  // blips/sec ~= 2.71 * km/h
  // hm/h      ~= 0.37 * blips/sec

  return (float)(get_bps()) * (float)WHEEL_DIAMETER_MM * top_const / ((float)DYNAMO_NUM_POLES * bottom_const);
}

long get_blips() {
  return allblips;
}

float get_rev() {
  return allblips * 2.0 / (float)DYNAMO_NUM_POLES;
}

float get_km() {
  return (float)allblips * ((float)WHEEL_DIAMETER_MM * 3.14159 * 2.0 / ((float)DYNAMO_NUM_POLES *  1000000.0));
}

void rpm_log(long now) {
  BT.print('R');
  BT.print('\t');
  BT.print(now);
  BT.print('\t');
  BT.print(get_bps());
  BT.print('\t');
  BT.print(get_kph());
  BT.print('\t');
  BT.print('\t');
  BT.print(get_blips());
  BT.print('\t');
  BT.print(get_km() ,3);
  BT.print('\t');
  BT.println();
}

void rpm_debug() {
  // for (size_t i = 0; i < 10; i++) {
  //   Debug.print(blips[i]);
  //   Debug.print('\t');
  // }
  Debug.print('\t');
  Debug.print(get_bps());
  Debug.print('\t');
  Debug.print(get_kph(),1);
  Debug.print('\t');
  Debug.print('\t');
  Debug.print(get_blips());
  Debug.print('\t');
  Debug.print(get_rev());
  Debug.print('\t');
  Debug.print(get_km() ,3);
  Debug.println();
}
