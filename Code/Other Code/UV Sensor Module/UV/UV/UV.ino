int pinS1 = A0;
int pinS2 = A1;
int pinS3 = A2;
float val = 0.000;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~~~~");
  Serial.print("Value 1: ");
  Serial.println(analogRead(pinS1));

  Serial.print("Value 2: ");
  Serial.println(analogRead(pinS2));

  Serial.print("Value 3: ");
  Serial.println(analogRead(pinS3));
  
  delay(1000);
}
