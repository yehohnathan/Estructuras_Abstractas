#include "Agenda.hpp"
#include "Contacto.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {

    /* Objetos de la clase contacto */
    Contacto<string> contacto1("Juanito Mora", "27381234", "dj.juanito@gmail.com");
    Contacto<string> contacto2("William Walker", "86541234", "willywalk@outlook.es");
    Contacto<string> contacto3("Juan Santamaria", "22315689", "adiosmezos@gamil.com");

    /* Crear agenda */
    Agenda<string> agenda;

    /* Agregar contacto a la agenda */
    try {
        agenda.agregarContacto(contacto1);
        agenda.agregarContacto(contacto2);
        agenda.agregarContacto(contacto3);
    } catch (const exception& e){
        cerr << "Error al agregar contacto: " << e.what() << endl; 
    }

    /* Buscando un contacto: */
    cout << "Buscando contacto: " << endl;
    
    /* Guarda el return de buscarContactos() en una agenda*/
    list<Contacto<string>> contactosEncontrados = agenda.buscarContactos("Walker");

    /* Crear un iterador para manipular el contenido de la lista contactosEncontrados*/
    list<Contacto<string>>::iterator it;

    /* Se crea un ciclo para iterar en cada elemento de la lista contactosEncontrados.*/
    for (it = contactosEncontrados.begin(); it != contactosEncontrados.end(); ++it) {
        cout << "Nombre: " << it->getNombre()
             << ". Telefono: " << it->getTelefono()
             << ". Email: " << it->getEmail() << endl;
    }


    /* Mostrar agenda de contactos: */
    cout << endl;
    cout << "Contactos en la agenda: " << endl;
    agenda.mostrarContactos();

    /* Eliminar contacto: */
    try {
        agenda.eliminarContacto("86541234");
    }
    catch(const std::exception& e) {
        cerr << "Error al eliminar contacto: "<<e.what() << endl;
    }
    
    /* Mostrar agenda de contactos: */
    cout << endl;
    cout << "Contactos en la agenda: " << endl;
    agenda.mostrarContactos();

    return 0;
}