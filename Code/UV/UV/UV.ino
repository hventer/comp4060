//----Begin Code (copy from here)----
//Variables:
int varPin = A0;
double val = 0.000;
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Serial connection established..\nAdjust the Potentiometer to see the value change!");
}
void loop() {
// put your main code here, to run repeatedly:
Serial.print("Value: ");
val = analogRead(varPin);
Serial.println(val);
delay(500);
}
//----End Code (copy to here)----
