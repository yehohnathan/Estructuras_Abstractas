/*
    Las funciones virtuales es una función miembro en la clase base que esperamos
    redifinir en clases derivadas.

    Se usa una función virtual en la clase base para garantizar que la función se
    invalide
*/

#include <iostream>
using namespace std;

class Base {
public:
    virtual void print() {  // Se pone acá para que el usuario cuando use Herencia
                            // la sobreescriba si o si. De no hacerlo, el compilador se queja.
        cout << "Base Function" << endl;
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "Derived Function" << endl;
    }
};

int main() {
    Derived derived1;

    // Otra forma de utilizar punteros con clases y objetos
    Base* base1 = &derived1;

    // calls member function of Derived class
    base1->print();

    return 0;
}
