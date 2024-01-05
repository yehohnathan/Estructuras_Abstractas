/*
    Mapa de memoria del programa
*/

#include <iostream>
using namespace std;

int main(){
    int var1 = 3;
    int var2 = 24;
    int var3 = 17;

    //Se muestra la dirección en memoria de cada variable
    cout << "Addres of var1: " << &var1 << endl;
    cout << "Addres of var2: " << &var2 << endl;
    cout << "Addres of var3: " << &var3 << endl;

    // La dirección se obtiene al poner & antes de la variable
    return 0;
}