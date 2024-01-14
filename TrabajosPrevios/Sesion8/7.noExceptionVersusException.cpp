/*
    Este es un ejemplo de una buena práctica frente a una mala práctica de programaciones, 
    en donde se ejemplifica el uso de las excepciones como las buenas prácticas.
*/

#include <iostream>
#include <stdexcept>
using namespace std;

// Esta función es una mala práctica de programación, solo solicito datos sin 
// importar los errores intencionados o sin intencion que puede tener el usuario
void noExceptionEjemplo(){
    // Se declaran las varibles utilizadas para realizar una división
    int numerador, denominador, resultado;

    // Se solicita al usuario el ingreso del número que será el numerador de la división
    cout << "Ingrese el numerador: ";
    cin >> numerador;

    // Se solicita al usuario el ingreso del número que será el denominador de la división
    cout << "Ingrese el denominador: ";
    cin >> denominador;

    // Se guarda la división de numerador y denominador en resultado
    resultado = numerador / denominador;

    // Se imprime el resultado obtenido, unicamente si se siguio el happy path
    cout << "El resultado es: " << resultado << endl;
}

void exceptionEjemplo(){
    // Se declaran las varibles utilizadas para realizar una división
    int numerador, denominador, resultado;

    // Se solicita al usuario el ingreso del número que será el numerador de la división
    cout << "Ingrese el numerador: ";
    cin >> numerador;

    // Se solicita al usuario el ingreso del número que será el denominador de la división
    cout << "Ingrese el denominador: ";
    cin >> denominador;

    // Se guarda la división de numerador y denominador en resultado
    resultado = numerador / denominador;
    
    try {
        if (denominador == 0)   // Si el denominador es cero activa la excepción
            
            // Se utiliza una función llamada de error en tiempo de ejecución
            // para mostar el string
            throw runtime_error("Error! El denominador no puede ser cero.");
        
        // Se guarda la división de numerador y denominador en resultado
        resultado = numerador / denominador;

        // Se imprime el resultado obtenido
        cout << "El resultado es: " << resultado << endl;

    } catch (const exception& e) {  // Nomemclatura especial de excepciones en C++
        cerr << e.what() << endl;   // El .what() me señala el tipo de error que tuve
    }    
}

int main() {
    cout << "\nCon excepction:" << endl;
    exceptionEjemplo();

    cout << "\nSin exception: el programa si no se sigue el happy path" << endl;
    noExceptionEjemplo();

    return 0;
}

