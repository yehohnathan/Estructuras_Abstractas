/*
    Ejemplo dememoria dinámica: utilizando new junto con un arreglo
*/

#include <iostream>
using namespace std;

int main() {

    int num;
    cout << "Ingresa el numero total de estudiantes:";
    cin >> num;
    float* ptr;

    // memory allocation of num number of floats
    // Se asigna de forma dinámica un espacio en el heap para un arreglo 
    // de flotantes de tamaño num
    ptr = new float[num];

    cout << "Ingresa GPA de los estudiantes." << endl;
    for (int i = 0; i < num; ++i) {
        cout << "Student" << i + 1 << ": ";
        cin >> *(ptr + i);  // Utilizando aritmética de punteros 
        // y se van guardando los datos en el espacio reservado del heap
    }

    cout << "\nDisplaying GPA of students." << endl;
    for (int i = 0; i < num; ++i) {
        cout << "Student" << i + 1<< ": " << *(ptr + i) << endl;
    }

   // Se libera la memoria ocupada por ptr
   delete[] ptr;

   return 0;
}
