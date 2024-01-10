/*
    Ahora un ejemplo pero con una clase amiga, esto significa que con usar el comando
    "friend" yo decido el tipo de objeto que pueda tener acceso a los miembros
    privados de una clase
*/

#include <iostream>
using namespace std;

class ClassB;  // Declaración anticipada de ClassB

class ClassA {
private:
    int numA;
    
    // friend class declaration
    friend class ClassB;
    
public:
    // constructor to initialize numA to 12
    ClassA() : numA(12) {}
};

class ClassB {
private:
    int numB;
    
public:
    // constructor to initialize numB to 1
    ClassB() : numB(1) {}
    
    // member function to add numa 
    // from ClassA and numb from Class B
    int add() {
        ClassA objectA;
        return objectA.numA + numB;
     }
};

int main() {
   ClassB objectB;
   cout << "Sum = " << objectB.add();
   return 0;
}
