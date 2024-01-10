/*
    Uso de Boilerplate con destructor, además de una nueva librería llamada fstream

    fstream: en C++ proporciona clases y funciones para realizar operaciones de entrada
    y salida en archivos. El nombre "fstream" es una combinación de "file" (archivo) 
    y "stream" (flujo), lo que refleja su función principal: =
        permitir la lectura y escritura de datos en archivos utilizando los mismos 
        conceptos que se utilizan para la entrada y salida estándar.
*/

#include <iostream>
#include <fstream>
using namespace std;

class Archivo
{
    private:
        fstream archivo;
        
    public:
        Archivo(string nombre_archivo){
            /* Se comentaron las ios::out, ios:app porque no se podia acceder
            a la sentencia if, debido a que creaba el archivo antes de preguntar
            por su no existencia */
            archivo.open(nombre_archivo, ios::in /*, ios::out, ios:app*/);
            if (!archivo.is_open()){
                cout << "No se pudo abrir el archivo " << nombre_archivo << endl;
            }
        }

        ~Archivo(){
            if (archivo.is_open()){
                archivo.close();
            }
        }
};

int main(){
    Archivo mi_archivo("2.destructor.txt");
    Archivo mi_archivo2("noExiste.txt");
    return 0;
}



