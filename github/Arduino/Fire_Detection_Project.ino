//By Vansh Jasodani: vanshjasodani.github.io
//If any doubts refer to: https://youtu.be/72DBEkGgu-w?si=i5jKp97OBcmgBtc-
const int buzzerPin = 12;
const int flamePin = 11;
int Flame = HIGH;
int redled = 5;
int greenled = 6;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzerPin, OUTPUT);
pinMode(redled, OUTPUT);
pinMode(greenled, OUTPUT);

pinMode(flamePin, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Flame = digitalRead(flamePin);
if (Flame== LOW)
{
  digitalWrite(buzzerPin, HIGH);
  digitalWrite(greenled, HIGH);
  digitalWrite(redled, LOW);
}
else
{
  digitalWrite(buzzerPin, LOW);
  digitalWrite(greenled, LOW);
  digitalWrite(redled, HIGH);
}
}
