/**
 * @file ValidaCorreo.hpp
 * @brief Retorna un boolneano true si la cadena corresponde un correo válido, y false de lo contrario.
 * @author Yehohnathan Miranda Vigil (yehohnathan.miranda@ucr.ac.cr)
 * @version 1.0
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef VALIDA_CORREO_HPP
#define VALIDA_CORREO_HPP


/* Se incluyen las clases que necesita el programa: */
#include <iostream>
#include <regex>        /* Para el uso de expresiones regulares */
#include <stdexcept>    /* Para el uso de excepciones */
#include <string>       /* Para agregar cadenas de texto */
using namespace std;

/**
 * @brief Clase que proporciona funciones para validar direcciones de correo electrónico.
 */
class ValidaCorreo
{
    private:
        regex correo;  /**< Expresión regular que contiene el patrón para un correo válido. */

    public:
        /**
         * @brief Constructor de la clase ValidaCorreo.
         * El constructor inicializa la expresión regular con el patrón para un correo electrónico válido.
         */
        ValidaCorreo();

        /**
         * @brief Método para validar una dirección de correo electrónico.
         * @param cadena Cadena de texto que representa la dirección de correo a validar.
         * @return true si la dirección de correo es válida, false si no es válida.
         */
        bool validador(string cadena);
};


#include "ValidaCorreo.cpp"
#endif