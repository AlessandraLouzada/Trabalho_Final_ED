#include <stdlib.h>
#include "lista.h"
#include "arvore_binaria.h"
#define SensorLumi A0
#define ledVermelho 10
#define ledAmarelo 9
#define ledVerde 8

int Luminosidade;
ABB *minhaArvore = new ABB();
Lista *minhaLista=new Lista();
 
void setup()
{
  pinMode(SensorLumi, INPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}


void loop()
{
  //Le o valor do pino A0 do sensor
  Luminosidade = analogRead(SensorLumi);
  minhaArvore->InsercaoIterativa(Luminosidade);
  
  //Mostra o valor da porta analogica no serial monitor
  //Serial.print("Porta analogica: ");
  //Serial.print(Luminosidade);
 
  //Luminosidade Alta, acende o led verde
  if (Luminosidade > 100){
   
    apagaleds();
    digitalWrite(ledVerde, HIGH);
  }
 
  //Luminosidade moderada, acende led amarelo
  if (Luminosidade >= 50 && Luminosidade <= 100){
    apagaleds();
    digitalWrite(ledAmarelo, HIGH);
  }
  
  //Luminosidade Baixa, acende led vermelho
  if (Luminosidade < 50) {
    apagaleds();
    digitalWrite(ledVermelho, HIGH);
  }
  
  delay(360000);
  if (minhaArvore->QtdElementos == 10){
    int vLista=0;
    for(int i=0; i<4; i++) {
      vLista=minhaArvore->salvaLista();
      minhaLista->Insere(vLista);
    }
    minhaArvore->apaga();
    delay(3600000);
    
    
  }
}
 
void apagaleds(){
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVerde, LOW);
}
