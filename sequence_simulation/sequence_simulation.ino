const int soundPin = 2; 
const int redLED = 8; 
const int blueLED = 9; 
const int greenLED = 10; 
unsigned long lastClapTime = 0; 
unsigned long clapWindow = 2000; // 2 seconds 
int clapCount = 0; 
void setup() { 
Serial.begin(9600); 
pinMode(soundPin, INPUT); 
pinMode(redLED, OUTPUT); 
pinMode(blueLED, OUTPUT); 
pinMode(greenLED, OUTPUT); 
Serial.println("Clap–Color Memory System Ready"); 
} 
void loop() { 
if (digitalRead(soundPin) == LOW) { 
clapCount++; 
lastClapTime = millis(); 
Serial.print("Clap detected. Count: "); 
Serial.println(clapCount); 
delay(200); // debounce 
} 
if (clapCount > 0 && millis() - lastClapTime > clapWindow) { 
showColor(clapCount); 
clapCount = 0; 
} 
} 
void showColor(int claps) { 
clearLEDs(); 
Serial.print("Final clap count: "); 
Serial.println(claps); 
switch (claps) { 
case 1: 
digitalWrite(redLED, HIGH); 
Serial.println("Color: RED"); 
break; 
case 2: 
digitalWrite(blueLED, HIGH); 
Serial.println("Color: BLUE"); 
break; 
case 3: 
digitalWrite(greenLED, HIGH); 
Serial.println("Color: GREEN"); 
break; 
default: 
Serial.println("No color mapped."); 
break; 
} 
delay(1500); 
clearLEDs(); 
} 
void clearLEDs() { 
digitalWrite(redLED, LOW); 
digitalWrite(blueLED, LOW); 
digitalWrite(greenLED, LOW); 
}
