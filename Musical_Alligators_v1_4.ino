//Swamp sounds
int swamp[] = {0x02,0x03,0x04,0x05,0x06,0x07};

//Floor mat led pins
int floorLed[] = {31,32,33,34,35,36,37,38,39,40};


//Floor mat switch pins
int floorButton[] = {2,3,4,5,6,7,8,9,11,12};


//Alligator eyes pin
int gatorLed = 41;

//Floor led state
int ledState = HIGH;


//Floor led timing
long previousMillis[10];

//Random Swamp sound generator
long randNumber;


long randInterval[10];


// current state of the floor mat switches
int buttonState[10];         


//previous state of the floor mat switches
int lastButtonState[10];

int i = 0;

void setup(){
  Serial.begin(9600);
  for (i = 0; i < 10; i = i + 1) {
    pinMode(floorLed[i], OUTPUT);
    pinMode(floorButton[i], INPUT);
    digitalWrite(floorButton[i], HIGH); //enable internal pullup; mat switches start in HIGH position; logic reversed
  }
  pinMode(gatorLed, OUTPUT);
  randomSeed (analogRead (0));
}

void loop()
{
  
  // read the pushbutton input pin:
  for (i = 0; i < 10; i = i+1) {
    buttonState[i] = digitalRead(floorButton[i]);
  }

  unsigned long currentMillis = millis();
 
 randNumber = random(0, 6);
 //Floor Mats///////////////////////////
 for(int i=0; i< 10; i++){
     if(currentMillis - previousMillis[i] > randInterval[i]){
         randInterval[i] = random(4000, 10000);
         previousMillis[i] = currentMillis; 

         if(ledState[i] == LOW)
          ledState[i] = HIGH;
         else
          ledState[i] = LOW;

         digitalWrite(floorLed[i], ledState[i]);
     }

     if(buttonState[i] != lastButtonState[i]){
      if(buttonState[i] == LOW && ledState[i] == HIGH){
        Serial.write (swamp[randNumber]);
        delay(1500);
        Serial.write (0xEF);          
      }

      if(buttonState[i] == LOW && ledState[i] == LOW){
        digitalWrite(gatorLed, HIGH);
        Serial.write(0x01);
        delay(5000);
        digitalWrite(gatorLed, LOW);  
      }
      lastButtonState[i] = buttonState[i];
         
     }
 }
}