/*
    Punteros junto arreglos, siempre que se apunte a una variable arreglo lo 
    hará a la primer posición array[0].
*/

#include <iostream>
using namespace std;

int main(){
    int *ptr;
    int array[5] = {2,4,6,8,10};
    ptr = array;

    cout << "ptr + 0 = " << ptr << " es equivalente a &array[0] = " << &array[0] << endl;
    cout << "ptr + 1 = " << ptr + 1 << " es equivalente a &array[1] = " << &array[1] << endl;
    cout << "ptr + 2 = " << ptr + 2 << " es equivalente a &array[2] = " << &array[2] << endl;
    cout << "ptr + 3 = " << ptr + 3 << " es equivalente a &array[3] = " << &array[3] << endl;
    cout << "ptr + 4 = " << ptr + 4 << " es equivalente a &array[4] = " << &array[4] << endl;

    *ptr = array[0];

    cout << "*ptr = " << *ptr << " es equivalente a array[0] = " << array[0] << endl;
    cout << "*(ptr + 1) = " << *(ptr + 1) << " es equivalente a array[1] = " << array[1] << endl;
    cout << "*(ptr + 2) = " << *(ptr + 2) << " es equivalente a array[2] = " << array[2] << endl;
    cout << "*(ptr + 3) = " << *(ptr + 3) << " es equivalente a array[3] = " << array[3] << endl;
    cout << "*(ptr + 4) = " << *(ptr + 4) << " es equivalente a array[4] = " << array[4] << endl;

    float arr[3];
    float *ptr2;

    cout << "\nDisplaying address using arrays: " << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "&array [" << i << "] = " << &arr[i] << endl;
    }
    
    ptr2 = arr;
    cout << "\nDisplaying address using pointers: " << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "ptr + 1" << i << " = " << ptr + 1 << endl;
    }

    return 0;
}