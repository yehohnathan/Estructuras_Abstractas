#include "MotoCoche.hpp"

int main(){
    MotoCoche miMotoCoche(666, 20, true);

    miMotoCoche.Coche::acelerar();
    miMotoCoche.abrirPuertas();
    miMotoCoche.usarCasco();
    return 0;
}