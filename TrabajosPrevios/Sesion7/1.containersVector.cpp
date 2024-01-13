/*
    Permiten almacenar elementos a los que se pueden acceder en orden
    secuencial
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Se crea un vector de numeros enteros
    vector<int> numbers = {1, 100, 10, 70, 100};
    
    // Se imprime el vector utilizando la función "auto"
    cout << "Numbers are: ";
    for(auto &num: numbers) {
        cout << num << " ";
    }
    
    // Esto se imprime de version secuencial
    return 0;
}
