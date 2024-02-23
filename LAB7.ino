#include <LiquidCrystal.h>
#include <Servo.h>
#include "Timer.h"
Servo motor;
LiquidCrystal lcd(6,7, 8, 9, 10, 11, 12);
const int moistureThresholdLow = 375; 
const int moistureThresholdHigh = 225;
const long waterLevelThreshold = 19; 
enum STATE{IDLE, WATERING, ALERT} gState = IDLE;
void setup() {
  lcd.begin(16,2);
  lcd.clear();
  motor.attach(2); //motor
  motor.write(0); //set motor to 0 degrees
  pinMode(A0,INPUT); // soil sensor
  pinMode(3, OUTPUT); // Ultrasonic sensor trigPin
  pinMode(4, INPUT); //echoPin
  TimerSet(100);
  TimerOn();
}

void loop() {
  int moistureLevel = analogRead(A0);
  int waterLevel = measureWaterLevel();
  if (TimerFlag){
  TimerFlag = 0;
  switch (gState) {
    case IDLE:
      if (moistureLevel > moistureThresholdLow) {
        lcd.clear();
        gState = WATERING;
      }else if(waterLevel > waterLevelThreshold){
        lcd.clear();
        gState = ALERT;
      }
      break;
    case WATERING:
      if (moistureLevel < moistureThresholdHigh) {
        lcd.clear();
        gState = IDLE;
      }else if(waterLevel > waterLevelThreshold){
        lcd.clear();
        gState = ALERT;
      }
      break;
    case ALERT:
      if(waterLevel < waterLevelThreshold && moistureLevel < moistureThresholdHigh){ // if the distance detected is below the threshold AND the soil is moist enough
        lcd.clear();
        gState = IDLE;
      } else if (waterLevel < waterLevelThreshold && moistureLevel > moistureThresholdHigh){ // if the distance detected is below the threshold AND the soil is dry
        lcd.clear();
        gState = WATERING;
      }
      break;
  }
  // Act based on the state
  if (gState == WATERING) {
    motor.write(90); //turn motor
    lcd.setCursor(0, 0);
    lcd.print("Watering...");
  } else if (gState == IDLE){
    motor.write(0); //turn motor back
    lcd.setCursor(0, 0);
    lcd.print("Idle");
  } else if (gState == ALERT){
    motor.write(0);
    lcd.setCursor(0, 0);
    lcd.print("Water LOW");
  }
  lcd.setCursor(0, 1);
  lcd.print("Moisture: ");
  lcd.print(600-moistureLevel); //because the acutal sensor values are counterintuitive
}
}
long measureWaterLevel() { // function to measure the water level
  digitalWrite(3, LOW);
  delayMicroseconds(10);
  digitalWrite(3, HIGH);
  delayMicroseconds(50);
  digitalWrite(3, LOW);

  long duration = pulseIn(4, HIGH);
  long distance = duration * 0.034 / 2; // Speed of sound wave divided by 2
  return distance;
}