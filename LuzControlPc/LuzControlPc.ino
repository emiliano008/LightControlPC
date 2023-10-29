const int analogPin = A6;    // Analog pin A6 to read voltage
const int digitalPin = 6;    // Digital pin D6 for controlling the output

int estadoLuz = 1;           // Assume there is light.
int estadoEncendido = 0;     // Assume that the first time everything is connected, the PC is turned off.

void setup() {
  pinMode(digitalPin, OUTPUT);   // Set pin D6 as an output.
  Serial.begin(9600);           // Initialize serial communication for debugging.
  digitalWrite(digitalPin, LOW); // Default state is OFF for pin 6.
}

void loop() {
  int sensorValue = analogRead(analogPin);  // Read the analog value from A5
  float voltage = (sensorValue / 1023.0) * 5.0;  // Convert the value to voltage (assuming a 5V reference)

  // Print the voltage value on the serial monitor
  Serial.print("Voltage: ");
  Serial.print(voltage, 2);  // 2 decimal places of precision
  Serial.println(" V");
  Serial.println(" Light State");
  Serial.println(estadoLuz);
  Serial.println(" PC State");
  Serial.println(estadoEncendido);

  // Check the voltage value and set the state to turn the PC on or off
  if (voltage <= 2.0) {  // Adjust this threshold according to your needs; I set it to 1 volt for no light.
    estadoLuz = 0; // No light
    delay(600000);  // Wait 10 minutes before the next reading
  } else {
    estadoLuz = 1; // Light is present
  }

  // Turn off the PC because there is no light
  if (estadoLuz == 0 && estadoEncendido == 1) {
    digitalWrite(digitalPin, HIGH);  // Activate output on D6
    delay(2000);  // Wait for 2 seconds to turn off the PC
    digitalWrite(digitalPin, LOW);  // Deactivate output on D6
    estadoEncendido = 0;
  }

  // Turn on the PC
  if (estadoLuz == 1 && estadoEncendido == 0) {
    digitalWrite(digitalPin, HIGH);  // Activate output on D6
    delay(2000);  // Wait for 2 seconds to turn on the PC
    digitalWrite(digitalPin, LOW);  // Deactivate output on D6
    estadoEncendido = 1;
  }

  delay(1000);  // Wait for 1 minutes before the next reading
}
