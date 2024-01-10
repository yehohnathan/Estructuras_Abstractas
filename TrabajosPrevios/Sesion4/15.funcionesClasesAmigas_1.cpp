/*
    Las funciones amigas son métodos que sirven para suavizar los
    miembros privados de una clase para utilizarlos.
*/


#include <iostream>
using namespace std;

class Distance {
    private:
        int meter;
    
    // friend function, definición para acceder a la privada
    friend int addFive(Distance);
    
    public:
        // Contructor:
        Distance() : meter(0) {}
};

// Esta esta función amiga, y dentro de ella hago el objeto Distance d
int addFive(Distance d) {
    // accessing private members from the friend function
    d.meter += 5;
    return d.meter;
}

int main() {
    Distance D;
    // Imprime a traves de addFive(D) el valor de meter que es un miembro privado de la clase
    cout << "Distance: " << addFive(D);
    return 0;
}
