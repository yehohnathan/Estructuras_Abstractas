/*
    Poseé la siguiente estructura:
    std::map<key_type, value_type> map_name = {{key1, value1}, {key2, value2}, ...}

    Si quiero un map de enteros y strings:
    std::map<int, string> student = {{1, "Jacqueline"}, {2, "Blake"}, ...}

    Tiene los siguientes Operadoraciones:
        insert():   añade un elemento (par key-value) al mapa *OJO
        erase():    elimina un elemento o rango de elementos del mapa
        clear():    elimina todos los elementos del mapa
        find():     busca en el mapa la key dada
        size():     devuelve el número de elementos en el mapa
        empty():    devuelve verdadero si el mapa está vacío

*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    // Tipo de dato key es int, tipo de dato value es string 
    map<int, string> student;

    // Se puede utilizar [] para agregar elementos
    student[1] = "Jacqueline";
    student[2] = "Blake";

    // Usando insert() como metodo de agregar elementos
    student.insert(make_pair(3, "Denise"));
    student.insert(make_pair(4, "Blake"));

    // Agregando elementos en key repetidas, se queda el ultimo elemento
    student[5] = "Timothy"; 
    student[5] = "Aaron";   // Lo que queda

    // Se imprime el map
    for (int i = 1; i <= student.size(); i++) {
        cout << "Student [" << i << "]: " << student[i] << endl;
    }

    return 0;
}
