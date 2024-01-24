/**
 * @file Matriz.hpp
 * @brief Contiene lo necesario para crear una función entera o double de tipo real o compleja 
 * @author Yehohnathan Miranda Vigil (yehohnathan.miranda@ucr.ac.cr)
 * @version 1.0
 * @date 2024-01-42
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef MATRIZ_HPP
#define MATRIZ_HPP

/* Se incluyen las librerías necesarias: */
#include <iostream>
#include <stdexcept>
#include <vector>
#include <limits>
using namespace std;

/**
 * @brief Clase que representa una matriz bidimensional genérica mediante templates.
 * @tparam T Tipo de dato de la matriz (int o double).
 */
template <typename T>
class Matriz
{
    private:
        T filas = 0;        /**< Corresponde al valor de las filas de la matriz. */
        T columnas = 0;     /**< Corresponde al valor de las columnas de la matriz. */
        bool complejo;      /**< Bandera para activar los números complejos. */
        T dato;             /**< Corresponde a los datos que va a tener la matriz o la opción del menú. */
        vector<T> datosMatriz;  /**< Contiene el valor de los datos ingresados. */

    public:
        /**
        * @brief Constructor de la clase Matriz.
        * @param complejo Indica si la matriz contiene números complejos (true) o reales (false).
        */
        Matriz(bool complejo);
        
        /**
        * @brief Método que le solicita al usuario el tamaño de la matriz.
        */
        void sizeMatriz();

        /**
        * @brief Método que utiliza el vector para ingresar datos complejos al vector.
        */
        void ingresarDatosComplejos();

        /**
        * @brief Método que utiliza el vector para ingresar valores al vector.
        */
        void ingresarDatosMatriz();

        /**
        * @brief Método para mostrar el contenido de la matriz siempre y cuando sea válida.
        */
        void mostrarMatriz() const;

        /**
        * @brief Método para mostrar el contenido de la matriz compleja siempre y cuando sea válida.
        */
        void mostrarComplejosMatriz() const;

        /**
        * @brief Menú que muestra todas las funciones que el usuario puede realizar con el objeto Matriz.
        */
        void menuMatriz();

        /**
        * @brief Método para obtener el número de filas de la matriz.
        * @return Número de filas.
        */
        T getFilas() const;

        /**
        * @brief Método para obtener el número de columnas de la matriz.
        * @return Número de columnas.
        */
        T getColumnas() const;

        /**
        * @brief Método para obtener la información sobre si la matriz contiene números complejos o no.
        * @return Valor booleano indicando si la matriz es compleja.
        */
        bool getComplejo() const;

        /**
        * @brief Método para obtener el dato correspondiente a una fila y columna específicas.
        * @param fila Número de fila.
        * @param columna Número de columna.
        * @return Valor almacenado en la posición fila x columna de la matriz.
        */
        T get(int fila, int columna) const;
};

/* Para que no de errores */
#include "Matriz.cpp"

#endif