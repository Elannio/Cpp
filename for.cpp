#include <iostream>

using namespace std;

int main(){

    /*
        for(ini ; cond ; inc/dec){
        comandos}
    */

   int x, y;

   for(x = 0, y = 1; x < 10; x++, y += 2){
        cout << x << " - " << y << "\n";
   }
    
    return 0;
}