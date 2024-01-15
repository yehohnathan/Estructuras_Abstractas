/* Se instancia el header que contiene la clase Noticia*/
#include "Noticia.hpp"

/* Se define el contructor */
Noticia::Noticia(string titulo, string grupo, string tipoMaterial, string autor, string editorial,
             string genero, string estado, int cantidadHojas, double precio, string infoAdicional)
            : MaterialLectura(titulo, grupo, tipoMaterial, autor, editorial, genero, estado, 
            cantidadHojas, precio), infoAdicional(infoAdicional) {}


/* Se definen los métodos públicos creados en el header: */

void Noticia::ponerInfoAdicional(string infoAdicional){
    /* Asignar el valor del parámetro al atributo infoAdicional */
    this->infoAdicional = infoAdicional;
}

void Noticia::sizeNoticia(){
    if(cantidadHojas >= 0 && cantidadHojas < 5) {
        cout << "\nLa noticia es corta, unicamente tiene " << cantidadHojas << " paginas."  << endl;
    }
    else if(cantidadHojas >= 5 && cantidadHojas < 10) {
        cout << "\nLa noticia es mediana, tiene " << cantidadHojas << " paginas."  << endl;
    }
    else {
        cout << "\nLa noticia es grande, tiene " << cantidadHojas << " paginas."  << endl;
    }
};

void Noticia :: mostrarInfo() {
    /* Muestra la información de los atributos de la clase MaterialLectura*/
    MaterialLectura::mostrarInfo();
    cout << "Informacion Adicional: " << infoAdicional << endl; 
}

/* Destructor: si hubiera datos se liberarían acá*/
Noticia :: ~Noticia() {}
