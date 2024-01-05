/*
    Los enumaredores  es un tipo de dato que permite definir un conjunto de 
    valores nombrados, que representan constantes enteras. Estos valores 
    nombrados son conocidos como enumeradores y son utilizados para mejorar 
    la legibilidad y la mantenibilidad del código al asignar nombres significativos 
    a valores específicos.

    Sirve mucho para manipular el código, con sentencias case o contadores.
*/

#include <iostream>
using namespace std;

// Se asignan las estaciones primavera, verano, otoño e invierno.
enum seasons {spring = 34, summer = 4, autumn = 9, winter = 32};

// Se asignan los días de la semana
enum week {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
// Cuando no se asignan números, empieza en 0 y se incrementa en 1

// Se asignan las membrecias de un club
enum suit {
    club = 0, 
    diamonds = 10, 
    hearts = 20, 
    spades = 3
} card;             // Se salta el paso de hacer un suit card

int main(){
    seasons s;
    s = summer;
    cout << "Summer = " << s << endl;

    week today;
    today = Wednesday;
    cout << "Day " << today+1 << endl;
    
    card = diamonds;
    cout << "Size of enum variable " << sizeof(card) << " bytes." << endl;
    
    return 0;
}

/*  
    La función sizeof en C++ se utiliza para obtener el tamaño en bytes de un tipo 
    de datos o de una variable. Puedes usar sizeof con tipos de datos, expresiones 
    o variables, y te dará la cantidad de bytes que ocupa en memoria.
*/