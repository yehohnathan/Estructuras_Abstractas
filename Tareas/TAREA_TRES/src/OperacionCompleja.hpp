#ifndef OPERACION_COMPLEJA_HPP
#define OPERACION_COMPLEJA_HPP

#include <iostream>
#include <vector>
#include <typeinfo>
#include <limits>
#include <complex>
#include "Matriz.hpp"
using namespace std;

template<typename T>
class OperacionCompleja
{
    private:
        /* Se instancia un vector para cada matriz (son solo 2) */
        vector<Matriz<T>> matriz1;
        vector<Matriz<T>> matriz2;

        /* Se instancia un vector que contiene los resultados de las conversiones */
        vector<complex<T>> matrizCompleja1; 
        vector<complex<T>> matrizCompleja2; 
        vector<complex<T>> resultadoMatrices;

        /* Se crea una bandera para asegurar que las matrices ingresadas cumplas
        con los requisitos solicitados */
        bool validar = false;

        /* Se crea para guardar datos de suma, resta, multiplicación y otros */
        complex<T> resultadoDato;

        /* Se crea para que el usuario ingresa opciones en el menu */
        int opciones;
        
        /* Creo un método para comprar si el tamaño de matriz 1 es igual al tamaño de
        matriz 1*/
        bool sonIguales(const Matriz<T>& matriz1, const Matriz<T>& matriz2) const;

        /* Convierte una matriz "normal" a una matriz "compleja"*/
        void conversorMatriz(const Matriz<T>& matriz);

    public:
        /* Método de menú para que el usuario pueda elegir si sumar, multiplizar o dividir */
        void menuOperacion();

        /* Método para agregar un objeto matriz al vector matriz1 o matriz2 */
        void agregarMatriz(const Matriz<T> matriz);

        /* El siguiente método se encarga de borrar las matrices guardadas*/
        void liberarEspacio();

        /* Método para validar para saber si se ingresaron dos matrices, si estas dos matrices
        tienen las mismas dimensiones y si son del mismo tipo. */
        void validarMatrices();

        /* Sobrecarga de operador de suma (+) */
        void suma(const Matriz<T>& matriz1, const Matriz<T>& matriz2,
                  const vector<complex<T>> matrizCompleja1, 
                  const vector<complex<T>> matrizCompleja2);

        /* Sobrecarga de operador de resta (-) */
        void resta(const Matriz<T>& matriz1, const Matriz<T>& matriz2,
                   const vector<complex<T>> matrizCompleja1, 
                   const vector<complex<T>> matrizCompleja2);

        /* Sobrecarga de operador de multiplicación (*) */
        void multiplicacion(const Matriz<T>& matriz1, const Matriz<T>& matriz2,
                            const vector<complex<T>> matrizCompleja1, 
                            const vector<complex<T>> matrizCompleja2);

        /* Método para mostrar el cualquier tipo de matriz compleja */
        void mostrarMatriz(const Matriz<T>& matriz, const vector<complex<T>>& matrizCompleja);
};

#include "OperacionCompleja.cpp"
#endif