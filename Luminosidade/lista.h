#include <stdlib.h>
typedef float Dado;
class NohLista{
  
  friend class Lista;
  private:
    NohLista *proximo;
    Dado valor;
  public:
    NohLista(Dado v) {
      proximo =NULL;
      valor = v;
    }
};

class Lista{
  private:
    NohLista *primeiro;
    NohLista *ultimo;
    int Tam;
  public:
    Lista() {
      primeiro == NULL;
      Tam = 0;
    }
    ~Lista();
    void Insere(Dado v) {
      NohLista *novo = new NohLista(v);
      if (primeiro == NULL) {
        primeiro = novo;
        ultimo = novo;
        Tam++;
      }
      else {
        ultimo->proximo = novo;
        ultimo = novo;
        ultimo->proximo = NULL;
        Tam++; 
      }
    }

    void Imprime() {
      NohLista *aux = primeiro;
      Serial.println("Maior: ");
      Serial.println(aux->valor);
      aux = aux->proximo;
      Serial.println("Segundo Maior: ");
      Serial.println(aux->valor);
      aux = aux->proximo;
      Serial.println("Terceiro Maior: ");
      Serial.println(aux->valor);
      aux = aux->proximo;
      Serial.println("Quarto Maior: ");
      Serial.println(aux->valor);
    }
};
