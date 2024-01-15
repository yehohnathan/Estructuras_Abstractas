/* Se instancia el header que contiene la clase MaterialAudiovisual*/

#include "MaterialAudiovisual.hpp"

/* Se define el contructor */
MaterialAudiovisual :: MaterialAudiovisual(string titulo, string grupo, string autor, 
                                           string tipoMaterial, string genero, int duracion, 
                                           string estado, double precio) {

    /* Se asignan los valores de parámetros a los atributos con el puntero this, el cual
    tiene siempre la dirección del objeto actual que se este usando.*/
    this->titulo = titulo;
    this->grupo = grupo;
    this->tipoMaterial = tipoMaterial;
    this->autor = autor;
    this->duracion = duracion;
    this->genero = genero;
    this->estado = estado;
    this->precio = precio;
}

/* Se definen los métodos públicos creados en el header: */
void MaterialAudiovisual :: ponerTitulo(string titulo) {
    /* Asignar el valor del parámetro al atributo titulo */
    this->titulo = titulo;
}

void MaterialAudiovisual :: ponerGrupo(string grupo) {
    /* Asignar el valor del parámetro al atributo grupo */
    this->grupo = grupo;
}

void MaterialAudiovisual :: ponerTipoMaterial(string tipoMaterial) {
    /* Asignar el valor del parámetro al atributo tipoMaterial */
    this->tipoMaterial = tipoMaterial;
}

void MaterialAudiovisual :: ponerAutor(string autor) {
    /* Asignar el valor del parámetro al atributo autor */
    this->autor = autor;
}


void MaterialAudiovisual :: ponerDuracion(int duracion) {
    /* Asignar el valor del parámetro al atributo duracion */
    this->duracion = duracion;
}


void MaterialAudiovisual :: ponerGenero(string genero) {
    /* Asignar el valor del parámetro al atributo genero */
    this->genero = genero;
}


void MaterialAudiovisual :: ponerEstado(string estado) {
    /* Asignar el valor del parámetro al atributo estado */
    this->estado = estado;
}


void MaterialAudiovisual :: ponerPrecio(double precio) {
    /* Asignar el valor del parámetro al atributo precio */
    this->precio = precio;
}

void MaterialAudiovisual :: mostrarInfo() {
    /* Muestra la información de los atributos de la clase MaterialAudiovisual*/
    cout << "\nTitulo: " << titulo << endl;
    cout << "Grupo: " << grupo << endl;
    cout << "Tipo de material: " << tipoMaterial << endl;
    cout << "Autor: " << autor << endl;
    cout << "Duracion: " << duracion << " minutos"<< endl;
    cout << "Genero: " << genero << endl;
    cout << "Estado: " << estado << endl;
    cout << "Precio: " << precio << endl;
    cout << endl;
}

/* Destructor: si hubiera datos se liberarían acá*/
MaterialAudiovisual :: ~MaterialAudiovisual() {}
