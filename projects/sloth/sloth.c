// includes start
#include <Arduino.h>
#include <BittyBuggy.h>
BittyBuggy Buggy(&Serial1);
// includes end
// definition start
void BuggyToneTime(int _fre, float _time);
void trackStop();

unsigned long tempoInicial = 0;
unsigned long tempoAtual = 0;
int direction = 0; // 0 para frente e 1 para tras


//
//
//
//
//
//
//
//
//
//
//  Mude aqui para definir o intervalo de mudança de direção
//  ** Siga as regras abaixo **
//
//
//
unsigned long intervalo = 180000; // 180 segundos (180 * 1000 milissegundos)
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//


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
void trackStop() {
	Buggy.setAllLED(0X000000);
	Buggy.setSpeed(0, 0);
}

void setup() {
	// setup define start
	while(!Buggy.begin());
  tempoInicial = millis();
	// setup define end
}

void loop() {
	BuggyToneTime(262, 1);
	delay(3 * 1000);
	BuggyToneTime(1760, 1);
	delay(3 * 1000);
	while(1) {
    
    tempoAtual = millis();

    // Define direção e LED correspondente
    if (direction == 0) {
      // Trás
      Buggy.setColorLEDA(0x00ff2e);
      Buggy.setColorLEDB(0x00ff2e);
      Buggy.setSpeed(-170, -170);
    } else {
      // Frente
      Buggy.setColorLEDA(0xff0000);
      Buggy.setColorLEDB(0xff0000);
      Buggy.setSpeed(170, 170);
    }

    // Verifica se já passou 60s
    if (tempoAtual - tempoInicial >= intervalo) {
      Serial.println("Mudando direção...");
      tempoInicial = tempoAtual;

      // Alterna direção
      direction = !direction;

      // Dá uma pausa rápida pra marcar a transição (opcional)
      trackStop();
      delay(500);

      BuggyToneTime(1760, 1);
    }


	}
}