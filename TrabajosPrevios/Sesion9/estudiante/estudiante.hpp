#ifndef ESTUDIANTE_HPP
#define ESTUDIANTE_HPP
#include <string>

// Se crea una clase llamanda Estudiante:
class Estudiante {
    public: // Miembros publicos
        // Contructor:
        Estudiante(const std::string& nombre, int edad);

        // Instancia de una función
        void mostrarDatos();

    private:    // Miembros privados
        std::string nombre;
        int edad;
        int edad2;
};

#endif
