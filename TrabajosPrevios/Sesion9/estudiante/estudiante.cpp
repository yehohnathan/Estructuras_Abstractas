/*
    Implementación de los miembros del header
*/

#include <iostream>
#include "estudiante.hpp"

// Instancia del constructor
Estudiante::Estudiante(
    const std::string& nombre, int edad
) : nombre(nombre), edad(edad) {}

// función que muestra el nombre y la edad
void Estudiante::mostrarDatos() {
    std::cout << "Nombre: " << nombre;
    std::cout << ", Edad: " << edad << std::endl;
}
