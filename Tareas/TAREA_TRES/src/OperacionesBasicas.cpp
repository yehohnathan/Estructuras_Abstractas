/* Se incluye el header asociado a esta clase */
#include "OperacionesBasicas.hpp"

/* Método para agregar un objeto matriz al vector matriz1 o matriz2 */
template <typename T>
void OperacionesBasicas<T>::agregarMatriz(const Matriz<T> matriz){
    /* Se verifica si el usuario ha ingresado las matrices validando el estado de los
       vectores de la clase. Si el vector matriz1 esta vacio, continue con el vector matriz2
       si también esta vacio. Si ninguno esta vacio lanza un mensaje */
    try
    {
        if(matriz1.empty()){
            cout << "\nHaz ingresado la primera matriz para realizar una operacion basica." << endl;
            matriz1.push_back(matriz);
        } 
        else if(matriz2.empty()){
            cout << "Haz ingresado la segunda matriz para realizar una operacion basica." << endl;
            matriz2.push_back(matriz);
        } 
        else {
            throw out_of_range("\nNo hay espacio disponible, ya se agregaron las dos matrices.");
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

/* El siguiente método se encarga de borrar las matrices guardadas*/
template <typename T>
void OperacionesBasicas<T>::liberarEspacio(){
    /* Se libera el posible espacio almacenado por los vectores */
    matriz1.clear();
    matriz2.clear();

    /* Mensaje indicandole al usuario la acción */
    cout << "\nLas posibles matrices ingresadas han sido borradas. " 
         << "Vuelve a utilizar el metodo agregarMatriz()." << endl;
}

/* Método para validar para saber si se ingresaron dos matrices, si estas dos matrices
   tienen las mismas dimensiones y si son del mismo tipo. */
template <typename T>
void OperacionesBasicas<T>::validarMatrices(){
    /* Se realiza un bloque de excepciones para evitar problemas */
    try {
        /* Se pregunta si las matrices estan vacias*/
        if (matriz1.empty() || matriz2.empty()) {
            throw runtime_error("\nError: No se han ingresado las dos matrices esperadas.");
        }
        else{
            /* Como las matrices no estan vacias me pregunto por su tamaño */
            if (sonIguales(matriz1[0],matriz2[0]) == false) {
                throw runtime_error("\nError: Las matrices no son del mismo tamayo o son complejas.");
            } else {
                /* Significa que las matrices son validas */
                validar = true;
                cout << "\nLas matrices son validas para ser utilizadas" << endl;
            }
        }
    }
    catch(const exception& e) {
        cerr << e.what() << '\n';
    }
}

/* Creo un método para comprar si el tamaño de matriz 1 es igual al tamaño de matriz 2. Además de
asegurarse de que ambas no sean de numeros complejos */
template <typename T>
bool OperacionesBasicas<T>::sonIguales(const Matriz<T>& matriz1, const Matriz<T>& matriz2) const {
    return ((matriz1.getFilas() == matriz2.getFilas()) && 
            (matriz1.getColumnas() == matriz2.getColumnas())
            && (matriz1.getComplejo() == false && matriz2.getComplejo() == false));
}