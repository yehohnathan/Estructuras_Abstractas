#include <iostream>
#include <cstring>
using namespace std;

struct Books
{
    char title[50];
    char author[50];
    char subject[100];
    int  book_id;
};

struct Person
{
    char name[50];
    int  age;
    float salary;
};

int main() {
    struct Books b1;

    strcpy(b1.title, "Las ultimas maravillas");
    strcpy(b1.author, "Carlos Carlos");
    strcpy(b1.subject, "C++");
    b1.book_id = 556664;

    struct Books b2;
    strcpy(b2.title, "Para tomarme en serio");
    strcpy(b2.author, "Marco Polo");
    strcpy(b2.subject, "Sicologia");
    b2.book_id = 997741; 

    cout << "Titulo Libro 1 : " << b1.title << endl;
    cout << "Autor Libro 1 : " << b1.author << endl;
    cout << "Tema Libro 1 : " << b1.subject << endl;
    cout << "Identificacion Libro 1 : " << b1.book_id << endl;

    cout << "Titulo Libro 2 : " << b1.title << endl;
    cout << "Autor Libro 2 : " << b1.author << endl;
    cout << "Tema Libro 2 : " << b1.subject << endl;
    cout << "Identificacion Libro 2 : " << b1.book_id << endl;

    Person p1;

    cout << "\nIngrese su nombre completo: ";
    cin.get(p1.name, 50);
    cout << "Ingrese su edad: ";
    cin >> p1.age;
    cout << "Ingrese su salario: ";
    cin >> p1.salary;

    cout << "\nPresentando informacion." << endl;
    cout << "Name: " << p1.name << endl;
    cout << "Age: " << p1.age << endl;
    cout << "Salary: " << p1.salary; 


    return 0;
}

/*
    strcpy: proviene la librería cstring proveniente de C, se usa para copiar
    un string a un array char pero sin verificar sus límites.
*/