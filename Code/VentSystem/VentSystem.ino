#include <LowPower.h>
#include <dht.h>

#define UV_PIN A0
#define TEMP_PIN 2
#define LED_PIN 8

dht DHT;

void setup() {
  Serial.begin(9600);
  //Turn the built in LED off initially
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  awake();
  readUV();
  readTemp();
  sleep();
}

void readUV() {
  //Displays the raw value from the sensor
  Serial.print("UV = ");
  int valUV = analogRead(UV_PIN);
  Serial.println(valUV);
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

  if(t > 27.0)
    digitalWrite(LED_PIN, HIGH);
  else
    digitalWrite(LED_PIN, LOW);
}

void awake() {
  //Turns the LED back on
  Serial.println("~~~~~~~~~ I'm Awake ~~~~~~~~~~");
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
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
