#include <iostream>
#include <string>
using namespace std;

class Animal {
    private:    // Si hay miembros que no estan especificados serán privados
        string color;

    protected:
        string type;

    public:
        void run() { cout << "I can run ... BASE!" << endl; }
        void eat() { cout << "I can eat!" << endl; }
        void sleep() { cout << "I can sleep!" << endl; }
        void setColor(string clr) { color = clr; }
        string getColor() { return color; }
};

class Dog : public Animal {
    public:
        void run() { cout << "I can run ... DERIVED!" << endl; }    // Sobreescritura
        void setType(string tp) { type = tp; }  // type proviene de Animal
        void displayInfo(string c) {            // Nuevo método de clase Dog
            setColor(c);                        // Nuevo de Dog, protegido en Animal
            cout << "My color is: " << c << endl;       
            cout << "My type is: "  << type  << endl;   // type proviene de Animal
            bark();
         }
        void bark() { cout <<"It Can bark! woof woof!!"<<endl;} // Nuevo método de clase Dog
};

int main(){
    Dog dog1;
    dog1.run();     // Imprime el método derivado
    dog1.eat();
    dog1.sleep();

    dog1.setColor("black");
    
    dog1.bark();
    
    dog1.setType("Doberman");
    
   // display info for dog
   dog1.displayInfo(dog1.getColor());
   
   return 0;
}


/*
Otros métodos de hacer herencia:

class Base {
public:
    int x;
protected:
    int y;
private:
    int z;
};

class PublicDerived: public Base {
    // x is public
    // y is protected
    // z is not accessible from PublicDerived
};

class ProtectedDerived: protected Base {
    // x is protected -> no se pueden usar fuera de la clase
    // y is protected
    // z is not accessible from ProtectedDerived
};

class PrivateDerived: private Base {
   // x is private 
   // y is private 
   // z is not accessible from PrivateDerived 
};



*/