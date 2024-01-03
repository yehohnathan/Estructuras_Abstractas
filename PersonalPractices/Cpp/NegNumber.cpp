/*  Nada más se encarga de verificar si el numero ingresado 
    es negativo
*/

#include <iostream>
#include <string>
using namespace std;
signed int number;

int main(){
    cout << "Verifica si el numero ingresado es negativo. Ingrese un numero: ";
    cin  >> number;

    if (number == 0)
    {
        cout << "El valor ingresado es igual a 0" << endl;
    }
    else if (number < 0)
    {
        cout << "El valor ingresado es negativo" <<  endl;
    }
    else
    {
        cout << "El valor ingresado es positivo" << endl;
    }

    cout << "FIN DEL PROGRAMA";
}