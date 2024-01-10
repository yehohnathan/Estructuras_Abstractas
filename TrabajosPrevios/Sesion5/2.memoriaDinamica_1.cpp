/*
    Ejemplo dememoria dinámica: usando new int y new float
*/

#include <iostream>
using namespace std;

int main() {

// declare an int pointer
int* pointInt;

// declare a float pointer
float* pointFloat;

// dynamically allocate memory
pointInt = new int;     // Se asigna memoria en el heap
pointFloat = new float; // Se asigna memoria en el heap, puntero float con new float

// assigning value to the variable memory
*pointInt = 45;
*pointFloat = 45.45f;

cout << *pointInt << endl;
cout << *pointFloat << endl;

// deallocate the memory
delete pointInt;
delete pointFloat;

return 0;
}
