#include "pitches.h"
#define REST 0

const int OUR_LED = 5;    // D5
const int POT_PIN = A5;   // potentiometer middle pin
const int SPEAKER = 9;    // D9

int tempo = 144;
int wholenote;

void setup() {
  pinMode(OUR_LED, OUTPUT);
  pinMode(SPEAKER, OUTPUT);
  wholenote = (60000 * 4) / tempo;
}

int getSongChoice() {
  int potValue = analogRead(POT_PIN);

  if (potValue < 341) return 1;
  else if (potValue < 682) return 2;
  else return 3;
}

void play(int note, int divider, int songNum) {
  // stop early if user switched songs
  if (getSongChoice() != songNum) return;

  float noteMs;

  if (divider > 0) {
    noteMs = (float)wholenote / divider;
  } else {
    noteMs = (float)wholenote / abs(divider);
    noteMs *= 1.5f; // dotted note
  }

  int playTime = noteMs * 0.9f;
  int pauseTime = noteMs - playTime;

  digitalWrite(OUR_LED, HIGH);

  if (note != REST) {
    tone(SPEAKER, note, playTime);
  }

  delay(playTime);

  noTone(SPEAKER);
  digitalWrite(OUR_LED, LOW);
  delay(pauseTime);
}

// tetris
void playSong1() {
  play(NOTE_E5, 4, 1);   play(NOTE_B4, 8, 1);
  play(NOTE_C5, 8, 1);   play(NOTE_D5, 4, 1);
  play(NOTE_C5, 8, 1);   play(NOTE_B4, 8, 1);
  play(NOTE_A4, 4, 1);   play(NOTE_A4, 8, 1);
  play(NOTE_C5, 8, 1);   play(NOTE_E5, 4, 1);
  play(NOTE_D5, 8, 1);   play(NOTE_C5, 8, 1);
  play(NOTE_B4, -4, 1);  play(NOTE_C5, 8, 1);
  play(NOTE_D5, 4, 1);   play(NOTE_E5, 4, 1);
  play(NOTE_C5, 4, 1);   play(NOTE_A4, 4, 1);
  play(NOTE_A4, 4, 1);   play(REST, 4, 1);

  play(REST, 8, 1);      play(NOTE_D5, 4, 1);
  play(NOTE_F5, 8, 1);   play(NOTE_A5, 4, 1);
  play(NOTE_G5, 8, 1);   play(NOTE_F5, 8, 1);
  play(NOTE_E5, -4, 1);  play(NOTE_C5, 8, 1);
  play(NOTE_E5, 4, 1);   play(NOTE_D5, 8, 1);
  play(NOTE_C5, 8, 1);
  play(NOTE_B4, 4, 1);   play(NOTE_B4, 8, 1);
  play(NOTE_C5, 8, 1);   play(NOTE_D5, 4, 1);
  play(NOTE_E5, 4, 1);
  play(NOTE_C5, 4, 1);   play(NOTE_A4, 4, 1);
  play(NOTE_A4, 4, 1);   play(REST, 4, 1);

  play(NOTE_E5, 2, 1);   play(NOTE_C5, 2, 1);
  play(NOTE_D5, 2, 1);   play(NOTE_B4, 2, 1);
  play(NOTE_C5, 2, 1);   play(NOTE_A4, 2, 1);
  play(NOTE_B4, 1, 1);

  play(NOTE_E5, 2, 1);   play(NOTE_C5, 2, 1);
  play(NOTE_D5, 2, 1);   play(NOTE_B4, 2, 1);
  play(NOTE_C5, 4, 1);   play(NOTE_E5, 4, 1);
  play(NOTE_A5, 2, 1);
  play(NOTE_GS5, 1, 1);

  play(NOTE_E5, 4, 1);   play(NOTE_B4, 8, 1);
  play(NOTE_C5, 8, 1);   play(NOTE_D5, 4, 1);
  play(NOTE_C5, 8, 1);   play(NOTE_B4, 8, 1);
  play(NOTE_A4, 4, 1);   play(NOTE_A4, 8, 1);
  play(NOTE_C5, 8, 1);   play(NOTE_E5, 4, 1);
  play(NOTE_D5, 8, 1);   play(NOTE_C5, 8, 1);
  play(NOTE_B4, -4, 1);  play(NOTE_C5, 8, 1);
  play(NOTE_D5, 4, 1);   play(NOTE_E5, 4, 1);
  play(NOTE_C5, 4, 1);   play(NOTE_A4, 4, 1);
  play(NOTE_A4, 4, 1);   play(REST, 4, 1);

  play(REST, 8, 1);      play(NOTE_D5, 4, 1);
  play(NOTE_F5, 8, 1);   play(NOTE_A5, 4, 1);
  play(NOTE_G5, 8, 1);   play(NOTE_F5, 8, 1);

  play(REST, 8, 1);      play(NOTE_E5, 4, 1);
  play(NOTE_C5, 8, 1);   play(NOTE_E5, 4, 1);
  play(NOTE_D5, 8, 1);   play(NOTE_C5, 8, 1);

  play(REST, 8, 1);      play(NOTE_B4, 4, 1);
  play(NOTE_C5, 8, 1);   play(NOTE_D5, 4, 1);
  play(NOTE_E5, 4, 1);

  play(REST, 8, 1);      play(NOTE_C5, 4, 1);
  play(NOTE_A4, 8, 1);   play(NOTE_A4, 4, 1);
  play(REST, 4, 1);
}
// sonic 
void playSong2() {
  play(REST, 2, 2);      play(NOTE_D5, 8, 2);   play(NOTE_B4, 4, 2);   play(NOTE_D5, 8, 2);
  play(NOTE_CS5, 4, 2);  play(NOTE_D5, 8, 2);   play(NOTE_CS5, 4, 2);  play(NOTE_A4, 2, 2);
  play(REST, 8, 2);      play(NOTE_A4, 8, 2);   play(NOTE_FS5, 8, 2);  play(NOTE_E5, 4, 2);   play(NOTE_D5, 8, 2);
  play(NOTE_CS5, 4, 2);  play(NOTE_D5, 8, 2);   play(NOTE_CS5, 4, 2);  play(NOTE_A4, 2, 2);
  play(REST, 4, 2);      play(NOTE_D5, 8, 2);   play(NOTE_B4, 4, 2);   play(NOTE_D5, 8, 2);
  play(NOTE_CS5, 4, 2);  play(NOTE_D5, 8, 2);   play(NOTE_CS5, 4, 2);  play(NOTE_A4, 2, 2);

  play(REST, 8, 2);      play(NOTE_B4, 8, 2);   play(NOTE_B4, 8, 2);   play(NOTE_G4, 4, 2);   play(NOTE_B4, 8, 2);
  play(NOTE_A4, 4, 2);   play(NOTE_B4, 8, 2);   play(NOTE_A4, 4, 2);   play(NOTE_D4, 2, 2);
  play(REST, 4, 2);      play(NOTE_D5, 8, 2);   play(NOTE_B4, 4, 2);   play(NOTE_D5, 8, 2);
  play(NOTE_CS5, 4, 2);  play(NOTE_D5, 8, 2);   play(NOTE_CS5, 4, 2);  play(NOTE_A4, 2, 2);
  play(REST, 8, 2);      play(NOTE_A4, 8, 2);   play(NOTE_FS5, 8, 2);  play(NOTE_E5, 4, 2);   play(NOTE_D5, 8, 2);
  play(NOTE_CS5, 4, 2);  play(NOTE_D5, 8, 2);   play(NOTE_CS5, 4, 2);  play(NOTE_A4, 2, 2);

  play(REST, 4, 2);      play(NOTE_D5, 8, 2);   play(NOTE_B4, 4, 2);   play(NOTE_D5, 8, 2);
  play(NOTE_CS5, 4, 2);  play(NOTE_D5, 8, 2);   play(NOTE_CS5, 4, 2);  play(NOTE_A4, 2, 2);
  play(REST, 8, 2);      play(NOTE_B4, 8, 2);   play(NOTE_B4, 8, 2);   play(NOTE_G4, 4, 2);   play(NOTE_B4, 8, 2);
  play(NOTE_A4, 4, 2);   play(NOTE_B4, 8, 2);   play(NOTE_A4, 4, 2);   play(NOTE_D4, 8, 2);   play(NOTE_D4, 8, 2);   play(NOTE_FS4, 8, 2);
  play(NOTE_E4, -1, 2);
  play(REST, 8, 2);      play(NOTE_D4, 8, 2);   play(NOTE_E4, 8, 2);   play(NOTE_FS4, -1, 2);

  play(REST, 8, 2);      play(NOTE_D4, 8, 2);   play(NOTE_D4, 8, 2);   play(NOTE_FS4, 8, 2);  play(NOTE_F4, -1, 2);
  play(REST, 8, 2);      play(NOTE_D4, 8, 2);   play(NOTE_F4, 8, 2);   play(NOTE_E4, -1, 2);

  play(REST, 2, 2);      play(NOTE_D5, 8, 2);   play(NOTE_B4, 4, 2);   play(NOTE_D5, 8, 2);
  play(NOTE_CS5, 4, 2);  play(NOTE_D5, 8, 2);   play(NOTE_CS5, 4, 2);  play(NOTE_A4, 2, 2);
  play(REST, 8, 2);      play(NOTE_A4, 8, 2);   play(NOTE_FS5, 8, 2);  play(NOTE_E5, 4, 2);   play(NOTE_D5, 8, 2);
  play(NOTE_CS5, 4, 2);  play(NOTE_D5, 8, 2);   play(NOTE_CS5, 4, 2);  play(NOTE_A4, 2, 2);
  play(REST, 4, 2);      play(NOTE_D5, 8, 2);   play(NOTE_B4, 4, 2);   play(NOTE_D5, 8, 2);
  play(NOTE_CS5, 4, 2);  play(NOTE_D5, 8, 2);   play(NOTE_CS5, 4, 2);  play(NOTE_A4, 2, 2);

  play(REST, 8, 2);      play(NOTE_B4, 8, 2);   play(NOTE_B4, 8, 2);   play(NOTE_G4, 4, 2);   play(NOTE_B4, 8, 2);
  play(NOTE_A4, 4, 2);   play(NOTE_B4, 8, 2);   play(NOTE_A4, 4, 2);   play(NOTE_D4, 2, 2);
  play(REST, 4, 2);      play(NOTE_D5, 8, 2);   play(NOTE_B4, 4, 2);   play(NOTE_D5, 8, 2);
  play(NOTE_CS5, 4, 2);  play(NOTE_D5, 8, 2);   play(NOTE_CS5, 4, 2);  play(NOTE_A4, 2, 2);
  play(REST, 8, 2);      play(NOTE_A4, 8, 2);   play(NOTE_FS5, 8, 2);  play(NOTE_E5, 4, 2);   play(NOTE_D5, 8, 2);
  play(NOTE_CS5, 4, 2);  play(NOTE_D5, 8, 2);   play(NOTE_CS5, 4, 2);  play(NOTE_A4, 2, 2);

  play(REST, 4, 2);      play(NOTE_D5, 8, 2);   play(NOTE_B4, 4, 2);   play(NOTE_D5, 8, 2);
  play(NOTE_CS5, 4, 2);  play(NOTE_D5, 8, 2);   play(NOTE_CS5, 4, 2);  play(NOTE_A4, 2, 2);
  play(REST, 8, 2);      play(NOTE_B4, 8, 2);   play(NOTE_B4, 8, 2);   play(NOTE_G4, 4, 2);   play(NOTE_B4, 8, 2);
  play(NOTE_A4, 4, 2);   play(NOTE_B4, 8, 2);   play(NOTE_A4, 4, 2);   play(NOTE_D4, 8, 2);   play(NOTE_D4, 8, 2);   play(NOTE_FS4, 8, 2);
  play(NOTE_E4, -1, 2);
  play(REST, 8, 2);      play(NOTE_D4, 8, 2);   play(NOTE_E4, 8, 2);   play(NOTE_FS4, -1, 2);

  play(REST, 8, 2);      play(NOTE_D4, 8, 2);   play(NOTE_D4, 8, 2);   play(NOTE_FS4, 8, 2);  play(NOTE_F4, -1, 2);
  play(REST, 8, 2);      play(NOTE_D4, 8, 2);   play(NOTE_F4, 8, 2);   play(NOTE_E4, 8, 2);
  play(NOTE_E4, -2, 2);  play(NOTE_A4, 8, 2);   play(NOTE_CS5, 8, 2);
  play(NOTE_FS5, 8, 2);  play(NOTE_E5, 4, 2);   play(NOTE_D5, 8, 2);   play(NOTE_A5, -4, 2);
}

//pallet town
void playSong3() {

  play(NOTE_D6, 8, 3);
  play(NOTE_C6, 8, 3);
  play(NOTE_B5, 8, 3);
  play(NOTE_A5, 8, 3);
  play(NOTE_G6, 8, 3);
  play(NOTE_E6, 8, 3);
  play(NOTE_FS6, 8, 3);
  play(NOTE_E6, 8, 3);

  play(NOTE_D6, -4, 3);
  play(NOTE_B5, 8, 3);
  play(NOTE_G5, 8, 3);
  play(NOTE_G5, 8, 3);
  play(NOTE_A5, 8, 3);
  play(NOTE_B5, 8, 3);

  play(NOTE_C6, -2, 3);
  play(NOTE_FS5, 8, 3);
  play(NOTE_G5, 8, 3);
  play(NOTE_A5, 8, 3);

  play(NOTE_B5, -4, 3);
  play(NOTE_C6, 16, 3);
  play(NOTE_B5, 16, 3);
  play(NOTE_A5, 2, 3);

  play(NOTE_D6, 8, 3);
  play(NOTE_C6, 8, 3);
  play(NOTE_B5, 8, 3);
  play(NOTE_D6, 8, 3);
  play(NOTE_G6, 8, 3);
  play(NOTE_FS6, 8, 3);
  play(NOTE_FS6, 8, 3);
  play(NOTE_G6, 8, 3);

  play(NOTE_E6, -4, 3);
  play(NOTE_D6, 8, 3);
  play(NOTE_D6, 2, 3);

  play(NOTE_C6, 8, 3);
  play(NOTE_B5, 8, 3);
  play(NOTE_A5, 8, 3);
  play(NOTE_G5, 8, 3);
  play(NOTE_D6, 8, 3);
  play(NOTE_C6, 8, 3);
  play(NOTE_B5, 8, 3);
  play(NOTE_A5, 8, 3);

  play(NOTE_G5, 2, 3);
  play(REST, 8, 3);
  play(NOTE_G5, 8, 3);
  play(NOTE_A5, 8, 3);
  play(NOTE_B5, 8, 3);

  play(NOTE_C6, 2, 3);
  play(NOTE_D6, -4, 3);
  play(NOTE_C6, 8, 3);

  play(NOTE_B5, -2, 3);
  play(NOTE_G5, 8, 3);
  play(NOTE_A5, 8, 3);
  play(NOTE_B5, 8, 3);

  play(NOTE_C6, 4, 3);
  play(NOTE_C6, 4, 3);
  play(NOTE_D6, -4, 3);
  play(NOTE_C6, 16, 3);
  play(NOTE_D6, 16, 3);

  play(NOTE_B5, -2, 3);
  play(NOTE_B5, 8, 3);
  play(NOTE_A5, 8, 3);
  play(NOTE_G5, 8, 3);

  play(NOTE_A5, 2, 3);
  play(NOTE_E5, 4, 3);
  play(NOTE_B5, 4, 3);

  play(NOTE_A5, 2, 3);
  play(NOTE_G5, 4, 3);
  play(NOTE_E5, 4, 3);

  play(NOTE_FS5, 2, 3);
  play(NOTE_G5, 4, 3);
  play(NOTE_B5, 4, 3);

  play(NOTE_B5, -4, 3);
  play(NOTE_C6, 16, 3);
  play(NOTE_B5, 16, 3);
  play(NOTE_A5, 2, 3);
}

void loop() {
  int songChoice = getSongChoice();

  if (songChoice == 1) {
    playSong1();
  } 
  else if (songChoice == 2) {
    playSong2();
  } 
  else {
    playSong3();
  }
}