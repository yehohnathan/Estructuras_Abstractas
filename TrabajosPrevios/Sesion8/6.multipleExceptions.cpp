/*
    Ejemplo de uso de multiples excepciones mostrado en el video de la clase
*/

#include <iostream>
using namespace std;

int main() {
    double numerator, denominator, arr[4] = {0.0, 0.0, 0.0,};
    int index;

    cout << "Ingrese un indice para el array: ";
    cin >> index;

    try {
        // Lanza una excepción si se pasa del rango del array
        if(index >= 4)
            throw "Error: Array out of bounds!";

        // Como no hubo excepción, index no supera el rango del array
        // Se solicita al usuario el ingreso del número que será el numerador de la división
        cout << "Enter numerator: ";
        cin >> numerator;

        // Se solicita al usuario el ingreso del número que será el denominador de la división
        cout << "Enter denominator: ";
        cin >> denominator;

        // throw an exception if denominator is 0
        if (denominator == 0)
            throw 0;    // Le regresa un 0 y brinca al bloque catch

        // not executed if denominator is 0
        arr[index] = numerator / denominator;
        cout << numerator << " / " << denominator << " = " << arr[index] << endl;
    }

    // catch "Array out of bounds" exception
    catch(const char* msg){
        cout << msg << endl;
    }

    // catch "Divide by 0" exception
    catch (int num) {
        cout << "Error: Cannot divide by" << num << endl;
    }
    return 0;
}