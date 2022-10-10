#define dcAdir 4
#define dcApwm 5
#define dcBdir 7
#define dcBpwm 6
#define relay1 A0
#define relay2 A1

int d = 0;
int nl_md = 200;
int run_ = 0;
String data;
long time_ht=0;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
#include"control.h"

void pinmode() {
  pinMode(dcAdir, OUTPUT);
  pinMode(dcApwm, OUTPUT);
  pinMode(dcBdir, OUTPUT);
  pinMode(dcBpwm, OUTPUT);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay1, 1);// tắt all
  digitalWrite(relay2, 1);
}
void khaibao() {
  Serial.begin(9600);
  Serial.setTimeout(5);
  mySerial.begin(9600);
  mySerial.setTimeout(5);

  pinmode();

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Do An ToT Nghiep");

}
