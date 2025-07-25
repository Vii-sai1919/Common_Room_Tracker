#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin = 7;
int buttonState;           
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;   

int studentCount = 0; 
const int maxCapacity = 100;

void setup() {
  lcd.begin(16, 2); 
  pinMode(buttonPin, INPUT);
  lcd.print("Common Room");
  lcd.setCursor(0, 1);
  lcd.print("Tracker Ready!");
  delay(2000);
  lcd.clear();
}
void loop() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == HIGH && lastButtonState == LOW) {
      if (studentCount < maxCapacity) {
        studentCount++;
      }
      updateLCD();
    }
  }
  lastButtonState = reading;
}
void updateLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Count: ");
  lcd.print(studentCount);
  lcd.setCursor(0, 1);
  if (studentCount >= maxCapacity) {
    lcd.print("Status: FULL");
  } else if (studentCount >= 90) {
    lcd.print("Closing Soon");
  } else if (studentCount >= 70) {
    lcd.print("Status: RUSH");
  } else {
    lcd.print("Status: Normal");
  }
}
