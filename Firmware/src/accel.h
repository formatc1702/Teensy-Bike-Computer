#ifndef __ACCEL_H
#define __ACCEL_H

#include <Arduino.h> // for boolean type

boolean acc_init();
void    acc_read();
void    acc_exec(long now);
float   acc_getX();
float   acc_getY();
float   acc_getZ();


#endif
