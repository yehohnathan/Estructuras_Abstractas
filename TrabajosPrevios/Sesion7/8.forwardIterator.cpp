#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    // Sea crea un forward list
    forward_list<int> nums{1, 2, 3, 4};

    // Creo un iterador que comienza desde el inicio del fordward
    forward_list<int>::iterator itr = nums.begin();

    // Se repite hasta que llegue al final de fordward list
    // y lo que hace este while es multiplicar por dos todos los elementos de la lista
    while (itr != nums.end()) {
        // Se accede al valor de la lista
        int original_value = *itr;

        // Se cambia el valor original en la posición de memoria por el mismo pero
        // multiplicado por dos
        *itr = original_value * 2;

        // Se mueve a la siguiente dirección
        itr++;
    }

    // Muestra el contenido de los valores utilizando el rango 
    for (int num: nums) {
        cout << num << " ";
    }

    return 0;
}
