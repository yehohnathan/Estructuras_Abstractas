/*
    Este programa muestra un paso más en dificultad, mostrando el paso de un objeto
    tipo "class Student" por medio de funciones
*/

#include <iostream>
using namespace std;

class Student {
    public:
        double marks;
        
        // Contructor:
        Student(double m) {
            marks = m;
        }
};

// Calcular promedio, utiliza dos parámetros de la clase student "mark"
// para encontrar el promedio de ambas.

void calculateAverage(Student s1, Student s2) {
    double average = (s1.marks + s2.marks) / 2;
    
    cout << "Average Marks = " << average << endl;
}

int main() {
    // Mediante el contructor se le pasan dos valores a marks
    Student student1(88.0), student2(56.0);
    
    // Luego se llama a la función con los objetos anteriores.
    calculateAverage(student1, student2);
    
    return 0;
}
