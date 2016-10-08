#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#include "Adafruit_SSD1306.h"
#include "Adafruit_GFX.h"

#include "oled.h"

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void oled_init() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("23");

  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(64,16);
  display.println("km/h");

  display.display();


  // display.clearDisplay();
  //
  // display.setTextSize(1);
  // display.setTextColor(WHITE);
  // display.setCursor(0,0);
  // display.println("12:45");
  //
  // display.setTextSize(2);
  // display.setTextColor(WHITE);
  // display.setCursor(64,16);
  // display.println("km/h");
  //
  // display.display();

  long tmr = 0;

  for (size_t ctr = 0; ctr < 80; ctr++) {
    display.clearDisplay();

    display.setTextColor(WHITE);

    display.setTextSize(1);
    display.setCursor(1,1);

    display.println("Trip");
    display.println(ctr);
    display.println(micros() - tmr);


    tmr = micros();

    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(48,0);
    display.print(ctr);

    // display.fillRect(0, 0, 128, 9, WHITE);
    //
    // display.setTextColor(BLACK);
    //
    // display.setCursor(1,1);
    // display.print("12:47");

    for (size_t i = 0; i <= 40; i++) {
      int pos = 24 + i * 2;
      display.drawPixel(pos, 31, WHITE);
      if (i % 5 == 0)
        display.drawPixel(pos, 30, WHITE);
      if (i % 10 == 0)
        display.drawPixel(pos, 29, WHITE);
      int tripos_x = 24 + ctr;
      int tripos_y = 28;
      display.drawTriangle(tripos_x, tripos_y, tripos_x - 1, tripos_y - 1, tripos_x + 1, tripos_y - 1, WHITE);
    }
    display.display();
    // delay(100);
  }
};
