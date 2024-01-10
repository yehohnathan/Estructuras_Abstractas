/*
    Malloc: se utiliza para asignar un bloque de memoria en el heap y devuelve
    un puntero void* al inicio de la memoria asignada (en el heap).

    No limpia la basura que haya en la memoria en dicho instante
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {

// allocate memory of int size to an int pointer
// Utilizando casting explicito, cambio el void pointer del malloc 
// por un número entero

int* ptr = (int*) malloc(sizeof(int));  // Recibe el tamaño en bytes de la memoria
                                        // que se quiere reservar sizeof(int)

// assign the value 5 to allocated memory
*ptr = 5;

cout << *ptr;

return 0;
}

// Output: 5
