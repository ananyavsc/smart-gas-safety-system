#include <ESP32Servo.h>

// Pin Definitions
#define MQ6_PIN 34
#define BUZZER_PIN 25
#define SERVO_PIN 13

// Threshold for gas detection
// ESP32 ADC resolution is 12-bit (0-4095)
const int GAS_THRESHOLD = 1500; 

Servo gasValveServo;

void setup() {
  // Serial monitor for debugging
  Serial.begin(115200);

  // Initialize Pins
  pinMode(MQ6_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Initialize Servo
  gasValveServo.setPeriodHertz(50);    // Standard 50hz servo
  gasValveServo.attach(SERVO_PIN, 500, 2400); 
  
  // Set valve to 'Open' position on startup
  gasValveServo.write(0); 
  
  Serial.println("Gas Detection System Active...");
  digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
  // Read the analog value from MQ-6
  int gasValue = analogRead(MQ6_PIN);
  
  // Print value to Serial Plotter/Monitor
  Serial.print("Gas Level: ");
  Serial.println(gasValue);

  if (gasValue > GAS_THRESHOLD) {
    // ALERT STATE
    Serial.println("!!! DANGER: Gas Leak Detected !!!");
    
    // Close the valve
    gasValveServo.write(90); 
    
    // Pulse the buzzer for a siren effect
    digitalWrite(BUZZER_PIN, HIGH);
    delay(100);
    digitalWrite(BUZZER_PIN, LOW);
    delay(100);
  } else {
    // SAFE STATE
    digitalWrite(BUZZER_PIN, LOW);
    
    // Ensure valve is open
    gasValveServo.write(0); 
  }

  delay(200); // Small delay for stability
}