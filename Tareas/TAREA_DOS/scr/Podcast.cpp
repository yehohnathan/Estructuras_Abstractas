/* Se instancia el header que contiene la clase Podcast*/
#include "Podcast.hpp"

/* Se define el contructor */
Podcast::Podcast(string titulo, string grupo, string autor, string tipoMaterial, string genero, 
                   int duracion, string estado, double precio, string infoAdicional)
                   : MaterialAudiovisual(titulo, grupo, autor, tipoMaterial, genero, duracion, 
                   estado, precio), infoAdicional(infoAdicional) {}


/* Se definen los métodos públicos creados en el header: */

void Podcast::ponerInfoAdicional(string infoAdicional){
    /* Asignar el valor del parámetro al atributo infoAdicional */
    this->infoAdicional = infoAdicional;
}

void Podcast::durationPodcast(){
    if(duracion >= 0 && duracion < 30) {
        cout << "\nEl podcast es corto, solo dura " << duracion << " minutos."  << endl;
    }
    else if(duracion >= 30 && duracion < 90) {
        cout << "\nEl podcast es mediano, dura " << duracion << " minutos."  << endl;
    }
    else {
        cout << "\nEl podcast es largo, dura " << duracion << " minutos."  << endl;
    }
};

void Podcast :: mostrarInfo() {
    /* Muestra la información de los atributos de la clase MaterialAudiovisual*/
    MaterialAudiovisual::mostrarInfo();
    cout << "Informacion Adicional: " << infoAdicional << endl; 
}

/* Destructor: si hubiera datos se liberarían acá*/
Podcast :: ~Podcast() {}