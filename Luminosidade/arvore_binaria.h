#include <stdlib.h>

class Noh {
      friend class ABB;
  public:
      Noh(int _valor) {
        valor = _valor;
        pai = NULL;
        esquerda = NULL;
        direita = NULL;
      }

      ~Noh() {
        delete direita;
        delete esquerda;
      }
  private:
      int valor;
      Noh* pai;
      Noh* esquerda;
      Noh* direita;
  };

  
  class ABB {
  public:
    int QtdElementos;
      ABB() {
        QtdElementos=0;
         raiz = NULL;
      }
      ~ABB() {
         delete raiz;
      }
      void InsercaoIterativa(int _valor) {
        Noh* novoNoh = new Noh(_valor);
      
        if (raiz == NULL) {
          raiz = novoNoh;
        } 
        else {
          Noh* percorredor = raiz;
          bool inserido = false;
          while (inserido == false) {
            if (_valor < percorredor->valor) {
              if (percorredor->esquerda == NULL) {
                percorredor->esquerda = novoNoh;
                inserido = true;
              }
              else {
                percorredor = percorredor->esquerda;
              }
            } 
            else {
              if (percorredor->direita == NULL) {
                percorredor->direita = novoNoh;
                inserido = true;
              } 
              else {
                percorredor = percorredor->direita;
              }
            }
          } //fim do while
          novoNoh->pai = percorredor;
        }
        QtdElementos++;
      }
      
      int EspiaARaiz() {
        if (raiz != NULL) {
          return raiz->valor;
        }
        return -1;
      }

      bool Busca(int _valor) {
        if (NohBuscado(_valor) == NULL) {
          return false;
        }
        return true;
      }
      
      int Remocao(int _valor) {
        Noh* nohADeletar = NohBuscado(_valor);
  
        if (nohADeletar == NULL) {
          return -1;
        } 
        else {
          int dadoRemovido = nohADeletar->valor;
          Noh* aSerOrganizado = NULL;
          
          if (nohADeletar->esquerda == NULL) {
            aSerOrganizado = nohADeletar->direita;
            Transplanta(nohADeletar, nohADeletar->direita);
          }
          else if (nohADeletar->direita == NULL) {
            aSerOrganizado = nohADeletar->esquerda;
            Transplanta(nohADeletar, nohADeletar->esquerda);
          }
          else { // noh tem dois filhos
            Noh* sucessor = GetSucessor(nohADeletar);
            aSerOrganizado = sucessor;
            
            if (sucessor->pai != nohADeletar) {
              Transplanta(sucessor, sucessor->direita);
              sucessor->direita = nohADeletar->direita;
              nohADeletar->direita->pai = sucessor;
            }
            Transplanta(nohADeletar, sucessor);
            sucessor->esquerda = nohADeletar->esquerda;
            nohADeletar->esquerda->pai = sucessor;
          }
          nohADeletar->esquerda = NULL;
          nohADeletar->direita = NULL;
          delete nohADeletar;
          QtdElementos--;
          return dadoRemovido;
        }
      }
      void apaga() {
        while(raiz!=NULL){
          Remocao(raiz->valor);
        }
      }
      int salvaLista(){
        Noh* aux=raiz;
        int retorno=0;
        while(aux->direita!=NULL){
          aux=aux->direita;
          
        }
       retorno=aux->valor;
       Remocao(aux->valor);
       return retorno;
      }
    
  private:
      void Transplanta(Noh* _noh1, Noh* _noh2) {
        if (_noh1 == raiz) {
          raiz = _noh2;
        } 
        else if (_noh1->pai->esquerda == _noh1) {
          _noh1->pai->esquerda = _noh2;
        } 
        else {
          _noh1->pai->direita = _noh2;
        }
        if (_noh2 != NULL) {
          _noh2->pai = _noh1->pai;
        }
      }
          
      Noh* NohBuscado(int _valor) {
        Noh* percorredor = raiz;
        while (percorredor != NULL) {
          if (percorredor->valor == _valor) {
            return percorredor;
          }
          else if (_valor < percorredor->valor) {
            percorredor = percorredor->esquerda;
          }
          else {
            percorredor = percorredor->direita;
          }
        }
        return NULL;
      }
      Noh* GetSucessor(Noh* _pai) {
        if (_pai->direita == NULL){
          return NULL;
        } 
        else {
          Noh* percorre = _pai->direita;
            while (percorre->esquerda != NULL){
              percorre = percorre->esquerda;
            }
            return percorre;
        }
      }
      Noh* raiz;
  };
  
