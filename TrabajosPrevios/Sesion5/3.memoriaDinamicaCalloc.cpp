/*
    Calloc: se utiliza para asignar un bloque de memoria en el heap, iniciandolo
    en cero, y devuelve un puntero void* al inicio de la memoria asignada (heap).

    Inicializa en cero, por lo que limpia la basura. Y es más caro en tiempo
    compitacional
*/

#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    int *ptr;

    // Calloc recibe 5 elementos a querer asignar del tamaño de un entero
    ptr = (int*) calloc(5, sizeof(int));    // Utilizando casting a un entero

    // Si ptr no es un valor valido, o sea que no es cero:
    if (!ptr) { //
        cout << "Memory Allocation Failed";
        exit(1);
    }

    cout << "Initializing values..." << endl
         << endl;

    // Se inicializan los valores:
    for (int i = 0; i < 5; ++i) {
        ptr[i] = i * 2 + 1;
    }

    cout << "Initialized values" << endl;
    
    for (int i = 0; i < 5; i++) {
        /* ptr[i] and *(ptr+i) can be used interchangeably */
        cout << *(ptr + i) << endl; // Aritmetica de punteros
    }

    // Libero todos los 5 espacios del malloc
    free(ptr);
    return 0;
}
// Output: 5
