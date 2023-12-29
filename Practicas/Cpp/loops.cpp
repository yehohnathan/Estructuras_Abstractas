/* Se realizan varios ejercicios para verificar el uso de wwhile*/
#include <iostream>
using namespace std;
// Ejercicio 1
/*
int main() {
    int numArray [] = {1,2,3,4,5,6};
    
    for (int i = 0; i < 6; i++)
    {
        cout << numArray[i] << " ";
    }
}
*/

// Ejercicio 2
/*
int main() {
    int numArray [] = {1,2,3,4,5,6};
    int i = 0;  
    while (i < 6)
    {
        cout << numArray[i] << " ";
        i++;
    }
}
*/

// Ejercicio 3

//#include <iterator>
int main() {
    int numArray [] = {1,2,3,4,5,6};
    
    int number;
    for (int i : numArray)  // Bucle basado en rango, en este caso termina hasta llegar
    {                       // al ultimo valor de numArray
        cout << i << " ";
        number++;
    }
    cout << "\n" << number << endl;
    cout << size(numArray) << endl;
}



