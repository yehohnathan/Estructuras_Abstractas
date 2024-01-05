/*
    Uso de punteros junto con las funciones
*/

#include <iostream>
using namespace std;

void func1(int numVal){}    // Función que toma el valor del parámetro

void func2(int &numRef){}   // Función que toma la dirección del parámetro

void swapSinPtr(int &n1, int &n2){
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

void swapConPtr(int* n1, int* n2){
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main(){
    // Paso de parámetros por referencia sin punteros
    int a = 1, b = 2;

    cout << "Before swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;  

    swapSinPtr(a, b);

    cout << "After swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;  

    // Paso de parámetros por referencia con punteros
    a = 1;
    b = 2;

    cout << "\nBefore swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;  

    swapConPtr(&a, &b);

    cout << "After swapping" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;  

}