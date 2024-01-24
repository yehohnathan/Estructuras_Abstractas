/* Se incluye el header correspondiente */
#include "ValidaCorreo.hpp"

/* Se instancia el contructor de la clase, el cual en vez de ingresar un correo(correo)
realiza un correo(R"patron")*/
ValidaCorreo::ValidaCorreo(){
    /* Se le asigna el patron de la variable regex */
    this->correo = regex(R"(([a-zA-Z0-9][a-zA-Z0-9\.-]{0,13}[a-zA-Z0-9])@([a-zA-Z]+)\.([a-zA-Z]{2,4}))");

    /* 
    - El primer grupo [a-zA-Z0-9][a-zA-Z0-9\.-]{0,13}[a-zA-Z0-9] representa el nombre
      y debe seguir las siguientes restrincciones:
        * Es invalido que el correo pueda empezar o terminar con un punto 
          o guión [a-zA-Z0-9]. Solo con letras o numeros.
          
        * El nombre puede tener letras, numeros, puntos y fuiones, pero su conjunto
          no debe ser mayor a 15 carácteres ([a-zA-Z0-9.-]{0,13}).
    
    - El simbolo @ separa el nombre del (expansion de) dominio.

    - El segudo grupo ([a-zA-Z]+)\. represente a el dominio y debe seguir las siguientes
      restricciones:
        * El dominio solo contiene letras y tiene un punto al final (\.).

    - EL tercer grupo ([a-zA-Z]{2,4})) representa la extensión del correo y debe seguir
      las siguientes restricciones:
        * La extensión solo puede contener letras ([a-zA-Z]).

        * La extensión debe tener entre 2 y 4 caracteres ({2,4}).

    - Todo lo que no cumpla lo anterior, como los carácteres adicionales, son excluidos.  
    */
}

/* Se crea un método que solicita una cenada de texto (string cadena) y luego retorna 
si la dirección de correo es valida(true) o no(false). */
bool ValidaCorreo::validador(string cadena){
    
    /* Bloque de excepciones para validar la cadena ingresada */
    try {
        /* Si la cadena no contiene un @, se lanza inmediatamente una excepción */
        if(cadena.find('@') == string::npos) {
            throw invalid_argument("Error: No incluiste el arroba, correo invalido.");
        }

        /* Si la cadena coincide con el patron retorna un true */
        if(regex_match(cadena, correo)){
            return true;
        }
    }
    catch(const exception& e) {
        cerr << e.what() << '\n';
    }

    /* Si se llegó a este punto el correo es totalmente invalido */
    return false;
    
}