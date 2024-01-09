/**
 * @file funciones.hpp
 * @brief Contiene las declaraciones de funciones y estructuras para el juego "Adivina el entero".
 * @author Yehohnathan Miranda Vigil (yehohnathan.miranda@ucr.ac.cr)
 * @version 1.0
 * @date 2024-01-09
 * 
 * @copyright Copyright (c) 2024
 */

#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

/**
 * @struct ValorObtenido
 * @brief Estructura para almacenar el valor deseado y el número de intentos.
 */
struct ValorObtenido {
    int valorDeseado; /**< Valor buscado por el usuario. */
    int n_intentos;   /**< Número de intentos permitidos. */

    /**
     * @brief Constructor que inicializa los valores como cero.
     */
    ValorObtenido() : valorDeseado(0), n_intentos(0) {} 
};

/**
 * @brief Muestra el menú principal del juego.
 */
void menuJuego();

/**
 * @brief Permite al usuario seleccionar la dificultad del juego.
 * @param valores Estructura que almacena el valor deseado y el número de intentos.
 */
void opcionDificultad(ValorObtenido& valores);

/**
 * @brief Implementa la dificultad normal del juego.
 * @param valores Estructura que almacena el valor deseado y el número de intentos.
 */
void dificultadNormal(ValorObtenido valores);

/**
 * @brief Implementa la dificultad difícil del juego.
 * @param valores Estructura que almacena el valor deseado y el número de intentos.
 */
void dificultadDificil(ValorObtenido valores);

/**
 * @brief Permite al usuario ingresar el intervalo de valores para el juego.
 * @param valores Estructura que almacena el valor deseado y el número de intentos.
 */
void intervaloValores(ValorObtenido& valores);

/**
 * @brief Genera un valor deseado aleatorio dentro del intervalo especificado.
 * @param num1 Extremo inferior del intervalo.
 * @param num2 Extremo superior del intervalo.
 * @return Valor deseado aleatorio.
 */
int valorDeseado(int num1, int num2);

#endif
