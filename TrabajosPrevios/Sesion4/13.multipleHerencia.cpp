/*
    Las clases no se gastan, por lo que se puede crear una clase derivada a partir
    de dos clases separadas.
*/

#include <iostream>
using namespace std;

class Mammal {
public:
    Mammal() {
        cout << "Mammals can give direct birth." << endl;
    }
};

class WingedAnimal {
public:
    WingedAnimal() {
        cout << "Winged animal can flap." << endl;
    }
};

// Bat hereda de Mammal y de WingedAnimal
class Bat: public Mammal, public WingedAnimal {};

int main() {
    Bat b1;
    return 0;
}
