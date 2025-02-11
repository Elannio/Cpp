/*void somaMatriz(int m[][2],int n[][2]){
    for(int i=0;i<2;i++){
    for (int j=0;j<2;j++){
    m[i][j]+=n[i][j];
        }
      }
    }
    
    Passo 1/Passo 2/Passo 3
    
    c1: int i=0 1
    c2: i<2 n+1
    c3: i++ n
    c4: int j=0 n
    c5: j<2 n²+n
    c6: j++ n²
    c7: m[i][j]+n[i][j] n²
    c8: m[i][j]= n²
    Soma: 4n²+4n+2
    segunda questão
    int somaVetor( int n[],int tam){
    int soma=0;
    for(int i=0;i<tam;i++){
    soma=soma+n[i];
    }
    return soma;
    }
    
    2)
    
    Passo 1/Passo 2/Passo 3
    
    C1: int soma=0; 1
    C2:int i=0 1
    C3:i<tam N+1
    C4:i++ n
    C5:soma= n
    C6:soma+n[i] n
    C7: return soma; 1
    Soma: 4n+4
    Terceira questão
    void buscaVetor(int vetor[],int tam,int n){
    if(tam<0){
    cout<<"Não encontrado!";
    return;
    }
    if (vetor[tam-1]==n){
    cout<<"Encontrado!";
    return;
    }
    buscaVetor(vetor,tam-1,n);
    }
    
    3)
    
    Passo 1/Passo 2/Passo 3
    C1:tam<0 N+1
    C2: cout<< 1
    C3:return; 1
    C4:vetor[tam-1]==n n
    C5:cout<< 0
    C6:return 0
    C7:buscaVetor(vetor,tam-1,n)
    
    resultado = N+1 3n+4
    
    
    
*/    