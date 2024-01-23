#ifndef MATRIZ_HPP
#define MATRIZ_HPP


/* Se incluyen las librerías necesarias: */
#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>
using namespace std;

/* Se crea una clase llamada Matriz (bidimensional) que sea genérica mediante template*/
template <typename T>
class Matriz
{
    private:
        T filas = 0;        /* Corresponde al valor de las filas de la matriz*/
        T columnas = 0;     /* Corresponde al valor de las columnas de la matriz*/
        bool complejo;  /* Bandera para activar los números complejos*/
        T dato;             /* Corresponde a los datos que va a tener la matriz o la opción del menú*/
        vector<T> datosMatriz;  /* Contiene el valor de los datos ingresados */

    public:
        /* Se crea un constructor para decidir si el número es complejo o no */
        Matriz(bool complejo);
        
        /* Se crea un método que le solicite al usuario el tamaño de la matriz */
        void sizeMatriz();

        /* Se crea un método que utiliza el vector para ingresar datos complejos al vector */
        void ingresarDatosComplejos();

        /* Se crea un método que utiliza el vector para ingresar valores al vector */
        void ingresarDatosMatriz();

        /* Método para mostrar el contenido de la matriz siempre y cuando sea válida*/
        void mostrarMatriz() const;

        /* Método para mostrar el contenido de la matriz siempre y cuando sea válida*/
        void mostrarComplejosMatriz() const;

        /* Este menú sirve mostrarle al usuario todas las funciones que puede realizar con
        el objeto sin importar si se equivoca */
        void menuMatriz();

        /* Lo siguiente son métodos para obtener información de los atributos */
        void getFilas() const;
        void getColumnas() const;
        bool getComplejo() const;

};

/* Para que no de errores */
#include "Matriz.cpp"

#endif