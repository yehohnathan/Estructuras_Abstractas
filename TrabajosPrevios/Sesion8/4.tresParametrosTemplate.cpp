/*
    En este caso se da la creación de una clase de 3 parámetros, un poco más compleja
    que el ejemplo anterior. En donde se tienen como parámetros class T, class U y
    una ultima class V que si no es especificada utiliza un char.
*/

#include <iostream>
using namespace std;

// Plantilla de clase con múltiples y parámetros por defecto
// Se tienen 3 parámetros y por defecto V es tipo char
template <class T, class U, class V = char>
class ClassTemplate {
private:
    // Se defines 3 variables genéricas
    T var1;
    U var2;
    V var3;

public:
    // Contructor:
    ClassTemplate(T v1, U v2, V v3) : var1(v1), var2(v2), var3(v3) {}

    // Método publico que imprime variables
    void printVar() {
        cout << "var1 = " << var1 << endl;
        cout << "var2 = " << var2 << endl;
        cout << "var3 = " << var3 << endl;
    }
};

int main() {
    // Crear objeto con tipos int, double y char (por defecto no hace falta declarar)
    ClassTemplate<int, double> obj1(7, 7.7, 'C');
    cout << "Valores de obj1: ";
    obj1.printVar();

    // Crear objeto con tipos double, char y bool
    ClassTemplate<double, char, bool> obj2(8.8, 'a', false);
    cout << "Valores de obj2: ";
    obj2.printVar();

    return 0;
}
