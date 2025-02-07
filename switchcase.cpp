#include <iostream>

using namespace std;

int main(){

    int val;

    cout << "Selecione uma dor:\n";
    //cout << "[1]=Verde, [2]=Azul, [3]=Vermelho\n";
    cout << "[1,2,3]=Verde, [4,5,6]=Azul\n";
    cin >> val;

    switch(val){

        case 1:
        case 2:
        case 3:
            cout << "Cor selecionada: Verde\n";
            break;
        case 4:
        case 5:
        case 6:
            cout << "Cor selecionada: Azul\n";
            break;
        default:
            cout << "Valor selecionado inválido\n";
            break;
        }
    return 0;
}