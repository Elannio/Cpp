#include <iostream>
using namespace std;

int n1,n2; //variaveis globais

int main(){

    int n3,n4; //variaveis locais
    int res;

    n1=11;
    n2=5;
    n3=14;
    n4=8;

    res=n1+n2+n3*n4;

    cout << "Soma de todas as variáveis: " << res << "\n\n";

    return 0;
}