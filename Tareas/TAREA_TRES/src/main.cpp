#include "Matriz.hpp"
#include <iostream>
#include <complex>
using namespace std;

int main(){
    /* Se crea un objeto. Si se escribe true es porque es un número complejo, si se
    escribe false es un número real */
    Matriz<double> matriz1 (true);

    matriz1.menuMatriz();

    return 0;
}