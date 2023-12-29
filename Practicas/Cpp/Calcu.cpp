/*  A continuación se procede a realizar un ejercicio mental
    para comprobar el entendimiento actual de la parte 1
    del curso.
    
    Problema a resolver: Calculadora simple
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
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
}

