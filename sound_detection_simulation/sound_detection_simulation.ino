#define RED_LED 8
#define BLUE_LED 9
#define GREEN_LED 10

int inputValue = 0;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  Serial.begin(9600);
  Serial.println("Type 1 (Red), 2 (Blue), or 3 (Green):");
}

void loop() {
  if (Serial.available() > 0) {
    inputValue = Serial.parseInt();

    // Turn everything OFF first
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);

    if (inputValue == 1) {
      digitalWrite(RED_LED, HIGH);
      Serial.println("RED LED ON");
    }
    else if (inputValue == 2) {
      digitalWrite(BLUE_LED, HIGH);
      Serial.println("BLUE LED ON");
    }
    else if (inputValue == 3) {
      digitalWrite(GREEN_LED, HIGH);
      Serial.println("GREEN LED ON");
    }
    else {
      Serial.println("Invalid input. Enter 1, 2, or 3.");
    }
  }
