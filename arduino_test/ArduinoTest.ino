//Load ultrassonic sensor library
#include <Ultrasonic.h>
 
//Define trigger and echo pins
#define pin_trigger 2
#define pin_echo 4

//Define led pin
#define ledOne 7
 
//Initialize ultrassonic sensor
Ultrasonic ultrasonic(pin_trigger, pin_echo);
 
void setup() {
  pinMode(ledOne, OUTPUT);
  Serial.begin(9600);
  Serial.println("Reading ultrasnic sensor data...");
}
 
void loop() {
  //Read ultrasonic sensor data
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  
  //Write ultrasonic sensor data
  Serial.print("Distance in cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distance in inches: ");
  Serial.println(inMsec);
    
  while (Serial.available() > 0) {
    Serial.println("Chose a pin from 0 to 9 to turn it on/off.");
    int serialInputVal = Serial.read();
    serialInputVal -= 48; //Convert ASCII int value to its original value
    Serial.print("Chosen pin: ");
    Serial.println(serialInputVal);

    if (digitalRead(serialInputVal) == LOW) {
      digitalWrite(serialInputVal, HIGH);
    }
    else if (digitalRead(serialInputVal) == HIGH) {
      digitalWrite(serialInputVal, LOW);
    }
    
    delay(1);
  }
}

