/*  Repaso del uso de estructuras/clases en C++ 
*/

#include <iostream>
#include <cstring>
using namespace std;

struct books
{
    char name[50];
    int  id;
    char subject[50];
};

// Sobrecarga del operador de inserción para imprimir la estructura
ostream& operator<<(ostream& os, const books& libro) {
    os << "Nombre: " << libro.name << ", ID: " << libro.id << ", Materia: " << libro.subject;
    return os;
}

int main() {
    struct books b1;

    strcpy(b1.name, "Las ultimas maravillas");
    strcpy(b1.subject, "C++");
    b1.id = 556664;

    struct books b2;
    strcpy(b2.name, "Para tomarme en serio");
    strcpy(b2.subject, "Sicologia");
    b2.id = 997741; 

    cout << b2 << endl;
    cout << b1 << endl;
    cout << b1.subject << endl;
}
