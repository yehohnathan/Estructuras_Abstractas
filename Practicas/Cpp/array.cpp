/*  En este programa se desea utilizar una función junto con una matriz y generar
    un recorrido de todos los valores sin importar la matriz*/

#include <iostream>
using namespace std;

template <size_t Filas, size_t Columnas>
void imprimirMatriz(const int (&matriz)[Filas][Columnas]) {
    for (size_t i = 0; i < Filas; ++i) {
        for (size_t j = 0; j < Columnas; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}


// Forma primitiva:
/* int main() {
    int numMatriz [3][4] = {{1,2,3,4},{8,9,10,11},{101,102,103,104}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << numMatriz[i][j] << " ";
        }
        cout << "\n";
    }
} */

// Utilizando librerías:
int main() {
    int numMatriz [3][4] = {{1,2,3,4},{8,9,10,11},{101,102,103,104}};
    int numMatri2 [3][5] = {{1,2,3,4,8},{8,9,10,11,89},{101,102,103,104,555}};
    imprimirMatriz(numMatriz);
    imprimirMatriz(numMatri2);
}

/*
    const: es una palabra clave en C++ que se utiliza para declarar constantes o indicar que
    una variable no puede ser modificada después de su inicialización.

    auto: es una característica introducida en C++11 que permite que el compilador deduzca
    automáticamente el tipo de una variable en función de su inicialización. Esto puede
    hacer que el código sea más conciso y menos propenso a errores tipográficos al evitar
    la repetición del tipo de datos.

    & asegura que los elementos de fila no se modificarán dentro del bucle.
*/