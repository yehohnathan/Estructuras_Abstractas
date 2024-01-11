#include <iostream>
using namespace std;

/* .data section */
int variableGlobal = 10;

/* .text section  */
void funcionGlobal(){

    /* .data section */
    static int variableLocalEstatica = 5;

    /* .stack section: se puede usar en este punto o otros puntos */
    int variableLocal = 20;

    /* Mostrar el valor de las variables */
    cout << "\nVariable global: " << variableGlobal << endl;
    cout << "Variable local estatica: " << variableLocalEstatica << endl;
    cout << "Variable local (funcionGlobal): " << variableLocal << endl;
}

int main(){
    /* .stack section */
    int variableMain = 15;

    cout << "Variable local (main): " << variableMain << endl;
    
    funcionGlobal();

    /*  heap section */
    int* variableDinamica = new int;
    * variableDinamica = 25;    // Modifica en esa dirección donde apunta variableDinamica

    cout << "\nVariable dinamica: " << *variableDinamica << endl; // Muestra el contenido de la dirección
    cout << "Direccion de variable dinamica: " << variableDinamica << endl; 
    delete variableDinamica;

    return 0;
}