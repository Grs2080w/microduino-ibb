#include <Servo.h>

/*

In this example is used a servo motor to move from 0 to 180 degrees and back to 0 degrees.
The servo motor is connected to pin 6 and the initial position is set to 0 degrees.
The servo motor is moved to 180 degrees and then back to 0 degrees.

Materials ___________
- Microduino Itty Bitty Buggy
- servo motor


Guide _____________
- Connect the servo motor to pin 6/7
- Upload the code to the Microduino Itty Bitty Buggy
- See the servo motor moving from 0 to 180 degrees and back to 0 degrees

*/

Servo myservo; 

#define servoPin  6
int pos = 0;   
int pos_final = 90;

void setup()
{
  myservo.attach(servoPin); 
}

void loop()
{
  myservo.write(0);
  delay(1000);

  // go to 180 position
  for (pos = 0; pos < pos_final; pos += 1) 
  {
    myservo.write(pos);             
  }

  // delay is for the servo to reach the position, else it's not accurate
  delay(1000);

  // return to 0 position
  for (pos = pos_final; pos != 0; pos -= 1) 
  {
    myservo.write(pos);              
  }

}