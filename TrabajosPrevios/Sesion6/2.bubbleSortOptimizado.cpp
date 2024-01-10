/*
    Código obtimizado del bubble sort, en donde si no es necesario realizar
    un intercambio de valores gracias a la variable "swapped"
*/

#include <iostream>
using namespace std;

void bubbleSort(int array[], int size) {

    // Ciclo para acceder a cada elemento del array
    for (int step = 0; step < (size -1); ++step) {

        // Se crea variable para verificar si se intercambiaron valores
        int swapped = 0;

        // Ciclo para comparar el elemento 1 frente al elemento 2 adyacente
        for(int i = 0; i < (size-step-1); ++i) {

            // Compara los elementos adyacentes
            // Y los cambia de posición si elemento 1 es mayor a elemento 2
            if (array[i] > array[i + 1]) {

                // Intercambia los elementos de posición
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                swapped = 1;    // Hubo un intercambio
            }
        }

        // Si swapped es 0, ya el algortimo esta ordenado
        if(swapped == 0)
            break;
    }
}

// print an array
void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << " " << array[i];
    }
    cout << "\n";
}

int main() {
    int data[] = {-2, 45, 0, 11, -1};

    int size = sizeof(data) / sizeof(data[0]);

    bubbleSort(data, size);

    cout << "Sorted Array in Ascending Order:\n";
    printArray(data, size);
}

/*
    Se puede utilizar la sumatorio de Gauss:
    (n-1) + (n-2) + ... + 1 = n(n-1)/2

    Complejidad:
    Mejor -> lineal O(n)
    Promedio: -> exponencial O(n^2) 
    Peor: -> exponencial O(n^2) 
*/