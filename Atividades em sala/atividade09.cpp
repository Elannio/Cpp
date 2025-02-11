/*#include <iostream>
using namespace std;

int multiplicaRestoPorParteInteira (int i, int j){

int resto= i%j;
int pinteira = i / j;
int resultado =resto * pinteira;
return resultado;
  
}

Resposta: 2



double precisaNaFinal (double notal, double nota2, double nota3) {
  double media= (notal+ nota2+nota3) / 3;
  if (media >= 7 || media < 4) {
    return 0;
    } else {
  double mediaFinal = 5;
  double pesoFinal =0.4;
  double pesoMedia = 0.6;
  double precisa = (mediaFinal - pesoMedia * media)/pesoFinal;

  return precisa;
}
  }
  
int main(){
  cout<<multiplicaRestoPorParteInteira(5, 3)<<endl;
  
  cout<<precisaNaFinal(5,7,4);
}

Resposta: 4.5
*/