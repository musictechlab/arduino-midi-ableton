#include "MIDIUSB.h"

// Define button pins
const int VOL_UP_PIN = 2;
const int VOL_DOWN_PIN = 3;

// Volume state
int volumeLevel = 64; // Start at a mid-level volume (0-127)

// Variables for dynamic delay
unsigned long pressStartTime = 0; // Time when the button was first pressed
unsigned long currentDelay = 100; // Initial delay (in milliseconds)

void setup() {
  pinMode(VOL_UP_PIN, INPUT_PULLUP);   // Enable internal pull-up resistor
  pinMode(VOL_DOWN_PIN, INPUT_PULLUP);
}

void loop() {
  // Volume Up Button Logic
  if (digitalRead(VOL_UP_PIN) == LOW) {
    handleButtonPress(5); // Increment volume
  } else if (digitalRead(VOL_UP_PIN) == HIGH) {
    resetDelay(); // Reset delay when button is released
  }

  // Volume Down Button Logic
  if (digitalRead(VOL_DOWN_PIN) == LOW) {
    handleButtonPress(-5); // Decrement volume
  } else if (digitalRead(VOL_DOWN_PIN) == HIGH) {
    resetDelay(); // Reset delay when button is released
  }
}

// Handle button press with dynamic speed
void handleButtonPress(int direction) {
  unsigned long currentTime = millis();
  
  // Speed up if the button is held longer
  if (pressStartTime == 0) {
    pressStartTime = currentTime; // Start timing when button is pressed
  } else if (currentTime - pressStartTime > 500) { // After 500ms, speed up
    currentDelay = max(20, currentDelay - 20); // Decrease delay, speed up
  }

  // Send volume change and wait
  volumeLevel = constrain(volumeLevel + direction, 0, 127);
  sendVolumeChange(volumeLevel);
  delay(currentDelay);
}

// Reset delay when button is released
void resetDelay() {
  pressStartTime = 0;     // Reset press time
  currentDelay = 200;     // Reset delay to initial value
}

// Function to send MIDI volume control change
void sendVolumeChange(int volume) {
  midiEventPacket_t volumeChange;

  // MIDI Control Change message format: [Type, Channel, Controller, Value]
  volumeChange.header = 0x0B;          // Control Change message
  volumeChange.byte1 = 0xB0;           // Channel 1
  volumeChange.byte2 = 7;              // Volume controller (7 is the standard for volume)
  volumeChange.byte3 = volume;         // Set volume level (0-127)

  MidiUSB.sendMIDI(volumeChange);
  MidiUSB.flush();
}
