#ifndef MATERIAL_ORDENADO_HPP
#define MATERIAL_ORDENADO_HPP

#include <vector>
#include <string>
#include "MaterialLectura.hpp"
#include "MaterialAudiovisual.hpp"
using namespace std;

class MaterialOrdenado {
    private:
        /* Se crean dos vectores, uno para MaterialLectura y otro para MaterialAudiovisual
        los cuales almacenarán el contenido de los objetos creados por las clases derivadas*/
        vector<MaterialLectura*> materialesLectura;
        vector<MaterialAudiovisual*> materialesAudiovisuales;

    public:
        /* Contructor: en esta ocación no se utiliza mucho.*/
        MaterialOrdenado();

        /* Ingresa el material mediante el uso de punteros, debido a que señalará a la
        dirección de memoria de un objeto Libro, Noticia, Pelicula o Podcast y luego lo
        meterá a uno de los vectores correspondientes*/
        void agregarMaterial(MaterialLectura* material);
        void agregarMaterial(MaterialAudiovisual* material);

        /* Se encarga de eliminar el material ingresado en el objeto mediante 
        el uso de la referencia del titulo o tipo(Material) utilizado*/
        void eliminarMaterial(const string& titulo);

        /* Se encarga de buscar el material ingresado en el objeto mediante 
        el uso de la referencia del titulo o tipo(Material) utilizado*/
        void buscarMaterialPorTitulo(const string& titulo);
        void buscarMaterialPorTipo(const string& tipo);

        /* Destructor: se utiliza para borrar el contenido de material y no generar 
        basura al momento de agregar materiales o cualquiera otra operación.*/
        ~MaterialOrdenado();
};

#endif