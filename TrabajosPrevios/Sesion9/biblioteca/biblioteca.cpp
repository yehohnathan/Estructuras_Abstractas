#include <iostream>
#include "biblioteca.hpp"

// Función agregar libro que funciona como contructor
void Biblioteca::agregarLibro(
    const std::string& titulo,
    const std::string& autor
) {
    // Vector que almacena la info
    catalogo.emplace_back(titulo, autor);
}

// Función que muestra el catalogo de libros, llamando un miembro publico
// de la clase Libro
void Biblioteca::mostrarCatalogo() {
    for (const auto& libro : catalogo) {
        libro.mostrarInfo();
    }
}

