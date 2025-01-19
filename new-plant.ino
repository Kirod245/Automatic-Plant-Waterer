const int moisturePin = A1;  // Analog pin connected to soil moisture sensor
const int pumpPin = 3;      // Digital pin connected to water pump relay
const int dryThreshold = 600; // Adjust based on sensor calibration (0-1023)
int waitTime = 1000;

//dry = 770 - 800

//wet = 400 

void setup() {
  Serial.begin(9600);       // Initialize serial communication
  pinMode(moisturePin, INPUT);
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW); // Ensure pump is off at startup
}

void loop() {
  int moistureLevel = analogRead(moisturePin);
  Serial.print("Soil Moisture Level: ");
  Serial.println(moistureLevel);

  if (moistureLevel > dryThreshold) {
    Serial.println("Soil is dry.");
    digitalWrite(pumpPin, HIGH); // Turn pump on
    
  }
  else{
    Serial.println("Moisture Level Sufficient");
    digitalWrite(pumpPin,LOW); // turn pump off
  }
  delay(waitTime); // Wait 1 second before next reading
}


