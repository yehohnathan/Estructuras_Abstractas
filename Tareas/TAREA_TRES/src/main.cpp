#include "Matriz.hpp"
#include "OperacionesBasicas.hpp"
#include "OperacionCompleja.hpp"
#include "ValidaCorreo.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

/** @defgroup Problema1 Operaciones con matrices
 * @{
 */

/**
 * @brief Función principal que encapsula todo para que el Problema 1 funcione correctamente.
 */
void problema1();

/**
 * @brief Función que permite al usuario seleccionar el tipo de matriz (entera o double) para las operaciones.
 * @param operacion1 Objeto de la clase OperacionesBasicas para matrices enteras.
 * @param operacion2 Objeto de la clase OperacionesBasicas para matrices double.
 * @param operacionCompleja1 Objeto de la clase OperacionCompleja para matrices complejas enteras.
 * @param operacionCompleja2 Objeto de la clase OperacionCompleja para matrices complejas double.
 */

void seleccionMatriz(OperacionesBasicas<int>& operacion1, OperacionesBasicas<double>& operacion2,
                     OperacionCompleja<int>& operacionCompleja1, OperacionCompleja<double>& operacionCompleja2);

/**
 * @brief Función que permite al usuario ingresar el tipo de matriz (real o compleja) para las operaciones.
 * @tparam T Tipo de dato de la matriz (int o double).
 * @param operacion Objeto de la clase OperacionesBasicas para matrices reales o complejas.
 * @param operacionCompleja Objeto de la clase OperacionCompleja para matrices complejas reales o complejas.
 */
template <typename T>
void ingresarMatriz(OperacionesBasicas<T>& operacion, OperacionCompleja<T>& operacionCompleja);

/** @} */

/** @defgroup Problema2 Validador de correos electrónicos
 * @{
 */

/**
 * @brief Función principal que encapsula todo para que el Problema 2 funcione correctamente.
 */
void problema2();

/** @} */

/**
 * @brief Implementación de la función principal del programa.
 * @details Se crea un menú para que el usuario pueda acceder al Problema 1 o al Problema 2.
 *          Se manejan excepciones para validar la entrada del usuario.
 * @return 0 si el programa se ejecuta con éxito.
 */
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

/**
 * @brief Implementación de la función que encapsula todo para que el Problema 2 funcione correctamente.
 * @details Crea un objeto de la clase ValidaCorreo, solicita al usuario que ingrese un correo electrónico
 *          y utiliza el validador para verificar si es válido o no. Maneja excepciones.
 */
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

/**
 * @brief Implementación de la función que encapsula todo para que el Problema 1 funcione correctamente.
 * @details Se instancian objetos de las clases OperacionesBasicas y OperacionesComplejas,
 *          se solicita al usuario que ingrese el tipo de dato para las matrices, y se realiza
 *          operaciones según la selección del usuario. Se manejan excepciones para validar la entrada.
 */
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

/**
 * @brief Implementación de la función que permite al usuario seleccionar el tipo de matriz (entera o double) para las operaciones.
 * @details Se utiliza un bucle while para manejar la entrada del usuario y se llama a la función ingresarMatriz.
 * @param operacion1 Objeto de la clase OperacionesBasicas para matrices enteras.
 * @param operacion2 Objeto de la clase OperacionesBasicas para matrices double.
 * @param operacionCompleja1 Objeto de la clase OperacionCompleja para matrices complejas enteras.
 * @param operacionCompleja2 Objeto de la clase OperacionCompleja para matrices complejas double.
 */
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

/**
 * @brief Implementación de la función que permite al usuario ingresar el tipo de matriz (real o compleja) para las operaciones.
 * @details Se utiliza un bucle while para manejar la entrada del usuario y se agrega la matriz correspondiente al objeto operacion o operacionCompleja.
 * @tparam T Tipo de dato de la matriz (int o double).
 * @param operacion Objeto de la clase OperacionesBasicas para matrices reales o complejas.
 * @param operacionCompleja Objeto de la clase OperacionCompleja para matrices complejas reales o complejas.
 */
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