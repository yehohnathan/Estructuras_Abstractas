/*
    Yo puedo crear dos clases derivadas a partir de la misma clase base y no tener
    problemas devido a que estas no se gastan.
*/

#include <iostream>
using namespace std;

class Animal {
    public:
    void info() { cout << "I am an animal." << endl; }
};

// Hereda de Animal
class Dog : public Animal {
    public:
    void bark() { cout << "I am a Dog. Woof woof." << endl; }
};

// Hereda de Animal
class Cat : public Animal {
    public:
    void meow() { cout << "I am a Cat. Meow." << endl; }
};

int main() {

// Create object of Dog class
Dog dog1;
cout << "Dog Class:" << endl;
dog1.info();  // Parent Class function
dog1.bark();

// Create object of Cat class
Cat cat1;
cout << "\nCat Class:" << endl;
cat1.info();  // Parent Class function
cat1.meow();

return 0;
}
