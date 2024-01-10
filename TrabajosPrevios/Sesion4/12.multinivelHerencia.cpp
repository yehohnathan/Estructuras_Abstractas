/*
    La herencia multinivel es como la caida continua de dominos. A partir de una clase
    se crea una clase derivada, de esa clase derivada se crea otra clase derivada, de
    esa clase dereviada se crea otra clase derivada, y así hasta que decida terminal
    este ciclo.
*/

#include <iostream>
using namespace std;

class A {
public:
    void display() {
        cout<<"Base class content.";
    }
};

// B deriva de A
class B : public A {};

// C deriva de B
class C : public B {};

int main() {
    C obj;
    obj.display();  // objt proviene de A, y se acceder desde clase C
    return 0;
}

