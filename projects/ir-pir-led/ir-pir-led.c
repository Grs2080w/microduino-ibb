#define PIR_PIN 6
#define LED_PIN 8
void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);  
  pinMode(LED_PIN, OUTPUT);   
}

void loop() {
  if (digitalRead(PIR_PIN))  
  {
    Serial.println(digitalRead(PIR_PIN));
    digitalWrite(LED_PIN, HIGH);    
  }else{
    digitalWrite(LED_PIN, LOW); 
  }
}


/**
 * ir-pir-led.c
 * ============
 *
 * This code is supposed to get data from a PIR sensor and use it to control
 * an LED. If the PIR sensor detects motion, the LED should turn on. It should
 * turn off when the sensor no longer detects motion.
 *
 *
 */
