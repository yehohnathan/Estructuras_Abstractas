/*
    Programa con un uso básico de punteros en C++
*/

#include <iostream>
using namespace std;

void change();

int main(){
    int var = 5;

    int* pointVar;      // Declaro variable puntero
    pointVar =&var;     // Cargo una dirección en el puntero
    
    cout << "var = " << var << endl;

    cout << "Addres of var = " << &var << endl;

    cout << "pointVar = " << pointVar << endl;

    cout << "Content of the addres pointed to by pointVar (*pointVar) = " << *pointVar << endl;

    cout << "*pointVar = " << *&var << " es igual a *&var = " << *&var <<endl; 

    change();
    return 0;
}

void change(){
    int var = 5;
    int* pointVar;
    pointVar =&var;

    cout << "\nvar = " << var << endl;  // Imprime var
    
    // Imprime el contenido de la dirección almacenada en pointVar
    cout << "*pointVar = " << *pointVar << endl;

    cout << "Changing value of var to 7:" << endl;

    var = 7;
    cout << "var = " << var << endl;
    cout << "*pointVar = " << *pointVar << endl;

    cout << "Changing value of *pointVar to 16:" << endl;

    *pointVar = 16;

    cout << "var = " << var << endl;
    cout << "*pointVar = " << *pointVar << endl;
}

/*
    Errores comunes:
    int var, *varPoint;

    varPoint = var Esta malo porque no se le esta ingresando un address
    *varpoint = &var    Lo primero es el valor de la dirección, así que no hace sentido
                        agregarle una dirección.

    Como debe ser:
    varPoint = &var
    *varpoint = var


*/