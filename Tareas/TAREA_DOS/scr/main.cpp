#include <iostream>
#include <vector>
#include "Libro.hpp"
#include "Noticia.hpp"
#include "Pelicula.hpp"
#include "Podcast.hpp"
#include "MaterialOrdenado.hpp"
#include "MaterialPrecio.hpp"

using namespace std;

/* El presente código es una prueba para la clase madere MaterialLectura*/
int main() {
    /* Se cera un objeto utilizando memoria dinámica de la clase derivada Libro*/
    Libro* ptr_libro =  new Libro("Orgullo y prejuicio (Spanish Edition)", "1", "Libro", 
                                  "Jane Austen", "Portal Libros", "Romance", "Disponible", 
                                  354, 11.99, " Aqui va toda la informacion adicional del libro");

    /* Se cera un objeto utilizando memoria dinámica de la clase derivada Noticia*/
    Noticia* ptr_noticia =  new Noticia("Choque de dos vehiculos", "2", "Noticia", "Patricio Estrella", 
                                        "Canal 11", "Ultima Hora", "Reservado", 
                                        2, 6.00, " Aqui va toda la informacion adicional de la noticia");

    /* Se cera un objeto utilizando memoria dinámica de la clase derivada Pelicula*/
    Pelicula* ptr_pelicula =  new Pelicula("La guerra de los mundos", "3", "Steven Spielberg", "Pelicula",
                                         "Ficcion", 120, "Prestado", 5.99 ,
                                         "Informacion adicional de la pelicula");

    /* Se cera un objeto utilizando memoria dinámica de la clase derivada Podcast*/
    Podcast* ptr_podcast =  new Podcast("Alex al habla", "4", "Alexelcapo", "Podcast",
                                         "Just Chating", 50, "Disponible", 0.0 ,
                                         "Informacion adicional de la podcast");

    /* Creación de un objeto para material ordenado */
    MaterialOrdenado tienda;
    cout << "\nUso de un objeto de la clase MaterialOrdenado: "<< endl;

    /* Se agregan los materiales a al objeto tienda*/
    tienda.agregarMaterial(ptr_libro);
    tienda.agregarMaterial(ptr_noticia);
    tienda.agregarMaterial(ptr_pelicula);
    tienda.agregarMaterial(ptr_podcast);

    /* Se realizan operaciones pertenecientes a MaterialOrdenado con el objeto tienda*/
    /* Se muestran los objetos almacenados por el tipo de material */
    cout << "\nMetodo de busqueda los objetos mediante el Tipo de Material: "<< endl;
    tienda.buscarMaterialPorTipo("Pelicula");
    tienda.buscarMaterialPorTipo("Libro");

    /* Se muestran los objetos almacenados por el titulo del material */
    cout << "\nMetodo de busqueda los objetos mediante el Titulo: "<< endl;
    tienda.buscarMaterialPorTitulo("Alex al habla");
    tienda.buscarMaterialPorTitulo("Choque de dos vehiculos");

    /* Ahora se prueba con eliminar el Libro y volviendolo a llamar*/
    cout << "\nEliminacion del objeto llamado \"Libro\": "<< endl;
    tienda.eliminarMaterial("Orgullo y prejuicio (Spanish Edition)");
    tienda.buscarMaterialPorTipo("Libro");  /* No aparece porque se eliminó*/

    /* Creación de un objeto para material precio */
    cout << endl;
    MaterialPrecio* ordenado = new MaterialPrecio("Orgullo y prejuicio", 
                                                        "Libro", 11.99);
    
    MaterialPrecio* noticia_ordenado = new MaterialPrecio("Choque de dos vehiculos", 
                                                        "Noticia", 20.00);
    
    MaterialPrecio* pelicula_ordenado = new MaterialPrecio("La guerra de los mundos", 
                                                        "Pelicula", 5.99);

    MaterialPrecio* podcast_ordenado = new MaterialPrecio("Alex al habla", 
                                                        "Podcast", 0.00);                    

    /* Se ingresan objetos de la clase MaterialPrecio a un unico objeto MaterialPrecio dominante */
    ordenado->agregarMaterial(ordenado);
    ordenado->agregarMaterial(noticia_ordenado);
    ordenado->agregarMaterial(pelicula_ordenado);
    ordenado->agregarMaterial(podcast_ordenado);

    /* Muestra info del contenido del vector de ordenado sin ordenar */
    cout << "\nMaterial sin ordenar: "<< endl;
    ordenado->mostrarInfo();

    /* Ordena de forma ascendete y muestra la info*/
    cout << "\nMaterial ordenado de forma ascendente: "<< endl;
    ordenado->ordenarAscendente();
    ordenado->mostrarInfo();

    /* Ordena de forma descendente y muestra la info*/
    cout << "\nMaterial ordenado de forma descendente: "<< endl;
    ordenado->ordenarDescendente();
    ordenado->mostrarInfo();

    /* Libera espacio de la memoria*/
    delete ptr_libro;
    delete ptr_noticia;
    delete ptr_pelicula;
    delete ptr_podcast;
    delete ordenado;
    delete noticia_ordenado;
    delete pelicula_ordenado;
    delete podcast_ordenado;

    return 0;
}