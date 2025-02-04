#include <iostream>
using namespace std;

int main(){

    int vidas=0; //variavel inteira
    char letra='B'; //recebe um character
    double decimal=5.43; //recebe um número decimal: 2.5555
    float decimal2=5.4; //recebe um npumero decimal preciso tipo 2.5
    bool vivo=true; //recebe um valor booleano verdadeiro ou falso
    string nome="winnie"; //recebe um texto entre ""


    cout << "Digite o número de vidas";
    cin >> vidas;
    cout << "digite uma letra";
    cin >> letra;
    cout << "Dinheiro";
    cin >> decimal;
    cout << "seu nome";
    cin >> nome;

    cout << vidas << "\n";
    cout << letra << "\n";
    cout << decimal << "\n";
    cout << decimal2 << "\n";
    cout << vivo << "\n";
    cout << nome << "\n";

    return 0;
}