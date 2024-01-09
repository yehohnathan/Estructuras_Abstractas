/**
 * @file funciones.hpp
 * @author Yehohnathan Miranda Vigil (yehohnathan.miranda@ucr.ac.cr)
 * @brief Funciones para implementar el juego "Adivina el entero"
 * @version 0.1
 * @date 2024-01-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */


#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

struct ValorObtenido {
    int valorDeseado;
    int n_intentos;

    // Constructor:
    ValorObtenido() : valorDeseado(0), n_intentos(0) {} 

};

void menuJuego();
void opcionDificultad(ValorObtenido& valores);
void dificultadNormal(ValorObtenido& valores);
void dificultadDificil(ValorObtenido& valores);
void opcionDificultad(ValorObtenido& valores);
void intervaloValores(ValorObtenido& valores);
int valorDeseado(int num1, int num2);


#endif