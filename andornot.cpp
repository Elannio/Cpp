#include <iostream>

using namespace std;

int main(){

    int num;

    num=8;

    //&& = and
    //|| = or/ou
    // .!= = diferente
    if(num > 4 && num < 7){
        cout << "\n\nValor aceito\n";
    }
    else{
        cout << "\n\nValor não aceito\n";
    }

    return 0;
}