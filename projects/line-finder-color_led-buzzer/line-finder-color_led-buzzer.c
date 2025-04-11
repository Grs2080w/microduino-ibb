// includes start
#include <Arduino.h>
#include <Microduino_ColorLED.h>

ColorLED strip_2 = ColorLED(16, 8);

void playUntil(int pin, int note, float duration);

void playUntil(int pin, int note, float duration) {
	tone(pin, note);
	if (duration > 0) {
		delay(duration * 1000);
		noTone(pin);
	}
}

void setup() {
  Serial.begin(9600);
  strip_2.begin();
}

void loop() {

    // This while is important because this is mode to buzzer works
    // without while, When buzzer stop working, it's out of the loop
    // and the buzzer will not work
	while(1) {
    Serial.println(analogRead(A6));

    if (analogRead(A6) < 1023) {
      strip_2.setPixelColor(0, 0xFF0000);
			strip_2.show();
      playUntil(A0, 1200, 0.5);
    } else {
      strip_2.setPixelColor(0, 0x000000);
		  strip_2.show();
    }
		delay(100);
	}
}
