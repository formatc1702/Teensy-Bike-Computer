#include <Arduino.h>
#include <EEPROM.h>

#include "eeprom_.h"
#include "config.h"
#include "rpm.h" // test

void eeprom_init() {
  char _eeprom = 0;
  Debug.print("Checking EEPROM...");
  EEPROM.get(0, _eeprom);
  if (_eeprom == EEPROM_STATUS_UNINITIALIZED || EEPROM_FORCE_RESET) {
    Debug.print("Initializing...");
    EEPROM.put (0, EEPROM_STATUS_OK);
  }
  EEPROM.get(0, _eeprom);
  if (_eeprom == EEPROM_STATUS_OK) {
    Debug.println("OK!");
  } else {
    Debug.println("Error.");
  }

  if(EEPROM_FORCE_RESET) {
    // Reset all EEPROM values
    Debug.print("Resetting EEPROM...");
    EEPROM.put (EEPROM_DIST_TOTAL, (long)0);
    Debug.println("OK!");
  }
}
