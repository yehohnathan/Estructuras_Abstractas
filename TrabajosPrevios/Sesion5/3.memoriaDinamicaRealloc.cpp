/*
    Realloc: se utiliza para cambiar el tamaño de un bloque de memoria
    previamente asignado con malloc o calloc. Puede redimensionar el 
    bloque existente o asignar uno nuevo, y devuelve un puntero al nuevo
    bloque de memoria.

    Free: se utiliza para liberar la memoria previamente asignada con un
    Malloc, Calloc o Realloc. Previene fugas de memoria para no perder
    pedazos de memoria (memory leak).


*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    float *ptr, *new_ptr;

    // Se realiza un malloc, sino no habría realloc que utilizar y reservo
    // 5 por el tamaño de un flotante

    ptr = (float*) malloc(5 * sizeof(float));
    if(ptr == NULL) {
        cout << "Memory Allocation Failed";
        exit(1);
    }

    // Inicializo los bloques de memoria
    for (int i = 0; i < 5; i++) {
        ptr[i] = i*1.5;
    }

    // reallocating memory
    // Cambio 5 * sizeof(float) a 10 * sizeof(float)
    new_ptr = (float*) realloc(ptr, 10 * sizeof(float));
    if(new_ptr == NULL) {
        cout << "Memory Re-allocation Failed";
        exit(1);
    }

   // Initializing re-allocated memory block
   for (int i = 5; i < 10; i++) {
       new_ptr[i] = i*2.5;
   }

   cout << "Printing Values:" << endl;
   for (int i = 0; i < 10; i++) {
       cout << new_ptr[i] << endl;
   }
   
   free(new_ptr);

   return 0;
}
