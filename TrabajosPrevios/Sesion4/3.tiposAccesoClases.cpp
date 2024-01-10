#include <iostream>
using namespace std;

class Animal {
public: // Todas las demás clases y funciones pueden acceder a los siguientes elementos
        // Same Class: Yes  Derived Class: Yes  Outside Class: Yes
    void setEdad(int age) {
        edad = age;
    }
    int getEdad() {
        return edad;
    }

protected:  // Los elementos son como los privados, excepto que las clases 
        // derivadas pueden acceder a ellos.
        // Same Class: Yes  Derived Class: Yes  Outside Class: no
    string nombre;

private:    // No se puede acceder a los elementos fuera de la clase en la que están 
        // declarados, excepto por clases y funciones amigas.
        // Same Class: Yes  Derived Class: No  Outside Class: no
    int edad;
};

// Herencia. La clase Perro toma de la clase Animal. Esto es una clase derivada
class Perro : public Animal { 
public:
    void setNombre(string n) {
        nombre = n;
    }
    string getNombre() {
        return nombre;
    }

    /* Esto hereda de la clase Animal
    void setEdad(int age) {
        edad = age;
    }
    int getEdad() {
        return edad;
    }*/
};

int main() {
    Perro miPerro;
    
    miPerro.setNombre("Toby");
    miPerro.setEdad(3);

    cout << "Mi perro se llama " << miPerro.getNombre() << endl;
    cout << "Y tiene " << miPerro.getEdad() << " anios." << endl;

    return 0;
}
