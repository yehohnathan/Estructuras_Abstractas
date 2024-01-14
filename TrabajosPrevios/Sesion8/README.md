## Templates:

Son una característica del lenguaje que permiten crear código genérico que puede trabajar con diferentes tipos de datos y estructuras de datos. En otras palabras, utilizar templates permite escribir funciones y clases que pueden ser usadas con distintos tipos de datos sin necesidad de escribir código específico para cada tipo.

Los templates se definen mediante la palabra clave template seguida de una lista de parámetros de tipo, que pueden ser nombres de tipos o valores constantes. Estos parámetros se utilizan para definir los tipos de los argumentos y variables dentro de la función o clase template.

### Function template:

Comienza con la palabra clave template seguida de los parámetros dentro de <> y finalmente la definición de la función.

```c++
template <typename T>
T functionName(T parameter1, T parameter2, ...){
    // code
}
```

En este ejemplo, T es el argumento de un template que acepta diferentes tipos de datos, typename es una palabra clave.

Cuando un argumento de un tipo de dato es pasado a functionName, el compilador genera una nueva versión de functionName() para el tipo de dato dado.

```c++
template <typename T>
T add(T num1, T num2, ...){
    return (num1 + num2)
};
```

## Class template:
De manera análoga a los functions templates, es posible utilizar class templates para crear una única clase y poder trabajar con distintos tipos de datos.

```c++
template <class T>
class className {
    private:
        T var;
        ... .. ...
    
    public:
        T functionName(T arg);
        ... .. ...
};
```

En este ejemplo, T es el argumento de un template que acepta diferentes tipos de datos, class es una palabra clave.

Dentro del cuerpo de la clase hay un atributo var y un método functionName() son ambos de tipo T.

### ¿Y si es necesario definir un método fuera de la clase?

`template1.hpp`
```c++
template <class T>
class className {
    ... .. ...
    // Prototipo de función
    returnType functionName();
};
```

`template1.cpp`
```c++
template <class T>
returnType ClassName<T>:: functionName() {
    // Code
}
```

`template2.hpp`
```c++
template <class T>
class Number {
    ... .. ...
    // Prototipo de función
    T getNum();
};
```

`template2.cpp`
```c++
template <class T>
Y Number<T>:: getNum() {
    return num;
}
```

### ¿Y es posible tener plantillas con múltiples parámetros?
`template3.cpp`
```c++
template <class T, class U, class V = int>
class ClassName {
    private:     
        T member1;
        U member2;
        V member3;
        ... .. ...
    public:
        ... .. ...
};
```

### Excepciones:
Es un evento inesperado que ocurre durante la ejecución de un programa, por ejemplo dividir entre cero. El proceso de manejo de este tipo de errores en C++ se conoce como manejo de excepciones.

En C++ se manejan las excepciones con la ayuda de los bloques try, catch y throw.

- try: código que puede generar una excepción.
- throw: lanza una excepción cuando se detecta un error (no es obligatoria, especialmente si usamos - excepciones estándar de C++).
- catch: código que maneja la excepción lanzada por throw

```c++
try {
    // Código que debería levantar una excepción
    throw argument;
}

catch (exception) {
    // Código para manejar la excepción
}
```

Si no es posible conocer los tipos de excepciones que podrían ocurrir, se debe utilizar el símbolo … como el parámetro del catch.

```c++
try {
    // code
}
catch (exception1) {
    // code
}
catch (exception2) {
    // code
}
catch (...) {
    // code
}
```

### Tabla de excepciones:
| Exception                | Description |
|--------------------------|-------------|
| std::exception           | An exception and parent class of all the standard C++ exceptions. |
| std::bad_alloc           | Thrown by new if there is no sufficient memory for allocation. |
| std::bad_cast            | Thrown by dynamic_cast when it fails the run-time check. |
| std::bad_exception       | Used to handle unexpected exceptions in a C++ program. |
| std::bad_typeid          | Thrown by typeid when the argument is a null pointer. |
| std::logic_error         | Represents errors in the internal logic of the program. |
| std::domain_error        | Thrown when a mathematically invalid domain is used. |
| std::invalid_argument    | Thrown due to invalid arguments. |
| std::length_error        | Thrown when a too big std::string is created. |
| std::out_of_range        | Thrown by methods like std::vector::at when index is out of range. |
| std::runtime_error       | Represents errors that cannot be detected before runtime. |
| std::overflow_error      | Thrown if a mathematical overflow occurs. |
| std::range_error         | Thrown when a value is out of range. |
| std::underflow_error     | Thrown if a mathematical underflow occurs. |
