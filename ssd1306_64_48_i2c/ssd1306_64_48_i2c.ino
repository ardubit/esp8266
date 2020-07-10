/*
   Wemos Mini 0.66" OLED Starter Project 15.02.2017
   Board: Wemos D1 Mini
   OLED: SSD1306 i2c
*/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_SSD1306_64_48.h"

// Wemos Mini 0.66" OLED Shield W64 x H48
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(OLED_RESET);

void setup()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println(F("OLED 64x48"));
  display.display();
  delay(2000);

  testdrawrect();
  display.display();
  delay(2000);

  testdrawchar();
  display.display();
  delay(2000);
}

void loop()
{
}

void testdrawrect(void)
{
  display.clearDisplay();
  for (int16_t i = 0; i < display.height() / 2; i += 2)
  {
    display.drawRect(i, i, display.width() - 2 * i, display.height() - 2 * i, WHITE);
    display.display();
    delay(250);
  }
}

void testdrawchar(void)
{
  display.clearDisplay();
  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  for (int16_t i = 0; i < 256; i++)
  {
    if (i == '\n')
      display.write(' ');
    else
      display.write(i);
  }

  display.display();
  delay(2000);
}