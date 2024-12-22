# Arduino MIDI Volume Control

This project is an Arduino-based MIDI volume control system that uses two buttons to increase or decrease the volume. The system sends MIDI Control Change messages to adjust the volume level dynamically.

## Components

- Arduino board (Leonardo)
- Two push buttons
- MIDIUSB library
- Ableton Live 12 (Trial version)
- USB Cable

## Pin Configuration

- **Volume Up Button**: Connect to digital pin 2
- **Volume Down Button**: Connect to digital pin 3

## Features

- **Dynamic Volume Control**: Adjusts the volume level between 0 and 127.
- **Button Hold Speed-Up**: The longer a button is held, the faster the volume changes.
- **MIDI Control Change**: Sends MIDI messages to control the volume.

## Code Overview

- **Setup**: Configures the button pins with internal pull-up resistors.
- **Loop**: Continuously checks the state of the buttons and adjusts the volume accordingly.
- **handleButtonPress**: Handles the logic for changing the volume, including dynamic speed adjustment.
- **resetDelay**: Resets the delay and timing when a button is released.
- **sendVolumeChange**: Sends a MIDI Control Change message to adjust the volume.

## Usage

1. Connect the buttons to the specified pins on the Arduino.
2. Upload the code to the Arduino board.
3. Press the buttons to increase or decrease the volume.

## Dependencies

- **MIDIUSB Library**: Ensure you have the MIDIUSB library installed in your Arduino IDE. You can install it via the Library Manager.

## License

This project is open-source and available under the MIT License. Feel free to modify and distribute as needed.

## Author
Mariusz.Smenzyk@MusicTechLab.io

# arduino-midi-ableton
