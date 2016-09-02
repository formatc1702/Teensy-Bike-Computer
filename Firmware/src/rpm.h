#ifndef __RPM_H
#define __RPM_H

void  rpm_init();
void  rpm_exec(long now);
void  rpm_log(long now);
void  rpm_debug();

long  get_bps();
float get_rpm();
float get_kph();

long   get_blips();
float  get_rev();
float  get_km();

// long  getAllBlips();
void  countBlip();
void  incBlip();
// void  printAllBlips();
#endif
