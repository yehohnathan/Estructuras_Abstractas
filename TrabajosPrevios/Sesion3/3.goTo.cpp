/*
    Lo más parecido a un salto jal de RISC o un salto con direccionamiento de 
    offset constante de CISC.

    Este programa se encarga de calcular el valor promedio de n cantidad de
    numeros (entradas) dadas por el usuario.
*/

#include <iostream>
using namespace std;

int main() {
    float num, average, sum = 0.0;
    int i, n;

    cout << "Maximum number of inputs: ";
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        cout << "Enter n" << i << ": ";
        cin >> num;

        if(num < 0.0){
            // Si el valor ingresado es necativo sale del for
            // y no se toma en cuenta en el promedio.
            goto jump;
        }
        sum += num;
    }

    jump:
        average = sum/(i-1);
        cout << "\nAverage = " << average;
        return 0;
}