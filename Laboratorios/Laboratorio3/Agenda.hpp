#ifndef AGENDA_HPP
#define AGENDA_HPP

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <stdexcept>
#include "Contacto.hpp"

using namespace std;

template <typename T>
class Agenda
{
    private:
        list<Contacto<T>> contactos;

    public:
        void agregarContacto(const Contacto<T> contacto);   /* Referencia constante para solo envair dato*/
        void eliminarContacto(const T& telefono); 
        void mostrarContactos() const;
        list<Contacto<T>> buscarContactos(const string& patron) const;
};

/* Para que no de errores */
#include "Agenda.cpp"


#endif