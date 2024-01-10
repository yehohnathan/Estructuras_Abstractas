/*
    Uso de un Boilerplate de una clase, el cual se refiere a un conjunto
    de líneas de código que se utilizan de manera repetitiva y que 
    generalmente o varían mucho
*/

#include <iostream>
using namespace std;

class Molde{
    public:
        double largo;
        double ancho;
        double altura;

        // Contructor:
        Molde(double largo_p, double ancho_p, double alto_p): largo(largo_p), ancho(ancho_p), altura(alto_p) {}

        Molde(){
            cout << "Esto se ejecuta en cada instanciacion" << endl;
            cout << "Iniciando un objeto de la clase Molde" << endl;
        }

        ~Molde(){
            cout << "Este es el destructor del molde" << endl;
        }

    double calcularArea(){
        return largo * ancho;
    }

    double calcularVolumen(){
        return largo * ancho * altura;
    }
};

int main(){
    Molde pared(10.0, 20.0, 30.0);    // Instancia del objeto "pared" basado en la clase Molde

    // Asignación de valores al objeto pared
    pared.largo = 400.5;  
    pared.ancho = 20.8;
    pared.altura = 315.2;

    // Calcular y desplegar el area y volumen
    cout << "Area = " << pared.calcularArea() << endl;
    cout << "Volumen = " << pared.calcularVolumen() << endl;

    return 0;
}


/*
Estructura de un Boilerplate:
    class NombreClase{
        private:
            // Atributos privados de la clase
            tipo_dato atributo1;
            tipo_dato atributo2;

        public:
            //Contructores
            NombreClase();
            NombreClase(tipo_dato parametro1, tipo_dato parametro2);

            //Destructor
            ~NombreClase();

            //Métodos públicos de la clase
            tipo_dato metodo1(tipo_parametro parametro1, tipo_parametro parametro1, ...);
            tipo_dato metodo2(tipo_parametro parametro1, tipo_parametro parametro1, ...);
    };

*/