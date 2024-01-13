#include <iostream>
#include "estudiante.hpp"

int main() {
    // Se crea un objeto llamado estudiante
    Estudiante estudiante("Juan", 20);

    // Se llama a una función que esta dentro de la clase
    estudiante.mostrarDatos();
    return 0;
}
