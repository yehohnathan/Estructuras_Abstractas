#include "Agenda.hpp"

template <typename T>
void Agenda<T>::agregarContacto(const Contacto<T> contacto){

    typename list<Contacto<T>> :: const_iterator it;

    /* Verificar si ya existe un contacto */
    for(it = contactos.begin(); it != contactos.end(); it++)
    {
        if(it->getTelefono() ==  contacto.getTelefono())
        {
            throw invalid_argument("Ya existe un contacto con este numero");
        }
    }

    /* Se agrega el contacto */
    contactos.push_back(contacto);
}

template <typename T>
void Agenda<T>::eliminarContacto(const T& telefono){
    
    typename list<Contacto<T>> :: const_iterator it;

    /* Recorrer la lista para verificar si se existe el contacto */
    /* Verificar si ya existe un contacto */
    for(it = contactos.begin(); it != contactos.end(); it++)
    {
        if(it->getTelefono() ==  telefono)
        {
            contactos.erase(it);    /* Se elimina el contacto*/
            return;
        }
    }   
    throw out_of_range(" No se encuentra un contacto con ese número");

}

template <typename T>
void Agenda<T>::mostrarContactos() const{
    
    typename list<Contacto<T>> :: const_iterator it;

    /* Se va a mostrar */
    for(it = contactos.begin(); it != contactos.end(); it++)
    {
        cout << "Nombre: " << it->getNombre()       /* Son punteros */
             << ". Telefono: " << it->getTelefono()
             << ". Email: " << it->getEmail() << endl; 
    }   
}

template <typename T>
list<Contacto<T>> Agenda<T>::buscarContactos(const string& patron) const {
    list<Contacto<T>> resultados;   /* Se crea un lista llamada resultados*/
    
    string::size_type pos;  /*Se crea una variable para almacenar la posición de coincidencia */

    /* Para indicar que esta dentro del template Agenda<T> */
    typename list<Contacto<T>> :: const_iterator it;    /* Iterador de la lista */
    
    /* Ciclo para buscar información de todos los contactos existentes */
    for (it = contactos.begin(); it != contactos.end(); ++it) {

        /* Almacena la posición del posible nombre (patron en este caso)*/
        pos = it->getNombre().find(patron); /* find() es quien busca patron dentro del string*/

        /* Se pregunta si la vartiable pos no es igual a "no se encontro nada (npos)"*/
        if (pos != string::npos) 
        {
            resultados.push_back(*it);  /* Almacena el resultado en resultados */
        } 
        else 
        {   /* Se pregunta si la vartiable pos no es igual a "no se encontro nada (npos)"*/
            pos = it->getEmail().find(patron);
            if (pos != string::npos) 
            {
                resultados.push_back(*it);  /* Almacena el resultado en resultados */
            }
        }
    }
    
    /* Retorna el valor de resultados */
    return resultados;
}
