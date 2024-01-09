#include "funciones.hpp"

int main() {
    // Definición de la estructura para almacenar el valor deseado y la cantidad de intentos
    ValorObtenido valores;

    // Mostrar el menú del juego
    menuJuego();

    // Seleccionar la dificultad y configurar los parámetros del juego
    opcionDificultad(valores);
}