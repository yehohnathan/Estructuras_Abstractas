/*
    Un iterador es un objeto similar a un puntero que representa la posición de 
    un elemento en un contenedor. Se recuerda que aquí se utiliza artimética
    de punteros.

    Crear un vector iterator:
    vector<int>::iterator vec_itr;

    Crear un mapa iterador:
    map<char, int>::iterator map_itr;

    Crear un vector de tipos entero:
    vector<int num {1, 2, 3}:

    Error: itr unicamente puede ser usado co vectores de enteros
    vector<double>:: iterator itr = num.begin();

    El uso de auto:
    vector<string>:: iterator itr = lenguages.begin();  -> Preferible
    auto itr = lenguages.begin();
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

    // Vreo un vector iterador tipo string
    vector<string> languages = {"Python", "C++", "Java"};

    // Crea un iterador a un vector tipo string
    vector<string>::iterator itr;

    // Itera todos los elementos haciendo uso de aritmética de punteros
    for (itr = languages.begin(); itr != languages.end(); itr++) {
        cout << *itr << " ";
    }

    return 0;
}
