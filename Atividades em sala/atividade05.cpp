/*#include <iostream>

using namespace std;

void modifica(int *&vetor,int tamanho, int pos){
  int vet[tamanho-1];
  int verifica=0;
  for (int i=0;i<tamanho-1;i++){
    if (i==pos){
      i++;
      verifica=1;
    }
      if(verifica==1){}
        vet[i-1]=vetor[i];
    else{
      vet[i]=vetor[i];
    }
    vetor=vet;
    
  }
}

int main(){
  int vetor[5]={1,2,3,4,5};
  for (int i=0;i<5;i++){
    cout<<vetor[i]<<endl;
  }
}

incompleta, porém tentei.

2 - Resposta:

A estrutura mais correta para armazenar os pontos de referência é a lista duplamente encadeada, que consiste em um conjunto de registros sequencialmente encadeados ou simplesmente encadeados, com cada nó contendo 2 campos, com um anterior e um posterior para ligar duplamente uma lista. Para o aplicativo a lista vai registrar o caminho percorrido de um ponto a outro em pontos de referência. Para indicar o caminho de volta ele vai ta armazenado na lista duplamente encadeada, decorando os caminhos e passando pelos mesmos pontos. Vai basicamente registrar os pontos da cidade em um ponto e no outro.

3 - Resposta:

#include <iostream>
using namespace std;

struct noLista{
  int dado;
  noLista *prox;
};

int contarElemento(noLista *l, int elemento){
  int quantidadeOcorrencias=0;
  noLista *p=l;
  while(p!=NULL){
    if(p->dado==elemento)
      quantidadeOcorrencias++;
    p=p->prox;
  }
  return quantidadeOcorrencias;
}

void excluirDado(noLista *&l,int dado){
  noLista *p=l;
  noLista *ant=p;
  
  if(l==NULL){
    cout<<"Lista Vazia"<<endl;
    return;
    }
  if(p->dado==dado){
    l=p->prox;
    delete p;
    return;
  }
  while (p->prox!=NULL && p->dado!=dado){
    ant=p;
    p=p->prox;
  }
  if(p->dado==dado){
    ant->prox=p->prox;
    delete p;
  }
}

void novoElemento(noLista *&lista,int dado){
  noLista *novo=new noLista;
  novo->dado=dado;
  if (lista==NULL){
    lista=novo;
    lista->prox=NULL;
  }else{
    noLista *p=lista;
    while (p->prox!=NULL)
      p=p->prox;
    p->prox=novo;
    novo->prox=NULL;
  }
}

void eliminarElemento(noLista *&l,int elemento){
  int quantidadeOcorrencias=contarElemento(l,elemento);
  for (int i=0;i<quantidadeOcorrencias;i++){
    excluirDado(l,elemento);
  }
}

void imprimir(noLista *lista){
  noLista *p=lista;
  while (p!=NULL){
    cout<<p->dado<<endl;
    p=p->prox;
  }
}

int main(){
  noLista *l = NULL;
  novoElemento(l,1);
  novoElemento(l,5);
  novoElemento(l,9);
  novoElemento(l,2);
  novoElemento(l,5);
  novoElemento(l,8);
  imprimir(l);
  eliminarElemento(l,1);
  eliminarElemento(l,5);
  cout<<"Lista alterada"<<endl;
  imprimir(l);
}


4 - Resposta:

Pré Ordem: Pega primeiro os elementos da esquerda e depois os da direita.

Começa pela raíz + ; 
Vai para esquerda - ; 
Vai para esquerda * ; 
Vai para esquerda e pega o 1 ;
Sem elementos na esquerda volta para o * e pega o 2 ;
Sem esquerda nem direita volta para o - e pega a / ;
Vai para a esquerda e pega o 3 ;
Volta para a / e pega o 4 ; 
Sem esquerda nem direita volta para a Raíz e pega o * da direita ;
Pega o 5 da esquerda e Por último o 6.

Resultado: + ; - ; * ; 1 ; 2 ; / ; 3 ; 4 ; * ; 5 ; 6.

Ordem Central: Pega os elementos da árvore e coloca em Ordem do menor ao maior, Pegando os últimos elementos da direita e depois a esquerda.

Vai percorrer a direita até encontrar o último elemento que é o 1;
Em seguida volta para o * e imprime;
Vai para a esquerda do * e pega o 2 que não tem nada depois e imprime;
Volta para o /, sobe e imprime o -;
Desce e procura o último a esquerda e pega o 3;
Volta e pega a / acima dele;
Em seguida o 4 a direita dele;
Volta e pega a Raíz +;
Em seguida começa a parte direita, pega o 5 que ta a esquerda do *;
Volta pega o *;
E o último da Ordem será o 6.

Resultado: 1 ; * ; 2 ; - ; 3 ; / ; 4 ; + ; 5 ; * ; 6

Pós Ordem: Visita os elementos da esquerda, em seguida os da direita e por último a raíz.

Percorre a árvore para encontrar o último elemento da árvore a esquerda e imprime o 1;
Logo após volta e pega o 2 da raíz * que é da direita dela;
E então volta e pega o * ;
Sem elementos da direita e esquerda volta para o - depois vai para a direita dele e procura o último elemento da esquerda, pega o 3 e imprime;
Volta para a raíz / e pega o 4 da direita e imprime;
Pega a raíz dele / e imprime, volta para o - e imprime já que foram todos a sua direita e esquerda;
Volta para a raíz + e pega os da direita, procura o último da esquerda 5 e imprime, logo após o 6 da direita;
Depois pega o * e imprime e por último o +.

Resultado: 1 ; 2 ; * ; 3 ; 4 ; / ; - ; 5 ; 6 ; * ; +
*/