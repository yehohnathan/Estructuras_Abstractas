/*
    Herencia: permite crear una clase derivada a partir de una clase existente. Es como
    agarrar el molde de una clase para hacer un molde (pero mayor) de otra clase.
*/

#include <iostream>
using namespace std;

class Animal {
public:
    void eat() {
        cout << "I can eat!" << endl;
    }

    void sleep() {
        cout << "I can sleep!" << endl;
    }
};

// Clase derivada Dog, que surge de la Animal, y en adición se agregar la función ladrar
// debido a que no todos los animales ladrán.
class Dog : public Animal {
public:
    void bark() {
        cout << "I can bark! Woof woof!!" << endl;
    }
};

int main() {
    Dog dog1;

    // Calling members of the base class
    dog1.eat();     // Provienen de clase Animal
    dog1.sleep();   // Provienen de clase Animal

    // Calling member of the derived class
    dog1.bark();    // Proviene de la clase Dog

return 0;
}
