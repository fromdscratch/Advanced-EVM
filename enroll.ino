#include <SoftwareSerial.h>

// Define the GSM module connections
#define GSM_TX_PIN 0
#define GSM_RX_PIN 1

// Set the GSM baud rate
#define GSM_BAUD 9600

// Create a SoftwareSerial object to communicate with the GSM module
SoftwareSerial gsmSerial(GSM_TX_PIN, GSM_RX_PIN);

void setup() {
  // Set up serial communication
  Serial.begin(9600);
  gsmSerial.begin(GSM_BAUD);

  // Initialize GSM module
  initializeGSM();
}

void loop() {
  // Send SMS
  sendSMS("+918248836046", "Hello from Arduino!");

  // Wait for 10 seconds
  delay(10000);
}

void initializeGSM() {
  gsmSerial.println("AT"); // Check if the GSM module is responding
  delay(1000);

  gsmSerial.println("AT+CMGF=1"); // Set SMS mode to text mode
  delay(1000);
}

void sendSMS(String number, String message) {
  gsmSerial.println("AT+CMGS=\"" + number + "\""); // Start SMS transmission to the specified number
  delay(1000);
  
  gsmSerial.println(message); // Send the message
  delay(1000);
  
  gsmSerial.write(0x1A); // End the message by sending Ctrl+Z
  delay(1000);
}
