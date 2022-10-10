void motor1(int nl) {//+ tien
  if (nl >= 0) {
    digitalWrite(dcAdir, 1);
    analogWrite(dcApwm, 250 - abs(nl));
  }
  else {

    digitalWrite(dcAdir, 0);
    analogWrite(dcApwm, abs(nl));
  }
}
void motor2(int nl) {//+ tien
  if (nl >= 0) {
    digitalWrite(dcBdir, 1);
    analogWrite(dcBpwm, 250 - abs(nl));
  }
  else {
    digitalWrite(dcBdir, 0);
    analogWrite(dcBpwm, abs(nl));
  }
}
void tien(int nl) {
  motor1(nl);
  motor2(nl);
}
void lui(int nl) {
  motor1(-abs(nl));
  motor2(-abs(nl));
}
void xp(int nl) {
  motor1(abs(nl));
  motor2(-abs(nl));
}
void xt(int nl) {
  motor1(-abs(nl));
  motor2(abs(nl));
}
void run() {
  if (Serial.available()) {
    data = Serial.readString();
    Serial.println(data);
    mySerial.print(data);
  }
  if (mySerial.available()) {
    data = mySerial.readString();
    Serial.println(data);
  }
  if (data.indexOf("tien") != -1) {
    tien(nl_md);
    lcd.setCursor(0, 1);
    lcd.print("    tien   ");
  }
  if (data.indexOf("lui") != -1) {
    lui(nl_md);
    lcd.setCursor(0, 1);
    lcd.print("     lui   ");
  }
  if (data.indexOf("trai") != -1) {
    xt(200);
    lcd.setCursor(0, 1);
    lcd.print("     trai   ");
  }
  if (data.indexOf("phai") != -1) {
    xp(200);
    lcd.setCursor(0, 1);
    lcd.print("     phai   ");
  }
  if (data.indexOf("stop") != -1) {
    tien(0);
    lcd.setCursor(0, 1);
    lcd.print("     stop   ");
  }
  if (data.indexOf("rl1") != -1) {
    digitalWrite(relay1, !digitalRead(relay1));
    lcd.setCursor(0, 1);
    lcd.print("     rl1   ");
    data = "";
  }
  if (data.indexOf("rl2") != -1) {
    digitalWrite(relay2, !digitalRead(relay2));
    lcd.setCursor(0, 1);
    lcd.print("     rl2   ");
    data = "";
  }
  if (millis() - time_ht > 1000) {
    lcd.setCursor(0, 1);
    lcd.print("            ");
    time_ht = millis();
  }
}
