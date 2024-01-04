// Código sobre break y continuo, que ejerce sobre los ciclos.

#include <iostream>
using namespace std;

int main(){
    int i;
    // Para el ciclo for
    for (i = 1; i <= 5; ++i) {
        cout << i << " ";
        if (i == 3) {
            std::cout << "Se imprimio un 3, fin del bucle";
            break; 
        }
    }

    cout << endl;
    // Para ciclo while
    i = 1;
    while (i <= 5) {
        cout << i << " ";
        if (i == 3) {
            std::cout << "Se imprimio un 3, fin del bucle";
            break; 
        }
        i ++;
    }

    cout << endl;    
    // Para el ciclo for
    for (i = 1; i <= 5; ++i) {
        if (i == 3) {
            cout << "\nAqui iba un 3" << endl;
            continue;
        }
        cout << i << " ";
    }

    cout << endl;
    // Para ciclo while
    i = 1;
    while (i <= 5) {
        if (i == 3) {
            cout << "\nAqui iba un 3" << endl;
            i ++;       // Aquí hay que tener mucho cuidado porque se podría enciclar
            continue;
        }
        cout << i << " ";
        i ++;
    }
    
    return 0;
}