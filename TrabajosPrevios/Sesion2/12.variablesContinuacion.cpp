/* 
    Continuación para de variables
*/

#include <iostream>
using namespace std;

int count;  // Variable global que se usa en otro programa
extern void write_extern(); // Linker al otro programa

void test(){
    static int var = 0;     // Solo ejecuta una única vez
    var ++;

    cout << var << endl;
}

int main(){
    test(); // Las variables staticas son como variables semiglobales
    test();

    count = 5;
    write_extern();
    return 0;
}
