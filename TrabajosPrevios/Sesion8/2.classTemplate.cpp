/*
    De la misma manera que las function templates, se pueden crear "class templates"
    para poder ingresarle distintos tipos de valores.

    En este caso es una clase que simplemente muestra el valor ingresado en el 
    código y se puede observar como admite valores enteros y doubles, así
    como podría con otro tipo de datos.
*/

#include <iostream>
using namespace std;

template <class T>
class Number {
    private:
        // Variable de tipo T
        T num;
    
    public:
        // Contructor:
        Number(T n): num(n) {}

        // Funcion que retorna el tipo de dato ingresado
        T getNum() { 
            return num;
        }
};

int main() {
    // Crea un objeto tipo entero
    Number<int> numberInt(7);

    // Crea un objeto tipo double
    Number<double> numberDouble(7.7);

    // Ejemplo extra para probar con un string
    Number<string> numberString("uno");

    // Imprime los resultados:
    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;
    cout << "string Number = " << numberString.getNum() << endl;
}