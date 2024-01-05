/*
    Los defines con como etiquetas o variables constantes.
*/

#include <iostream>
using namespace std;

#define BOOK_ID_MAX 10  // Cada vez que ponga esta etiqueta se interpreta como un 10

enum {
    CASA_BADILLA,
    CASA_ALVARADO,
    CASA_SOLANO,
    CASA_MAX
} casas_t;

int main(){
    cout << "El valor de Book ID Max es: " << BOOK_ID_MAX << endl;

    cout << "La cantidad de casa en el condiminio es: " << CASA_MAX + 1 << endl;

    return 0;
}