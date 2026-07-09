const int greenLED = 8;
const int blueLED = 9;
const int redLED = 10;
const int buzzer = 7;

int mode = 0;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  Serial.println("Type 1 (Green), 2 (Red), or 3 (Blue):");
}

// Function to pulse buzzer
void buzz(int times) {
  for (int i = 0; i < times; i++) {
    tone(buzzer, 1000);
    delay(300);

    noTone(buzzer);
    delay(300);
  }
}

void loop() {
  if (Serial.available() > 0) {
    mode = Serial.parseInt();

    // Turn everything off first
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);
    noTone(buzzer);

    if (mode == 1) {
      // GREEN → 2 pulses
      Serial.println("Green selected");
      digitalWrite(greenLED, HIGH);
      buzz(2);
    }
    else if (mode == 2) {
      // RED → 3 pulses
      Serial.println("Red selected");
      digitalWrite(redLED, HIGH);
      buzz(3);
    }
    else if (mode == 3) {
      // BLUE → 1 pulse
      Serial.println("Blue selected");
      digitalWrite(blueLED, HIGH);
      buzz(1);
    }
    else {
      Serial.println("Invalid input. Type 1, 2, or 3.");
    }

    // Turn LEDs off after action
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED, LOW);
    digitalWrite(blueLED, LOW);

    Serial.println("Enter next mode:");
  }
}
