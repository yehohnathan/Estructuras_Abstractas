/*
    Este es un template genérico con una clase que se encarga de multiplicar dos
    números, que pueden ser del tipo diferente de dato gracias a que usa dos 
    parámetros T y U.
*/

#include <iostream>
using namespace std;

// Creo un template con dos parámetros para realizar una multiplicación
template <typename T, typename U>
T multiply(T a, U b){
    return a * b;
}

int main() {
    // Se declara una variable tipo double
    double result;

    // Llamando al template con un parámetro double  T y el otro entero U
    result = multiply<double, int>(5.5, 3.5);
    cout << "Multiplicacion (result): " << result << endl;

}