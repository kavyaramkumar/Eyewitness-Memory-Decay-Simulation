# Eyewitness Memory Decay Simulation

Arduino-based project for BE 1200 (Arduino Microcontrollers) testing how accurately people recall details after being shown a short physical/sensory stimulus, modeling eyewitness memory decay.

**Team:** Lamisa Ahmed, Kavya Ramkumar, Ameera Farooqui

## Overview

Memory decay is the weakening of memory traces over time, especially when a memory isn't accessed. For eyewitnesses this means details fade or distort, increasing the risk of false memories and misidentification. This project uses 3 separate Arduino builds to test recall accuracy right after a stimulus is presented.

Note: these are physical hardware simulations, not just code. Each folder below contains the Arduino sketch (`.ino` file) that ran on the physical build. Photos of the actual breadboard setups are in `/images`.

## Simulations

### 1. Sequence Simulation (`/sequence_simulation`)
Tests recall of a sequence of visual stimuli (LED lights).

**Hardware used:**
- Arduino Uno R3
- Breadboard
- Jumper wires
- 6 resistors
- 3 LED lights (red, blue, green)
- 3 buttons

**What it does:** Runs a sequence of LED lights in a set order and timing, then asks the participant to recall the full sequence, how many times each color lit up, and the time interval between lights.

**Results:** Full sequence recall 12.5%, color count accuracy 25%, time interval accuracy 50%.

### 2. Race Car Simulation (`/race_car_simulation`)
Tests recall under a fast, real-world-style event (a moving object plus sound).

**Hardware used:**
- Arduino Uno R3
- Breadboard
- Jumper wires
- 3 resistors
- 3 LED lights (red, blue, green)
- Piezo buzzer
- Hot Wheels car
- Hot Wheels track

**What it does:** A car is pushed down the track toward the breadboard 3 times. Each run triggers a different LED color plus a buzzer sound (1, 2, or 3 beeps). Participant recalls buzzer counts, LED colors per run, and the number on the car.

**Results:** Color sequence accuracy 50%, buzzer count sequence 62.6%, number-on-car recall 25%.

### 3. Sound Detection Simulation (`/sound_detection_simulation`)
Tests recall triggered by an auditory cue (claps) rather than a purely visual one.

**Hardware used:**
- Arduino Uno R3
- Breadboard
- Jumper wires
- 3 resistors
- 3 LED lights (red, blue, green)
- Sound sensor module

**What it does:** Detects claps and lights an LED based on clap count (1 clap = red, 2 = blue, 3 = green). Participant recalls the color mapping, a shape drawn on their hand during the task, and an unrelated fact mentioned beforehand.

**Results:** Color sequence recall 100%, shape-on-hand recall 75%, unrelated fact recall 50%.

## Key takeaway

Recall accuracy varied a lot by stimulus type and complexity, supporting the idea that eyewitness memory is unreliable even minutes after an event, with accuracy dropping further as the number of details or the delay increases. This has real implications for how eyewitness testimony is weighted in legal settings.

## Repo structure

