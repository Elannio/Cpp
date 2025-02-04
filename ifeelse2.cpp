#include <iostream>
#include <cstdlib> //biblioteca que limpa a tela

using namespace std;

int main(){

    int num1,num2;
    char opc;

    inicio:

    system("cls"); //limpar a tela quando for pro inicio

    cout << "Digite a primeira nota: ";
    cin >> num1;

    cout << "Digite a segunda nota: ";
    cin >> num2;

    if((num1+num2)/2 >= 7){
        cout << "Você foi aprovado";
    }
    else{
        cout << "Reprovado";
    }

    cout << "\nDigitar outras notas: ";
    cin >> opc;

    if (opc == 's' || opc == 'S'){
        goto inicio;
    } 

    return 0;
}