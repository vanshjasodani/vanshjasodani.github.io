//Vansh Jasodani: https://vanshjasodani.github.io/
//For keypad library: https://playground.arduino.cc/Code/Keypad/#Download
//For servo library: https://www.arduino.cc/reference/en/libraries/servo/
//For i2c library: https://www.arduino.cc/reference/en/libraries/liquidcrystal-i2c/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <Servo.h>

// Define the I2C LCD Address
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define the Servo
Servo doorServo;

// Define the Keypad
const byte ROWS = 4; // four rows
const byte COLS = 4; // four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6};  // Connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2};  // Connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

const String password = "1234"; // Change this to your desired password
String inputPassword;

void setup() {
  // put your setup code here, to run once:

   lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");

  doorServo.attach(10);  // Attach the servo to pin 10
  doorServo.write(0);     // Start with the door closed
}

void loop() {
  // put your main code here, to run repeatedly:
char key = keypad.getKey();
  
  if (key) {
    lcd.setCursor(inputPassword.length(), 1);
    lcd.print("*");  // Display '*' for each key press
    inputPassword += key;
    
    if (inputPassword.length() == password.length()) {
      if (inputPassword == password) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Access Granted");
        doorServo.write(90);  // Open the door (servo rotates to 90 degrees)
        delay(5000);          // Keep the door open for 5 seconds
        doorServo.write(0);   // Close the door
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Access Denied");
        delay(2000);  // Show "Access Denied" for 2 seconds
      }
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Enter Password:");
      inputPassword = "";  // Clear the input
    }
  }
}
