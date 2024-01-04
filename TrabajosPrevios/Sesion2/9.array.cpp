// Simple impresión de array (matriz)

#include <iostream>
using namespace std;

int main() {
    int numMatriz [3][4] = {{1,2,3,4},{8,9,10,11},{101,102,103,104}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << numMatriz[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}