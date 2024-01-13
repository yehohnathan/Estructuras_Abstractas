/*
    Uso de expresiones regulares en C++
*/

#include <iostream>
#include <regex>

int main() {

    // El compilador interpretra que tipo de dato es, aunque es un regex
    // y lo que esta dentro del paréntesis en mi expresión regular.
    // En este cao tiene que hacer coincidir el "my"
    auto const regex = std::regex("my(|your) regex");

    auto const myText = std::string("A piece of text that contains my regex.");
    // Busca la coincidencia
    bool const myTextContainsRegex = std::regex_search(myText, regex);

    auto const yourText = std::string("A piece of text that contains your regex.");
    // Busca la coincidencia
    bool const yourTextContainsRegex = std::regex_search(yourText, regex);

    auto const theirText = std::string("A piece of text that contains their regex.");
    // Busca la coincidencia
    bool const theirTextContainsRegex = std::regex_search(theirText, regex);

    // Y busca booleanos con boolalpha
    std::cout << std::boolalpha
              << myTextContainsRegex << '\n'
              << yourTextContainsRegex << '\n'
              << theirTextContainsRegex << '\n';
}
