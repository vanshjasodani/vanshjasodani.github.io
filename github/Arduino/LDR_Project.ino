//Vansh Jasodani: vanshjasodani.github.io
//For doubts refer to: https://youtu.be/iYcXjmJk7dQ?si=-mXZvGA3QUX1UMqC

int ldr = 7;
int x;
int led = 13;
int buzzer = 12;

void setup() 
{
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  x = digitalRead(7);
  Serial.println(x);

  if(x == HIGH)
  {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
  }
  if(x == LOW)
  {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
  }

}
