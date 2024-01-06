#include "funciones.hpp" //Esto hace que no sea necesario compilarlo en la terminal

void mostrarMenu(){
    cout << "\n--- MENU ---\n";
    cout << "1. Agregar empleado\n";
    cout << "2. Listar empleado\n";
    cout << "3. Eliminar empleado\n";
    cout << "4. Salir\n";
}

void procesarOpcion(Empleado empleados[], int& numEmpleados){
    int opcion;
    cout << "\nIngrese una opcion: ";
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        agregarEmpleado(empleados, numEmpleados);
        break;

    case 2:
        listarEmpleado(empleados, numEmpleados);
        break;

    case 3:
        eliminarEmpleado(empleados, numEmpleados);
        break;

    case 4:
        cout << "Saliendo del programa...\n";
        break;

    default:
        cout << "Opcion no valida. Intente de nuevo...\n";
        break;
    }
}

void agregarEmpleado(Empleado empleados[], int& numEmpleados){
    if(numEmpleados < MAX_EMPLEADOS){
        Empleado nuevoEmpleado;

        nuevoEmpleado.id = numEmpleados + 1;
        
        cout << "\nIngrese el nombre del empleado: ";
        cin >> nuevoEmpleado.nombre;

        cout << "Ingrese el salario del empleado: ";
        cin >> nuevoEmpleado.salario;

        empleados[numEmpleados++] = nuevoEmpleado;
        cout << "Empleado agregado con exito\n";
    } 
    else {
        cout << "No se puede agregar mas, limite alcanzado\n";
    }
}

void listarEmpleado(const Empleado empleados[], int& numEmpleados){
    cout << "\n--- Lista de empleados ---\n";

    for (int i = 0; i < numEmpleados; i++)
    {
        cout << "ID: " << empleados[i].id << ", Nombre: " << empleados[i].nombre << ", Salario: " << empleados[i].salario << endl;
    }

}

void eliminarEmpleado(Empleado empleados[], int& numEmpleados){
    int idEliminar;

    cout << "\nIngrese el ID a eliminar: ";
    cin >> idEliminar;

    for (int i = 0; i < numEmpleados; ++i)
    {
        if (empleados[i].id == idEliminar)
        {
            for (int j = i; j < numEmpleados - 1; ++j)
            {
                empleados[j] = empleados[j+1];
            }
            --numEmpleados;
            cout << "Empleado elimnado con exito.\n";
            return;
        }    
    }
}

