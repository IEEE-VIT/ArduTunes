#include "pitches.h" //file with the frequencies of notes in the fourth octave

#define SPEAKER_PIN 16 //defining the speaker pin 

#define POTENTIOMETER_PIN A0 //defining the potentiometer pin

const int buttonPins[] = { 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 14, 15 }; //declares an array representing the pin numbers for buttons

//notes mapped to respective indices of the buttonPins array
const int Notes[] = {
  NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4,
  NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4
}; 

const int NumNotes = 12; //number of notes

int potValue; // Variable to store the potentiometer value

void setup() {
  for (int i = 0; i < NumNotes; i++) { //for i from 0 to 11
    pinMode(buttonPins[i], INPUT_PULLUP); //INPUT_PULLUP configures the pinMode of the buttonPins as an input with a pull-up resistor enabled
  }
  pinMode(SPEAKER_PIN, OUTPUT); //sets the pinMode of the SPEAKER_PIN as output
}

void loop() {
  int pitch = 0; 
  for (int i = 0; i < NumNotes; i++) { //for i from 0 to 11
    if (digitalRead(buttonPins[i]) == LOW) { // if the button is pressed
      pitch = Notes[i]; //pitch takes the value of the corresponding index from Notes array
    }
  }
  if (pitch) { //if the pitch has a value (i.e., not zero)
    tone(SPEAKER_PIN, pitch); //output in the speaker is the corresponding frequency value of the selected note
  } else { //if pitch is zero
    noTone(SPEAKER_PIN); //no output sound
  }

  potValue = analogRead(POTENTIOMETER_PIN);  // Read the potentiometer value (0-1023)
  for (int i = 0; i < NumNotes; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      int pitch = Notes[i]; //for i from 0 to 11
      // For modifying the pitch based on the potentiometer value
      pitch += map(potValue, 0, 1023, -12, 12);  // Adjust the range for pitch modulation
      tone(SPEAKER_PIN, pitch);  //output in the speaker is the corresponding frequency value of the selected note and the adjusted pitch
      delay(200);  // Adjust the delay as needed
      noTone(SPEAKER_PIN); //no output sound
    }
  }
}
