int temperaturePin = A0;  // TMP36 connected to A0
int ledPin = 9;    // LED anpdeleg is connected to digital pin 9
float threshold = 30.0; // Temperature threshold in °C

void setup() 
{
  pinMode(ledPin, OUTPUT); // here we had set LED pin as output
  Serial.begin(9600);      // Start serial communication
}

void loop() 
{
  int sensorValue = analogRead(temperaturePin); // Read TMP36 sensor value
  float voltage = sensorValue * (5.0 / 1023.0); //converting sensor value into actual voltage using the formula
  float temperature = (voltage - 0.5) * 100; // Convert voltage to temperature in °C
  //At 0°C, the output voltage is 0.5V (baseline voltage)
  //Every 1°C increase, the voltage increases by 0.01V

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature > threshold) // If temperature is high, simulate motion
  { 
    digitalWrite(ledPin, HIGH); // Turn LED ON
    Serial.println("Event Detected: LED ON");
  } 
  else 
  {
    digitalWrite(ledPin, LOW); // Turn LED OFF
    Serial.println("No Event detected: LED OFF");
  }
  
  delay(1000); // Wait for a second
}
