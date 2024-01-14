#include <iostream>
using namespace std;

template <typename T, typename U>
T multiply(T a, U b){
    return a * b;
}

int main() {
    // Se declara una variable tipo double
    double result;

    // Llamando al template con un parámetro double  T y el otro entero U
    result = multiply<double, int>(5.5, 3.5);
    cout << "Multiplicacion (result): " << result << endl;

}