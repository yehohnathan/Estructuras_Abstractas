#ifndef VALIDA_CORREO_HPP
#define VALIDA_CORREO_HPP


/* Se incluyen las clases que necesita el programa: */
#include <iostream>
#include <regex>        /* Para el uso de expresiones regulares */
#include <stdexcept>    /* Para el uso de excepciones */
#include <string>       /* Para agregar cadenas de texto */
using namespace std;

class ValidaCorreo
{
    private:
        /* Expresión regular que contiene el patrón de para un correo valido */
        regex correo;

    public:
        /* Se instancia el contructor de la clase, el cual en vez de ingresar un correo(correo)
        realiza un correo(R"patron")*/
        ValidaCorreo();

        /* Se crea un método que solicita una cenada de texto (string cadena) y luego retorna 
        si la dirección de correo es valida(true) o no(false). */
        bool validador(string cadena);
};


#include "ValidaCorreo.cpp"
#endif