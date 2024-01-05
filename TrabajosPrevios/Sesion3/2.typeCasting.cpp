/*
    El Type Casting se refiere a la conversión explícita de un tipo de dato
    a otro. En muchos lenguajes de programación, incluido C++, hay momentos
    en los que es necesario convertir un tipo de dato a otro, ya sea para
    realizar operaciones específicas o para asignar un valor a una variable 
    de un tipo diferente. Hay dos tipos principales de casting: 
    
    1.Casting implícito: El casting implícito se produce automáticamente por
    el compilador cuando no hay pérdida de información y no se requiere intervención
    del programador.
     
    2.Casting explícito: Se usa cuando hay una pérdida potencial de información o 
    cuando se quiere forzar la interpretación de un tipo de dato de una manera específica.
*/

#include <iostream>
using namespace std;

void implicit(){
    int num_int = 9;    // Se crea una variable entera
    double num_double;  // Se crea una variable flotante de mayor preseción

    num_double = num_int;   //Se realiza una conversión implicita

    cout << "num_int = " << num_int << endl;
    cout << "num_double = " << num_double << endl;
}

void forzada(){
    double num_double = 3.56;   // Se crea una variable flotante de mayor preseción
    cout << "num_double = " << num_double << endl;

    int num_int1 = (int)num_double; // Conversión explicita o forzada con C-Style
    cout << "num_int1 = " << num_int1 << endl;  

    int num_int2 = int(num_double); // Conversión explicita o forzada con function-style
    cout << "num_int2 = " << num_int2 << endl;  

    // No redondea, solo borra lo que haya despues del punto decimal, por lo que se
    // pierde info.

}

int main() {
    implicit();

    forzada();

    return 0;
}

/* 
    Menor a mayor Data Type:
    char > short > int > long > float > double > long double

*/