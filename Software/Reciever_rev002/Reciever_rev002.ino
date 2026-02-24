#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define relayPin 4
#define LEDPin 5

int buttonState = 0;
//int leaksensorState = 0;

RF24 radio(6,7); // CE, CSN
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);
  pinMode(LEDPin, OUTPUT);
  digitalWrite(relayPin, HIGH);
  digitalWrite(LEDPin, HIGH);
  delay(2000);
  digitalWrite(LEDPin, LOW);
 // digitalWrite(relayPin, LOW);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);  
}

void loop() {
  radio.startListening();
  while (!radio.available());
  radio.read(&buttonState, sizeof(buttonState));
//  radio.read(&buttonState, sizeof(leaksensorState));

    digitalWrite(relayPin, LOW);
  
  if (buttonState == HIGH) {

 //   digitalWrite(LEDPin, LOW);
    delay(500);
    digitalWrite(relayPin, LOW);
 //   digitalWrite(relayPin, LOW);
    digitalWrite(LEDPin, buttonState);
    delay(500);
    Serial.println(buttonState);
  }
  else {
//    digitalWrite(relayPin,HIGH);
    digitalWrite(LEDPin, buttonState);
    delay(500);
    digitalWrite(relayPin, HIGH);
    delay(5000);
    delay(5000);
    delay(5000);
    Serial.println(buttonState);
    }
}
