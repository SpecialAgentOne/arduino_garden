#define sensorPin1 A0
#define sensorPin2 A1
#define sensorPin3 A2
#define sensorPin4 A3
#define RELAY_PIN 10 // In my case for Arduino Mega 2560, constant

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // speed of connection
  pinMode(RELAY_PIN, OUTPUT);
}

// Reading the moisture level from sensor(s)
void loop() {
   // If value >= 600, It means that sensor is DRY (0%)
   // If value <= 290, sensor is wet, fully in water (100%)
   int value1 = analogRead(sensorPin1);
   int value2 = analogRead(sensorPin2);
   int value3 = analogRead(sensorPin3);
   int value4 = analogRead(sensorPin4);
  
  // Print the value to the serial monitor
  Serial.println("Sensor #1 output: " + value1);
  Serial.println("Sensor #2 output: " + value2);
  Serial.println("Sensor #3 output: " + value3);
  Serial.println("Sensor #4 output: " + value4);
  
  // Wait for 1 second before the next reading
  delay(3000); // Can adjust for the needs

  if(value1 > 500 || value2 > 500 || value3 > 500 || value4 > 500) {
    Serial.println("The soil is DRY!");
    Serial.println("*** PUMP ACTIVE ***");
    digitalWrite(RELAY_PIN, HIGH);
    delay(2000);
  } else {
    Serial.println("The soil is WET");
    Serial.println("*** PUMP DEACTIVATED ***");
    digitalWrite(RELAY_PIN, LOW);
    delay(2000);
  }

  delay(3000); // Delay timer
}