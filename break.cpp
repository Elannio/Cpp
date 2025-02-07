#include <iostream>

using namespace std;

int main(){

    int cont;

    cont=0;
    while(cont<20){
        //while(cont++<20){ pode incrementar assim também se for ++ ou --
        cout << "Winnie - "<< cont <<"\n";
        cont++;
        if(cont == 15){
            break;
        }
        //cont += 2 pra ir de 2 em 2
    }

    cout << "\nFim do programa\n";
    
    return 0;
}