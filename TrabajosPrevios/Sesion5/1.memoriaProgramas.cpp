#include <iostream>
using namespace std;

// Se define una variable global y se guarda en Data Segment
int globalVariable = 42;

int main() {
// Se define variable local y se guarda en el Stack
int stackVariable = 10;

// Se define el puntero y se guarda en el heap
int* heapVariable = new int(20);    // new: devuelve un espacio para almacenar un entero en el heap

cout << "Valor de globalVariable: " << globalVariable << endl;
cout << "Valor de stackVariable: " << stackVariable << endl;
cout << "Valor de heapVariable: " << *heapVariable << endl;

// Libera la memoria asignada en el heab con new int(20)
delete heapVariable;

return 0;
}


/*
// declare an int pointer
int* pointVar;

// dynamically allocate memory
// for an int variable
// Nos da una porción de la memoria que esta en el heap, y lo que retorna es una
dirección de memoria por lo que pointVar debe ser un puntero.

pointVar = new int;

// assign value to the variable memory
*pointVar = 45;

// print the value stored in memory
cout << *pointVar; // Output: 45

// deallocate the memory
// Libera la memoria asignada en el heab
delete pointVar;
*/