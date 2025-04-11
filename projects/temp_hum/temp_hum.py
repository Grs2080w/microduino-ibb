import mcookie
import time

temp = 31.13
hum = 31.13

print("Temperature and Humidity Sensor STH2X")
print("----------------------------------------------")

while True:
    temp = mcookie.temperatureSTH2X()
    hum = mcookie.humiditySTH2X()
    
    
    print("Temperature: ", temp, " Humidity: ", hum)
    print("__________________________________________________")
    
    time.sleep(1)
