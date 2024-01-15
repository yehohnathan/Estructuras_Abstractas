#include <iostream>
#include "MaterialLectura.hpp"
using namespace std;

/* El presente código es una prueba para la clase madere MaterialLectura*/
int main() {
    /* Se cera un objeto utilizando memoria dinámica*/
    MaterialLectura* ptr_libro =  new MaterialLectura("Orgullo y prejuicio (Spanish Edition) ", "1", "Libro", 
                                                      "Jane Austen", "Portal Libros", 
                                                      "Romance", "Disponible", 354, 11.99);

    ptr_libro->mostrarInfo();

    delete ptr_libro;
}