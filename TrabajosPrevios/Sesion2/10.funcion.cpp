/*
    Se utiliza una función void y argumentos en el main

*/

#include <iostream>
using namespace std;

void displaNum(int n1, double n2){
    cout << "El int number es " << n1 << endl;
    cout << "El double number es " << n2;
}

int main(int argc, char*argv[]){
    cout << "Numero de argumentos: " << argc << endl;
    cout << "Nombre del programa: " << argv[0] << endl;

    if (argc > 1){
        cout << "Argumentos adicionales:" << endl;
    for (int i = 1; i < argc; i++)
    {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }
    
    }
    
    int num1 = 5;
    double num2 = 5.5;

    displaNum(num1, num2);

    return 0;

}