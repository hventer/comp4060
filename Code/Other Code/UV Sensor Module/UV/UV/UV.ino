int varPin = A0;
double val = 0.000;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial connection established..\nAdjust the Potentiometer to see the value change!");
}

void loop() {
  Serial.print("Value: ");
  val = analogRead(varPin);
  Serial.println(val);
  delay(500);
}
