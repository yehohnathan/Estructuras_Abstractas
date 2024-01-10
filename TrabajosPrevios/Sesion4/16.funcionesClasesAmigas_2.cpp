/*
    Otro ejemplo de función amiga para acceder a miembros privados
*/

#include <iostream>
using namespace std;

class ClassB;  // Prototipo de clase

class ClassA {
public:
    // constructor to initialize numA to 12
    ClassA() : numA(12) {}
private:
    int numA;
    // Función amiga
    friend int add(ClassA, ClassB);
};

class ClassB {
public:
    // constructor to initialize numB to 1
    ClassB() : numB(1) {}
private:
    int numB;
    // friend function declaration
    friend int add(ClassA, ClassB);
};

// Esta función se tuvo que poner como amiga en ambas clases para poder
// usar los dos objetos

int add(ClassA objectA, ClassB objectB) {
    return (objectA.numA + objectB.numB);
}

int main() {
    ClassA objectA;
    ClassB objectB;

    // Suma los miembros privados
    cout << "Sum: " << add(objectA, objectB);
    return 0;
}
