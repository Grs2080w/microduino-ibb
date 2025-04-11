#include <Servo.h>
#include <Arduino.h>
#include <Microduino_ColorLED.h>

Servo myservo;

#define servoPin 6
int pos = 0;
int target_pos = 90;
int last_pos = -1;

bool previousState = false;

ColorLED strip_2 = ColorLED(16, 8);

void playUntil(int pin, int note, float duration) {
  tone(pin, note);
  if (duration > 0) {
    delay(duration * 1000);
    noTone(pin);
  }
}

void setup() {
  myservo.attach(servoPin);
  strip_2.begin();
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(A6);
  bool sensorDetected = reading < 1023;

  Serial.print("Sensor: ");
  Serial.print(reading);
  Serial.print(" | Detected: ");
  Serial.println(sensorDetected ? "Yes" : "No");

  if (sensorDetected != previousState) {
    //
    // If the sensor change state!!!
    //

    previousState = sensorDetected;

    if (sensorDetected) {
      //
      // If there is someone in front of the sensor
      //

      // Led to green
      strip_2.setPixelColor(0, 0x00FF00);
      strip_2.show();

      // play buzzle
      playUntil(A0, 1200, 0.5);

      // rotate servo to 0 degress (servo begins in 90 degress position)
      for (pos = target_pos; pos >= 0; pos--) {
        if (pos != last_pos) {
          myservo.write(pos);
          last_pos = pos;
          delay(10);
        }
      }

    } else {

      //
      // If there is not someone in front of the sensor
      //

      delay(5000);

      // led to red
      strip_2.setPixelColor(0, 0xFF0000);
      strip_2.show();

      // rotate servo to 90 degress (initial position)
      for (pos = 0; pos <= target_pos; pos++) {
        if (pos != last_pos) {
          myservo.write(pos);
          last_pos = pos;
          delay(10);
        }
      }

      // led turn of
      strip_2.setPixelColor(0, 0x000000);
      strip_2.show();
    }
  }

  delay(100);
}
