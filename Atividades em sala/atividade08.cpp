/*void transporMatriz(int matriz[][tam]){
  for(int i=0;i<tam;i++){
    for(int j=i+1;j<tam;j++){
      int aux=matriz[i][j];
      matriz[i][j]=matriz[j][i];
      matriz[j][i]=aux;
      }
   }
}


c1 int i=0 — 1
c2 i<tam — n+1
c3 i++ — n
c4 i+1 — n
c5 j=i+1 — n
c6 j<tam — n*(n-1)
c7 j++ — n*(n-1)-1
c8 aux=matriz[i][j] — n*(n-1)-1
c9 matriz[i][j]=matriz[j][i] — n*(n-1)-1
c10 matriz[j][i]=aux — n*(n-1)-1

Total: 

1+n+1+n+n+n+n²-n+n²-n+n²-n+n²-n+n²-n=5n²c-nc+2c


Resposta da questão 2) 


int buscaVetor(int tamanho,int v,int vetor[]){
  for (int i=0;i<tamanho;i++){
    if(vetor[i]==v){
      return i;
    }
  }
  return -1;
}


c1 int i=0 — 1
c2 i<tamanho — n+1
c3 i++ — n
c4 vetor[i]==v — n
c5 return i — 0
c6 return -1 — 1

Total: 

1+n+1+n+n+0+1= 3nc+3c


*/