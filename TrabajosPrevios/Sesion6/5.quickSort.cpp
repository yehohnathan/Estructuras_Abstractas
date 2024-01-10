/*
    El código fue estaido de la página: https://www.geeksforgeeks.org/cpp-program-for-quicksort/

    En donde se implementa el algoritmo de ordenamiento quickSort, en donde este
    utiliza la técnica de "divide y vencerás" cuya forma es la de un arbol.

    La idea básica detrás del algoritmo es elegir un elemento pivote del arrelo
    y particionar el arreglo alrededor de ese elemento. Todos los elementos 
    menores que el pivote se colocan a la izquierda del pivote, y todos los 
    elementos mayores se colocan a la derecha. Luego se repite el recursivamente
    para los subarreglos y despues del pivote hasta que todo el arreglo este 
    ordenado.

    * En clases el elemento pivote es el de más a la derecha
*/

// C++ Implementation of the Quick Sort Algorithm.
#include <iostream>
using namespace std;
 
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
 
int main()
{
 
    int arr[] = {9, -3, 5, 2, 6, 8, -6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);;
 
    quickSort(arr, 0, n - 1);
 
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
 
    return 0;
}

/*
    Tiempo de complejidad:
    Best:       O(n*log n)
    Worst:      O(n^2)
    Average:    O(n*log n)
    
    Space Complexy: O(n*log n)
*/