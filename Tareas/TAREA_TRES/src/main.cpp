#include "Matriz.hpp"
#include "OperacionesBasicas.hpp"
#include "OperacionCompleja.hpp"
#include "ValidaCorreo.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

/* Operaciones con matrices */
void problema1();
/* Validador de correos electrónicos */
void problema2();

int main(){
    /* Se crea el ménu para que el usuario pueda acceder al Problema 1 o al Problema 2*/
    cout << "\nPara ejecutar al Problema 1 o al Problema 2, ingrese un numero entero:"
         << "\nIngresar 1 ejecuta el Problema 1: operaciones con matrices."
         << "\nIngresar 2 ejecuta el Problema 2: expresiones regulares, valida los correos electronicos.\n";

    /* Se crea la variable entera que contiene la opción ingreasada por el usuario */
    int opcion;

    /* Se hace un ciclo while para que el usuario ingrese opciones hasta que sea correcta */
    while (1) {
        try {
            cout << "\nIngrese una opcion: ";
            cin >> opcion;

            /* Si el dato ingresado es incorrecto se vuelve a solicitar el ingreso */
            if (cin.fail()) {
                /* Limpia el estado de error*/
                cin.clear();
                /* Descarta caracteres no deseados hasta alcanzar el salto de línea */
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Error: No se ingreso un numero.");
            }
            else if (opcion == 1) {   
                cout << "A continuacion se le solicita configurar las matrices:" << endl;
                problema1();
                break;
            }
            else if (opcion == 2) {   
                cout << "A continuacion se le muestra el uso de expresiones regulares:" << endl;
                problema2();
                break;
            }
            else {
                /* Descarta caracteres no deseados hasta alcanzar el salto de línea */
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Error: No se ingreso un numero dentro de las opciones disponibles.");
            }
        }
        catch(const exception& e) {
            cerr << e.what() << '\n';
        }  
    }

    cout << "\n================================== FIN DEL PROGRAMA ==================================\n" << endl;
    return 0;
}

/* Función que encapsula todo que hace que Problema 1 funciones perfectamente */
void problema1(){
    /* Se crean dos objetos de la clase Matriz. Cada objeto debe configurarse antes de ingresarlo
    en el objeto OperacionesBasicas o el objeto OperacionesComplejas */
    Matriz<double> matriz1(true);
    Matriz<double> matriz2(true);

    /* Por defecto, si ambos objetos matriz no son iguales al tipo del objeto de OperacionesBasicas
    o OperacionesComplejas, no se puede usar. Por ello se descarta preguntar si dos matrices son
    iguales antes de ingresarlas con un método a los objetos de OperacionesX */
    
    OperacionesBasicas<double> operacionReal;
    OperacionCompleja<double> operacionCompleja;

    /* Aunque si se pregunta si los objetos matrices son complejos para decidir en qué objeto Operacion
       deben ser ingresador*/

    if ((matriz1.getComplejo() == true) && (matriz2.getComplejo() == true))
    {
        /* Se solicita que se configuren las matrices: */
        cout <<"\n===================Configure el la matriz 1: ===================" << endl;
        matriz1.menuMatriz();
        cout <<"\n===================Configure el la matriz 2: ===================" << endl;
        matriz2.menuMatriz();

        /*Se ingresan las matrices al objeto de Operaciones Basicas */
        operacionCompleja.agregarMatriz(matriz1);
        operacionCompleja.agregarMatriz(matriz2);

        /* Se accede al menú */
        operacionCompleja.menuOperacion();

        
    } 
    else if ((matriz1.getComplejo() == false) && (matriz2.getComplejo() == false ))
    {
        /* Se solicita que se configuren las matrices: */
        cout <<"\n========================= Configure la matriz 1: =========================" << endl;
        matriz1.menuMatriz();
        cout <<"\n========================= Configure la matriz 2: =========================" << endl;
        matriz2.menuMatriz();

        /* Se ingresan las matrices al objeto de Operaciones Basicas*/
        operacionReal.agregarMatriz(matriz1);
        operacionReal.agregarMatriz(matriz2);

        /* Se accede al menú */
        operacionReal.menuOperacion();
    } 
    else {
        cout << "\nUna matriz es de numeros complejos y la otra es de numeros real. No se puede" 
             << " realizar ninguna operacion"<< endl;
    }
}

/* Función que encapsula todo lo que hace que Problema 2 funcione correctamente*/
void problema2(){
    /* Crea un objeto de la clase ValidaCorreo */ 
    ValidaCorreo correos;

    /* Declara una variable de tipo string para almacenar la cadena de texto
    que corresponde al correo electrónico */ 
    string cadena;

    cout << "Ingrese un correo electronico: ";
    /* Se ingresa la cadena de texto que corresponde al correo a validar*/ 
    cin >> cadena;

    /* Usa correos.validador() para validar el valor de la variable como una dirección de correo 
    electrónico válida o no*/ 
    try {
        if (correos.validador(cadena)) {
            cout << "El correo electronico es valido.\n";
        } else {
            cout << "El correo electronico no es valido.\n";
        }
    } catch (invalid_argument& e) {
        cout << e.what() << "\n";
    }
}