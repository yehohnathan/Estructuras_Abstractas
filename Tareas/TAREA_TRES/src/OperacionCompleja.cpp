/* Se incluye el header asociado a esta clase */
#include "OperacionCompleja.hpp"

/* Método para agregar un objeto matriz al vector matriz1 o matriz2 */
template <typename T>
void OperacionCompleja<T>::agregarMatriz(const Matriz<T> matriz){
    /* Se verifica si el usuario ha ingresado las matrices validando el estado de los
       vectores de la clase. Si el vector matriz1 esta vacio, continue con el vector matriz2
       si también esta vacio. Si ninguno esta vacio lanza un mensaje */
    try {
        if(matriz1.empty()){
            conversorMatriz(matriz);
            matriz1.push_back(matriz);
        } 
        else if(matriz2.empty()){
            conversorMatriz(matriz);
            matriz2.push_back(matriz);
        } 
        else {
            throw out_of_range("\nNo hay espacio disponible, ya se agregaron las dos matrices.");
        }
    } 
    catch(const exception& e) {
        cerr << e.what() << '\n';
    }
    

}

/* El siguiente método se encarga de borrar las matrices guardadas*/
template <typename T>
void OperacionCompleja<T>::liberarEspacio(){
    /* Se libera el posible espacio almacenado por los vectores */
    matriz1.clear();
    matriz2.clear();
    matrizCompleja1.clear();
    matrizCompleja2.clear();

    /* Mensaje indicandole al usuario la acción */
    cout << "\nLas posibles matrices ingresadas han sido borradas. " 
         << "Vuelve a utilizar el metodo agregarMatriz()." << endl;
}

/* El siguiente método se encarga de borrar las matrices guardadas*/
template <typename T>
void OperacionCompleja<T>::conversorMatriz(const Matriz<T>& matriz){
    /* Se crea un ciclo for anidado para convertir los datos en el vector real pero
    distribuido como si fuera un número complejo a un verdadero vector complejo */

    /* Se multiplcan los iteradores * 2 para ajustar los espacios */
    for (int i = 0; i < matriz.getFilas()*2; i++) {
        for (int j = 0; j < matriz.getColumnas()*2; j +=2) {
            /* Se obtiene el valor de la parte real y la parte imaginaria*/
            complex<double> numeroComplejo(matriz.get(i, j), matriz.get(i, (j + 1)));

            if(matriz1.empty()){
                matrizCompleja1.push_back(numeroComplejo);
            } 
            else if(matriz2.empty()){
                matrizCompleja2.push_back(numeroComplejo);
            }
        }
        i ++;
        cout << "\n";
    }
    cout << "\n";

    /* La explicación de por qué este ciclo for funciona es por lo siguiente: 
    1. El vector matriz dice que es de tamaño NxM, pero en realidad es de tamaño Nx(M*2);
    ocultando el hecho de que realmente no es una matriz compleja, unicamente es real.

    2. En el caso de tener una matriz:
        1+2j 3+4j
        5+6j 7+8j
       Eso es igual a matriz = [1, 2, 3, 4, 5, 6, 7, 8]

    3. matriz.get(i,j) = i*matriz.getColumnas()+ j. Por lo que en el caso de tener una matriz 2x2:
        Para el elemento 1x1: 
            real = get(0,0) = 0*2+0 = matriz[0]
            imaginario = get(0,1) = 0*2+1 = matriz[1]

        Para el elemento 1x2: 
            real = get(0,2) = 0*2+2 = matriz[2]
            imaginario = get(0,3) = 0*2+3 = matriz[3]

        Para el elemento 2x1: 
            No se puede hacer:
                real = get(1,0) = 1*2+0 = matriz[2]
            Por lo que se le suma i + 1 al final del ciclo for de j:
                real = get(2,0) = 2*2+0 = matriz[4]
                imaginario = get(2,1) = 2*2+1 = matriz[5]

        Para el elemento 2x2: 
            real = get(2,2) = 2*2+2 = matriz[6]
            imaginario = get(2,3) = 2*2+3 = matriz[7]
    */
}

/* Método para validar para saber si se ingresaron dos matrices, si estas dos matrices
   tienen las mismas dimensiones y si son del mismo tipo. */
template <typename T>
void OperacionCompleja<T>::validarMatrices(){
    /* Se realiza un bloque de excepciones para evitar problemas */
    try {
        /* Se pregunta si las matrices estan vacias*/
        if (matrizCompleja1.empty() || matrizCompleja2.empty()) {
            throw runtime_error("Error: No se han ingresado las dos matrices esperadas.");
        }
        else{
            /* Como las matrices no estan vacias me pregunto por su tamaño */
            if (sonIguales(matriz1[0], matriz2[0]) == false) {
                throw runtime_error("Error: Las matrices no son del mismo tamayo o son complejas.");
            } else {
                /* Significa que las matrices son validas */
                validar = true;
                cout << "Las matrices son validas para ser utilizadas";
                suma(matriz1[0], matriz2[0], matrizCompleja1, matrizCompleja2);
                resta(matriz1[0], matriz2[0], matrizCompleja1, matrizCompleja2);
                multiplicacion(matriz1[0], matriz2[0], matrizCompleja1, matrizCompleja2);
            }
        }
    }
    catch(const exception& e) {
        cerr << e.what();
    }

    /* Salto de linea para mejorar la impresión de mensajes*/
    cout << "\n";
}


/* Creo un método para comprar si el tamaño de matriz 1 es igual al tamaño de matriz 2. Además de
asegurarse de que ambas sean de numeros complejos */
template <typename T>
bool OperacionCompleja<T>::sonIguales(const Matriz<T>& matriz1, const Matriz<T>& matriz2) const {
    return ((matriz1.getFilas() == matriz2.getFilas()) && 
            (matriz1.getColumnas() == matriz2.getColumnas())
            && (matriz1.getComplejo() == true && matriz2.getComplejo() == true));
}

/* Sobrecarga de operador de suma (+) */
template <typename T>
void OperacionCompleja<T>::suma(const Matriz<T>& matriz1, const Matriz<T>& matriz2,
                                const vector<complex<T>> matrizCompleja1, 
                                const vector<complex<T>> matrizCompleja2) {
    /* Se limpia el vector de resultados */
    resultadoMatrices.clear();

    /* Se valida si las matrices son válidas con el atributo bool */
    if (validar == false) {
        return;
    }

    cout << "\nEl resultado de sumar (matriz 1 + matriz 2) es una matriz: " << endl;
    
    /* Se crea un ciclo for anidado para sumar los datos en el vector resultado */
    for (int i = 0; i < matriz1.getFilas(); i++) {
        for (int j = 0; j < matriz1.getColumnas(); j ++) {
            /* Se obtienen los datos directamente de las matrices y se suman */
            resultadoDato = matrizCompleja1[i * matriz1.getColumnas() + j] +
                            matrizCompleja2[i * matriz1.getColumnas() + j];

            /* Se guardan los resultados en un vector */
            resultadoMatrices.push_back(resultadoDato);
        }
    }
    /* Muestra el resultado de la suma */
    mostrarMatriz(matriz1, resultadoMatrices);
}

/* Sobrecarga de operador de resta (-) */
template <typename T>
void OperacionCompleja<T>::resta(const Matriz<T>& matriz1, const Matriz<T>& matriz2,
                                 const vector<complex<T>> matrizCompleja1, 
                                 const vector<complex<T>> matrizCompleja2) {
    /* Se limpia el vector de resultados */
    resultadoMatrices.clear();

    /* Se valida si las matrices son válidas con el atributo bool */
    if (validar == false) {
        return;
    }

    /* Se le dice al usuario el resultado de multiplicar las matrices*/
    cout << "\nEl resultado de restar (matriz 1 - matriz 2) es una matriz: " << endl;

    /* Se crea un ciclo for anidado para restar los datos en el vector resultado */
    for (int i = 0; i < matriz1.getFilas(); i++) {
        for (int j = 0; j < matriz1.getColumnas(); j ++) {
            /* Se obtienen los datos directamente de las matrices y se restan */
            resultadoDato = matrizCompleja1[i * matriz1.getColumnas() + j] -
                            matrizCompleja2[i * matriz1.getColumnas() + j];

            /* Se guardan los resultados en un vector */
            resultadoMatrices.push_back(resultadoDato);
        }
    }
    /* Muestra el resultado de la resta */
    mostrarMatriz(matriz1, resultadoMatrices);
}

/* Sobrecarga de operador de resta (*) */
template <typename T>
void OperacionCompleja<T>::multiplicacion(const Matriz<T>& matriz1, const Matriz<T>& matriz2,
                                 const vector<complex<T>> matrizCompleja1, 
                                 const vector<complex<T>> matrizCompleja2) {
    /* Se limpia el vector de resultados */
    resultadoMatrices.clear();
    
    /* Se valida si las matrices son válidas con el atributo bool */
    if (validar == false) {
        return;
    }

    /* Se le dice al usuario el resultado de multiplicar las matrices*/
    cout << "\nEl resultado de multiplicar (matriz 1 * matriz 2) es una matriz: " << endl;

    /* Se crea un ciclo for anidado para restar los datos en el vector resultado */
    for (int i = 0; i < matriz1.getFilas(); i++) {
        for (int j = 0; j < matriz1.getColumnas(); j ++) {
            /* Se obtienen los datos directamente de las matrices y se multiplican */
            resultadoDato = 0.0;

            //* Se realiza la multiplicación de cada elemento y se acumula el resultado */
            for (int k = 0; k < matriz1.getColumnas(); ++k) {
                resultadoDato += matrizCompleja1[i * matriz1.getColumnas() + k] *
                                 matrizCompleja2[k * matriz2.getColumnas() + j];
            }

            /* Se guardan los resultados en un vector */
            resultadoMatrices.push_back(resultadoDato);
        }
    }
    /* Muestra el resultado de la multiplicación */
    mostrarMatriz(matriz1, resultadoMatrices);
}

/* Método para mostrar el cualquier tipo de matriz compleja */
template <typename T>
void OperacionCompleja<T>::mostrarMatriz(const Matriz<T>& matriz, const vector<complex<T>>& matrizCompleja) {
    for (int i = 0; i < matriz.getFilas(); ++i) {
        for (int j = 0; j < matriz.getColumnas(); ++j) {
            T real = matrizCompleja[i * matriz.getColumnas() + j].real();
            T imag = matrizCompleja[i * matriz.getColumnas() + j].imag();

            cout << real;
                
            if (imag >= 0) {
                cout << "+";
            }
                
            cout << imag << "j  ";
        }
        cout << endl;
    }
}
