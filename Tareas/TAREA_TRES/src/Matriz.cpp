/* Se incluye el header asociado a esta clase */
#include "Matriz.hpp"

/* Se crea un método que le solicite al usuario el tamaño de la matriz */
template <typename T>
void Matriz<T>::sizeMatriz() {
    /* Se crea un bloque de excepción para asegurar que los datos ingresados por el usuario puedan
    ser convertidos a un valor entero*/
    try
    {
        cout << "Ingrese el valor de filas de la matriz: ";
        cin >> this->filas; /* Ingresa el valor al atributo filas */
        
        /* Si no se puede realizar una conversión explícita que lance un error y termine el programa*/
        if (static_cast<int>(this->filas) == 0)
        {
            throw invalid_argument("Error: Debiste ingresar un numero");
        } 
        else if (static_cast<int>(this->filas) < 0)
        {
            throw invalid_argument("Error: Ingresa un numero mayor o igual a 0");
        }

        

        cout << "Ingrese el valor de columnas de la matriz: ";
        cin >> this->columnas; /* Ingresa el valor al atributo filas */

        /* Si no se puede realizar una conversión explícita que lance un error y termine el programa*/
        if (static_cast<int>(this->columnas) == 0)
        {
            throw invalid_argument("Error: Debiste ingresar un numero");
        }
        else if (static_cast<int>(this->columnas) < 0)
        {
            throw invalid_argument("Error: Ingresa un numero mayor o igual a 0");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Excepcion: "<< e.what() << endl;
    }

    /* Se encarga de convertir los aributos en enteros. Y si no es un entero valido le asigna un cero
    por lo que la matriz no existiría */
    
    this->filas = static_cast<int>(this->filas);
    this->columnas = static_cast<int>(this->columnas);

}

template <typename T>
void Matriz<T>::mostrarMatriz() const{
    if (this->filas <= 0 || this->columnas <= 0){
        cout << "\nNo hay matriz que mostrar" << endl;
    } 
    else
    {
        cout << this->filas << endl;
        cout << this->columnas << endl;
    }
}