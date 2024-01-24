/**
 * @file OperacionCompleja.hpp
 * @brief Puede realizar operaciones de suma, resta y multiplicación de matrices complejas
 * @author Yehohnathan Miranda Vigil (yehohnathan.miranda@ucr.ac.cr)
 * @version 1.0
 * @date 2024-01-42
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef OPERACION_COMPLEJA_HPP
#define OPERACION_COMPLEJA_HPP

#include <iostream>
#include <vector>
#include <typeinfo>
#include <limits>
#include <complex>
#include "Matriz.hpp"
using namespace std;

/**
 * @brief Clase que realiza operaciones complejas con matrices.
 * @tparam T Tipo de dato de la matriz (int o double).
 */
template<typename T>
class OperacionCompleja
{
    private:
        vector<Matriz<T>> matriz1;  /**< Vector que contiene la primera matriz. */
        vector<Matriz<T>> matriz2;  /**< Vector que contiene la segunda matriz. */

        vector<complex<T>> matrizCompleja1;  /**< Vector que contiene la versión compleja de la primera matriz. */
        vector<complex<T>> matrizCompleja2;  /**< Vector que contiene la versión compleja de la segunda matriz. */
        vector<complex<T>> resultadoMatrices;  /**< Vector que almacena los resultados de las operaciones. */

        bool validar = false;  /**< Bandera para asegurar que las matrices ingresadas cumplen con los requisitos solicitados. */

        complex<T> resultadoDato;  /**< Almacena el resultado de una operación entre dos elementos. */

        int opciones;  /**< Almacena las opciones ingresadas por el usuario en el menú de operaciones. */

        /**
         * @brief Compara si el tamaño de dos matrices es igual.
         * @param matriz1 Primera matriz a comparar.
         * @param matriz2 Segunda matriz a comparar.
         * @return true si las matrices tienen el mismo tamaño, false de lo contrario.
         */
        bool sonIguales(const Matriz<T>& matriz1, const Matriz<T>& matriz2) const;

        /**
         * @brief Convierte una matriz "normal" a una matriz "compleja".
         * @param matriz Matriz a convertir.
         */
        void conversorMatriz(const Matriz<T>& matriz);

    public:
        /**
         * @brief Menú de operaciones para que el usuario pueda elegir sumar, multiplicar o dividir.
         */
        void menuOperacion();

        /**
         * @brief Agrega un objeto matriz al vector matriz1 o matriz2.
         * @param matriz Matriz a agregar.
         */
        void agregarMatriz(const Matriz<T> matriz);

        /**
         * @brief Libera el espacio ocupado por las matrices guardadas.
         */
        void liberarEspacio();

        /**
         * @brief Valida si se ingresaron dos matrices, si estas dos matrices tienen las mismas dimensiones y si son del mismo tipo.
         */
        void validarMatrices();

        /**
         * @brief Sobrecarga del operador de suma (+).
         * @param matriz1 Primera matriz a sumar.
         * @param matriz2 Segunda matriz a sumar.
         * @param matrizCompleja1 Versión compleja de la primera matriz.
         * @param matrizCompleja2 Versión compleja de la segunda matriz.
         */
        void suma(const Matriz<T>& matriz1, const Matriz<T>& matriz2,
                const vector<complex<T>> matrizCompleja1, 
                const vector<complex<T>> matrizCompleja2);

        /**
         * @brief Sobrecarga del operador de resta (-).
         * @param matriz1 Primera matriz a restar.
         * @param matriz2 Segunda matriz a restar.
         * @param matrizCompleja1 Versión compleja de la primera matriz.
         * @param matrizCompleja2 Versión compleja de la segunda matriz.
         */
        void resta(const Matriz<T>& matriz1, const Matriz<T>& matriz2,
                const vector<complex<T>> matrizCompleja1, 
                const vector<complex<T>> matrizCompleja2);

        /**
         * @brief Sobrecarga del operador de multiplicación (*).
         * @param matriz1 Primera matriz a multiplicar.
         * @param matriz2 Segunda matriz a multiplicar.
         * @param matrizCompleja1 Versión compleja de la primera matriz.
         * @param matrizCompleja2 Versión compleja de la segunda matriz.
         */
        void multiplicacion(const Matriz<T>& matriz1, const Matriz<T>& matriz2,
                            const vector<complex<T>> matrizCompleja1, 
                            const vector<complex<T>> matrizCompleja2);

        /**
         * @brief Muestra el contenido de cualquier tipo de matriz compleja.
         * @param matriz Matriz a mostrar.
         * @param matrizCompleja Versión compleja de la matriz.
         */
        void mostrarMatriz(const Matriz<T>& matriz, const vector<complex<T>>& matrizCompleja);

        /**
         * @brief Obtiene el valor de la bandera de validación.
         * @return Valor de la bandera de validación.
         */
        bool getValidar();
};


#include "OperacionCompleja.cpp"
#endif