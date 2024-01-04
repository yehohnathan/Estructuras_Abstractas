/*
    Aquí se practicará el uso de desiciones y como son muchas se utilizarán
    las funciones void ya vistas en el curso pasado.    
*/

#include <iostream>
using namespace std;

int number;        // Intancia de variables globales

// Prototipos de funciones
void ifTRUE();
void ifFALSE();
void ifelseTRUE();
void ifelseFALSE();
void elseif();
void switchCase();
void anidaciones();

int main(){
    number = 5;
    ifTRUE();
    ifFALSE();
    ifelseTRUE();
    ifelseFALSE();
    cout << endl;

    number = 2;
    elseif();

    number = 0;
    elseif();

    number = -2;
    elseif();
    cout << endl;
    
    switchCase();
    cout << endl;

    anidaciones();

    return 0;
}

void ifTRUE(){
    if (number > 0){
        cout << "Number mayor a 0" << endl;
    }
}

void ifFALSE(){
    if (number < 0){
        cout << "Number menor a 0" << endl;
    }
}

void ifelseTRUE(){
    if (number > 0){
        cout << "Number mayor a 0" << endl;
    }
    else{
        cout << "Number no es mayor a 0" << endl;
    }
}

void ifelseFALSE(){
    if (number < 0){
        cout << "Number menor a 0" << endl;
    }
    else{
        cout << "Number no es menor a 0" << endl;
    }
}

void elseif(){
    if (number > 0){
        cout << "Numero mayor a 0" << endl;
    }
    else if (number == 0) {
        cout << "Numero igual a 0" << endl;
    }
    else{
        cout << "Numero menor a 0" << endl;
    }
}

void switchCase(){
    char operador;
    float num1, num2;
    cout << "Ingrese uno de los siguientes caracteres + (suma), - (resta), * (mult) o / (div): ";
    cin  >> operador;
    cout << "Ingrese dos numeros: " << endl; // endl es como un \n
    cin  >> num1 >> num2;

    switch (operador)
    {
    case '+':
        cout << num1 << " + " << num2 << " = "<< num1 + num2;
        break;

    case '-':
        cout << num1 << " - " << num2 << " = "<< num1 - num2;
        break;
    
    case '*':
        cout << num1 << " * " << num2 << " = "<< num1 * num2;
        break;

    case '/':
        cout << num1 << " / " << num2 << " = "<< num1 / num2;
        break;
    
    default: 
        cout << "No se ingreso el caracter correcto, intentelo nuevamente.";
        break;
    }
    cout << endl;
}

void anidaciones(){
    cout << "Ingrese un numero entero: ";
    cin >> number;

    // Sentancia if primaria
    if (number != 0)
    {
        // Sentencia if secundaria
        if (number > 0)
        {
            cout << "El numero es positivo" << endl;
        }
        else
        {
            cout << "El numero es negativo" << endl;
        }
    }
    else {
        cout << "El numero es 0 y no es positivo ni negativo" << endl;
    }
    cout << "Esta linea siempre se imprime";
}