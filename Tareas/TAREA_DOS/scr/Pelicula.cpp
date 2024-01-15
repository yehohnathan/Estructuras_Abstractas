/* Se instancia el header que contiene la clase Noticia*/
#include "Pelicula.hpp"

/* Se define el contructor */
Pelicula::Pelicula(string titulo, string grupo, string autor, string tipoMaterial, string genero, 
                   int duracion, string estado, double precio, string infoAdicional)
                   : MaterialAudiovisual(titulo, grupo, autor, tipoMaterial, genero, duracion, 
                   estado, precio), infoAdicional(infoAdicional) {}


/* Se definen los métodos públicos creados en el header: */

void Pelicula::ponerInfoAdicional(string infoAdicional){
    /* Asignar el valor del parámetro al atributo infoAdicional */
    this->infoAdicional = infoAdicional;
}

void Pelicula::durationPelicula(){
    if(duracion >= 0 && duracion < 90) {
        cout << "\nLa pelicula es corta, solo dura " << duracion << " minutos."  << endl;
    }
    else if(duracion >= 90 && duracion < 150) {
        cout << "\nLa pelicula es mediana, dura " << duracion << " minutos."  << endl;
    }
    else {
        cout << "\nLa pelicula es larga, dura " << duracion << " minutos."  << endl;
    }
};

void Pelicula :: mostrarInfo() {
    /* Muestra la información de los atributos de la clase MaterialLectura*/
    MaterialAudiovisual::mostrarInfo();
    cout << "Informacion Adicional: " << infoAdicional << endl; 
}

/* Destructor: si hubiera datos se liberarían acá*/
Pelicula :: ~Pelicula() {}