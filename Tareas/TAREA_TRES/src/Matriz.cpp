/* Se incluye el header asociado a esta clase */
#include "Matriz.hpp"

/* Se crea un método que le solicite al usuario el tamaño de la matriz */
template <typename T>
void Matriz<T>::sizeMatriz() {
    /* Se crea un bloque de excepción para asegurar que los datos ingresados por el usuario puedan
    ser convertidos a un valor entero */
    try
    {
        cout << "Ingrese el valor de filas de la matriz: ";
        cin >> this->filas; /* Ingresa el valor al atributo filas */
        
        /* Si no se puede realizar una conversión explícita que lance un error y termine el programa*/
        if (static_cast<int>(this->filas) == 0)
        {
            throw invalid_argument("\nError: Debiste ingresar un numero.");
        } 
        else if (static_cast<int>(this->filas) < 0)
        {
            throw invalid_argument("\nError: Ingresa un numero mayor o igual a 0.");
        }

        

        cout << "Ingrese el valor de columnas de la matriz: ";
        cin >> this->columnas; /* Ingresa el valor al atributo filas */

        /* Si no se puede realizar una conversión explícita que lance un error y termine el programa*/
        if (static_cast<int>(this->columnas) == 0)
        {
            throw invalid_argument("\nError: Debiste ingresar un numero.");
        }
        else if (static_cast<int>(this->columnas) < 0)
        {
            throw invalid_argument("\nError: Ingresa un numero mayor o igual a 0.");
        }
    }
    catch(const exception& e)
    {
        cerr << e.what() << endl;
    }
}

/* Se crea un método que utiliza el vector para ingresar valores al vector */
template <typename T>
void Matriz<T>::ingresarDatosMatriz() {
    /* Se crea un bloque de excepción para asegurar que los datos ingresados por el usuario puedan
    ser agregados a una matriz */
    try {
        /* Se encarga de convertir los atributos en enteros. Y si no es un entero válido le asigna un cero
        por lo que la matriz no existiría */
        this->filas = static_cast<int>(this->filas);
        this->columnas = static_cast<int>(this->columnas);

        /* Comprueba que el valor de los atributos sea mayor a cero para que tenga sentido la matriz */
        if (this->filas <= 0 || this->columnas <= 0)
        {
            throw invalid_argument("Error: Valor de filas o columnas no válido para crear una matriz.");
        }

        /* Se crea un ciclo for anidado para ingresar los datos en el vector datosMatriz */
        for (int i = 0; i < this->filas; i++)
        {
            for (int j = 0; j < this->columnas; j++)
            {   
                /* Se le solicita al usuario que ingrese un dato para la matriz. Adicionalmente se le va
                indicando en qué posición de la matriz ingresa el dato*/
                cout << "Ingrese el dato para la fila " << i + 1 << " columna " << j + 1 << ": ";
                cin >> this->dato;

                /* Si el dato ingresado es incorrecto se vuelve a solicitar el inggreso */
                if (cin.fail()) {
                    cout << "\nEl numero es de un tipo de dato no esperado, intentalo de nuevo.\n";
                    datosMatriz.clear();    /* Limpiar el contenido de la matriz */
                    return;
                }

                /* Ingresa el dato a la "matriz" */
                datosMatriz.push_back(this->dato);
            }
        }
    } 
    catch (const exception& e) 
    {
        cerr << e.what() << endl;
    }
}

/* Método para mostrar el contenido de la matriz siempre y cuando sea válida*/
template <typename T>
void Matriz<T>::mostrarMatriz() {
    try {
        /* Se encarga de convertir los atributos en enteros. Y si no es un entero válido le asigna un cero
        por lo que la matriz no existiría */
        this->filas = static_cast<int>(this->filas);
        this->columnas = static_cast<int>(this->columnas);


        if (this->filas <= 0 || this->columnas <= 0)
        {
            throw invalid_argument("\nError: Valor de filas o columnas no valido para crear una matriz.");
        }

        /* Se instancia un iterador para manipular el contenido del vector */
        typename vector<T>::const_iterator it = this->datosMatriz.begin();

        /* Verificar si el vector datosMatriz está vacío */
        if (this->datosMatriz.empty()) {
            throw out_of_range("\nError: La matriz esta vacia.");
        }

        /* Mensaje de lo que se va a imprimir */
        cout << "A continuacion se imprime el contenido de la Matriz " 
             << this->filas << "x" << this->columnas << ":" << endl << endl;

        /* Se crea un ciclo for anidado para mostrar los datos en el vector datosMatriz */
        for (int i = 0; i < this->filas; i++)
        {
            for (int j = 0; j < this->columnas; j++)
            {   
                /* Se imprime el valor actual del iterador y luego se suma uno para acceder al siguiente dato*/
                cout << *it << " ";
                it++;
            }

            /* Hace un salto de línea cuando se terminó de mostrar los datos de una fila */
            cout << endl;
        }

        /* Se hace un salto de línea para que se vea más clara la matriz */
        cout << endl;

    } catch (const exception& e) 
    {
        cout << e.what() << endl;
    }
}