#include "funciones.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

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
        dificultadDificil(valores);
        break;
    
    default:
        cout << "No ingresaste un valor valido" << endl;
        break;
    }

    cout << "\n-------------------------------------- FIN DEL PROGRAMA ---------------------------------------" << endl;       
}

void dificultadNormal(ValorObtenido valores){
    // Ingresa el intervalo, obtiene el valor deseado y número de intentos
    intervaloValores(valores);

    // Se instancia la variable que contiene el intento del usuario
    int intento;

    // While que se repite hazta que el usuario gane o pierda (n_intentos = 0)
    while (valores.n_intentos != 0)
    {
        // Al inicio de cada ciclo while se le pide al usuario que adivide un número,
        // su intento será colocado en la variable intento.
        cout << "\nAdivina el valor deseado: ";
        cin >> intento;

        if (intento == valores.valorDeseado)    // Adivino el número
        {
            cout << "\nFelicidades, encontraste adivinaste el numero buscado!!!" << endl;
            break;  // Realiza un break para salir del ciclo while
        }
        else if (intento > valores.valorDeseado) 
        {   // Se le pide al usuario que intente con un número menor
            cout << "El numero buscado es menor" << endl;
            valores.n_intentos--;   // Se le resta 1 a n_intentos
        }
        else
        {   // Se le pide al usuario que intente con un número mayor
            cout << "El numero buscado es mayor" << endl;
            valores.n_intentos--;   // Se le resta 1 a n_intentos
        }
    }

    // Terminado el ciclo while, con n_interos = 0, significa que si intento es diferente
    // a valor deseado, entonces no se encontró el valor deseado.
    if (intento != valores.valorDeseado)
    {
        // Le muestra al usuario el mensaje de pérdida y el valor deseado.
        cout << "\nLo siento mucho pero haz perdido :<" << endl;
        cout << "Valor deseado: " << valores.valorDeseado <<endl;
    }

}

void dificultadDificil(ValorObtenido valores){
    // Ingresa el intervalo, obtiene el valor deseado y número de intentos
    intervaloValores(valores);
    // Se instancia la variable que contiene el intento del usuario
    int intento;

    // While que se repite hazta que el usuario gane o pierda (n_intentos = 0)
    while (valores.n_intentos != 0)
    {
        // Al inicio de cada ciclo while se le pide al usuario que adivide un número,
        // su intento será colocado en la variable intento.
        cout << "\nAdivina el valor deseado: ";
        cin >> intento;

        if (intento == valores.valorDeseado)    // Adivino el número
        {
            cout << "\nFelicidades, encontraste adivinaste el numero buscado!!!" << endl;
            break;  // Realiza un break para salir del ciclo while
        }
        else if (abs(intento - valores.valorDeseado) >= 15){
            // Si la resta en valor absoluto es mayor a 20, significa que intento
            // esta muy lejos de ser el valor deseado.
            cout << "CONGELADO! Muy lejos del numero buscado." << endl;
            valores.n_intentos--;   // Se le resta 1 a n_intentos
        }
        else if (abs(intento - valores.valorDeseado) >= 10){
            // Si la resta en valor absoluto es mayor a 15, significa que intento
            // esta lejos de ser el valor deseado.
            cout << "FRIO! Lejos del numero buscado." << endl;
            valores.n_intentos--;   // Se le resta 1 a n_intentos
        }
        else if (abs(intento - valores.valorDeseado) >= 5){
            // Si la resta en valor absoluto es mayor a 10, significa que intento
            // esta cerca de ser el valor deseado.
            cout << "CALIENTE! Un poco cerca del numero buscado." << endl;
            valores.n_intentos--;   // Se le resta 1 a n_intentos
        }
        else{
            // Si se llega a este punto, significa que el intento es menor a 10, por
            // lo que se esta muy cerca del valor deseado.
            cout << "HIERVIENDO! Cerca del numero buscado." << endl;
            valores.n_intentos--;   // Se le resta 1 a n_intentos
        }
    }

    // Terminado el ciclo while, con n_interos = 0, significa que si intento es diferente
    // a valor deseado, entonces no se encontró el valor deseado.
    if (intento != valores.valorDeseado)
    {
        // Le muestra al usuario el mensaje de pérdida y el valor deseado.
        cout << "\nLo siento mucho pero haz perdido :<" << endl;
        cout << "Valor deseado: " << valores.valorDeseado <<endl;
    }
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