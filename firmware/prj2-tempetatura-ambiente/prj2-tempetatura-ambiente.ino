#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int pinoLM35 = A0;

float tempAtual = 0.0;
float tempMin   = 999.0;
float tempMax   = -999.0;

float lerTemperatura() {
  long soma = 0;
  for (int i = 0; i < 10; i++) {
    soma += analogRead(pinoLM35);
    delay(10); // pequena pausa entre leituras
  }
  float media = soma / 10.0;
  return (media * 5.0 / 1023.0) * 100.0;
}

void setup() {
  delay(500);
  lcd.begin(16, 2);
  delay(200);
  lcd.clear();
  delay(100);
  lcd.setCursor(0, 0);
  lcd.print("Termometro LM35");
  delay(1500);
  lcd.clear();
}

void loop() {
  tempAtual = lerTemperatura();

  if (tempAtual < tempMin) tempMin = tempAtual;
  if (tempAtual > tempMax) tempMax = tempAtual;

  lcd.setCursor(0, 0);
  lcd.print("Atual:          ");
  lcd.setCursor(7, 0);
  lcd.print(tempAtual, 1);
  lcd.print((char)223);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Mi:");
  lcd.print(tempMin, 1);
  lcd.print(" Ma:");
  lcd.print(tempMax, 1);

  delay(3000);
}
