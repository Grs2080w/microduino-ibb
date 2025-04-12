// includes start
#include <Arduino.h>
#include <BittyBuggy.h>
BittyBuggy Buggy(&Serial1);
#include <IRremote.h>
// includes end

int RECV_PIN = 6;             //Declare uma variável do tipo int com um valor de 6, que é o fundamento do nosso sensor infravermelho 6
IRrecv  irrecv(RECV_PIN);     //Definir objeto IRrecv para receber sinal infravermelho 
decode_results  results;    //Os resultados da decodificação são colocados nos resultados do objeto construídos por decode_results 

void trackStop();

void trackStop() {
	Buggy.setAllLED(0X000000);
	Buggy.setSpeed(0, 0);
}    

void BuggyToneTime(int _fre, float _time);
// definition end

void BuggyToneTime(int _fre, float _time) {
	if (_time > 0) {
		Buggy.tone(_fre);
		delay(_time * 1000);
		Buggy.noTone();
	} else {
		Buggy.noTone();
	}
	return false;
}


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();       // Iniciar decodificação infravermelha 
  while(!Buggy.begin());
}

int down_before = 0;

void loop() {
  if (irrecv.decode(&results)) {   //Receber e analisar
    Serial.println(results.value); //Impressão e recebimento de instruções em formato de 16% 

    if(results.value == 33464415){
      down_before = 0;
		  Buggy.setSpeed(255, 255);
    }
    if(results.value == 33478695) {
      down_before = 1;
      Buggy.setSpeed(-150, -150);
    }
    if(results.value == 33460335) {
      if (down_before == 1) {
        Buggy.setSpeedA(150);
      } else {
        Buggy.setSpeedB(0);
        Buggy.setSpeedA(150);
      }
    }
    if(results.value == 33480735) {
        if (down_before == 1) {
        Buggy.setSpeedB(150);
      } else {
        Buggy.setSpeedA(0);
        Buggy.setSpeedB(150);
      }
    } 
    if(results.value == 33468495) {
      down_before = 1;
      trackStop();
    } 
    if(results.value == 33486855) {
      BuggyToneTime(262, 0.1);
    } 

    irrecv.resume();      // Redefinir o ponto de apoio para se preparar para a próxima aceitação
  }
}