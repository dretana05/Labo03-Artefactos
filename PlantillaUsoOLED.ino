#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

const int pinLM35 = A0;

Adafruit_SH1106G display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

void setup() {
  Serial.begin(9600);
  Wire.begin();

  delay(250);

  if (!display.begin(i2c_Address, true)) {
    Serial.println("ERROR: OLED no encontrada");
    while (1);
  }

  Serial.println("OLED funcionando correctamente");
}

void loop() {
  
  int valorLeido = analogRead(pinLM35);

  
  float temperatura = (valorLeido * (5.0 / 1024.0)) * 100.0;

 
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);

  display.setTextSize(1);
  display.setCursor(10, 10);
  display.println("TERMOMETRO LM35");

  display.setTextSize(2);
  display.setCursor(15, 30);
  display.print(temperatura, 1); 
  display.print(" C");
  
  display.display();

  delay(1000); 
}