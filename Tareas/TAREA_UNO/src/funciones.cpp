#include "funciones.hpp"
#include <iostream>
using namespace std;

void menuJuego(){
    cout << "\n----------------------------------- MENU: Adivina el entero -----------------------------------" << endl;
    cout << "El numero indica la dificultad: " << endl;
    cout << "1. Dificultad Normal: Si no logras adivinar el numero entero en el primer intento," << endl;

    cout << "   recibiras indicaciones sobre si el numero ingresado es menor o mayor al esperado.\n" << endl;

    cout << "2. Dificultad Dificil: Si no logras adivinar el numero entero en el primer intento," << endl;
    cout << "   recibiras indicaciones. Estaras CONGELADO si el valor ingresado esta muy lejos del esperado," << endl;
    cout << "   FRIO si el valor ingresado esta lejos del esperado, CALIENTE si esta cerca del esperado," << endl;
    cout << "   e HIRVIENDO si el valor ingresado esta muy cerca del esperado.\n" << endl;
}

void dificultad(){
    int opcion;
    cout << "Selecciona la dificultad ingresas 1 o 2: ";
    cin >> opcion;
}