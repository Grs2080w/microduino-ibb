import arduino
import time


while True:
    if arduino.digitalRead(6) == 0:
        arduino.digitalWrite(4, 1)
    else:
        arduino.digitalWrite(4, 0)
    time.sleep(0.1)
