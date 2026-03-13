# Arduino Nano “iPod”


## Overview
This project is a simple **Arduino Nano music player** inspired by an iPod. A **potentiometer (knob)** controls which song is played depending on how far it is twisted. As the knob rotates, the Arduino reads the analog value and selects a different melody.

The device includes a **speaker for audio output**, an **LED that synchronizes with the notes being played**, and basic wiring connecting the components to the Arduino Nano. The project is written in **C++ using the Arduino framework**.

## Features
- 🎵 **Song selection with a potentiometer**
- 🔊 **Speaker output for playing melodies**
- 💡 **LED that blinks in sync with notes**
- ⚡ **Runs on an Arduino Nano**
- 🧠 **Written in C++ (Arduino environment)**

## Components
- Arduino Nano  
- Potentiometer  
- Speaker / Piezo buzzer  
- LED  
- Resistors (for LED)  
- Breadboard  
- Jumper wires  

## How It Works
1. The **potentiometer** is connected to an analog input pin on the Arduino.
2. The Arduino reads the **analog value (0–1023)** from the potentiometer.
3. The range is divided into sections that correspond to different songs.
4. When a song plays:
   - The **speaker outputs the melody notes**
   - The **LED blinks in sync with the note timing**
5. Currently I have only put three songs (Green Hill Zone, Pallet Town, Tetris Theme); however, feel free to change these songs into anything that you would like!
