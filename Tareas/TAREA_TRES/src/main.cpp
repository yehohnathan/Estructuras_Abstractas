#include "Matriz.hpp"
#include "OperacionesBasicas.hpp"
#include "OperacionCompleja.hpp"
#include "ValidaCorreo.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

/* Operaciones con matrices */
void problema1();
void seleccionMatriz(OperacionesBasicas<int>& operacion1, OperacionesBasicas<double>& operacion2,
                     OperacionCompleja<int>& operacionCompleja1, OperacionCompleja<double>& operacionCompleja2);
template <typename T>
void ingresarMatriz(OperacionesBasicas<T>& operacion, OperacionCompleja<T>& operacionCompleja);

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

/* Función que encapsula todo que hace que Problema 1 funciones perfectamente */
void problema1(){
    /* Se instancian los objetos de OperacionesBasicas y OperacionesBasicas*/
    OperacionesBasicas<int> operacion1;
    OperacionesBasicas<double> operacion2;

    OperacionCompleja<int> operacionCompleja1;
    OperacionCompleja<double> operacionCompleja2;

    cout << "\nIngrese el tipo de dato para la matriz 1:\n"
         << "1. Entero\n"
         << "2. Double\n";

    seleccionMatriz(operacion1, operacion2, operacionCompleja1, operacionCompleja2);

    cout << "\nIngrese el tipo de dato para la matriz 2:\n"
         << "1. Entero\n"
         << "2. Double\n";

    seleccionMatriz(operacion1, operacion2, operacionCompleja1, operacionCompleja2);

    /* Se accede a cada menu de Operación */
    operacion1.menuOperacion();
    operacion2.menuOperacion();
    operacionCompleja1.menuOperacion();
    operacionCompleja2.menuOperacion();

    if(operacion1.getValidar() == false && operacion1.getValidar() == false &&
       operacionCompleja1.getValidar() == false && operacionCompleja2.getValidar() == false){
        cout << "\nLas matrices ingresadas no eran de las mismas dimensiones o no eran"
             << " del mismo tipo." << endl;
    }
}

/* Aquí se selecciona si la matriz es entera o double */
void seleccionMatriz(OperacionesBasicas<int>& operacion1, OperacionesBasicas<double>& operacion2,
                     OperacionCompleja<int>& operacionCompleja1, OperacionCompleja<double>& operacionCompleja2) {
    int opcion;

    while (true) {
        try {
            cout << "Ingrese una opcion: ";
            cin >> opcion;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Error: No se ingreso un numero.");
            }

            if (opcion != 1 && opcion != 2) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Error: Opcion invalida. Ingrese 1 o 2.");
            }

            /* Decide a qué objeto ingresar*/
            if (opcion == 1) {
                ingresarMatriz(operacion1, operacionCompleja1);
            } else {
                ingresarMatriz(operacion2, operacionCompleja2);
            }
            break; 
        } catch (const exception& e) {
            cerr << e.what() << '\n';
        }
    }
}

/* Aquí se selecciona si la matriz es real o compleja */
template <typename T>
void ingresarMatriz(OperacionesBasicas<T>& operacion, OperacionCompleja<T>& operacionCompleja) {
    int opcionTipoMatriz;
    
    cout << "Ingrese el tipo de matriz:\n"
         << "1. Real\n"
         << "2. Compleja\n" << endl;

    while (true) {
        try {
            cout << "Ingrese una opcion: ";
            cin >> opcionTipoMatriz;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Error: No se ingreso un numero.");
            }

            if (opcionTipoMatriz != 1 && opcionTipoMatriz != 2) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Error: Opcion invalida. Ingrese 1 o 2.");
            }

            /* Se guardan dependiendo de la selección utilizada */
            if (opcionTipoMatriz == 1) {
                /* Matriz real */
                Matriz<T> matriz(false);
                matriz.menuMatriz();
                operacion.agregarMatriz(matriz);
            } else {
                /* Matriz compleja */
                Matriz<T> matriz(true);
                matriz.menuMatriz();
                operacionCompleja.agregarMatriz(matriz);
            }

            break; // Salir del bucle while
        } catch (const exception& e) {
            cerr << e.what() << '\n';
        }
    }
}