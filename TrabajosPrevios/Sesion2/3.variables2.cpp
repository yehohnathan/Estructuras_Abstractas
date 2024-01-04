/* 
    Este programa se trata del uso de las variables globales y locales,
    además de la inicialización de las mismas 
*/

#include <iostream>
using namespace std;

int g;              //Instanciacíon de variable global

int main(){
    int a, b;    //Instanciacíon de variables locales

    a = 10;
    b = 20;
    g = a + b;      //Resultado de la suma de dos números enteros

    cout << g;      // Imprime el resultado de la suma en la terminal

    return 0;
}