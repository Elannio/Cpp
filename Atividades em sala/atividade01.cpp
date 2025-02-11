#include <iostream>

using namespace std;

struct nolista{
  string nome;
  nolista* prox;
};

nolista* instanciar_lista(){
  return NULL;
}

void inserir_inicio(nolista* &l, string dado){
  nolista* novo = new nolista;
  novo->nome = dado;
  novo->prox = l;
  l = novo;
}

void inserir_fim(nolista* &l, string dado){
  nolista* novo = new nolista;
  novo->nome = dado;
  novo->prox = NULL;
  if(l == NULL){
    l = novo;
  } else {
    nolista *p = l;
    while(p->prox != NULL){
      p = p->prox;
    }
    p->prox = novo;
  }
}

void imprimir_lista(nolista*l){
  nolista*p = l;
  while(p != NULL){
    cout<<p->nome<<endl;
    p = p->prox;
  }
}

int tamanho(nolista* l){
  int cont = 0;
  nolista* p = l;
  while(p != NULL){
    cont++;
    p = p->prox;
  }
  return cont;
}

bool inserir_posicao(nolista*&l, string info, int pos){
  int tam = tamanho(l);
  if(pos > tam + 1)
    return false;
  else{
    nolista* novo = new nolista;
    novo->nome = info;
    if(pos==1){
      novo->prox = l;
      l = novo;
    }
    else if(pos == tam+1){
      novo->prox = NULL;
      nolista* p = l;
      while(p->prox != NULL)
        p = p->prox;
      p->prox = novo;
    }
    else{
      nolista* p = l;
      int pos_p = 1;
      while(pos_p != pos-1){
        p = p->prox;
        pos_p++;
      }
      novo->prox = p->prox;
      p->prox = novo;
    }
    return true;
  }
}

void inserir_ordemalfa(nolista*&l, string nome){
  nolista*p = l;
  nolista* novo = new nolista;
  novo -> nome = nome;

if(nome < l->nome){
  novo->prox=l;
  l=novo;
}

while((p->prox != NULL) && (novo->nome > p->prox->nome)){
p = p->prox;
}

novo -> prox = p -> prox;
p -> prox = novo;
  
}

int main() {
  nolista* lista1 = instanciar_lista();
  //nolista* lista2 = instanciar_lista();
  inserir_inicio(lista1,"Dayane");
  inserir_ordemalfa(lista1,"Wesley");
  inserir_ordemalfa(lista1,"Ricardo");
  inserir_ordemalfa(lista1,"Elannio");
  inserir_ordemalfa(lista1,"Tamara");
  inserir_ordemalfa(lista1,"Tiberio");
    cout<<endl;
  imprimir_lista(lista1);
}