/*
    Implementación del stack en C++, utilizando un modelo LIFO

    Push: agrega un elemento a la parte superior de una pila.
    Pop: elimina un elemento de la parte superior de una pila.
    IsEmpty: comprueba si la pila está vacía.
    IsFull: compuerba si la pila está lleva.
    Peek: obtiene el valor del elemento superior sin eliminarlo
*/

#include <stdlib.h>
#include <iostream>

using namespace std;

#define MAX 10      // Define constante
int stackSize = 0;  // Se cambia el nombre de la variable global 'size' a 
                    // 'stackSize' para evitar ambiguedad

// Se creak la estructura Stack
struct stack {
    int items[MAX]; // Arreglo de enteros
    int top;        // top para saber el número de más arriba
};

// typedef para tener un struct stack llamado st
typedef struct stack st;

// Función que hace una pila vacía
void createEmptyStack(st *s) {
    s->top = -1;    // Recive la dirección *s de la memoria, -1 (pila vacia)
}

// Check if the stack is full
int isfull(st *s) {
    if (s->top == MAX - 1)
        return 1;   // Esta llena
    else
        return 0;   // No esta llena
}

// Check if the stack is empty
int isempty(st *s) {
    if (s->top == -1)
        return 1;   // Esta vacia
    else
        return 0;   // No esta vacia
}

// Add elements into stack
void push(st *s, int newitem) {
    if (isfull(s)) {    // Se pregunta si esta llena
        cout << "STACK FULL";  
    } else {
        s->top++;   // Aumenta el top en 1
        s->items[s->top] = newitem; // Agrega el elemento  newitem a apilar en el arreglo
    }
    stackSize++;   
}

// Remove element from stack
void pop(st *s) {   // Se pregunta si la pila esta vacia
    if (isempty(s)) {
        cout << "\n STACK EMPTY \n";
    } else {
        cout << "Item popped= " << s->items[s->top];    // Muestar el item popeado
        s->top--;   // Regresa al elemento anterior
    }
    stackSize--;    // Decrementa en una unidad la variable size
    cout << endl;
}

// Print elements of stack
void printStack(st *s) {
    printf("Stack: ");
    for (int i = 0; i < stackSize; i++) { // Cambiado 'size' a 'stackSize'
        cout << s->items[i] << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    //int ch; no se utiliza
    st *s = (st *)malloc(sizeof(st));

    createEmptyStack(s);    // Se crea una pila vacia

    push(s, 1);             // Se le empiezan a meter valores
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    cout << "\nAfter popping out\n";
    printStack(s);
}
