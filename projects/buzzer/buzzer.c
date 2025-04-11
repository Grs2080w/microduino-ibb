// includes start
#include <Arduino.h>
// includes end
// definition start
void playUntil(int pin, int note, float duration);
// definition end

void playUntil(int pin, int note, float duration) {
	tone(pin, note);
	if (duration > 0) {
		delay(duration * 1000);
		noTone(pin);
	}
}

void setup() {}

void loop() {
	while(1) {
		playUntil(2, 440, 0.5);
	}
}