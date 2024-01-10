/*
    SelectionSort es otro algortimo de ordenamiento que recorre un arreglo y 
    selecciona el elemento más pequeño y lo coloca en la posición correcta.
    En donde se hace un swap entre el elemento más pequeño y el elemento de la
    posición cero; se repite esto pero intercambiando la posición x.
*/

#include <iostream>
using namespace std;

// Se crea una función llamada intercambiar valores, utilizando punteros
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funcion de imprimi
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selectionSort(int array[], int size) {
    // Itera desde el cero hasta el tamaño - 1
    for (int step = 0; step < size - 1; ++step) {
        int min_idx = step; // El indice menor cambia

        for (int i = step + 1; i < size; i++) {
            // Se empieza en el indice sted + 1
            if (array[i] < array[min_idx])  // Sin llaves por tener una sola instrucción
            min_idx = i;    // Se actualiza el indice del elemento menor
        }

        // Va a la función para hacer swap
        swap(&array[min_idx], &array[step]);
    }
}

// Código de prueba
int main() {
    int data[] = {20, 12, 10, 15, 2};

    int size = sizeof(data) / sizeof(data[0]);

    selectionSort(data, size);

    cout << "Sorted array in Ascending Order:\n";

    printArray(data, size);
}

/*
    Tiempo de complejidad:
    Best:       O(n^2)
    Worst:      O(n^2)
    Average:    O(n^2)
*/