#ifndef MATERIAL_PRECIO_HPP
#define MATERIAL_PRECIO_HPP

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class MaterialPrecio
{
    private:
        vector<MaterialPrecio*> materialTotal;

        string titulo;
        string tipoMaterial;
        double precio;
    public:
        
        /* Contructor: no inicializa nada pero si acomula los objetos de otras clases 
        en una sola */
        MaterialPrecio(string titulo, string tipoMaterial, double precio);

        /* Ingresa el material mediante el uso de punteros, debido a que señalará a la
        dirección de memoria de un objeto Libro, Noticia, Pelicula o Podcast y luego lo
        meterá a uno de los vectores correspondientes*/
        void agregarMaterial(MaterialPrecio* material);

        /* Sirve para mostrar el precio de los objetos guardados en el vector */
        void mostrarInfo();

        /* Ordenada de forma ascendente o descendente utilizando el bubble sort los elementos 
        inrgesados, mediante los sigueintes dos métodos */
        void ordenarAscendente();
        void ordenarDescendente();

        ~MaterialPrecio();
};

#endif