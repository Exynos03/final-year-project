#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  Serial.begin(115200);
  Wire.begin(D1,D0);
  lcd.begin();
  lcd.home();
  lcd.print("ABS");
  delay(3000);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("i2c lcd display");
  lcd.setCursor(0, 1);
  lcd.print("9889676786987");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SKHHVV");
  lcd.setCursor(0, 1);

}
