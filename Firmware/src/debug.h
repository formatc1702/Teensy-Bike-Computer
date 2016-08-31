#ifndef __DEBUG_H
#define __DEBUG_H
// #include "Arduino.h"

#define BLINK_STATUS        150
#define BLINK_ERR_BLIP      500
#define BLINK_ERR_INTERVAL 2500

#define ERR_ADXL_NOT_FOUND 1

// Prototyping
void blink       (int times, int between, int after);
void blink_error (int errorcode );
void blink_status(int statuscode);

#endif
