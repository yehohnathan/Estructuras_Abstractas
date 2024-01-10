/*
    La sobrecarga permite definir el comportamiento de los operadores (-,+,/,*,etc)
    para trabajar con objetos de una clase personalizada.

    Nosotros decidimos qué es lo que el compilador va a interpretar cuando se hace
    suma (operador) de dos objetos
*/

#include <iostream>
using namespace std;

class Fraccion {
    int numerador, denominador;
    public:
        // Contructor: cada vez que se intancia algo se pasa el numero y denominador
        Fraccion(int n, int d) : numerador(n), denominador(d) {}
    
        //Cuando se vayan a sumar Fraccion "operador+" se crea lo siguiente:
        Fraccion operator+ (const Fraccion &f) {
            Fraccion resultado(     // hace esto -> a/b + c/d = (a*d + c*b)/(b + c)
                numerador * f.denominador + f.numerador * denominador,
                denominador * f.denominador
            );
            return resultado;   // Retorna resultado, que será un nuevo objeto Fraccion
        }
    
        void imprimir() {
            cout << numerador << "/" << denominador << endl;
        }
};

int main() {
    Fraccion f1(1, 2);
    Fraccion f2(3, 4);
    
    Fraccion f3 = f1 + f2;
    
    f3.imprimir();
    
    return 0;
}
