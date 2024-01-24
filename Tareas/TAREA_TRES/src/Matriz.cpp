/* Se incluye el header asociado a esta clase */
#include "Matriz.hpp"

/* Se instancia el contructor: */
template <typename T>
Matriz<T>::Matriz(bool complejo): complejo(complejo) {};


/* Se crea un método que le solicite al usuario el tamaño de la matriz */
template <typename T>
void Matriz<T>::sizeMatriz() {
    /* Se inicializan los atributos cada vez se ingresa a este método*/
    filas = 0;
    columnas = 0;

    /* Se repite el ciclo while hasta que se ingrese un valor válido */
    while (filas <= 0) {
        /* Se crea un bloque de excepción para asegurar que los datos ingresados por el usuario puedan
        ser convertidos a un valor entero */
        try {
            cout << "Ingrese el valor de filas de la matriz: ";
            cin >> filas; /* Ingresa el valor al atributo filas */
            
            /* Si el dato ingresado es incorrecto se vuelve a solicitar el ingreso */
            if (cin.fail()) {
                /* Limpia el estado de error*/
                cin.clear();
                throw invalid_argument("Error: No se ingreso un numero.");
            }
            /* Si no se puede realizar una conversión explícita que lance un error y termine el programa*/
            else if (static_cast<int>(filas) <= 0) {
                throw invalid_argument("Error: Debiste ingresar un numero, valido mayor que 0.");
            } 

            /* Se asegura que el valor ingresado sea un entero */
            filas = static_cast<int>(filas);
        }
        catch(const exception& e)
        {
            cerr << e.what() << endl;
        }     
        /* Descarta caracteres no deseados de cin */
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    /* Se repite el ciclo while hasta que se ingrese un valor válido */
    while (columnas <= 0) {
        /* Se crea un bloque de excepción para asegurar que los datos ingresados por el usuario puedan
        ser convertidos a un valor entero */
        try {
            cout << "Ingrese el valor de columnas de la matriz: ";
            cin >> columnas; /* Ingresa el valor al atributo columnas */
            
            /* Si el dato ingresado es incorrecto se vuelve a solicitar el ingreso */
            if (cin.fail()) {
                /* Limpia el estado de error*/
                cin.clear();
                throw invalid_argument("Error: No se ingreso un numero.");
            }
            /* Si no se puede realizar una conversión explícita que lance un error y termine el programa*/
            else if (static_cast<int>(columnas) <= 0) {
                throw invalid_argument("Error: Debiste ingresar un numero, valido mayor que 0.");
            } 

            /* Se asegura que el valor ingresado sea un entero */
            columnas = static_cast<int>(columnas);
        }
        catch(const exception& e)
        {
            cerr << e.what() << endl;
        } 
        /* Descarta caracteres no deseados de cin */
        cin.ignore(numeric_limits<streamsize>::max(), '\n');   
    }
}

/* Se crea un método que utiliza el vector para ingresar valores al vector */
template <typename T>
void Matriz<T>::ingresarDatosMatriz() {
    /* Se inicializa la matriz limpiandola: */
    datosMatriz.clear();

    /* Se crea un ciclo for anidado para ingresar los datos en el vector datosMatriz */
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {  
            /* Bloque de excepción para asegurar que se ingresen los datos correctamente */
            try {
                /* Se le solicita al usuario que ingrese un dato para la matriz. Adicionalmente se le va
                indicando en qué posición de la matriz ingresa el dato */
                cout << "Ingrese el numero de la posicion " << i + 1 << "x" << j + 1 << ": ";
                cin >> dato;

                /* Si el dato ingresado es incorrecto se vuelve a solicitar el ingreso */
                if (cin.fail()) {
                    /* Limpia el estado de error*/
                    cin.clear();
                    /* Se le resta 1 al iterador j para que el usuario pueda ingresar un dato valido */
                    j--;
                    throw invalid_argument("\nError: No se ingreso un numero.\n");
                } 
                else {  /* Se ingresa el dato, el cual es valido */
                    /* Ingresa el dato a la "matriz" */
                    datosMatriz.push_back(dato);
                }  
            }
            catch(const exception& e) {
                cerr << e.what() << '\n';
            }
            /* Descarta caracteres no deseados de cin */
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } 
}


/* Se crea un método que utiliza el vector para ingresar numeros complejos al vector */
template <typename T>
void Matriz<T>::ingresarDatosComplejos() {
    /* Se crean una bandera para no reescribir la parte real y la imaginaria fue incorrecta */
    bool realLista = false;
    /* Se inicializa la matriz limpiandola: */
    datosMatriz.clear();

    /* Se crea un ciclo for anidado para ingresar los datos en el vector datosMatriz */
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {  
            /* Bloque de excepción para asegurar que se ingresen los datos correctamente */
            try {
                /* Si realLista no es igual a false significa que esta lista y no necesita ingresarse.
                   Esto se usa para cuando hay un error en la parte imaginaria */
                if (realLista == false){
                    /* Se le solicita al usuario que ingrese un dato para la matriz. Adicionalmente se le va
                    indicando en qué posición de la matriz ingresa el dato */
                    cout << "Ingrese la parte real de la posicion " << i + 1 << "x" << j + 1 << ": ";
                    cin >> dato;

                    /* Si el dato ingresado es incorrecto se vuelve a solicitar el ingreso */
                    if (cin.fail()) {
                        /* Limpia el estado de error*/
                        cin.clear();
                        /* Descarta caracteres no deseados de cin */
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        /* Se le resta 1 al iterador j para que el usuario pueda ingresar un dato valido */
                        j--;
                        throw invalid_argument("\nError: No se ingreso un numero.\n");
                    } 
                    else {  /* Se ingresa el dato, el cual es valido */
                        /* Ingresa la parte real a la "matriz" */
                        datosMatriz.push_back(dato);

                        /* Se dice que la parte real ingresada fue correcta y esta lista*/
                        realLista = true;
                    }
                    /* Descarta caracteres no deseados de cin */
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } 

                /* Se le solicita al usuario que ingrese un dato para la matriz. Adicionalmente se le va
                indicando en qué posición de la matriz ingresa el dato */
                cout << "Ingrese la parte imaginaria de la posicion " << i + 1 << "x" << j + 1 << ": ";
                cin >> dato;

                /* Si el dato ingresado es incorrecto se vuelve a solicitar el ingreso */
                if (cin.fail()) {
                    /* Limpia el estado de error*/
                    cin.clear();
                    /* Descarta caracteres no deseados de cin */
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    /* Se le resta 1 al iterador j para que el usuario pueda ingresar un dato valido
                    para la parte imaginaria */
                    j--;
                    cout << realLista;
                    throw invalid_argument("\nError: No se ingreso un numero.\n");
                } 
                else {  /* Se ingresa el dato, el cual es valido */
                    /* Ingresa la parte imaginaria a la "matriz" */
                    datosMatriz.push_back(dato);

                    /* Se dice que la parte imaginaria ingresada fue correcta y se va a agregar una
                    nueva parte real */
                    realLista = false;
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
         << filas << "x" << columnas << ":" << endl << endl;

    /* Se crea un ciclo for anidado para mostrar los datos en el vector datosMatriz */
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {   
            /* Se imprime el valor actual del iterador y luego se suma uno para acceder al siguiente dato*/
            cout << *it << "  ";
            it++;
        }

        /* Hace un salto de línea cuando se terminó de mostrar los datos de una fila */
        cout << endl;
    }
}

/* Método para mostrar el contenido de la matriz siempre y cuando sea válida*/
template <typename T>
void Matriz<T>::mostrarComplejosMatriz() const{
    /* Se instancia un iterador para manipular el contenido del vector */
    typename vector<T>::const_iterator it = this->datosMatriz.begin();

    /* Mensaje de lo que se va a imprimir */
    cout << "A continuacion se imprime el contenido de la Matriz " 
         << filas << "x" <<   columnas << ":" << endl << endl;

    /* Se crea un ciclo for anidado para mostrar los datos en el vector datosMatriz */
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {   
            /* Se imprime primero la parte real */
            cout << *it;
            it++;

            /* Luego se pregunta si la parte imaginaria es positiva o no */
            if(*it >= 0){
                /* Se imprime un número de más para indicar que es positivo */
                cout << "+";
            }
            /*El número negativo no necesita que se le coloque un simbolo. Se imprime en número
              imaginario. */
            cout << *it << "j  ";
            it++;   /* Para que continue el siguiente número real*/
        }

        /* Hace un salto de línea cuando se terminó de mostrar los datos de una fila */
        cout << endl;
    }
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
            cin >> dato;

            /* Si el dato ingresado es incorrecto se vuelve a solicitar el ingreso */
            if (cin.fail()) {
                /* Limpia el estado de error*/
                cin.clear();
                /* Descarta caracteres no deseados hasta alcanzar el salto de línea */
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Error: No se ingreso un numero.");
            }
            else if (dato == 1) {   
                cout << "Selecciona el tamayo de la matriz:\n" ;
                sizeMatriz();
            }
            else if (dato == 2) {   
                /* Comprueba que el valor de los atributos sea mayor a cero para que tenga sentido la matriz */
                if (filas <= 0 || columnas <= 0)
                {
                    throw invalid_argument("Error: La matriz carece de tamayo, ingresa la opcion 1 antes");
                }

                cout << "Ingrese los datos de la matriz:\n" ;

                if (complejo == true){
                    ingresarDatosComplejos();
                } else {
                    ingresarDatosMatriz();
                }

            }
            else if (dato == 3) {   
                /* Verificar si el vector datosMatriz está vacío */
                if (  datosMatriz.empty()) {
                    throw out_of_range("Error: La matriz esta vacia, ingrese la opcion 2 antes.");
                }
                if (complejo == true){
                    mostrarComplejosMatriz();
                } else {
                    mostrarMatriz();
                }
            }
            else if (dato == 4){   
                if (datosMatriz.empty()) {
                    throw out_of_range("Error: La matriz esta vacia, es mejor ingresar la opcion 2 antes.");
                } else
                {
                    return; /* Retorna si el usuario ya termino la matriz*/
                }
            }
            else {
                /* Descarta caracteres no deseados hasta alcanzar el salto de línea */
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Error: No se ingreso un numero dentro de las opciones disponibles.");
            }
        }
        catch(const exception& e) {
            cerr << e.what() << '\n';
        }  

    }
}

/* Lo siguiente son métodos para obtener información de los atributos */
template<typename T>
T Matriz<T>::getFilas() const{
    return filas;
}

template<typename T>
T Matriz<T>::getColumnas() const{
    return columnas;
}

template<typename T>
bool Matriz<T>::getComplejo() const{
    return complejo;
}

/* Se crea un método para obtener el dato correspondiende a una fila x columna */
template<typename T>
T Matriz<T>::get(int fila, int columna) const {
    /* Realiza la lógica para obtener el dato en la posición fila x columna
    y devuelve el valor correspondiente*/
    return datosMatriz[fila * columnas + columna];
}