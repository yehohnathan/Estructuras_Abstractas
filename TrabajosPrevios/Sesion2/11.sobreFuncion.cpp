/*
    El uso de varias funciones pero con el mismo nombre, sobrecarga.
*/


#include <iostream>
using namespace std;

float absolute(float var){
    if (var < 0.0){
        var = -var;
    }
    return var;
}

int absolute(int var){
    if (var < 0){
        var = -var;
    }
    return var;
}

void display(int var1, double var2){
    cout << "Numero entero: " << var1;
    cout <<  " y numero double: " << var2 << endl;
}

void display(double var){
    cout << "Numero double: " << var << endl;
}

void display(int var){
    cout << "Numero entero: " << var << endl;
}


int main(){
    cout << "El valor absoluto de -5 = " << absolute(-5) << endl;
    cout << "El valor absoluto de -5.5 = " << absolute (5.5f) << endl;
    
    int a = 5;
    double b = 5.5;

    display(a);     // Función con valor entero
    display(b);     // Función con valor double
    display(a,b);   // Función con valores enteros y double
    return 0;
}

/*  
    Las funciones con valores por defecto prefiero no agregarlas dentro del código pero
    mi apreciación consiste en estos 2 puntos:

        1. Los valores por defecto deben ser declarados al final add(int a, int b, int c = 3)
        2. Es un poco mejor usar instanciación local de variables para evitar conflictos :/
*/