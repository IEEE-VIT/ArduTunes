#include "pitches.h" //file with the frequencies of notes in the fourth octave

#define SPEAKER_PIN 16       // defining the speaker pin
#define POTENTIOMETER_PIN A0 // defining the potentiometer pin

const int buttonPins[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 14, 15}; // declares an array representing the pin numbers for buttons
// notes mapped to respective indices of the buttonPins array
const int Notes[] = {NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4,
                     NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4, NOTE_B4};
const int NumNotes = sizeof(buttonPins) / sizeof(buttonPins[0]);

int potValue;

void setup()
{
  // Initialize pins and components
  initializePins();
}

void loop()
{
  // Read buttons, adjust pitch, and play notes
  int selectedNote = readButtons();

  if (selectedNote)
  {
    playNote(selectedNote);
  }
  else
  {
    stopSound();
  }

  potValue = analogRead(POTENTIOMETER_PIN);
  adjustPitchAndPlay(selectedNote);
}

void initializePins()
{
  // Set up button pins as inputs with pull-up resistors
  for (int i = 0; i < NumNotes; i++)
  {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(SPEAKER_PIN, OUTPUT); // Set the speaker pin as an output
}

int readButtons()
{
  // Check if any button is pressed and return the corresponding note
  for (int i = 0; i < NumNotes; i++)
  {
    if (digitalRead(buttonPins[i]) == LOW)
    {
      return Notes[i];
    }
  }
  return 0; // No button pressed
}

void playNote(int note)
{
  // Play a note on the speaker
  tone(SPEAKER_PIN, note);
}

void stopSound()
{
  // Stop the sound on the speaker
  noTone(SPEAKER_PIN);
}

void adjustPitchAndPlay(int note)
{
  if (note)
  {
    for (int i = 0; i < NumNotes; i++)
    {
      if (digitalRead(buttonPins[i]) == LOW)
      {
        int selectedNote = Notes[i];
        int adjustedNote = adjustPitch(selectedNote);
        playNoteForDuration(adjustedNote, 200);
        stopSound();
      }
    }
  }
}

int adjustPitch(int note)
{
  // Modify the pitch of a note based on the potentiometer reading
  int pitchRange = map(potValue, 0, 1023, -12, 12);
  return note + pitchRange;
}

void playNoteForDuration(int note, int duration)
{
  // Play a note for a specified duration
  playNote(note);
  delay(duration);
}
