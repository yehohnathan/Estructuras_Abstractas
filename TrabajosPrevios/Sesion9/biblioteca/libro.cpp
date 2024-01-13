#include <iostream>
#include "libro.hpp"

// Implementación del contructor
Libro::Libro(
    const std::string& titulo, const std::string& autor
) : titulo(titulo), autor(autor) {}

// Función que muestra la información del posible objeto ingresado
void Libro::mostrarInfo() const {
    std::cout << "Titulo: " << titulo << ", Autor: " << autor << std::endl;
}
