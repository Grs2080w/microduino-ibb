#include <Microduino_Tem_Hum.h>
Tem_Hum_S2  termo;
void setup()
{
  Serial.begin(9600);
  Serial.print("Tem_Hum_S2:");
  Serial.print(termo.begin());  
  delay(1000);
}
void loop()
{
  Serial.print("Tem_Hum_S2 Tem:");
  Serial.print(termo.getTemperature()); 
  Serial.print("\t");
  Serial.print("Tem_Hum_S2 Hum:");
  Serial.println(termo.getHumidity()); 
  Serial.println("------------------");
  delay(1000);
  Serial.print("onLine:");
  Serial.println(termo.begin()); 
}