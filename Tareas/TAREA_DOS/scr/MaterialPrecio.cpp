#include "MaterialPrecio.hpp"

MaterialPrecio::MaterialPrecio(string titulo, string tipoMaterial, double precio){
    this->titulo = titulo;
    this->tipoMaterial = tipoMaterial;
    this->precio = precio;
}

/* Método para agregar los punteros referente a los objetos de Libro*/
void MaterialPrecio::agregarMaterial(MaterialPrecio* material) {
    materialTotal.push_back(material);  /* Se agrega el objeto al final del vector */
}

void MaterialPrecio::mostrarInfo(){
    for (auto material : materialTotal) {
        cout << "----------------------------------------------------------" << endl;
        cout << "Titulo: " << material->titulo<< endl;
        cout << "Tipo de material: " << material->tipoMaterial << endl;
        cout << "Precio: " << material->precio << endl;
    }
}

void MaterialPrecio::ordenarAscendente() {
    int n = materialTotal.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (materialTotal[j]->precio > materialTotal[j + 1]->precio) {
                // Intercambiar los elementos si están en el orden incorrecto
                swap(materialTotal[j], materialTotal[j + 1]);
            }
        }
    }
}

void MaterialPrecio::ordenarDescendente() {
    int n = materialTotal.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (materialTotal[j]->precio < materialTotal[j + 1]->precio) {
                // Intercambiar los elementos si están en el orden incorrecto
                swap(materialTotal[j], materialTotal[j + 1]);
            }
        }
    }
}

/* Destructor: una vez se sale del ambito el destructor se encarga de eliminar todo
contenido de la variable material*/
MaterialPrecio::~MaterialPrecio() {
    for (auto material : materialTotal) {
        delete material;
    }
    materialTotal.clear();
}