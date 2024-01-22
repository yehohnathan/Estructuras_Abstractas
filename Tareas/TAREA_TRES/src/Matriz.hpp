#ifndef MATRIZ_HPP
#define MATRIZ_HPP


/* Se incluyen las librerías necesarias: */
#include <iostream>
#include <stdexcept>
using namespace std;

/* Se crea una clase llamada Matriz (bidimensional) que sea genérica mediante template*/
template <typename T>
class Matriz
{
    private:
        T filas;        /* Corresponde al valor de las filas de la matriz*/
        T columnas;     /* Corresponde al valor de las columnas de la matriz*/
        T dato;         /* Corresponde a los datos que va a tener la matriz*/

    public:

        /* Se crea un método que le solicite al usuario el tamaño de la matriz */
        void sizeMatriz();
        void mostrarMatriz() const;

};

/* Para que no de errores */
#include "Matriz.cpp"

#endif