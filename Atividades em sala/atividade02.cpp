/*1) Dado o tipo de dados de funcionário a seguir:
Matrícula - inteiro;
nome - string;
salário - double;
função - string;

Implemente uma tabela hash de tamanho M = 25. Os funcionários devem ser indexados pela sua matrícula e a função de hash deve ser h(x) = x % M. Para o tratamento de colisões, use listas simplesmente encadeadas.
Faça um programa com um laço para incluir funcionários na tabela, até que o usuário informe matrícula 0 (4,0 pontos).

Resposta:

#include <iostream>

//Questão 1

using namespace std;

struct Funcionario{
  int matricula;
  string nome;
  double salario;
  string funcao;
};

struct nolistad{
  Funcionario fun;
  nolistad *prox;
};

struct descritor{
  nolistad *ini,*fim;
};

void inicializar(descritor*& lista){
  lista= new descritor;
  lista->ini= NULL;
  lista->fim= NULL;
}

void inserirFuncionario(descritor *vetor, int matricula){
  nolistad *novo=new nolistad;
  novo->fun.matricula=matricula;
  
  cout<<"Nome: ";cin>>novo->fun.nome;
  cout<<"Salario: ";cin>>novo->fun.salario;
  cout<<"Função: ";cin>>novo->fun.funcao;
  novo->prox=NULL;
  
  int chave = matricula % 25;
  
  if (vetor[chave] == NULL){
    inicializar(vetor[chave]);
    vetor[chave]->ini = novo;
    vetor[chave]->fim = novo;
  }
  else{
    vetor[chave]->fim->prox = novo;
    vetor[chave]->fim = novo;
  }
}

void imprimirLista(nolistad *inicio){
  nolistad *p= inicio;
  
  while (p != NULL){
  cout<<"Matricula: "<<p->fun.matricula<<"\nNome: "<<p->fun.nome<<"\nFunção: "<<p->fun.funcao<<"\nSalario: "<<p->fun.salario<<"\n\n";
    p=p->prox;
  }
}

void buscarFuncionario(descritor *vetor){
  int matricula;
  cout<<"Matrícula: ";cin>>matricula;
  int chave=matricula % 25;
  
  if (vetor[chave] != NULL){
    cout<<"\n\n";
    imprimirLista(vetor[chave]->ini);
    cout<<"\n\n";
  }
}

void imprimirTodosOsFuncionarios(descritor *vetor){
  for(int i=0;i<25;i++){
    cout<<"\n\nPosição "<<i+1<<endl;
    if(vetor[i]!=NULL)
      imprimirLista(vetor[i]->ini);
    else
      cout<<"Sem posição";
    cout<<"\n\n";
  }
}

int main() {
  descritor *vetor=new descritor[25];
  int menu=99;
  int matricula;
  while (menu!=0){
    cout<<"\n\n1 - Cadastrar Funcionario\n2 - Buscar Funcionario\n3 - Imprimir Funcionários\n0 - Sair: ";cin>>menu;
    
    switch (menu){
      case 1:
        cout<<"Matrícula do funcionário: ";cin>>matricula;
        while (matricula != 0){
          
          inserirFuncionario(vetor,matricula);
          cout<<"Cadastro de Funcionário:\n\n";
          cout<<"Matrícula do funcionário:";cin>>matricula;
        }
      break;
      case 2:
        buscarFuncionario(vetor);
      break;
      case 3:
        imprimirTodosOsFuncionarios(vetor);
      case 0:
        cout<<"Encerrar";
        break;
      default:
        cout<<"Inválido.";
      break;
    }
  }
}


2) Considere um grafo em que cada vértice representa uma pessoa e cada adjacência representa um voto. Faça uma função que receba a matriz de adjacência desse grafo e retorne o índice do vértice que venceu a eleição. Considere o índice de linha e coluna da matriz como os índices dos vértices (3,0 pontos).

Resposta:

#include <iostream>

using namespace std;

struct Vertice{
  string label;
  Vertice *prox;
  struct Aresta *adj;
  bool visitado;
};

struct Aresta{
  int valor;
  Aresta* prox;
  Vertice *dest;
};

struct Fila{
  Vertice *dado;
  Fila* prox;
};

Fila* inicializar();
void enfileirar(Fila *&f, Vertice*dado);
Vertice* desenfileirar(Fila *&f);

int votos(Vertice *grafo){
  int tamanho=0;
  Vertice *p=grafo;
  
  while (p!=NULL){
    tamanho++;
    p=p->prox;
  }
  p=grafo;
  Vertice *q=grafo;
  int matriz[tamanho][tamanho];
  string nomes[tamanho];
  int votos[tamanho];
  cout<<"Responda com 1 para sim ou 0 para não\n";
  for(int i=0;i<tamanho;i++){
    votos[i]=0;
    nomes[i]=p->label;
    for(int j=0;j<tamanho;j++){
      setbuf(stdin,NULL);
      cout<<p->label<<" tem ligação para "<<q->label<<"? ";cin>>matriz[i][j];
      q=q->prox;
    }
    p=p->prox;
    q=grafo;
  }
  for(int i=0;i<tamanho;i++){
    for(int j=0;j<tamanho;j++){
      cout<<matriz[i][j]<<" ";
    }
    cout<<"\n";
  }
  for (int i=0;i<tamanho;i++){
    for(int j=0;j<tamanho;j++){
      if(matriz[j][i]!=0)
        votos[i]++;
    }
  }
  int maior=votos[0];
  int indice=0;
  for(int i=0;i<tamanho;i++){
    for(int j=0;j<tamanho;j++){
      if(votos[i]>maior){
        maior=votos[i];
        indice=i;
      }
    }
  }
  cout<<"O vencedor é: "<<nomes[indice];
  return indice;
}

int vencedor(int matriz[][2],int tamanho){
  int votos[tamanho];
  for (int i=0;i<tamanho;i++){
    votos[i]=0;
  }
  for (int i=0;i<tamanho;i++){
    for(int j=0;j<tamanho;j++){
      if(matriz[j][i]!=0)
        votos[i]++;
    }
  }
  int maior=votos[0];
  int indice=0;
  for(int i=0;i<tamanho;i++){
      if(votos[i]>maior){
        maior=votos[i];
        indice=i;
    }
  }
  return indice;
}

int main() {

  Vertice *vert=new Vertice;
  vert->label="a";
  Vertice *novo=new Vertice;
  novo->label="b";
  vert->prox=novo;
  votos(vert);
  int matriz[2][2]={
    {0,1},
    {0,1}
    };
  cout<<"\nO vencedor é o candidato de número: "<<eleito+1;
}

//3) Faça uma função que receba uma árvore binária de pesquisa contendo as mesmas informações da questão 1. A função deve retornar a soma dos salários de todos os vendedores (3,0 pontos).

//Resposta:

#include <iostream>
using namespace std;

struct noArvore{
  int matricula;
  string nome;
  double salario;
  string funcao;
  noArvore *esq,*dir;
};

double somaSalarios(noArvore *raiz){
  if (raiz!=NULL){
     return raiz->salario+somaSalarios(raiz->esq)+somaSalarios(raiz->dir);
  }else
    return 0;
}

void inicializar(noArvore *&raiz){
  raiz=NULL;
}

void inserirElemento(noArvore *&raiz,int matricula){
  if (raiz==NULL){
    raiz=new noArvore;
    raiz->matricula=matricula;
    cout<<"Nome: ";cin>>raiz->nome;
    cout<<"Salario: ";cin>>raiz->salario;
    cout<<"Função: ";cin>>raiz->funcao;
    raiz->esq=NULL;
    raiz->dir=NULL;
  }
  else if(matricula<raiz->matricula)
    inserirElemento(raiz->esq,matricula);
  else if(matricula>raiz->matricula)
    inserirElemento(raiz->dir,matricula);
}

void imprimirArvore(noArvore *raiz){
  if(raiz!=NULL){
    imprimirArvore(raiz->esq);
    cout<<"\n----------\nMatricula: "<<raiz->matricula<<"\nNome: "<<raiz->nome<<"\nSalario: "<<raiz->salario<<"\nFunção: "<<raiz->funcao<<"\n----------\n";
    imprimirArvore(raiz->dir);
  }
}

int main() {
  int menu=99;
  int matricula;
  noArvore *raiz;
  inicializar(raiz);
  while (menu!=0){
    cout<<"\n1 - Cadastrar\n2 - Imprimir\n3 - Somar Salarios\n0 - Sair: ";cin>>menu;
    switch(menu){
      case 1:
      cout<<"Matrícula do funcionário: ";cin>>matricula;
      inserirElemento(raiz,matricula);
      break;
      case 2:
        imprimirArvore(raiz);
      break;
      case 3:
        cout<<"A soma de todos os salarios: "<<somaSalarios(raiz)<<endl;
      break;
      case 0:
      cout<<"Saindo..."<<endl;
      break;
      default:
      cout<<"Opção Inválida!"<<endl;
      break;
    }
  }
}
*/