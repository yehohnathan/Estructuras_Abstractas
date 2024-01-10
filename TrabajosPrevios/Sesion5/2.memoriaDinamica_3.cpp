/*
    Ejemplo dememoria dinámica: utilizando clases y objetos con new
*/

#include <iostream>
using namespace std;

class Student {
private:
    int age;

public:
    // constructor initializes.age to 12
    Student() : age(12) {}

    void getAge() {
        cout << "Age = " << age << endl;
    }
};

int main() {
    // dynamically declare Student object
    Student* ptr = new Student();   // Reserva espacio en el heap para el objeto ptr

    // call getAge() function
    ptr->getAge();                  // Utiliza flecha por ser un objeto

    // ptr memory is released
    delete ptr;                     // Libera el espacio

    return 0;
}
