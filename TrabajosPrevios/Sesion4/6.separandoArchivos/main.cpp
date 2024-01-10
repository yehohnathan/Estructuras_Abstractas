#include <iostream>
#include "personas.hpp"

using namespace std;

int main() {
    Persona p("Juan", 25);  // Esto pasa por el contructor Persona::Persona(string nombre, int edad)

    cout << "Nombre: " << p.getNombre() << endl;
    cout << "Edad: " << p.getEdad() << endl;

    p.setEdad(26);  // Le cae encima a la edad de 25

    // Acá debería imprimir la nueva edad ingresas p.setEdad(26)
    cout << "Nueva edad: " << p.getEdad() << endl;
    
    return 0;
}
