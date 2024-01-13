#ifndef LIBRO_HPP
#define LIBRO_HPP

#include <string>

// Creación de la clase Libro
class Libro {
    public:
        // Contructor:
        Libro(const std::string& titulo, const std::string& autor);
        void mostrarInfo() const;

    private:    // Valores privados, no heredables
        std::string titulo;
        std::string autor;
};

#endif
