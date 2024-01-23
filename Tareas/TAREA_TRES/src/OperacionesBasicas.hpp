#ifndef OPERACIONES_BASICAS_HPP
#define OPERACIONES_BASICAS_HPP

#include <iostream>
#include <vector>
#include <typeinfo>
#include <limits>
#include "Matriz.hpp"
using namespace std;

template<typename T>
class OperacionesBasicas
{
    private:
        /* Se instancia un vector para cada matriz (son solo 2) */
        vector<Matriz<T>> matriz1;
        vector<Matriz<T>> matriz2;

        /* Se instancia un vector que contiene los resultados de las operaciones */
        vector<T> resultado; 

        /* Se crea una bandera para asegurar que las matrices ingresadas cumplas
        con los requisitos solicitados */
        bool validar = false;

        /* Se cre*/
        T resultadoDato;
        
        /* Creo un método para comprar si el tamaño de matriz 1 es igual al tamaño de
        matriz 1*/
        bool sonIguales(const Matriz<T>& matriz1, const Matriz<T>& matriz2) const;

    public:
        /* Método para agregar un objeto matriz al vector matriz1 o matriz2 */
        void agregarMatriz(const Matriz<T> matriz);

        /* El siguiente método se encarga de borrar las matrices guardadas*/
        void liberarEspacio();

        /* Método para validar para saber si se ingresaron dos matrices, si estas dos matrices
        tienen las mismas dimensiones y si son del mismo tipo. */
        void validarMatrices();

        /* Sobrecarga de operador de suma (+) */
        void suma(const Matriz<T>& matriz1, const Matriz<T>& matriz2);

        /* Sobrecarga de operador de resta (-) */
        void resta(const Matriz<T>& matriz1, const Matriz<T>& matriz2);

        /* Sobrecarga de operador de multiplicación (*) */
        void multiplicacion(const Matriz<T>& matriz1, const Matriz<T>& matriz2);
};

#include "OperacionesBasicas.cpp"
#endif