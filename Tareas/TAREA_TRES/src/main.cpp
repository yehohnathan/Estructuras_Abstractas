#include "Matriz.hpp"
#include "OperacionesBasicas.hpp"
#include <iostream>
#include <typeinfo> /* Para averiguar el tipo de dato que es una matriz */
using namespace std;

int main(){
    
    /* Se crean dos objetos de la clase Matriz. Cada objeto debe configurarse antes de ingresarlo
    en el objeto OperacionesBasicas o el objeto OperacionesComplejas */
    Matriz<int> matriz1(false);
    Matriz<int> matriz2(false);

    /* Por defecto, si ambos objetos matriz no son iguales al tipo del objeto de OperacionesBasicas
    o OperacionesComplejas, no se puede usar. Por ello se descarta preguntar si dos matrices son
    iguales antes de ingresarlas con un método a los objetos de OperacionesX */
    
    OperacionesBasicas<int> operacionReal;
    // OperacionesComplejas<int> operacionCompleja;

    /* Aunque si se pregunta si los objetos matrices son complejos para decidir en qué objeto Operacion
       deben ser ingresador*/

    if ((matriz1.getComplejo() == true) && (matriz2.getComplejo() == true))
    {
        /* 
        Se solicita que se configuren las matrices: 
        cout <<"\n===================Configure el la matriz 1: ===================" << endl;
        matriz1.menuMatriz();
        cout <<"\n===================Configure el la matriz 2: ===================" << endl;
        matriz1.menuMatriz();

        Se ingresan las matrices al objeto de Operaciones Basicas
        operacionCompleja.agregarMatriz(matriz1);
        operacionCompleja.agregarMatriz(matriz2);

        */
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
    } 
    else {
        cout << "\nUna matriz es de numeros complejos y la otra es de numeros real. No se puede" 
             << " realizar ninguna operacion"<< endl;
    }
    
    operacionReal.menuOperacion();
    
    return 0;
}
