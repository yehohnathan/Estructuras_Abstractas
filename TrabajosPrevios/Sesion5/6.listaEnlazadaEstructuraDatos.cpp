/*
    Una lista enlazada es una estructura de datos lineal que incluye una serie de nodos
    conectados. Cada nodo almacena los datos y la dirección del siguiente nodo.
*/

// Linked list implementation in C++
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Creating a node
class Node {
    public:
        int value;
        Node* next; // Puntero al siguiente nodo
};

int main() {
    Node* head;     // Creo varias clases de Node
    Node* one = NULL;  
    Node* two = NULL;
    Node* three = NULL;

    // allocate 3 nodes in the heap
    one = new Node();       // Guardo espacio utilizando el operador new Node(), el cual
    two = new Node();       // devuelve la dirección de memoria del head. Y esto funciona
    three = new Node();     // porque son punteros

    // Assign value values
    one->value = 1;
    two->value = 2;
    three->value = 3;

    // Connect nodes
    one->next = two;        // Es como encadenarlos
    two->next = three;      // También se pueden enlazar de forma circular y atras y adelante 
    three->next = NULL;

    // print the linked list value
    head = one;             // head es one, y se va a desplezar para imprimir la lista
    while (head != NULL) {
        cout << head->value;
        head = head->next; 
    }

    return 0;
}
