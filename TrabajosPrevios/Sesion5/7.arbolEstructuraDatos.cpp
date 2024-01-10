/*
    Un árbol es una estructura de datos jerárquica no lineal que consta de nodos 
    conectados por aristas.

    Nodo: Es una entidad que contiene una clave o valor y punteros a sus nodos secundarios. 
    Los últimos nodos de cada ruta se denominan nodos hoja o nodos externos que no 
    contienen un enlace/puntero a nodos secundarios. El nodo que tiene al menos un nodo 
    hijo se denomina nodo interno.

    Arista: Es el vínculo entre dos nodos cualesquiera.

    Raíz: Es el nodo más alto de un árbol.

    Altura de un nodo: Es el número de aristas desde el nodo hasta la hoja más profunda (es 
    decir, el camino más largo desde el nodo hasta un nodo de hoja).
    Profundidad de un nodo: Es el número de aristas desde la raíz hasta el nodo.

    Altura de un árbol: Es la altura del nodo raíz o la profundidad del nodo más profundo.

    Grado de un nodo: Es el número total de ramas de ese nodo.

    Bosque: Un conjunto de árboles separados se llama bosque.

*/

#include <iostream>
using namespace std;

struct Node {
    int data;   // Valor que almacena
    
    struct Node *left, *right; 

    //Contructor:
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Recorrido de preorden
void preorderTraversal(struct Node* node) {
    if (node == NULL)
        return;

    cout << node->data << " ";      // 1. Raíz
    // Funciones recursivas:
    preorderTraversal(node->left);  // 2. Izquierda
    preorderTraversal(node->right); // 3. Derecha
}

// Recorrido de postorden
void postorderTraversal(struct Node* node) {
    if (node == NULL)
        return;

    // Funciones recursivas:
    postorderTraversal(node->left); // 1. Izquierda
    postorderTraversal(node->right);// 2. Derecha
    cout << node->data << "->";     // 3. Raiz
}

// Inorder traversal
void inorderTraversal(struct Node* node) {
    if (node == NULL)
        return;

    // Funciones recursivas:        
    inorderTraversal(node->left);   // 1. Izquierda
    cout << node->data << "->";     // 2. Raíz
    inorderTraversal(node->right);  // 3. Derecha
}

int main() {
    // Se crea un nodo raíz y se guardan valores en el head
    struct Node* root = new Node(1);    // Raiz                             
    root->left = new Node(12);          // Izquierda                     
    root->right = new Node(9);          // Derecha               
    root->left->left = new Node(5);     // Izquierda Izquierda               
    root->left->right = new Node(6);    // Izquierda Derecha           

    cout << "Inorder traversal ";
    inorderTraversal(root);

    cout << "\nPreorder traversal ";
    preorderTraversal(root);

    cout << "\nPostorder traversal ";
    postorderTraversal(root);
}
