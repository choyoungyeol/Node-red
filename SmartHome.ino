#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_NeoPixel.h>
#include <Servo.h>
#include <SoftwareSerial.h>

#define DHTPIN 8
#define DHTTYPE DHT11
#define PIN        6
#define NUMPIXELS 3
#define DELAYVAL 500
#define Fan 11

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo;
SoftwareSerial Bluetooth(5, 4);

void setup() {
  Serial.begin(9600);
  Bluetooth.begin(9600);
  pixels.begin();
  pinMode(Fan, OUTPUT);
  myservo.attach(13);
  myservo.write(180);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Jeju Nat'l Univ.");
  lcd.setCursor(1, 1);
  lcd.print("Hello, world!");

}
void loop() {
  int humi = dht.readHumidity();
  int temp = dht.readTemperature();
  Serial.print(temp);
  Serial.print(", ");
  Serial.println(humi);
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp : ");
  lcd.print(temp);
  lcd.print(" oC");
  lcd.setCursor(0, 1);
  lcd.print("Humi : ");
  lcd.print(humi);
  lcd.print(" %");
  delay(1000);

  if (Bluetooth.available()) {
    delay(3);
    char c = Bluetooth.read();
    if (c == 'a') {
      digitalWrite(Fan, HIGH);
    }
    if (c == 'b') {
      digitalWrite(Fan, LOW);
    }
    if (c == 'c') {
      myservo.write(90);
    }
    if (c == 'd') {
      myservo.write(180);
    }
    if (c == 'e') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(255, 0, 0));
      pixels.setPixelColor(1, pixels.Color(255, 0, 0));
      pixels.setPixelColor(2, pixels.Color(255, 0, 0));
      pixels.show();
    }
    if (c == 'f') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(255, 127, 0));
      pixels.setPixelColor(1, pixels.Color(255, 127, 0));
      pixels.setPixelColor(2, pixels.Color(255, 127, 0));
      pixels.show();
    }
    if (c == 'g') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(255, 255, 0));
      pixels.setPixelColor(1, pixels.Color(255, 255, 0));
      pixels.setPixelColor(2, pixels.Color(255, 255, 0));
      pixels.show();
    }
    if (c == 'h') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(0, 255, 0));
      pixels.setPixelColor(1, pixels.Color(0, 255, 0));
      pixels.setPixelColor(2, pixels.Color(0, 255, 0));
      pixels.show();
    }
    if (c == 'i') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(0, 0, 255));
      pixels.setPixelColor(1, pixels.Color(0, 0, 255));
      pixels.setPixelColor(2, pixels.Color(0, 0, 255));
      pixels.show();
    }
    if (c == 'j') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(255, 51, 153));
      pixels.setPixelColor(1, pixels.Color(255, 51, 153));
      pixels.setPixelColor(2, pixels.Color(255, 51, 153));
      pixels.show();
    }
    if (c == 'k') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(255, 255, 255));
      pixels.setPixelColor(1, pixels.Color(255, 255, 255));
      pixels.setPixelColor(2, pixels.Color(255, 255, 255));
      pixels.show();
    }
    if (c == 'l') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(0, 0, 0));
      pixels.setPixelColor(1, pixels.Color(0, 0, 0));
      pixels.setPixelColor(2, pixels.Color(0, 0, 0));
      pixels.show();
    }
  }

  if (Serial.available()) {
    delay(3);
    char c = Serial.read();
    if (c == 'a') {
      digitalWrite(Fan, HIGH);
    }
    if (c == 'b') {
      digitalWrite(Fan, LOW);
    }
    if (c == 'c') {
      myservo.write(90);
    }
    if (c == 'd') {
      myservo.write(180);
    }
    if (c == '1') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(255, 0, 0));
      pixels.setPixelColor(1, pixels.Color(255, 0, 0));
      pixels.setPixelColor(2, pixels.Color(255, 0, 0));
      pixels.show();
    }
    if (c == '2') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(255, 127, 0));
      pixels.setPixelColor(1, pixels.Color(255, 127, 0));
      pixels.setPixelColor(2, pixels.Color(255, 127, 0));
      pixels.show();
    }
    if (c == '3') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(255, 255, 0));
      pixels.setPixelColor(1, pixels.Color(255, 255, 0));
      pixels.setPixelColor(2, pixels.Color(255, 255, 0));
      pixels.show();
    }
    if (c == '4') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(0, 255, 0));
      pixels.setPixelColor(1, pixels.Color(0, 255, 0));
      pixels.setPixelColor(2, pixels.Color(0, 255, 0));
      pixels.show();
    }
    if (c == '5') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(0, 0, 255));
      pixels.setPixelColor(1, pixels.Color(0, 0, 255));
      pixels.setPixelColor(2, pixels.Color(0, 0, 255));
      pixels.show();
    }
    if (c == '6') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(255, 51, 153));
      pixels.setPixelColor(1, pixels.Color(255, 51, 153));
      pixels.setPixelColor(2, pixels.Color(255, 51, 153));
      pixels.show();
    }
    if (c == '7') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(255, 255, 255));
      pixels.setPixelColor(1, pixels.Color(255, 255, 255));
      pixels.setPixelColor(2, pixels.Color(255, 255, 255));
      pixels.show();
    }
    if (c == '8') {
      pixels.clear();
      pixels.setPixelColor(0, pixels.Color(0, 0, 0));
      pixels.setPixelColor(1, pixels.Color(0, 0, 0));
      pixels.setPixelColor(2, pixels.Color(0, 0, 0));
      pixels.show();
    }
  }
}
