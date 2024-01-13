/*
    Los iteradores de entrada pueden leer/procesar valores mientras iteran hacia adelante. 
    Se puede iterar hacia adelante usando ++ y leer valores usando * o usando ->. Un 
    iterador que lee valores del flujo de entrada es un ejemplo de iterador de entrada.

    Ejemplo de código:
    istream_iterator<int> input_itr(cin);

    Los iteradores de salida pueden escribir valores mientras iteran hacia adelante. 
    Se puede iterar hacia adelante usando ++ y escribir valores usando *. 
    El operador = se puede utilizar para escribir valores.

    Ejemplo de código:
    ostream_iterator<int> output_itr(cout, " ");

    A continuación muestro un código de ejemplo de su uso:
*/



#include <iostream>
#include <iterator>
using namespace std;

int main() {

    cout << "Ingresa los numeros que quieres sumar, separado por espacios, y un \".\" para terminar:";
    istream_iterator<int> iterador_entrada(cin); // Se le ingresan numeros enteros 
    istream_iterator<int> fin_eof;  // Se le ingresa el mismo numero final que iterador_entrada(cin)

    int suma_total = 0; // Almacena el valor de la suma

    // Lee y suma todos los números
    while (iterador_entrada != fin_eof) {
        suma_total += *iterador_entrada;    // Se accede al valor 
        ++iterador_entrada;                 // Se mueve a la siguiente dirección + 1
    }

    cout << "La suma total es: " << suma_total << endl;

    return 0;
}
