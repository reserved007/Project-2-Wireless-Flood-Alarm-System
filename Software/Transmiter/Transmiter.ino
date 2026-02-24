#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define buttonPin 5
#define powerLED 3
int buttonState = 0;
//int leaksensorState = 0;

RF24 radio(7,8 ); // CE, CSN
const byte address[6] = "00001";
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(powerLED, OUTPUT);
  Serial.begin(9600);
  digitalWrite(powerLED, HIGH);
  delay(2000);
  digitalWrite(powerLED, LOW);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
void loop() {
  buttonState = digitalRead(buttonPin);
//  leaksensorState = digitalRead(leaksensor);
  Serial.println(buttonState);
//  Serial.print("leaksensorState:");
//  Serial.println(leaksensorState,DEC);
  digitalWrite(powerLED,buttonState);
  radio.write(&buttonState, sizeof(buttonState));
//  radio.write(&buttonState, sizeof(leaksensorState));
  delay(1000);
}
