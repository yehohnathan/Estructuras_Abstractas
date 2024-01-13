/*
    Proporcionan las versiones sin ordenar del contenedor asociativo. Internamente,
    se implementan como estructuras de datos de hash-tables.

    Los hash-tables lo quiero cuando no quiero algo ordenado.
*/
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    // Se crea un vector de numeros enteros. A pesar de que es desordenado
    // sigue siendo un Set por lo que elimina elementos repetidos
    unordered_set<int> numbers = {1, 100, 10, 70, 100};

    // Se imprime el vector utilizando la función "auto"
    cout << "Numbers are: ";
    for(auto &num: numbers) {
        cout << num << " ";
    }

    return 0;
}
