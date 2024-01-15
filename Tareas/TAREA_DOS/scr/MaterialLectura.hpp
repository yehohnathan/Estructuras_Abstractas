#ifndef MATERIAL_LECTURA_HPP
#define MATERIAL_LECTURA_HPP

#include <iostream>
#include <string>
using namespace std;

class MaterialLectura
{
    private:    /* Los atributos privados solo se pueden acceder desde la misma clase */

        /* Se declaran las siguientes variables tipo string para que el usuario tenga
        libertad de colocar el nombre que más se le parescan a los sigueintes atributos: */
        string titulo;          /* Para agregar el titulo de la lectura o noticia */
        string grupo;           /* Grupo de lectura*/
        string tipoMaterial;    /* Para asignar el tipo de material (libro o noticia)*/
        string autor;           /* Escribir el nombre del autor de libro o noticia*/
        string editorial;       /* Nombre de la editorial del libro o noticia*/
        string genero;          /* Genero de la libro o noticia*/
        string estado;          /* Para poder estado: disponible, prestado o reservado*/
        int cantidadHojas;      /* Número entero de cantidad de hojas del libro o noticia*/
        double precio;          /* Valor del precio, también acepta decimales*/

    public:     /* Los métodos públicos se pueden acceder desde cualquier parte */   

        /* Contructor: el usuario puede ingresar todos los datos del objeto si desea*/
        MaterialLectura(string titulo, string grupo, string tipoMaterial, string autor, string editorial, 
                        string genero, string estado, int cantidadHojas, double precio);
        
        /* Si hubo algun error, el usuario puede cambiar el contenido de un atributo
        manualmente con los siguientes métodos: */
        void ponerTitulo(string titulo);
        void ponerGrupo(string grupo);
        void ponerTipoMaterial(string tipoMaterial);
        void ponerAutor(string autor);
        void ponerEditorial(string editorial);
        void ponerGenero(string genero);
        void ponerEstado(string estado);
        void ponerCantidadHojas(int cantidadHojas);
        void ponerPrecio(double precio);

        /* Método que muestra información de todo el objeto creado */
        void mostrarInfo();

        /* Destructor: este realmente no se llega a utilizar porque no se
        usa memoria dinámica en la asignación de parámetros a los atributos*/
        ~MaterialLectura();
};

#endif