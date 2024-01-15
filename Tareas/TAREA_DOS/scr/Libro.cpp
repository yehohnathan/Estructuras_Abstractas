/* Se instancia el header que contiene la clase Lectura*/
#include "Libro.hpp"

/* Se define el contructor */
Libro::Libro(string titulo, string grupo, string tipoMaterial, string autor, string editorial,
             string genero, string estado, int cantidadHojas, double precio, string infoAdicional)
            : MaterialLectura(titulo, grupo, tipoMaterial, autor, editorial, genero, estado, 
            cantidadHojas, precio), infoAdicional(infoAdicional) {}


/* Se definen los métodos públicos creados en el header: */

void Libro::ponerInfoAdicional(string infoAdicional){
    /* Asignar el valor del parámetro al atributo infoAdicional */
    this->infoAdicional = infoAdicional;
}

void Libro::sizeLibro(){
    if(cantidadHojas >= 0 && cantidadHojas < 5) {
        cout << "El libro es corto, unicamente tiene " << cantidadHojas << " paginas."  << endl;
    }
    else if(cantidadHojas >= 5 && cantidadHojas < 10) {
        cout << "El libro es mediano, tiene " << cantidadHojas << " paginas."  << endl;
    }
    else {
        cout << "El libro es grande, tiene " << cantidadHojas << " paginas."  << endl;
    }
};

void Libro :: mostrarInfo() {
    /* Muestra la información de los atributos de la clase MaterialLectura*/
    MaterialLectura::mostrarInfo();
    cout << "Informacion Adicional: " << infoAdicional << endl; 
}

/* Destructor: si hubiera datos se liberarían acá*/
Libro :: ~Libro() {}
