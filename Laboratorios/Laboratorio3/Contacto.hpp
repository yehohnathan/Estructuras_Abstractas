#ifndef CONTACTO_HPP
#define CONTACTO_HPP

#include <string>

template <typename T>
class Contacto
{
    private:
        T nombre;    
        T telefono;
        T email;

    public:
        /* Contructor: */
        Contacto(T nombre, T telefono, T email);
        T getNombre() const;    /* Const ayuda al compilador para optimizar */
        T getTelefono() const;  
        T getEmail() const;
};

/* Para que no de errores */
#include "Contacto.cpp"


#endif
