#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  delay(500);
  lcd.begin(16, 2);
  delay(200);
  lcd.clear();
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("ABCDEFGHIJKLMNOP");
  lcd.setCursor(0, 1);
  lcd.print("1234567890123456");
}

void loop() {}
