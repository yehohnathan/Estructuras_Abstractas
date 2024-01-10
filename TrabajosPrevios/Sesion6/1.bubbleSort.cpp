/*
    Un algoritmo de ordenamiento sirve para organizar los elementos de una matriz/lista
    en un orden específico.

    El bubble sort es uno de esos algoritmos y ordena los elementos de forma ascendente. 
    Este recorre el arreglo varias veces y compara elementos adyacentes para intercambiarlos
    si están en orden incorrecto.
*/

#include <iostream>
using namespace std;

// Instancia del Bubble Sort: utiliza un ciclo for para recorrer la misma cantidad
// de pasoso que el tamaño del array (size)
void bubbleSort(int array[], int size) {    // Recibe un array de tamaño variable y el tamaño

    // Ciclo para acceder a cada elemento del array
    for (int step = 0; step < size; ++step) {

        // Ciclo para comparar el elemento 1 frente al elemento 2 adyacente
        for (int i = 0; i < size - step - 1; ++i) {

            // Compara los elementos adyacentes
            // Y los cambia de posición si elemento 1 es mayor a elemento 2
            if (array[i] > array[i + 1]) {

                // Intercambia los elementos de posición
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}

// Imprime el valor del arreglo
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << " " << array[i];
    }
    cout << "\n";
}

int main() {
    int data[] = {-2, 45, 0, 11, -1};

    // find array's length
    int size = sizeof(data) / sizeof(data[0]);

    bubbleSort(data, size);

    cout << "Sorted Array in Ascending Order:\n";
    printArray(data, size);
}
