
//Floor mat leds
int floorLed1 = 31;
int floorLed2 = 32;
int floorLed3 = 33;
int floorLed4 = 34;
int floorLed5 = 35;
int floorLed6 = 36;
int floorLed7 = 37;
int floorLed8 = 38;
int floorLed9 = 39;
int floorLed10 = 40;

//Floor mat switches
int floorButton1 = 2;
int floorButton2 = 3;
int floorButton3 = 4;
int floorButton4 = 5;
int floorButton5 = 6;
int floorButton6 = 7;
int floorButton7 = 8;
int floorButton8 = 9;
int floorButton9 = 11;
int floorButton10 = 12;

//Alligator eyes
int gatorLed = 41;

//Floor led state
int ledState1 = HIGH;
int ledState2 = HIGH;
int ledState3 = HIGH;
int ledState4 = HIGH;
int ledState5 = HIGH;
int ledState6 = HIGH;
int ledState7 = HIGH;
int ledState8 = HIGH;
int ledState9 = HIGH;
int ledState10 = HIGH;

//Floor led timing
long previousMillis1 = 0;
long previousMillis2 = 0;
long previousMillis3 = 0;
long previousMillis4 = 0;
long previousMillis5 = 0;
long previousMillis6 = 0;
long previousMillis7 = 0;
long previousMillis8 = 0;
long previousMillis9 = 0;
long previousMillis10 = 0;


long randInterval1 = 0;
long randInterval2 = 0;
long randInterval3 = 0;
long randInterval4 = 0;
long randInterval5 = 0;
long randInterval6 = 0;
long randInterval7 = 0;
long randInterval8 = 0;
long randInterval9 = 0;
long randInterval10 = 0;

// current state of the floor mat switches
int buttonState1 = 0;         
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;
int buttonState7 = 0;
int buttonState8 = 0;
int buttonState9 = 0;
int buttonState10 = 0;

//previous state of the floor mat switches
int lastButtonState1 = 0;
int lastButtonState2 = 0;
int lastButtonState3 = 0;
int lastButtonState4 = 0;
int lastButtonState5 = 0;
int lastButtonState6 = 0;
int lastButtonState7 = 0;
int lastButtonState8 = 0;
int lastButtonState9 = 0;
int lastButtonState10 = 0;


void setup(){
  Serial.begin(9600);
  pinMode(floorLed1, OUTPUT);
  pinMode(floorLed2, OUTPUT);
  pinMode(floorLed3, OUTPUT);
  pinMode(floorLed4, OUTPUT);
  pinMode(floorLed5, OUTPUT);
  pinMode(floorLed6, OUTPUT);
  pinMode(floorLed7, OUTPUT);
  pinMode(floorLed8, OUTPUT);
  pinMode(floorLed9, OUTPUT);
  pinMode(floorLed10, OUTPUT);
  pinMode(gatorLed, OUTPUT);
  pinMode(floorButton1, INPUT);
  pinMode(floorButton2, INPUT);
  pinMode(floorButton3, INPUT);
  pinMode(floorButton4, INPUT);
  pinMode(floorButton5, INPUT);
  pinMode(floorButton6, INPUT);
  pinMode(floorButton7, INPUT);
  pinMode(floorButton8, INPUT);
  pinMode(floorButton9, INPUT);
  pinMode(floorButton10, INPUT);
  
  //enable internal pullup; mat switches start in HIGH position; logic reversed
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  
  
  randomSeed (analogRead (0));
}

void loop()
{
  
  // read the pushbutton input pin:
  buttonState1 = digitalRead(floorButton1);
  buttonState2 = digitalRead(floorButton2);
  buttonState3 = digitalRead(floorButton3);
  buttonState4 = digitalRead(floorButton4);
  buttonState5 = digitalRead(floorButton5);
  buttonState6 = digitalRead(floorButton6);
  buttonState7 = digitalRead(floorButton7);
  buttonState8 = digitalRead(floorButton8);
  buttonState9 = digitalRead(floorButton9);
  buttonState10 = digitalRead(floorButton10);

  unsigned long currentMillis = millis();
 
 
  //Floor Mat 1/////////////////////////
  if(currentMillis - previousMillis1 > randInterval1) {
    randInterval1 = random (4000, 10000);
    previousMillis1 = currentMillis;   


    if (ledState1 == LOW)
      ledState1 = HIGH;
    else
      ledState1 = LOW;


    digitalWrite(floorLed1, ledState1);
  }
  
  if(buttonState1 != lastButtonState1){
    if(buttonState1 == LOW && ledState1 == HIGH){
    Serial.write (0x02);
    delay (1500);
    Serial.write (0xEF);
    }
    
    if(buttonState1 == LOW && ledState1 == LOW){
      digitalWrite (gatorLed, HIGH);
      Serial.write (0x01);
      delay (5000);
      digitalWrite (gatorLed, LOW);
      Serial.write (0xEF);
    }
    lastButtonState1 = buttonState1;
       
  }
  //Floor Mat 2/////////////////////////
  if(currentMillis - previousMillis2 > randInterval2) {
    randInterval2 = random (4000, 10000);
    previousMillis2 = currentMillis;   


    if (ledState2 == LOW)
      ledState2 = HIGH;
    else
      ledState2 = LOW;


    digitalWrite(floorLed2, ledState2);
  }
  
  if(buttonState2 != lastButtonState2){
    if(buttonState2 == LOW && ledState2 == HIGH){
    Serial.write (0x03);
    delay (1500);
    Serial.write (0xEF);
    }
    
    if(buttonState2 == LOW && ledState2 == LOW){
      digitalWrite (gatorLed, HIGH);
      Serial.write (0x01);
      delay (5000);
      digitalWrite (gatorLed, LOW);
      Serial.write (0xEF);
    }
    lastButtonState2 = buttonState2;
       
  }

  //Floor Mat 3/////////////////////////
  if(currentMillis - previousMillis3 > randInterval3) {
    randInterval3 = random (4000, 10000);
    previousMillis3 = currentMillis;   


    if (ledState3 == LOW)
      ledState3 = HIGH;
    else
      ledState3 = LOW;


    digitalWrite(floorLed3, ledState3);
  }
  
  if(buttonState3 != lastButtonState3){
    if(buttonState3 == LOW && ledState3 == HIGH){
    Serial.write (0x04);
    delay (1500);
    Serial.write (0xEF);
    }
    
    if(buttonState3 == LOW && ledState3 == LOW){
      digitalWrite (gatorLed, HIGH);
      Serial.write (0x01);
      delay (5000);
      digitalWrite (gatorLed, LOW);
      Serial.write (0xEF);
    }
    lastButtonState3 = buttonState3;
       
  }

  //Floor Mat 4/////////////////////////
  if(currentMillis - previousMillis4 > randInterval4) {
    randInterval4 = random (4000, 10000);
    previousMillis4 = currentMillis;   


    if (ledState4 == LOW)
      ledState4 = HIGH;
    else
      ledState4 = LOW;


    digitalWrite(floorLed4, ledState4);
  }
  
  if(buttonState4 != lastButtonState4){
    if(buttonState4 == LOW && ledState4 == HIGH){
    Serial.write (0x05);
    delay (1500);
    Serial.write (0xEF);
    }
    
    if(buttonState4 == LOW && ledState4 == LOW){
      digitalWrite (gatorLed, HIGH);
      Serial.write (0x01);
      delay (5000);
      digitalWrite (gatorLed, LOW);
      Serial.write (0xEF);
    }
    lastButtonState4 = buttonState4;
       
  }

  //Floor Mat 5/////////////////////////
  if(currentMillis - previousMillis5 > randInterval5) {
    randInterval5 = random (4000, 10000);
    previousMillis5 = currentMillis;   


    if (ledState5 == LOW)
      ledState5 = HIGH;
    else
      ledState5 = LOW;


    digitalWrite(floorLed5, ledState5);
  }
  
  if(buttonState5 != lastButtonState5){
    if(buttonState5 == LOW && ledState5 == HIGH){
    Serial.write (0x02);
    delay (1500);
    Serial.write (0xEF);
    }
    
    if(buttonState5 == LOW && ledState5 == LOW){
      digitalWrite (gatorLed, HIGH);
      Serial.write (0x01);
      delay (5000);
      digitalWrite (gatorLed, LOW);
      Serial.write (0xEF);
    }
    lastButtonState5 = buttonState5;
       
  }

  //Floor Mat 6/////////////////////////
  if(currentMillis - previousMillis6 > randInterval6) {
    randInterval6 = random (4000, 10000);
    previousMillis6 = currentMillis;   


    if (ledState6 == LOW)
      ledState6 = HIGH;
    else
      ledState6 = LOW;


    digitalWrite(floorLed6, ledState6);
  }
  
  if(buttonState6 != lastButtonState6){
    if(buttonState6 == LOW && ledState6 == HIGH){
    Serial.write (0x06);
    delay (1500);
    Serial.write (0xEF);
    }
    
    if(buttonState6 == LOW && ledState6 == LOW){
      digitalWrite (gatorLed, HIGH);
      Serial.write (0x01);
      delay (5000);
      digitalWrite (gatorLed, LOW);
      Serial.write (0xEF);
    }
    lastButtonState6 = buttonState6;
       
  }

  //Floor Mat 7/////////////////////////
  if(currentMillis - previousMillis7 > randInterval7) {
    randInterval7 = random (4000, 10000);
    previousMillis7 = currentMillis;   


    if (ledState7 == LOW)
      ledState7 = HIGH;
    else
      ledState7 = LOW;


    digitalWrite(floorLed7, ledState7);
  }
  
  if(buttonState7 != lastButtonState7){
    if(buttonState7 == LOW && ledState7 == HIGH){
    Serial.write (0x03);
    delay (1500);
    Serial.write (0xEF);
    }
    
    if(buttonState7 == LOW && ledState7 == LOW){
      digitalWrite (gatorLed, HIGH);
      Serial.write (0x01);
      delay (5000);
      digitalWrite (gatorLed, LOW);
      Serial.write (0xEF);
    }
    lastButtonState7 = buttonState7;
       
  }

  //Floor Mat 8/////////////////////////
  if(currentMillis - previousMillis8 > randInterval8) {
    randInterval8 = random (4000, 10000);
    previousMillis8 = currentMillis;   


    if (ledState8 == LOW)
      ledState8 = HIGH;
    else
      ledState8 = LOW;


    digitalWrite(floorLed8, ledState8);
  }
  
  if(buttonState8 != lastButtonState8){
    if(buttonState8 == LOW && ledState8 == HIGH){
    Serial.write (0x07);
    delay (1500);
    Serial.write (0xEF);
    }
    
    if(buttonState8 == LOW && ledState8 == LOW){
      digitalWrite (gatorLed, HIGH);
      Serial.write (0x01);
      delay (5000);
      digitalWrite (gatorLed, LOW);
      Serial.write (0xEF);
    }
    lastButtonState8 = buttonState8;
       
  }

  //Floor Mat 9/////////////////////////
  if(currentMillis - previousMillis9 > randInterval9) {
    randInterval9 = random (4000, 10000);
    previousMillis9 = currentMillis;   


    if (ledState9 == LOW)
      ledState9 = HIGH;
    else
      ledState9 = LOW;


    digitalWrite(floorLed9, ledState9);
  }
  
  if(buttonState9 != lastButtonState9){
    if(buttonState9 == LOW && ledState9 == HIGH){
    Serial.write (0x04);
    delay (1500);
    Serial.write (0xEF);
    }
    
    if(buttonState9 == LOW && ledState9 == LOW){
      digitalWrite (gatorLed, HIGH);
      Serial.write (0x01);
      delay (5000);
      digitalWrite (gatorLed, LOW);
      Serial.write (0xEF);
    }
    lastButtonState9 = buttonState9;
       
  }

  //Floor Mat 10/////////////////////////
  if(currentMillis - previousMillis10 > randInterval10) {
    randInterval10 = random (4000, 10000);
    previousMillis10 = currentMillis;   


    if (ledState10 == LOW)
      ledState10 = HIGH;
    else
      ledState10 = LOW;


    digitalWrite(floorLed10, ledState10);
  }
  
  if(buttonState10 != lastButtonState10){
    if(buttonState10 == LOW && ledState10 == HIGH){
    Serial.write (0x06);
    delay (1500);
    Serial.write (0xEF);
    }
    
    if(buttonState10 == LOW && ledState10 == LOW){
      digitalWrite (gatorLed, HIGH);
      Serial.write (0x01);
      delay (5000);
      digitalWrite (gatorLed, LOW);
      Serial.write (0xEF);
    }
    lastButtonState10 = buttonState10;
       
  }



}



