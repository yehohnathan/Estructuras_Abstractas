/* Se instancia el header que contiene la clase MaterialLectura*/
#include "MaterialLectura.hpp"

/* Se define el contructor */
MaterialLectura :: MaterialLectura(string titulo,  string grupo, string tipoMaterial, string autor,
                                   string editorial,  string genero, string estado,int cantidadHojas,
                                   double precio) {

    /* Se asignan los valores de parámetros a los atributos con el puntero this, el cual
    tiene siempre la dirección del objeto actual que se este usando.*/
    this->titulo = titulo;
    this->grupo = grupo;
    this->tipoMaterial = tipoMaterial;
    this->autor = autor;
    this->editorial = editorial;
    this->genero = genero;
    this->estado = estado;
    this->cantidadHojas = cantidadHojas;
    this->precio = precio;
}

/* Se definen los métodos públicos creados en el header: */
void MaterialLectura :: ponerTitulo(string titulo) {
  /* Asignar el valor del parámetro al atributo titulo */
  this->titulo = titulo;
}

void MaterialLectura :: ponerGrupo(string grupo) {
  /* Asignar el valor del parámetro al atributo grupo */
  this->grupo = grupo;
}

void MaterialLectura :: ponerTipoMaterial(string tipoMaterial) {
  /* Asignar el valor del parámetro al atributo tipoMaterial */
  this->tipoMaterial = tipoMaterial;
}

void MaterialLectura :: ponerAutor(string autor) {
  /* Asignar el valor del parámetro al atributo autor */
  this->autor = autor;
}


void MaterialLectura :: ponerEditorial(string editorial) {
  /* Asignar el valor del parámetro al atributo editorial */
  this->editorial = editorial;
}


void MaterialLectura :: ponerGenero(string genero) {
  /* Asignar el valor del parámetro al atributo genero */
  this->genero = genero;
}


void MaterialLectura :: ponerEstado(string estado) {
  /* Asignar el valor del parámetro al atributo estado */
  this->estado = estado;
}

void MaterialLectura :: ponerCantidadHojas(int cantidadHojas) {
  /* Asignar el valor del parámetro al atributo cantidadHojas */
  this->cantidadHojas = cantidadHojas;
}


void MaterialLectura :: ponerPrecio(double precio) {
  /* Asignar el valor del parámetro al atributo precio */
  this->precio = precio;
}

void MaterialLectura :: mostrarInfo() {
  /* Muestra la información de los atributos de la clase MaterialLectura*/
  cout << "\nTitulo: " << titulo << endl;
  cout << "Grupo: " << grupo << endl;
  cout << "Tipo de material: " << tipoMaterial << endl;
  cout << "Autor: " << autor << endl;
  cout << "Editorial: " << editorial << endl;
  cout << "Genero: " << genero << endl;
  cout << "Estado: " << estado << endl;
  cout << "Cantidad de hojas: " << cantidadHojas << endl;
  cout << "Precio: " << precio << endl;
}

/* Destructor: si hubiera datos se liberarían acá*/
MaterialLectura :: ~MaterialLectura() {}
