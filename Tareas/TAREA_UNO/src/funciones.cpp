#include "funciones.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

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

void opcionDificultad(ValorObtenido& valores){
    int opcion;
    cout << "Selecciona la dificultad ingresas 1 o 2: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        cout << "\n----------------------------------------- MODO NORMAL -----------------------------------------" << endl;
        dificultadNormal(valores);
        break;

    case 2:
        cout << "\n---------------------------------------- MODO DIFICIL -----------------------------------------" << endl;
        break;
    
    default:
        cout << "No ingresaste un valor valido" << endl;
        break;
    }

    cout << "\n-------------------------------------- FIN DEL PROGRAMA ---------------------------------------" << endl;       
}

void dificultadNormal(ValorObtenido& valores){
    intervaloValores(valores);
    cout << valores.valorDeseado << endl;

    int intento;
    while (valores.n_intentos != 0)
    {
        cout << "Adivina el valor deseado: ";
        cin >> intento;

        if (intento == valores.valorDeseado)
        {
            cout << "\nFelicidades, encontraste adivinaste el numero buscado!!!" << endl;
            break;
        }
        else if (intento > valores.valorDeseado)
        {
            cout << "El numero buscado es menor" << endl;
            valores.n_intentos--;
        }
        else
        {
            cout << "El numero buscado es mayor" << endl;
            valores.n_intentos--;
        }
    }

    if (intento != valores.valorDeseado)
    {
        cout << "\nLo siento mucho pero haz perdido :<" << endl;
    }
    
}

void dificultadDificil(ValorObtenido& valores){
    intervaloValores(valores);
}

void intervaloValores(ValorObtenido& valores){
    // Se pide al usuario el intervalo de valores deseado para los números enteros
    int valor1, valor2;
    cout << "Selecciona el intervalo de posibles numeros enteros." << endl;
    cout << "Elige el primer valor del intervalo: ";
    cin >> valor1;
    cout << "Elige el segundo valor del intervalo: ";
    cin >> valor2;

    // Intercambian valores si valor1 es mayor que valor2
    if (valor1 > valor2) {
        int temp = valor1;
        valor1 = valor2;
        valor2 = temp;
    }

    // Se guarda el valor deseado obtenido
    valores.valorDeseado = valorDeseado(valor1, valor2);

    // Se guarda el numero posible de intentos
    valores.n_intentos = (valor2 - valor1 + 1)/3;
}

int valorDeseado(int num1, int num2){
    // Número de posibles valores para valorDeseado
    int rango = num2 - num1 + 1;

    // Crea una seed para generar números aleatorios
    srand(time(0));

    // Genera un número aleatorio dentro del intervalo
    int numeroAleatorio = num1 + rand() % rango;

    return numeroAleatorio;
}