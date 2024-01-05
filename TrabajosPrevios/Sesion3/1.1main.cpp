/*  Se práctica el uso de header de archivos como "sum.hpp", muy diferentes 
    a un <iostream> que es un header estándar del sistema.
*/

#include <iostream>
#include "1.3sum.hpp"
using namespace std;

int main(){
    int num1 = 5;
    int num2 = 3;
    int result = sum(num1,num2);

    cout << "El resultado de la suma de " << num1 << " y " << num2 << " es: "<<result << endl;
}