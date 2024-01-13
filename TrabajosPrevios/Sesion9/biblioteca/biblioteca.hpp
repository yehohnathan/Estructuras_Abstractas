#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <vector>
#include "libro.hpp"

// Se crea una clase llama Biblioteca
class Biblioteca {
    public:     // Se instancias los miembros publicos, se pueden heredar.
        void agregarLibro(      // Función miembro
            const std::string& titulo,  // Valor con referencia a un string 
            const std::string& autor    // Valor con referencia a un string 

        );
        void mostrarCatalogo(); // Función miembro

    private:    // Instancia del unico miembro privado, no heredable.
        std::vector<Libro> catalogo;
    };

#endif
