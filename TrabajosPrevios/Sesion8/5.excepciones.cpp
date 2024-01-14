/*
    Las excepciones son eventos ajenos al Happy Path y para prevenir esto se utilizan
    los bloques de código: try, throw, catch
*/

#include <iostream>
using namespace std;

int main() {
    // Se declaran las varibles utilizadas para realizar una división
    double numerator, denominator, divide;

    // Se solicita al usuario el ingreso del número que será el numerador de la división
    cout << "Enter numerator: ";
    cin >> numerator;

    // Se solicita al usuario el ingreso del número que será el denominador de la división
    cout << "Enter denominator: ";
    cin >> denominator;

    // Se crea el código que puede generar una excepción
    try { 
        // throw an exception if denominator is 0
        if (denominator == 0)
            throw 0;    // Le regresa un 0 y brinca al bloque catch

        // not executed if denominator is 0
        divide = numerator / denominator;
        cout << numerator << " / " << denominator << " = " << divide << endl;
    }

    // Maneja la excepción lanzada por el throw
    catch (int num_exception) {
        cout << "Error: Cannot divide by " << num_exception << endl;
    }

    return 0;
}
