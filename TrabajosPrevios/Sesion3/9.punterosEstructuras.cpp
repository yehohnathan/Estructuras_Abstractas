/*
    Mezcla de punteros con estructuras
*/

#include <iostream>
using namespace std;

void temperatura();
void distancia();

struct temp{
    int i;
    float f;
};

struct Distance
{
    int feet;
    float inch;
};

int main() {
    temperatura();
    distancia();

    return 0;
}

void temperatura(){
    // Declaración de una variable de tipo temp
    temp miObjeto;

    // Declaración de un puntero a temp y asignación para que apunte a la dirección de miObjeto
    temp *ptr = &miObjeto;

    // Asignación de valores a los miembros de temp a través del puntero
    ptr->i = 42;        //Esto es igual a hacer (*ptr).i
    ptr->f = 3.14;

    // Acceso a los valores a través del puntero
    cout << "Valor de i: " << ptr->i << endl;
    cout << "Valor de f: " << ptr->f << endl;
}

void distancia(){
    Distance *ptr, d;
    ptr = &d;

    cout << "\nEnter feet: ";
    cin >> ptr->feet;
    cout << "Enter inch: ";
    cin >> ptr->inch;

    cout << "Displaying information." << endl;
    cout << "Distance = " << ptr->feet << " feet " << ptr->inch << " inches" << endl;

}
