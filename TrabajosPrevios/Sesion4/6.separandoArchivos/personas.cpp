/*
    En el header se instancia la clase y en la función relacionada
    se hace la lógica del contructor y otros archivos públicos

*/

#include "personas.hpp"
using namespace std;

// Acá va el contructor y utiliza los dos argumentos
Persona::Persona(string nombre, int edad) {
    this->nombre = nombre;  // this hace referencia a la clase Persona
    this->edad = edad;
}

// Con la sixtaxis le dice a qué clase pertenecé
string Persona::getNombre() {
    return nombre;
}

int Persona::getEdad() {
    return edad;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}
