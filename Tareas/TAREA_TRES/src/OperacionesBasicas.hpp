/**
 * @file OperacionesBasicas.hpp
 * @brief Puede realizar operaciones de suma, resta y multiplicación de matrices reales
 * @author Yehohnathan Miranda Vigil (yehohnathan.miranda@ucr.ac.cr)
 * @version 1.0
 * @date 2024-01-42
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef OPERACIONES_BASICAS_HPP
#define OPERACIONES_BASICAS_HPP

#include <iostream>
#include <vector>
#include <typeinfo>
#include <limits>
#include "Matriz.hpp"
using namespace std;

/**
 * @brief Clase que realiza operaciones básicas con matrices.
 * @tparam T Tipo de dato de la matriz (int o double).
 */
template<typename T>
class OperacionesBasicas
{
    private:
        vector<Matriz<T>> matriz1;  /**< Vector que contiene la primera matriz. */
        vector<Matriz<T>> matriz2;  /**< Vector que contiene la segunda matriz. */

        bool validar = false;  /**< Bandera para asegurar que las matrices ingresadas cumplen con los requisitos solicitados. */

        T resultadoDato;  /**< Almacena el resultado de una operación entre dos elementos. */

        /**
         * @brief Compara si el tamaño de dos matrices es igual.
         * @param matriz1 Primera matriz a comparar.
         * @param matriz2 Segunda matriz a comparar.
         * @return true si las matrices tienen el mismo tamaño, false de lo contrario.
         */
        bool sonIguales(const Matriz<T>& matriz1, const Matriz<T>& matriz2) const;

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
         */
        void suma(const Matriz<T>& matriz1, const Matriz<T>& matriz2);

        /**
         * @brief Sobrecarga del operador de resta (-).
         * @param matriz1 Primera matriz a restar.
         * @param matriz2 Segunda matriz a restar.
         */
        void resta(const Matriz<T>& matriz1, const Matriz<T>& matriz2);

        /**
         * @brief Sobrecarga del operador de multiplicación (*).
         * @param matriz1 Primera matriz a multiplicar.
         * @param matriz2 Segunda matriz a multiplicar.
         */
        void multiplicacion(const Matriz<T>& matriz1, const Matriz<T>& matriz2);

        /**
         * @brief Obtiene el valor de la bandera de validación.
         * @return Valor de la bandera de validación.
         */
        bool getValidar();
};

#include "OperacionesBasicas.cpp"
#endif