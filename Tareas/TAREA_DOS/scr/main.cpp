#include <iostream>
#include "Libro.hpp"
using namespace std;

/* El presente código es una prueba para la clase madere MaterialLectura*/
int main() {
    /* Se cera un objeto utilizando memoria dinámica*/
    Libro* ptr_libro =  new Libro("Orgullo y prejuicio (Spanish Edition) ", "1", "Libro", 
                                            "Jane Austen", "Portal Libros", "Romance", "Disponible", 
                                            354, 11.99, " Aqui va toda la informacion adicional del libro");

    ptr_libro->mostrarInfo();

    /* Libera espacio de la memoria*/
    delete ptr_libro;
}