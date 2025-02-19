#ifndef MATERIAL_AUDIOVISUAL_HPP
#define MATERIAL_AUDIOVISUAL_HPP

#include <iostream>
using namespace std;

class MaterialAudiovisual
{
    private:    /* Los atributos privados solo se pueden acceder desde la misma clase */

        /* Se declaran las siguientes variables tipo string para que el usuario tenga
        libertad de colocar el nombre que más se le parescan a los sigueintes atributos: */
        string titulo;          /* Para agregar el titulo de la pelicula o podcast */
        string grupo;           /* Grupo de audiovisual*/
        string autor;           /* Escribir el nombre del autor de pelicula o podcast*/
        string tipoMaterial;    /* Para asignar el tipo de material (pelicula o podcast)*/
        string genero;          /* Genero de la libro o noticia*/
        string estado;          /* Para poder estado: disponible, prestado o reservado*/
        double precio;          /* Valor del precio, también acepta decimales*/
    
    protected:  /* Los atributos protected solo se pueden acceder desde la misma clase o 
    clases derivadas*/
        int duracion;        /* Duracción en minutos de la pelicula o podcast*/

    public:     /* Los métodos públicos se pueden acceder desde cualquier parte */   

        /* Contructor: el usuario puede ingresar todos los datos del objeto si desea*/
        MaterialAudiovisual(string titulo, string grupo, string autor, string tipoMaterial, 
                            string genero, int duracion, string estado, double precio);
        
        /* Si hubo algun error, el usuario p uede cambiar el contenido de un atributo
        manualmente con los siguientes métodos: */
        void ponerTitulo(string titulo);
        void ponerGrupo(string grupo);
        void ponerAutor(string autor);
        void ponerTipoMaterial(string tipoMaterial);
        void ponerGenero(string genero);
        void ponerDuracion(int duracion);
        void ponerEstado(string estado);
        void ponerPrecio(double precio);

        /* Método que muestra información de todo el objeto creado */
        void mostrarInfo();

        /* Para poder seleccionar con base al titulo y tipoMaterial es necesario crear funciones
        string que simplemente regresen lo ingresado por el usuario: */
        string mostrarTitulo();
        string mostrarTipoMaterial();

        /* Destructor: este realmente no se llega a utilizar porque no se
        usa memoria dinámica en la asignación de parámetros a los atributos*/
        ~MaterialAudiovisual();
};

#endif