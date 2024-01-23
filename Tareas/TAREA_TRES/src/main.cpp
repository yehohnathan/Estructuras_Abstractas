#include "Matriz.hpp"
#include <iostream>
#include <typeinfo>
using namespace std;

int main(){
    Matriz<double> matriz1;

    matriz1.sizeMatriz();
    matriz1.ingresarDatosMatriz();
    matriz1.mostrarMatriz();

    return 0;
}