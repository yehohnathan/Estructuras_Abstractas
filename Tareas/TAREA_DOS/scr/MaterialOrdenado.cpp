/* Se instancia el header que contiene la clase MaterialOrdenado*/
#include "MaterialOrdenado.hpp"

/* Contructor: en este caso no se necesita*/
MaterialOrdenado::MaterialOrdenado() {}

/* Método para agregar los punteros referente a los objetos de MaterialLectura (Libro o Noticia)*/
void MaterialOrdenado::agregarMaterialLectura(MaterialLectura* material) {
    materialesLectura.push_back(material);  /* Se agrega el objeto al final del vector */
}

/* Método para agregar los punteros referente a los objetos de MaterialAudiovisual (Pelicula o Podcast)*/
void MaterialOrdenado::agregarMaterialAudiovisual(MaterialAudiovisual* material) {
    materialesAudiovisuales.push_back(material); /* Se agrega el objeto al final del vector */
}

/* Método para eliminar el espacio en memoria perteneciente a la información que tiene
un puntero del objeto MaterialLectura. Este caso unicamente se elimina material con poner
el titulo, debido a que poner el tipo de material significaría borrar todo lo referente a este
y no tendría mucho sentido*/
void MaterialOrdenado::eliminarMaterialLectura(const string& titulo) {
    /* Se realiza un ciclo en donde se recorré todo el vector hasta encontrar el objeto
    de MaterialLectura que coincide con el titulo ingresado para eliminar*/
    for (size_t i = 0; i < materialesLectura.size(); ++i) { 
        if (materialesLectura[i]->mostrarTitulo() == titulo) {
            delete materialesLectura[i];    /* Se libera ese espacio del vector*/

            /* Se borra el elemento de la posición i del vector, y se desplazan los
            elementos para llenar el vacio: */
            materialesLectura.erase(materialesLectura.begin() + i);

            /* Simplemente retorna para no utilizar un break*/
            return;
        }
    }
}

/* Método para eliminar el espacio en memoria perteneciente a la información que tiene
un puntero del objeto MaterialAudiovisual*/
void MaterialOrdenado::eliminarMaterialAudiovisual(const string& titulo) {
    /* Se realiza un ciclo en donde se recorré todo el vector hasta encontrar el objeto
    de MaterialAudiovisual que coincide con el titulo ingresado para eliminar*/
    for (size_t i = 0; i < materialesAudiovisuales.size(); ++i) {
        if (materialesAudiovisuales[i]->mostrarTitulo() == titulo) {
            delete materialesAudiovisuales[i];  /* Se libera ese espacio del vector*/

            /* Se borra el elemento de la posición i del vector, y se desplazan los
            elementos para llenar el vacio: */
            materialesAudiovisuales.erase(materialesAudiovisuales.begin() + i);
            
            /* Simplemente retorna para no utilizar un break*/
            return;
        }
    }
}

/* Método que sirve para buscar si se ingreso un objeto Libro, Noticia, Pelicula o Podcast 
mediante el titulo*/
void MaterialOrdenado::buscarMaterialPorTitulo(const string& titulo) {

    /* Se realiza un ciclo for del mismo rango de material, hasta que coincida el titulo 
    de un vector de materialesLectura y mostar su información*/
    for (auto material : materialesLectura) {
        if (material->mostrarTitulo() == titulo) {
            material->mostrarInfo();    /* Muestra toda el info del material*/

            /* Simplemente retorna para no utilizar un break*/
            return;
        }
    }

    /* Se realiza un ciclo for del mismo rango de material, hasta que coincida el titulo 
    de un vector de materialesAudiovisual y mostar su información*/
    for (auto material : materialesAudiovisuales) {
        if (material->mostrarTitulo() == titulo) {
            material->mostrarInfo();    /* Muestra toda el info del material*/

            /* Simplemente retorna para no utilizar un break*/
            return;
        }
    }

    /* El titulo buscado simplemente no pertenecía a ningun objeto */
    cout << "Material no encontrado con el título: " << titulo << endl;
}

/* Método que sirve para buscar si se ingreso un objeto Libro, Noticia, Pelicula o Podcast 
mediante el tipoMaterial. Realiza el mismo procedimiento para la busca de titulo explicada
anteriormente */
void MaterialOrdenado::buscarMaterialPorTipo(const string& tipo) {
    for (auto material : materialesLectura) {
        if (material->mostrarTipoMaterial() == tipo) {
            material->mostrarInfo();
        }
    }

    for (auto material : materialesAudiovisuales) {
        if (material->mostrarTipoMaterial() == tipo) {
            material->mostrarInfo();
        }
    }
}

/* Destructor: una vez se sale del ambito el destructor se encarga de eliminar todo
contenido de la variable material*/
MaterialOrdenado::~MaterialOrdenado() {
    for (auto material : materialesLectura) {
        delete material;
    }
    materialesLectura.clear();

    for (auto material : materialesAudiovisuales) {
        delete material;
    }
    materialesAudiovisuales.clear();
}