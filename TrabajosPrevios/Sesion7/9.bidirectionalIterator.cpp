/* 
    Los iteradores bidireccionales pueden iterar tanto hacia adelante como hacia atrás.
    Se puede iterar hacia adelante usando ++, hacia atrás usando --,
    y leer y escribir valores usando * o leer y escribir los miembros usando ->.
    
    Los iteradores de las clases de contenedor list, multiset, map y multimap son
    iteradores bidireccionales.
*/

#include <iostream>
#include <list>
using namespace std;

int main() {

    // Se define una lista llamada nums
    list<int> nums {1, 2, 3 ,4 ,5};

    // Se inicializa un iterador que apunta al inicio de nums
    list<int>::iterator itr = nums.begin();

    // Nos movemos hacia adelante;
    cout << "Moving forward: " << endl;

    // Muestra los elementos de forma ascendente
    while (itr != nums.end()) {
        cout << *itr << " ";
        
        // Mueve la dirección hasta llegar al ultimo elemento
        itr++;
    }

    cout << endl << "Moving backward: " << endl;

    // Ahora muestra el contenido de forma descendente 
    while (itr != nums.begin()) {
        
        
        // Mueve la dirección hasta llegar al primer elemento
        itr--;
        
        cout << *itr << " ";
    }

    return 0;
}
