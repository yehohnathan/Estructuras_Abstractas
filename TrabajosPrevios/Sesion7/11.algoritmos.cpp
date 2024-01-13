/*
    A continuación se muestra un código utilizando el algoritmo de ordenamiento sort
    para ordenar un arreglo de menor a mayor.

    Este proviene de la librería STL y se instancia con <algorithm>.
*/
#include <iostream>     // cout
#include <algorithm>    // sort
#include <vector>       // vector

using namespace std;

// Función que se encarga de retornar False o True dependiendo de si i < j
bool myfunction (int i,int j) { return (i<j); }

void printArray(vector<int> myvector){
  for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
    cout << ' ' << *it;
    cout << '\n';
}

// Estructura que contiene la misma función:
struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main () {

  // Creo un arreglo desordenado de enteros
  int myints[] = {32,71,12,45,26,80,53,33};

  // Creo un vector que va desde myints[1] hasta myints[8]
  vector<int> myvector (myints, myints+8);              

  cout << "Ordena los primero 4 elementos de myvector:";
  sort(myvector.begin(), myvector.begin()+4);    
  printArray(myvector);

  cout << "Ordena los ultimos 4 elementos de myvector:";
  sort(myvector.begin()+4, myvector.end(), myfunction); 
  printArray(myvector);

  cout << "Ordena todo myvector:"; 
  sort(myvector.begin(), myvector.end(), myobject); 
  printArray(myvector);   

  return 0;
}
