#include <Arduino.h>

#include "comm.h"
#include "debug.h"

void bt_init (int serialnumber) {
  delay(5000);
  Debug.println("# BT setup start");
  blink_status(1);
  Debug.println("# Setting baud rate");
  long BTBaudRates[] = {4800, 9600, 19200, 38400, 57600, 115200};
  for (unsigned int i = 0; i < sizeof(BTBaudRates)/sizeof(long); i++) {
    BT.begin(BTBaudRates[i]);
    BT.print("AT+BAUD8");
    delay(1500);
    BT.end();
    blink_status(1);
    delay(1500);
    Debug.println(i);
  }
  blink_status(2);
  BT.begin(115200);
  delay(1000);
  Debug.println("# Setting BT name");
  BT.print("AT+NAMEDekoboko-");
  if (serialnumber < 1000) BT.print('0');
  if (serialnumber <  100) BT.print('0');
  if (serialnumber <   10) BT.print('0');
  BT.print(serialnumber);
  delay(1500);
  Debug.println("# Setting BT pin");
  BT.print("AT+PIN0000");
  delay(1500);
  Debug.println("# BT setup done");
  BT.end();
  blink_status(3);
  delay(1000);
}
