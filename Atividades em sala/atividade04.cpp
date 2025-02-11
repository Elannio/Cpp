/*#include <iostream>


using namespace std;


struct nolistad{
 int dado;
 nolistad *prox, *ant;
};


struct descritor{
 int tamanho;
 nolistad *ini, *fim;
};


void inicializar(descritor *&lista){
 lista= new descritor;
 lista->tamanho=0;
 lista->ini=NULL;
 lista->fim=NULL;
}


void inserir_fim(descritor *lista, int dado){
 nolistad *novo = new nolistad;
 novo->dado = dado;
 novo->prox = NULL;
 novo->ant = NULL;


 if(lista->ini == NULL){
   lista->ini = novo;
   lista->fim = novo;
   lista->tamanho++;
 }


 else{
   lista->fim->prox = novo;
   novo->ant = lista->fim;
   lista->fim = novo;
   lista->tamanho++;
 }
}


void duplicar(descritor *lista){
 int tamanho=lista->tamanho;
 nolistad *p=lista->ini;


 for(int i=0;i<tamanho;i++){
   nolistad *novo = new nolistad;
   novo->dado = p->dado;
   novo->prox = NULL;
   novo->ant = NULL;
   lista->fim->prox = novo;
   novo->ant = lista->fim;
   lista->fim = novo;
   lista->tamanho++;
   p=p->prox;
 }
}




void imprimir(nolistad *lista){
 nolistad *p=lista;


 if (p==NULL)
   cout<<"Lista sem elementos.";


 else{
 while (p!=NULL){
   cout<<p->dado<<endl;
   p=p->prox;
   }
 }
}


int main() {
 descritor *lista;
 inicializar(lista);
 inserir_fim(lista,1);
 inserir_fim(lista,2);
 inserir_fim(lista,3);
 inserir_fim(lista,4);
 duplicar(lista);
 imprimir(lista->ini);


}


2) #include <iostream>


using namespace std;


struct Lista{
 int dado;
 Lista *ant,*prox;
};


void inserir(Lista *&lista, int dado){
 Lista *novo=new Lista;


 novo->dado=dado;
 novo->ant=NULL;
 novo->prox=NULL;


 if (lista==NULL){
   lista=novo;
 }


 else{
   Lista *p=lista;


   while (p->prox!=NULL){
     p=p->prox;
   }
   p->prox=novo;
   p->ant=p;
 }
}


bool crescente(Lista *lista){
 Lista *p=lista;
 if (p==NULL){
   cout<<"Não é válida";
   return false;
 }
  else{
   while (p->prox != NULL){
     if(p->dado > p->prox->dado)
       return false;
       p = p->prox;
   }


   return true;
 }
}




void imprimir(Lista *lista){
 Lista *p=lista;


 if (p==NULL)
  cout<<"Lista sem elementos.";
 else{


 while (p!=NULL){
  cout<< p->dado <<endl;
  p = p->prox;
   }
 }
}


int main() {
 Lista *lista=NULL;
 inserir(lista,1);
 inserir(lista,2);
 inserir(lista,3);
 inserir(lista,4);
 imprimir(lista);
 cout<<crescente(lista);


}

3) void mediaPonderada(double mat[5][4]){


   for(int i = 0; i < 5; i++){
       mat[i][3] = ((mat[i][1]*7)+ (mat[i][2]*3))/10;
   }


}
*/