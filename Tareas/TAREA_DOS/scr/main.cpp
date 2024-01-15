#include <iostream>
#include "Libro.hpp"
#include "Noticia.hpp"
#include "Pelicula.hpp"
using namespace std;

/* El presente código es una prueba para la clase madere MaterialLectura*/
int main() {
    /* Se cera un objeto utilizando memoria dinámica de la clase derivada Libro*/
    Libro* ptr_libro =  new Libro("Orgullo y prejuicio (Spanish Edition) ", "1", "Libro", 
                                  "Jane Austen", "Portal Libros", "Romance", "Disponible", 
                                  354, 11.99, " Aqui va toda la informacion adicional del libro");

    ptr_libro->mostrarInfo();

    ptr_libro->sizeLibro();

    /* Se cera un objeto utilizando memoria dinámica de la clase derivada Noticia*/
    Noticia* ptr_noticia =  new Noticia("Choque de dos vehiculos", "2", "Noticia", "Patricio Estrella", 
                                        "Canal 11", "Ultima Hora", "Reservado", 
                                        2, 6.00, " Aqui va toda la informacion adicional de la noticia");

    ptr_noticia->mostrarInfo();

    ptr_noticia->sizeNoticia();

    /* Se cera un objeto utilizando memoria dinámica de la clase derivada Noticia*/
    Pelicula* ptr_pelicula =  new Pelicula("La guerra de los mundos", "3", "Steven Spielberg", "Pelicula",
                                         "Ficcion", 120, "Prestado", 5.99 ,
                                         "Informacion adicional de la pelicula");

    ptr_pelicula->mostrarInfo();

    ptr_pelicula->durationPelicula();

    /* Libera espacio de la memoria*/
    delete ptr_libro;
    delete ptr_noticia;
    delete ptr_pelicula;
}