#ifndef __COMM_H
#define __COMM_H

#ifndef Debug
#define Debug Serial // default for Teensy, redefine in your program if necessary
#endif
#ifndef BT
#define BT    Serial1 // default for Teensy, redefine in your program if necessary
#endif

// #include <Arduino.h>

void bt_init(int serialnumber);

#endif
