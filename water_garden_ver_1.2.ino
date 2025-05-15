// *************************** //
// **** ARDUINO GARDENING **** //
// ******** BCTC, KY ********* //
// *************************** //

// Description: For automatic watering we use 11 independent relays with water valves
// and 11 humidity sensors. One for each "bath" with plants.

// In my case for Arduino Mega 2560 we need 11 relays
// Number of sensors and relays
const int NUM_ZONES = 11;

// Sensor pins (analog A0 to A10)
const int sensorPins[NUM_ZONES] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10};

// Relay pins (you must define actual pin numbers for relays)
const int relayPins[NUM_ZONES] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // Adjust to your wiring

// Moisture thresholds
// If value >= 600, It means that sensor is DRY (0%)
// If value <= 290, sensor is wet, fully in water (100%)
const int DRY_THRESHOLD = 500; // Set according to your needs, will works as a threshold to activate the pump

void setup() {
  Serial.begin(9600); // Connection speed
  
  // Initialize relay pins
  for (int i = 0; i < NUM_ZONES; i++) {
    pinMode(relayPins[i], OUTPUT);
    digitalWrite(relayPins[i], LOW); // Start with valves closed
  }
}

void loop() {
  for (int i = 0; i < NUM_ZONES; i++) {
    int sensorValue = analogRead(sensorPins[i]);
    Serial.print("Sensor #");
    Serial.print(i + 1);
    Serial.print(" output: ");
    Serial.println(sensorValue);

    if (sensorValue > DRY_THRESHOLD) {
      Serial.println("The soil is DRY!");
      Serial.print("*** VALVE #");
      Serial.print(i + 1);
      Serial.println(" OPEN ***");
      digitalWrite(relayPins[i], HIGH);
    } else {
      Serial.println("The soil is WET");
      Serial.print("*** VALVE #");
      Serial.print(i + 1);
      Serial.println(" CLOSED ***");
      digitalWrite(relayPins[i], LOW);
    }

    delay(2000); // Delay between each valve check
  }

  Serial.println("All zones checked. Waiting for next cycle...");
  delay(3000); // Delay before next loop
}
