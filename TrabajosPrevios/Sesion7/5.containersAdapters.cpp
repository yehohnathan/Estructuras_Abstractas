/*
    Los containers adapters: toman un contener existente y se le agrega
    una interfaz restringida para que cambien su comportamiento.

    Por ejemplo, una pila es un adaptador de  contenedor que utiliza la
    del de contenedor secuencial y proporciona una interfaz restringida
    para admitir operaciones "push()" y "pop()" únicamente. Una cola y una
    cola de prioridad también son un contenedor adaptado
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    // Se crea una stack de enteros
    stack<int> numbers;

    // Pone de los elementos en la pila:
    numbers.push(1);
    numbers.push(100);
    numbers.push(10);   // Elemento más próximo a salir, Stack es LIFO

    cout << "Numbers are: ";

    // we can access the element by getting the top and popping it until the stack is empty
    while(!numbers.empty()) {
        // Se imprime el elemento que esta en la cima
        cout << numbers.top() << " ";
        
        // y dicho elemento de la cima se quita del stack
        numbers.pop();
    }

    return 0;
}
