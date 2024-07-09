// Vansh Jasodani: https://vanshjasodani.github.io/

const int flexSensorPin = A0;  // Analog pin for flex sensor
const int buzzerPin = 8;       // Digital pin for buzzer
int sensorValue = 0;           // Variable to store the sensor value
int threshold = 1000;           // Threshold value to detect door open

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);  // Set the buzzer pin as an output
  Serial.begin(9600);          // Initialize serial communication for debugging;
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(flexSensorPin);  // Read the value from the flex sensor
  Serial.println(sensorValue);              // Print the sensor value for debugging
  
  if (sensorValue < threshold) {            // Check if the sensor value is above the threshold
    digitalWrite(buzzerPin, HIGH);          // Turn the buzzer on
  } else {
    digitalWrite(buzzerPin, LOW);           // Turn the buzzer off
  }
  
  delay(100);  // Small delay for stability
}
