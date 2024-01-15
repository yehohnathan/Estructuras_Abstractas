#ifndef PELICULA_HPP
#define PELICULA_HPP

#include "MaterialAudiovisual.hpp"

class Pelicula : public MaterialAudiovisual
{
    private:    /* Los atributos privados solo se pueden acceder desde la misma clase */

        /* Se crea un nuevo atributo para la clase Noticia, el cual tendrá la información
        adicional que quiera ingresar el usuario. */
        string infoAdicional;

    public:     /* Los métodos públicos se pueden acceder desde cualquier parte */ 

        /* Contructor: el usuario puede ingresar todos los datos del objeto si desea */
        Pelicula(string titulo, string grupo, string autor, string tipoMaterial, string genero, 
                 int duracion, string estado, double precio, string infoAdicional);

        /* A partir del siguiente método el usuario podrá ingresar la información adicional, si 
        es que tuvo algun error */
        void ponerInfoAdicional(string infoAdicional);

        /* El siguiente método le dirá al usuario si la Pelicula comprada es corta, mediana o larga
        depediendo de la cantidad de hojas */
        void durationPelicula();

        /* Método que muestra información de todo el objeto Pelicula creado */
        void mostrarInfo();

        /* Destructor: este realmente no se llega a utilizar porque no se
        usa memoria dinámica en la asignación de parámetros a los atributos*/
        ~Pelicula();
};

#endif