/*#include <iostream>
#include <fstream>

using namespace std;

struct noArvore{
  string dado;
  noArvore *pai, *esq, *dir;
};

noArvore* inicializar(){
  return NULL;
}



void ABBImprimirChaves(noArvore* raiz){
  if(raiz!=NULL){
    ABBImprimirChaves(raiz->esq);
    cout<<endl<<raiz->dado<<endl;
    ABBImprimirChaves(raiz->dir);
  }
}
void ABBInserir(noArvore*&raiz, string info, noArvore* pai){
  if(raiz == NULL){
    raiz = new noArvore;
    raiz->dado = info;
    raiz->esq = NULL;
    raiz->dir = NULL;
    raiz->pai=pai;
  }
  else if(info < raiz->dado)
    ABBInserir(raiz->esq,info,raiz);
  else if(info > raiz->dado)
    ABBInserir(raiz->dir,info,raiz);
  else{
    cout<<info<<" já existe na árvore."<<endl;
  }
}

noArvore* ABBBuscar(noArvore* raiz,string info){
  if(raiz == NULL || raiz->dado == info)
    return raiz;
  else if(info < raiz->dado)
    return ABBBuscar(raiz->esq,info);
  else
    return ABBBuscar(raiz->dir,info);
}

noArvore* maior(noArvore* raiz){
  if(raiz == NULL || raiz->dir == NULL)
    return raiz;
  else
    return maior(raiz->dir);
}

bool ABBRemover(noArvore *&raiz, string elemento,noArvore* pai){
  if(raiz == NULL)
    return false;
  else if(elemento < raiz->dado)
    return ABBRemover(raiz->esq,elemento,raiz);
  else if(elemento > raiz->dado)
    return ABBRemover(raiz->dir,elemento,raiz);
  else{
    if(raiz->esq == NULL && raiz->dir == NULL){
      delete raiz;
      raiz = NULL;
    }
    else if(raiz->esq == NULL){
      noArvore *aux = raiz;
      raiz = raiz->dir;
      raiz->dir->pai=pai;
      delete aux;
    }
    else if(raiz->dir == NULL){
      noArvore *aux = raiz;
      raiz = raiz->esq;
      raiz->esq->pai=pai;
      delete aux;
    }
    else{
      noArvore *aux = maior(raiz->esq);
      raiz->dado = aux->dado;
      raiz->esq = aux->esq;
      delete aux;
    }
    return true;
  }
}

void lendoArquivo(noArvore *&raiz){
  ifstream arquivo;
  arquivo.open("dicionario.txt");
  char opcao;
  string linha;
  bool teste;
  while (arquivo.get(opcao)){
    getline(arquivo,linha);
    if (opcao=='1')
      ABBInserir(raiz,linha,raiz);
    else if(opcao=='0'){
      teste=ABBRemover(raiz,linha,raiz);
      if (teste==false)
        cout<<linha<<" nao pode ser removido pois nao esta na arvore.\n";
      }
  }
  arquivo.close();
  cout<<"Arvore preenchida com dados do dicionario...\n";
}

void ABBImprimirNos(noArvore* raiz){
  if(raiz!=NULL){
    ABBImprimirNos(raiz->esq);
    ABBImprimirNos(raiz->dir);
    string pai="",esq="",dir="";
    if (raiz->pai==NULL)
      pai="nó pai nulo";
    else pai=raiz->pai->dado;
    if (raiz->esq==NULL)
      esq="nó esquerdo nulo";
    else esq=raiz->esq->dado;
    if (raiz->dir==NULL)
      dir="nó direito nulo";
    else dir=raiz->dir->dado;
    cout<<endl<<pai<<","<<raiz->dado<<","<<esq<<","<<dir<<endl;
  }
}

void menu(noArvore *&raiz){
  int opc=99;
  while(opc!=0){
    cout<<"\nEscolha uma opcao:\n1 - Inserir elemento\n2 - Buscar Elemento\n3 - Imprimir Chaves\n4 - Imprimir Nos\n5 - Remover Elemento\n0 - Sair: ";
    cin>>opc;
    switch(opc){
      case 1:{
        cout<<"Que nome deseja inserir? ";
        string nome;
        cin>>nome;
        ABBInserir(raiz,nome,raiz);
      }
      break;
      case 2:{
        cout<<"Que nome deseja buscar? ";
        string nome;
        cin>>nome;
        noArvore* busca=ABBBuscar(raiz,nome);
        if(busca==NULL)
          cout<<"Nome não encontrado na arvore"<<endl;
        else cout<<"Encontrado "<<busca->dado<<endl;
      }
      break;
      case 3:
        ABBImprimirChaves(raiz);
      break;
      case 4:
        ABBImprimirNos(raiz);
      break;
      case 5:
        {
        cout<<"Que nome deseja remover? ";
        string nome;
        cin>>nome;
        ABBRemover(raiz,nome,raiz);
        ABBImprimirChaves(raiz);
        ABBImprimirNos(raiz);
      }
      break;
      case 0:
      break;
      default:"Opção invalida";
      break;
    }
  }
}



int main() {
  noArvore *arv1 = inicializar();
  lendoArquivo(arv1);
  menu(arv1);
  
}


Custos de cada função:

Inicializar: C1 return null; 1

ABBImprimirChaves:
c1:   if(raiz!=NULL) :   n*n porque para cada nó a função é chamada recursivamente 2 vezes(esquerda e direita)
    c2:ABBImprimirChaves(raiz->esq);  n*n 
    c3:cout<<endl<<raiz->dado<<endl;  n*n 
    c4:ABBImprimirChaves(raiz->dir);  n*n 
  }
}      resultado: 4n^2 (quadrática)

ABBInserir:
  c1: if(raiz == NULL)  n*n
   c2:  raiz = new noArvore; 1
    c3:raiz->dado = info; 1
    c4:raiz->esq = NULL; 1
    c5:raiz->dir = NULL; 1
    c6:raiz->pai=pai; 1
  }
  c7:else if(info < raiz->dado) n+n-1
    c8:ABBInserir(raiz->esq,info,raiz); n*n
  c9:else if(info > raiz->dado) n+n-2
    c10:ABBInserir(raiz->dir,info,raiz); n*n
  else{
    c11:cout<<info<<" já existe na árvore."<<endl;  n
  }
}   3n^2 +7n +4  = Quadrática

ABBBuscar:
 c1: if(raiz == NULL || raiz->dado == info) n*n
  c2:  return raiz; 1 
  c3: else if(info < raiz->dado) n*n
    c4:return ABBBuscar(raiz->esq,info); n*n
  else
  c5:  return ABBBuscar(raiz->dir,info); n*n
}
3n^2+1=quadrática Obs: estão sendo n*n porque a cada execução a chamada recursiva é feita novamente, o que multiplica a quantidade de execuções.

maior
c1:  if(raiz == NULL || raiz->dir == NULL) n
    c2: return raiz; 1
  else
    c3: return maior(raiz->dir); n
}
2n+1= Linear

ABBRemover:
c1:  if(raiz == NULL) n*n
c2:    return false; 1
c3:  else if(elemento < raiz->dado)     n*n
c4:    return ABBRemover(raiz->esq,elemento,raiz); n*n-x (o x é porque não se sabe quantos números maiores do que o elemento estarão na árvore)
c5:  else if(elemento > raiz->dado) n*n
c6:    return ABBRemover(raiz->dir,elemento,raiz); n*n-x
  else{
c7:    if(raiz->esq == NULL && raiz->dir == NULL){ n*n
c8:      delete raiz; 1
c9:      raiz = NULL; 1
    }
c10:    else if(raiz->esq == NULL){ n*n
c11:      noArvore *aux = raiz; 1
c12:      raiz = raiz->dir; 1
c13:      raiz->dir->pai=pai; 1
c14:      delete aux; 1
    }
c15:    else if(raiz->dir == NULL){ n*n
c16:      noArvore *aux = raiz; 1 
c17:      raiz = raiz->esq; 1
c18:      raiz->esq->pai=pai; 1
c19:      delete aux; 1
    }
    else{
c20:      noArvore *aux = maior(raiz->esq); n*n
c21:      raiz->dado = aux->dado; 1
c22:      raiz->esq = aux->esq;1
c23:      delete aux;1
    }
c24:    return true;1
  }
}

9n^2-2x+15= quadrática

lendoArquivo:
c1:  ifstream arquivo; 1
c2:  arquivo.open("dicionario.txt"); 1
c3:  char opcao;1
c4:  string linha;1
c5:  bool teste;1
c6:  while (arquivo.get(opcao)){ n
c7:    getline(arquivo,linha); n
c8:    if (opcao=='1')n
  c9:    ABBInserir(raiz,linha,raiz); x(x porque não se sabe quantos elementos do dicionario contém o numero 1 ordenando a inserção)
  c10:  else if(opcao=='0'){ n
  c11:    teste=ABBRemover(raiz,linha,raiz); y
  c12:    if (teste==false) n
  c13:      cout<<linha<<" nao pode ser removido pois nao esta na arvore.\n"; y
      }
  }
c14:  arquivo.close(); 1
c15:  cout<<"Arvore preenchida com dados do dicionario...\n"; 1
}
x+5n+2y+7 = Linear

ABBImprimirNos:
c1: if(raiz!=NULL){   n*n
c2:    ABBImprimirNos(raiz->esq); n* n
c3:    ABBImprimirNos(raiz->dir); n*n
c4:    string pai="",esq="",dir=""; n*n
c5:    if (raiz->pai==NULL) n*n
c6:      pai="nó pai nulo"; 1
c7:    else pai=raiz->pai->dado; n*n
c8:    if (raiz->esq==NULL)  n*n
c9:      esq="nó esquerdo nulo"; n*n
c10:    else esq=raiz->esq->dado; n*n
c11:    if (raiz->dir==NULL) n*n
c12:      dir="nó direito nulo"; n*n
c13:    else dir=raiz->dir->dado; n*n
c14:    cout<<endl<<pai<<","<<raiz->dado<<","<<esq<<","<<dir<<endl; n
  }
}

11n^2 + n+1 = quadrática

menu
  c1:int opc=99; 1
 c2: while(opc!=0){ n
 c3:   cout<<"\nEscolha uma opcao:\n1 - Inserir elemento\n2 - Buscar Elemento\n3 - Imprimir c4:Chaves\n4 - Imprimir Nos\n5 - Remover Elemento\n0 - Sair: "; n
c5:    cin>>opc; n
c6:    switch(opc){ n
c7:      case 1:{ n
c8:        cout<<"Que nome deseja inserir? "; n
c9:        string nome; n
c10:        cin>>nome; n
 c11:       ABBInserir(raiz,nome,raiz); n
      }
    c12:  break;n
    c13:  case 2:{ n
     c14:   cout<<"Que nome deseja buscar? "; n
     c15:   string nome; n
     c16:   cin>>nome;n
     c17:   noArvore* busca=ABBBuscar(raiz,nome);n
     c18:   if(busca==NULL)n
    c19:      cout<<"Nome não encontrado na arvore"<<endl;n
    c20:    else cout<<"Encontrado "<<busca->dado<<endl;n
      }
    c21:  break;n
    c22:  case 3:n
     c23:   ABBImprimirChaves(raiz);n
    c24:  break;n
    c25:  case 4:n
    c26:    ABBImprimirNos(raiz);n
    c27:  break;n
   c28:   case 5:n
        {
   c29:     cout<<"Que nome deseja remover? ";n
   c30:     string nome;n
   c31:     cin>>nome;n
   c32:     ABBRemover(raiz,nome,raiz);n
   c33:     ABBImprimirChaves(raiz);n
   c34:     ABBImprimirNos(raiz);n
      }
   c35:   break;n
   c36:   case 0:n
   c37:   break;1
   c38:   default:"Opção invalida";n
   c39:   break;n
    }
  }
}
37n+2 = Linear
*/