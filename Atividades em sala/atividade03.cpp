/*O projeto consiste em criar uma lista encadeada de funcionários contendo nome e matrícula como dados. Considerando a possibilidade de que a lista contenha uma quantidade muito grande de elementos, a realização de pesquisas sequenciais pode ter desempenho abaixo do aceitável. Dessa forma, árvores binárias de pesquisa serão utilizadas como índices em operações de busca.
Devem ser criadas duas árvores de pesquisa: uma organizada por nome, outra por matrícula. As árvores não devem conter informações, e sim uma referência para a posição da lista que representam. O seguinte menu de opções deve ser oferecido ao usuário:


1 - Inserir elemento no fim da lista;
2 - Buscar elemento na lista por matrícula;
3 - Buscar elemento na lista por nome;
4 - Imprimir todos os elementos por ordem de matrícula;
5 - Imprimir todos os elementos por ordem de nome;
6 - Balancear árvores;
0 - Sair

Resposta:

#include <iostream>

using namespace std;

struct nolistad{
  string nome;
  int matricula;
  nolistad *prox;
};

struct noArvore{
  nolistad *item;
  noArvore *esq,*dir;
};

struct descritor{
  int tamanho;
  nolistad *inicio,*fim;
};

void inicializar(descritor *&lista){
  lista= new descritor;
  lista->tamanho=0;
  lista->inicio=NULL;
  lista->fim=NULL;
}

noArvore* inicializarArvore(){
  return NULL;
}

void raizMatricula(noArvore*&raiz,nolistad *no){
  if(raiz==NULL){
    raiz=new noArvore;
    raiz->item=no;
    raiz->esq=NULL;
    raiz->dir=NULL;
  }
  else{
    if(no->matricula<raiz->item->matricula)
      raizMatricula(raiz->esq,no);
    if (no->matricula>raiz->item->matricula)
      raizMatricula(raiz->dir,no);
  }
}

void raizNome(noArvore*&raiz,nolistad *no){
  if(raiz==NULL){
    raiz=new noArvore;
    raiz->item=no;
    raiz->esq=NULL;
    raiz->dir=NULL;
  }
  else{
    if(no->nome<raiz->item->nome)
      raizNome(raiz->esq,no);
    if (no->nome>raiz->item->nome)
      raizNome(raiz->dir,no);
  }
}

void inserirElemento(descritor lista, noArvore *&arvoreMatricula,noArvore& arvoreNome,string nome, int matricula){
  nolistad *novo=new nolistad;
  novo->nome=nome;
  novo->matricula=matricula;
  novo->prox=NULL;
  if(lista->inicio==NULL){
    lista->inicio=novo;
    lista->fim=novo;
  }
  else{
    lista->fim->prox=novo;
    lista->fim=novo;
  }
  lista->tamanho++;
  raizMatricula(arvoreMatricula,novo);
  raizNome(arvoreNome,novo);
}

nolistad* buscarMatricula(noArvore *raiz, int matricula){
  if(raiz!=NULL && matricula<raiz->item->matricula)
    return buscarMatricula(raiz->esq,matricula);
  else if (raiz!=NULL && matricula>raiz->item->matricula)
    return buscarMatricula(raiz->dir,matricula);
  else if(raiz!= NULL && matricula==raiz->item->matricula)
    return raiz->item;
  else
    return NULL;
}

nolistad* buscarNome(noArvore *raiz, string nome){
  if(raiz!=NULL && nome<raiz->item->nome)
    return buscarNome(raiz->esq,nome);
  else if (raiz!=NULL && nome>raiz->item->nome)
    return buscarNome(raiz->dir,nome);
  else if(raiz!= NULL && nome==raiz->item->nome)
    return raiz->item;
  else
    return NULL;
}

void imprimirMatricula(noArvore* raiz){
  if(raiz!=NULL){
    imprimirMatricula(raiz->esq);
    cout<<raiz->item->matricula<<" "<<raiz->item->nome<<endl;
    imprimirMatricula(raiz->dir);
  }
}

void imprimirNome(noArvore* raiz){
  if(raiz!=NULL){
    imprimirNome(raiz->esq);
    cout<<raiz->item->nome<<" "<<raiz->item->matricula<<endl;
    imprimirNome(raiz->dir);
  }
}

void gerar_vetor(noArvore raiz, nolistad* vet, int &i){
  if(raiz != NULL){
    gerar_vetor(raiz->esq,vet,i);
    vet[i] = raiz->item;
    i++;
    gerar_vetor(raiz->dir,vet,i);
  }
}

void destruir(noArvore *&raiz){
  if(raiz != NULL){
    destruir(raiz->esq);
    destruir(raiz->dir);
    delete raiz;
    raiz = NULL;
  }
}

void gerar_arvore(noArvore &raiz, nolistad* vet, int ini, int fim){
  if(fim < ini)
    raiz = NULL;
  else{
    int meio = (ini+fim)/2;
    raiz = new noArvore;
    raiz->item = vet[meio];
    gerar_arvore(raiz->esq, vet, ini, meio-1);
    gerar_arvore(raiz->dir, vet, meio+1, fim);
  }
}

int altura(noArvore* raiz){
  if(raiz == NULL)
    return -1;
  else{
    int altE = altura(raiz->esq);
    int altD = altura(raiz->dir);
    if(altE > altD)
      return altE + 1;
    else
      return altD + 1;
  }
}

bool balanceada(noArvore *raiz){
  if(raiz == NULL)
    return true;
  else{
    if(abs(altura(raiz->esq) - altura(raiz->dir)) > 1)
      return false;
    else
      return balanceada(raiz->esq) && balanceada(raiz->dir) ; 
  }
}

int tamanho(noArvore* raiz){
  if(raiz == NULL)
    return 0;
  else
    return tamanho(raiz->esq) + tamanho(raiz->dir) + 1;
}

void balanceamento_estatico(noArvore *&raiz){
  if(!balanceada(raiz)){
    int tam = tamanho(raiz);
    nolistad *vet = new nolistad[tam];
    int indice = 0;
    gerar_vetor(raiz, vet, indice);
    destruir(raiz);
    gerar_arvore(raiz, vet, 0, tam-1);
    delete [] vet;
  }
  }

int main() {
  descritor *lista;
  inicializar(lista);
  noArvore *raizNome,*raizMatricula;
  raizNome=inicializarArvore();
  raizMatricula=inicializarArvore();
  int menu=99;
  while (menu!=0){
    cout<<"1 - Inserir elemento no fim da lista; \n2 - Buscar elemento na lista por matrícula; \n3 - Buscar elemento na lista por nome; \n4 - Imprimir todos os elementos por ordem de matrícula; \n5 - Imprimir todos os elementos por ordem de nome; \n6 - Balancear árvores; \n0 - Sair: ";
    cin>>menu;
    switch(menu){
      case 1:{
      int matricula;
      string nome;
      cout<<"Nome do funcionario: ";cin>>nome;
      cout<<"Numero de matricula: ";cin>>matricula;
      inserirElemento(lista,raizMatricula,raizNome,nome,matricula);
      }
      break;
      case 2:{
        int matricula;
        cout<<"Numero de matricula: ";cin>>matricula;
        nolistad *p=buscarMatricula(raizMatricula,matricula);
        if (p!=NULL)
        cout<<p->matricula<<" "<<p->nome<<endl;
        else
          cout<<"Não Existe!"<<endl;
      }
      break;
      case 3:{
        string nome;
        cout<<"Nome: ";cin>>nome;
        nolistad *p=buscarNome(raizNome,nome);
        if (p!=NULL)
        cout<<p->nome<<" "<<p->matricula<<endl;
        else
          cout<<"Não Existe!"<<endl;
      }
      break;
      case 4:
        imprimirMatricula(raizMatricula);
      break;
      case 5:
        imprimirNome(raizNome);
      break;
      case 6:
        balanceamento_estatico(raizMatricula);
        balanceamento_estatico(raizNome);
        cout<<"Arvores Balanceadas!"<<endl;
      break;
      case 0:
        cout<<"sair";
      break;
      default:
        cout<<"inválido!"<<endl;
      break;
    }
  }
}

*/