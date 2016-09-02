#ifndef __CONFIG_H
#define __CONFIG_H
// User config
#define WHEEL_DIAMETER_MM 457 // 18 inch, R&M Birdy World Comfort
#define DYNAMO_NUM_POLES   28 // Shimano DH-3N30DA

#define DEKOBOKO_SN         0

// Version
#define VERSION_MAJOR       0
#define VERSION_MINOR       0
#define VERSION_PATCH       0

// Internal config
#define BAUD_DEBUG       9600 // irrelevant on Teensy
#define BAUD_BT        115200
#define BT_FORCE_SETUP  false

// Pins
// Interface
#define PIN_LED        13
#define PIN_SWITCH
#define PIN_BUZZER
// SPI
#define PIN_SPI_MOSI   11
#define PIN_SPI_MISO   12
#define PIN_SPI_SCK    14 // because 13 is LED // UNPLUGGED FOR RPM TEST!!
// TWI/I2C
#define PIN_TWI_SDA    18
#define PIN_TWI_SCL    19
// Others
#define PIN_RPM_SENSOR 14 // CONFLICT WITH SPI SCK!! REASSIGN!
#define PIN_V_BATT

// Aliases
#define Debug Serial
#define BT    Serial1

#endif
