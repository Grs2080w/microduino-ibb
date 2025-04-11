// includes start
#include <Arduino.h>
#include <Microduino_ColorLED.h>
// includes end

ColorLED strip_2 = ColorLED(16, 2);

void setup() {
	// setup define start
	strip_2.begin();
	// setup define end
  Serial.begin(9600);
}

void loop() {
    // See on serial monitor
    Serial.println(analogRead(A2));


		if((analogRead(A2)) < 400) {
			strip_2.setPixelColor(0, 0x131313);
			strip_2.show();
		} else {
			strip_2.setPixelColor(0, 0x000000);
			strip_2.show();
		}
	
}