#include <iostream>
#include "MaterialLectura.hpp"
#include "MaterialAudiovisual.hpp"
using namespace std;

/* El presente código es una prueba para la clase madere MaterialLectura*/
int main() {
    /* Se cera un objeto utilizando memoria dinámica*/
    MaterialLectura* ptr_libro =  new MaterialLectura("Orgullo y prejuicio (Spanish Edition) ", "1", "Libro", 
                                                      "Jane Austen", "Portal Libros", 
                                                      "Romance", "Disponible", 354, 11.99);

    ptr_libro->mostrarInfo();

    MaterialAudiovisual* ptr_pelicula =  new MaterialAudiovisual("Orgullo y prejuicio", "1", "Pelicula", 
                                                                 "Joe Wright", "129 minutos", 
                                                                 "Drama romantico", "Disponible", 8.39);

    ptr_pelicula->mostrarInfo();

    /* Libera espacio de la memoria*/
    delete ptr_libro;
    delete ptr_pelicula;
}