/*
    Si hay una sobreescritura de metodos a la hora de realizar herencia de clases,
    el último método escrito es que definitivo.

    En esta caso, la clase Derivada de clase Base utiliza el método print instanciado
    dentro de ella misma; a no sér que se utilice simbología de 4 puntitos.
*/

#include <iostream>
using namespace std;

class Base {
public:
    void print() {  // Método imprimir
        cout << "Base Function" << endl;
    }
};

class Derived : public Base {
public:
    void print() {  // Método final que usará esta clase
        cout << "Derived Function" << endl;
    }
};

int main() {
    Derived derived1, derived2;
    derived1.print();

    // Una forma de acceder al primer método de print de clase Base
    derived2.Base::print();

    return 0;
}
