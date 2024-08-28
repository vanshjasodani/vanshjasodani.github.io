//By: Vansh Jasodani- vanshjasodani.github.io
//For doubts refer to: https://youtu.be/SJV51kScJLg?si=vOsJxIxJWNAFxzKZ
int Red_led = 13;
int Green_led = 12;
int sensor_pin = A0;
int sensor_thres = 400;


void setup() {
  // put your setup code here, to run once:
pinMode(Red_led,OUTPUT);
pinMode(Green_led,OUTPUT);
pinMode(sensor_pin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int Gas_value= analogRead(A0);
if (Gas_value > sensor_thres){

  digitalWrite(Red_led,HIGH);
  digitalWrite(Green_led,LOW);

}
else{
  digitalWrite(Red_led,LOW);
  digitalWrite(Green_led,HIGH);

}
delay(100);
}
