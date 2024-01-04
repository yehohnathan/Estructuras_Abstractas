/*
    De la misma forma, utilizando funciones void, se realizan los loops
*/

#include <iostream>
using namespace std;

void loopFor();
void loopForNumbers();
void loopWhile();
void loopDoWhile();

int main(){
    loopFor();
    cout << endl;
    loopForNumbers();
    cout << endl;
    loopWhile();
    cout << endl;
    loopDoWhile();
    cout << endl;
}

void loopFor(){
    for (int i = 0; i < 5; i++)
    {
        cout << i << " ";
    }
}

void loopForNumbers(){
    int num_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int n : num_array){    // Bucle basado en rango, en este caso termina hasta llegar
    cout << n << " ";           // al ultimo valor de numArray
    }             
}

void loopWhile(){
    int i = 1;

    while (i <= 5)
    {
        cout << i << " ";
        i++;
    }
}

void loopDoWhile(){
    int i = 1;

    do {
        cout << i << " ";
        i++;
    }

    while (i <= 5);
}