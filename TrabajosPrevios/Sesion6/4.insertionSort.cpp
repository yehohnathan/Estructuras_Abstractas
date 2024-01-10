/*
    Algoritmo de ordenamiento por inserción "ÏnsertionSort". Toma cada
    elemento del arreglo y lo inserta en su posición correnta en la parte
    ya ordenada del arreglo.

    Se va comparando con los elementos de la izquierda comparandolos si 
    es menor. * Se entiende mucho mejor con el gráfico del algoritmo.
*/

#include <iostream>
using namespace std;

// Función para imprimir arreglos
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Función para realizar el InsertionSort
void insertionSort(int array[], int size) {
    // Se realiza un ciclo desde el paso uno hasta size - 1
    for (int step = 1; step < size; step++) {
        // key como elemento actual del array segun el paso
        int key = array[step];

        // Donde j es el número de comparaciones que se deben hacer
        int j = step - 1;

        // Key es menor al elemento de la izquierda 
        while (key < array[j] && j >= 0) {
            array[j + 1] = array[j];    // Copio el elemento de la izquierda
            --j;                        // a la posición de key y resto j
        }
        array[j + 1] = key;             // Luego coloca key en la posición
                                        // de la izquierda, como un swap
    }   // Termina también si j no es mayor e igual a 0
}

// Código de prueba
int main() {
    int data[] = {9, 5, 1, 4, 3};

    int size = sizeof(data) / sizeof(data[0]);

    insertionSort(data, size);

    cout << "Sorted array in ascending order:\n";

    printArray(data, size);
}


/*
    Tiempo de complejidad:
    Best:       O(n)
    Worst:      O(n^2)
    Average:    O(n^2)
*/