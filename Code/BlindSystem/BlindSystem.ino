#include <LowPower.h>
#include <dht.h>

#include "UV.h"
#include "Blinds.h"

#define TEMP_PIN 2

//Creation of the temperature sensor
dht DHT;

//Creation of 3 UV Sensor objects
UV UV0(A2);
UV UV1(A0);
UV UV2(A1);

//Create a blinds object and pass the pins
Blinds blinds(7,6,5);

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  
  blinds.init();
}

void loop() {
  awake();
  readUV();
  //readTemp();
  sleep();
}

void readUV() {
  if(!UV1.inSunlight() && !UV2.inSunlight()) {
   blinds.raise();
  }
  else if(UV0.inSunlight()) {
  if(UV0.inSunlight()) {
    blinds.lower();
    readUV();
  }
  else {
    blinds.stop();
  }
}

void readTemp() {
  //Uses the DHT library
  int readData = DHT.read11(TEMP_PIN);

  float t = DHT.temperature; 
  float h = DHT.humidity; 
 
  Serial.print("Temperature = ");
  Serial.print(t);
  Serial.print(" C | ");

  Serial.print("Humidity = ");
  Serial.print(h);
  Serial.println(" %");
}

void awake() {
  //Turns the LED back on
  Serial.println("~~~~~~~~~ I'm Awake ~~~~~~~~~~");
  digitalWrite(LED_BUILTIN,HIGH);
  delay(200);
}

void sleep() {
  //Uses the LowPower library
  delay(2000);
  Serial.println("I am going for a Nap");
  Serial.println("");
  delay(200);

  digitalWrite(LED_BUILTIN,LOW);
  LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, 
                 SPI_OFF, USART0_OFF, TWI_OFF);
}
