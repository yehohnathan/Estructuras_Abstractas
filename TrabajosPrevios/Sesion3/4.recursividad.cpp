/*
    Entendimiento de la recursividad realizando un factorial, a pesar de que hay
    un ejemplo de clase quiero hacerlo por mi cuenta. 

    Un número factorial x se entiende como:
    x! = x*(x-1)*(x-2)...(1)

    Solo puede ser un número entero y 0! = 1.
*/

#include <iostream>
using namespace std;

int factorial(int num){
    if (num > 1){   // Si num es diferente de 1 o 0, tiene que multiplicarse
        return num * factorial(num - 1);
    } else {        // Si sum es 1 o 0
        return 1;
    }

/*
    Ejemplo num = 3.
    1. return 3 * factorial(2)
    2. return 2 * factorial(1)
    3. return 1

    Haciendo 2 y 3 en 1, se obtiene = 
    return 3 * 2 * 1 
*/

}

int main(){
    int n, result;

    cout << "Ingrese un numero (no negativo): ";
    cin >> n;

    result = factorial(n);
    cout << "El factorial de " << n << " es " << result;
    
    return 0;
}
