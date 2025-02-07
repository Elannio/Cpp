#include <iostream>

using namespace std;

int main(){

    int cont;

    cont=20;
    do{
        //while(cont++<20){ pode incrementar assim também se for ++ ou --
        cout << "Winnie - "<< cont <<"\n";
        cont++;
    }while(cont<20);
        //cont += 2 pra ir de 2 em 2

    cout << "\nFim do programa\n";
    
    return 0;
}

//do while executa primeiro e no final vai executar o bloco de comandos pelo menos uma vez