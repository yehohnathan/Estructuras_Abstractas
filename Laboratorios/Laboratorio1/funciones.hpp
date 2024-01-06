#ifndef FUNCIONES_HPP   //Esto nos sirve para no ser redundantes
#define FUNCIONES_HPP
#include <string>
#include <iostream>
using namespace std;

const int MAX_EMPLEADOS = 10;

struct Empleado
{
    int id;
    string nombre;
    double salario;
    
};


void mostrarMenu();
void procesarOpcion(Empleado empleados[], int& numEmpleados);
void agregarEmpleado(Empleado empleados[], int& numEmpleados);
void listarEmpleado(const Empleado empleados[], int& numEmpleados);
void eliminarEmpleado(Empleado empleados[], int& numEmpleados);

#endif