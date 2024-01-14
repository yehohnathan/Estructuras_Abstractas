/*
    Gracias al template se puede crear la función "add", la cual no
    tiene parámetros definidos porque se encuentra de forma genérica.
    Esto significa que podría funcionar con cual tipo de parámetro
    a priori.

    Estas funciones con la palabra "template" y en seguida los parámetros
    que va a tener. Se aclará que "typename" es una palabra clave.
*/

#include <iostream>
using namespace std;

template<typename T>
T add(T num1, T num2){
    return (num1 + num2);
}

int main(){
    // Se instancia una varibale entera
    int result1;

    // Se instancia una variable tipo double
    double result2;

    // Llamando al template con parámetros enteros
    result1 = add<int>(2, 3);
    cout << "Suma de enteros (result1): " << result1 << endl;

    // Llamando al template con parámetros double
    result2 = add<double>(2.2, 3.3);
    cout << "Suma de doubles (result2): " << result2 << endl;
}