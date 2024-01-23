/* Se incluye el header asociado a esta clase */
#include "Matriz.hpp"

/* Se crea un método que le solicite al usuario el tamaño de la matriz */
template <typename T>
void Matriz<T>::sizeMatriz() {
    /* Se inicializan los atributos cada vez se ingresa a este método*/
    this->filas = 0;
    this->columnas = 0;

    /* Se repite el ciclo while hasta que se ingrese un valor válido */
    while (this->filas <= 0) {
        /* Se crea un bloque de excepción para asegurar que los datos ingresados por el usuario puedan
        ser convertidos a un valor entero */
        try {
            cout << "Ingrese el valor de filas de la matriz: ";
            cin >> this->filas; /* Ingresa el valor al atributo filas */
            
            /* Si el dato ingresado es incorrecto se vuelve a solicitar el ingreso */
            if (cin.fail()) {
                /* Limpia el estado de error*/
                cin.clear();
                /* Descarta caracteres no deseados hasta alcanzar el salto de línea */
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("\nError: No se ingreso un numero.");
            }
            /* Si no se puede realizar una conversión explícita que lance un error y termine el programa*/
            else if (static_cast<int>(this->filas) <= 0) {
                /* Descarta caracteres no deseados de cin */
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                throw invalid_argument("\nError: Debiste ingresar un numero, valido mayor que 0.");
            } 

            /* Se asegura que el valor ingresado sea un entero */
            this->filas = static_cast<int>(this->filas);
                
            /* Descarta caracteres no deseados de cin */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            /* Se inserta un salto de linea para darle paso a las columnas */
            cout << "\n";
        }
        catch(const exception& e)
        {
            cerr << e.what() << endl;
        }     
    }
    
    /* Se repite el ciclo while hasta que se ingrese un valor válido */
    while (this->columnas <= 0) {
        /* Se crea un bloque de excepción para asegurar que los datos ingresados por el usuario puedan
        ser convertidos a un valor entero */
        try {
            cout << "Ingrese el valor de columnas de la matriz: ";
            cin >> this->columnas; /* Ingresa el valor al atributo columnas */
            
            /* Si el dato ingresado es incorrecto se vuelve a solicitar el ingreso */
            if (cin.fail()) {
                /* Limpia el estado de error*/
                cin.clear();
                /* Descarta caracteres no deseados hasta alcanzar el salto de línea */
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("\nError: No se ingreso un numero.");
            }
            /* Si no se puede realizar una conversión explícita que lance un error y termine el programa*/
            else if (static_cast<int>(this->columnas) <= 0) {
                /* Descarta caracteres no deseados de cin */
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                throw invalid_argument("\nError: Debiste ingresar un numero, valido mayor que 0.");
            } 

            /* Se asegura que el valor ingresado sea un entero */
            this->columnas = static_cast<int>(this->columnas);
                
            /* Descarta caracteres no deseados de cin */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch(const exception& e)
        {
            cerr << e.what() << endl;
        }     
    }
}

/* Se crea un método que utiliza el vector para ingresar valores al vector */
template <typename T>
void Matriz<T>::ingresarDatosMatriz() {
    /* Se inicializa la matriz limpiandola: */
    datosMatriz.clear();

    /* Se crea un ciclo for anidado para ingresar los datos en el vector datosMatriz */
    for (int i = 0; i < this->filas; i++) {
        for (int j = 0; j < this->columnas; j++) {  
            /* Bloque de excepción para asegurar que se ingresen los datos correctamente */
            try {
                /* Se le solicita al usuario que ingrese un dato para la matriz. Adicionalmente se le va
                indicando en qué posición de la matriz ingresa el dato */
                cout << "Ingrese el dato para la fila " << i + 1 << " columna " << j + 1 << ": ";
                cin >> this->dato;

                /* Si el dato ingresado es incorrecto se vuelve a solicitar el ingreso */
                if (cin.fail()) {
                    /* Limpia el estado de error*/
                    cin.clear();
                    /* Descarta caracteres no deseados de cin */
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    /* Se le resta 1 al iterador j para que el usuario pueda ingresar un dato valido*/
                    j--;
                    throw invalid_argument("\nError: No se ingreso un numero.\n");
                } 
                else {  /* Se ingresa el dato, el cual es valido */
                    /* Ingresa el dato a la "matriz" */
                    datosMatriz.push_back(this->dato);
                }
                /* Descarta caracteres no deseados de cin */
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                
            }
            catch(const exception& e) {
                cerr << e.what() << '\n';
            }
        }
    } 
}

/* Método para mostrar el contenido de la matriz siempre y cuando sea válida*/
template <typename T>
void Matriz<T>::mostrarMatriz() const{
    /* Se instancia un iterador para manipular el contenido del vector */
    typename vector<T>::const_iterator it = this->datosMatriz.begin();

    /* Mensaje de lo que se va a imprimir */
    cout << "A continuacion se imprime el contenido de la Matriz " 
         << this->filas << "x" << this->columnas << ":" << endl << endl;

    /* Se crea un ciclo for anidado para mostrar los datos en el vector datosMatriz */
    for (int i = 0; i < this->filas; i++) {
        for (int j = 0; j < this->columnas; j++) {   
            /* Se imprime el valor actual del iterador y luego se suma uno para acceder al siguiente dato*/
            cout << *it << " ";
            it++;
        }

        /* Hace un salto de línea cuando se terminó de mostrar los datos de una fila */
        cout << endl;
    }

    /* Se hace un salto de línea para que se vea más clara la matriz */
    cout << endl;
}


/* Este menú sirve mostrarle al usuario todas las funciones que puede realizar con
el objeto sin importar si se equivoca */
template <typename T>
void Matriz<T>::menuMatriz() {
    cout << "Seleccione una de las siguientes opciones para su matriz, ingresando un numero entero:\n"
         << "Ingrese 1 para seleccionar la cantidad de filas y columnas de la matriz.\n"
         << "Ingrese 2 para ingresar los datos de la matriz.\n"
         << "Ingrese 3 para mostrar la matriz ingresada.\n"
         << "Ingrese 4 para dar por finalizada la matriz.\n";

    while (1) {
        try {
            cout << "\nIngrese una opcion para su matriz: ";
            cin >> this->dato;

            /* Si el dato ingresado es incorrecto se vuelve a solicitar el ingreso */
            if (cin.fail()) {
                /* Limpia el estado de error*/
                cin.clear();
                /* Descarta caracteres no deseados hasta alcanzar el salto de línea */
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                throw invalid_argument("\nError: No se ingreso un numero.");
            }
            else if (this->dato == 1) {   
                cout << "\nSelecciona el tamayo de la matriz:\n" ;
                sizeMatriz();
            }
            else if (this->dato == 2) {   
                /* Comprueba que el valor de los atributos sea mayor a cero para que tenga sentido la matriz */
                if (this->filas <= 0 || this->columnas <= 0)
                {
                    throw invalid_argument("Error: La matriz carece de tamayo, ingresa la opcion 1 antes");
                }
                cout << "\nIngrese los datos de la matriz:\n" ;
                ingresarDatosMatriz();

            }
            else if (this->dato == 3) {   
                /* Verificar si el vector datosMatriz está vacío */
                if (this->datosMatriz.empty()) {
                    throw out_of_range("\nError: La matriz esta vacia, ingrese la opcion 2 antes.");
                }
                mostrarMatriz();
            }
            else if (this->dato == 4){   
                cout << this->dato;
                return;
            }
            else {
                throw invalid_argument("\nError: No se ingreso un numero dentro de las opciones disponibles.");
            }
        }
        catch(const std::exception& e) {
                std::cerr << e.what() << '\n';
        }  
    }
}