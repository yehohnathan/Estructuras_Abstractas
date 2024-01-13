/*
    Permiten almacenar elementos en orden. El orden no depende de cuándo se inserta
    elemento. En este caso va de menor a mayor.
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
    // Se crea un vector de numeros enteros
    set<int> numbers = {1, 100, 10, 70, 100};

    // Se imprime el vector utilizando la función "auto"
    cout << "Numbers are: ";
    for(auto &num: numbers) {
        cout << num << " ";
    }

    // Como acá los elementos se almacenan en orden tampoco permite
    // elementos repetidos

    return 0;
}
