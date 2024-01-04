/* 
    Este programa se trata del uso de las variables globales y locales,
    además de la inicialización de las mismas 
*/

#include <iostream>
using namespace std;

int main(){
    int a, b, c;    //Instanciacíon de variables locales

    a = 10;
    b = 20;
    c = a + b;      //Resultado de la suma de dos números enteros

    cout << c;      // Imprime el resultado de la suma en la terminal

    return 0;
}