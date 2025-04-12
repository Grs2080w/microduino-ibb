#include <IRremote.h>

int RECV_PIN = 6;             //Declare uma variável do tipo int com um valor de 6, que é o fundamento do nosso sensor infravermelho 6
IRrecv  irrecv(RECV_PIN);     //Definir objeto IRrecv para receber sinal infravermelho 
decode_results  results;       //Os resultados da decodificação são colocados nos resultados do objeto construídos por decode_results 

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();          // Iniciar decodificação infravermelha 
}

void loop() {
  if (irrecv.decode(&results)) {        //Receber e analisar
    Serial.println(results.value);  //Impressão e recebimento de instruções em formato de 16% 
    irrecv.resume();                // Redefinir o ponto de apoio para se preparar para a próxima aceitação
  }
}

// Button __ HEX-CODE __ CODE

// Button power - ED127F80 - 3977412480
// Button A - FE017F80 - 4261511040
// Button B - FD027F80 - 4244799360
// Button C- FC037F80 - 4228087680
// Button D - FB047F80 - 4211376000
// Button E - F9067F80 - 4177952640
// Button UP - FA057F80 - 4194664320
// Button DOWN - E41B7F80 - 3827007360
// Button LEFT - F8077F80 - 4161240960
// Button RIGHT - F6097F80 - 4127817600
// Button MORE_VOLUME - E01F7F80 - 3760160640
// Button LESS-VOLUME - F10E7F80 - 4044259200
// Button MUTE - F20D7F80 - 4060970880
// Button PLAY_PAUSE - F30C7F80 - 4077682560