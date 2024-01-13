/*
    Los iteradores de acceso aleatorio tienen todas las propiedades de los iteradores 
    bidireccionales junto con el acceso aleatorio. Algunos operadores comúnmente utilizados 
    para iteradores de acceso aleatorio son:

    1. ++ para iterar hacia adelante
    2. -- para iterar hacia atrás
    3. * o [] para leer y escribir valores
    4. -> para acceder a los valores de los miembros
    5. + para iterar hacia adelante según el número deseado de pasos
    6. - para iterar hacia atrás según el número de pasos deseado

    Los iteradores de las clases contenedoras vector, deque, array e 
    iteradores de strings son iteradores de acceso aleatorio.
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    // Crea un vector
    vector<int> vec{1, 2, 3, 4};

    // Crea iteradores que apuntan al inicio y al ultimo elemento
    vector<int>::iterator itr_first = vec.begin();
    vector<int>::iterator itr_last = vec.end() - 1; // Menos para ajustarlo al ultimo

    // Muestra los elementos en el display
    cout << "First Element: " << *itr_first << endl;
    cout << "Second Element: " << itr_first[1] << endl;
    cout << "Second Last Element: " << *(itr_last - 1) << endl;
    cout << "Last Element: " << *itr_last << endl;

    return 0;
}
