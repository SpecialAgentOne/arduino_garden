#define sensorPin A0
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
   int value = analogRead(sensorPin);
  
  // Print the value to the serial monitor
  Serial.println("Analog output: " + value);
  
  // Wait for 1 second before the next reading
  delay(3000); // Can adjust for the needs

  if(value > 500) {
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

  delay(1000); // Delay timer
}