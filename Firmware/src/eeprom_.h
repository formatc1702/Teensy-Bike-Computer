#ifndef __EEPROM_H
#define __EEPROM_H

// Addresses
#define EEPROM_STATUS        0 // 1 byte
#define EEPROM_VERSION_MAJOR 1 // 1 byte
#define EEPROM_VERSION_MINOR 2 // 1 byte
#define EEPROM_VERSION_PATCH 3 // 1 byte

#define EEPROM_DIST_TOTAL 4 // long -> 4 bytes

// Contents
#define EEPROM_STATUS_UNINITIALIZED 0xFF
#define EEPROM_STATUS_OK            0x01

// Functions
void eeprom_init();

#endif
