import arduino
import mcookie


while True:
    if (arduino.analogRead(2) < 400):
        mcookie.colorLEDColor(2, 0, '#000000')
    else:
        mcookie.colorLEDColor(2, 0, '#ffffff')
