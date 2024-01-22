# Tarea 3: Algebra lineal, expresiones regulares en C++ y teoría

## Parte práctica 1:

## Parte práctica 2:

## Parte teórica:
### Templates:

1. Definición de Templates:
Explique el concepto de templates en C++ y proporcione un ejemplo simple.

Los templates son un herramienta que permiten la programación genérica en C++, en otras palabras, sin tener que definir el tipo de dato repetidamente. Permiten definir las operaciones de una clase o una función, y dejar que el usuario especifique con qué tipos concretos deben trabajar esas operaciones [1].

A continuación se muestra un ejemplo de uso de templates, para un función cuyo propósito es multiplicar dos elementos:

```c++
/* Se crea una función que pueda multiplicar números enteros y doubles*/
template <typename T>
T multiply(const T num1, const T& num2)
{
    return num1 * num2;
}
```

Ejecutando en el main:

```c++
/*  Se llama a la función y el compilador entiende que multiply debe ser tipo int. */
int a = multiply(2,3);
cout << a << endl;  /* Output: 6 */

/*  Se llama a la función, pero en este caso el compilador no es capaz de decidir si usar
    tipo int o double debido a que ambos números son de tipo de dato distintos. Por lo que
    hay que indicarle al compulador que debe ser un double para evitar problemas. */
double b = multiply<double>(2.1234,3);
cout << b << endl;  /* Output: 6.3702 */
```

Como se pudo observar no fue necesario crear dos funciones `multiply`, evitando la sobreescritura de funciones, gracias a los templates.

2. Sobrecarga de Plantillas:
¿Cómo se realiza la sobrecarga de funciones con plantillas en C++?

La sobrecarga de funciones con plantillas (templates) en C++ consiste en definir varias versiones de una función con el mismo nombre, pero con diferentes tipos o número de parámetros. Estas versiones pueden ser funciones que no son de plantilla o plantillas de función [2]. El compilador seleccionará la versión más adecuada de la función sobrecargada según los argumentos que se le pasen al llamarla.

Utilizando como ejemplo parte de la función `multiply` de la pregunta anterior, se crean las siguientes 3 funciones mediante la sobrecarga:

```c++
/* Se crea una función que pueda multiplicar números enteros y doubles de dos elementos*/
template <typename T>
T multiply(const T num1, const T& num2)
{
    return num1 * num2;
}

/* Se crea una función que pueda multiplicar números enteros y doubles de tres elementos*/
template <typename T>
T multiply(const T num1, const T& num2, const T& num3)
{
    return num1 * num2 * num3;
}
```

Ejecutando en el main:

```c++
/*  Se llama a la función y se indica que multiply debe ser tipo int, para dos elementos. */
int a = multiply<int>(5,10);
cout << a << endl;  /* Output: 50 */

/*  Se llama a la función y se indica que multiply debe ser tipo double, para tres elementos. */
double b = multiply<double>(5.5, 10.10, 2.2);
cout << b << endl;  /* Output: 122.21 */
```

Por lo que el compilador es capaz de distinguir cual de los dos templates utilizar. Esto permite que no sea necesario la creación de 4 funciones para multiplicar dos elementos con tipo int o double y multiplicar tres elementos con tipo int o double; aunque el alcance teórico puede llegar a ser mayor y ahorrar mucho espacio en nuestro código.

3. Plantillas de Clases:
Explique cómo se pueden utilizar plantillas en la definición de clases en C++.

Las plantillas (templates) junto con las clases en C++ son una forma de crear clases genéricas que pueden trabajar con diferentes tipos de datos. Una plantilla de clase se declara usando la palabra clave template y luego se crea una clase como se haría de forma normal, con el código dentro de los corchetes [3]. 

La estructura que se debe serguir es la siguiente: 

```c++
/* Definir una plantilla de clase con un parámetro de tipo T */
template <typename T>

/* Se instancia la clase */
class Clase {
    /* Se define un atributo privado tipo T*/
    private:
        T dato;

    /* Se definen los métodos*/
    public:
        /* Para que el usuario ingrese el valor del atributo dato*/
        void valorDato(T dato){
            this->dato = dato;
        }

        /* Para que el usuario pueda ver qué fue lo que ingresó*/
        void tipoDato(){
            std::cout << "Se ingreso un dato con el valor de " << dato << std::endl;
        }
}
```

```c++
/* Se crea una clase y se le asigna un tipo de dato double*/
Clase<double> objeto1;
objeto1.valorDato(5.13);    /* Se le asigna un double al atributo*/
objeto1.tipoDato();         /* Muestra lo que se agregó */

/* Se crea una clase y se le asigna un tipo de dato string*/
Clase<std::string> objeto2;
objeto2.valorDato("Hola mundo");    /* Se le asigna un mensaje al atributo */
objeto2.tipoDato();                 /* Muestra lo que se agregó */
```         

Lo que se muestra en la terminal es lo siguiente:

```
Se ingreso un dato con el valor de 5.13
Se ingreso un dato con el valor de Hola mundo
```

### Excepciones:

4. Manejo de Excepciones:
Describa los bloques try, catch y throw y cómo se utilizan para el manejo de excepciones en C++.

El manejo de excepciones es un mecanismo que permite detectar y resolver los errores que pueden ocurrir durante la ejecución de un programa.

Un bloque `try` es una sección de código que puede lanzar una excepción, es decir, una situación anormal o errónea que requiere una acción especial. Por ejemplo, una división por cero, una lectura de un archivo inexistente o una asignación de memoria fallida son posibles excepciones [4].

Un bloque `catch` es una sección de código que se ejecuta cuando se ejecuta una excepción del bloque `try` correspondiente. Un bloque `catch` especifica el tipo de excepción que puede manejar y recibe un objeto que contiene información sobre la excepción. Un bloque `catch` puede realizar acciones como mostrar un mensaje de error, liberar recursos o terminar el programa. Un bloque `try`  puede tener varios bloques `catch` asociados, cada uno para un tipo diferente de excepción [4].

Un bloque `throw` es una expresión que se usa para lanzar una excepción. Un bloque `throw` puede especificar cualquier objeto como argumento, pero se recomienda usar la clase std::exception o una de sus clases derivadas definidas en la biblioteca estándar de C++. Un bloque `throw` transfiere el control al primer bloque `catch` que coincida con el tipo de la excepción lanzada.

A continuación se muestra un código utilizando una división de valores ingresados por el usuario:

```cpp
/* Se debe instanciar la librería para el uso de excepciones */
#include <stdexcept>

/* Se crea el código que va dentro del main*/
try {   /* Bloque en donde se puede lanzar la excepción */

    // Variables para almacenar los números a dividir
    double numerador, denominador;

    // Solicitar al usuario que ingrese el numerador
    std::cout << "Ingrese el numerador: ";
    std::cin >> numerador;

    // Solicitar al usuario que ingrese el denominador
    std::cout << "Ingrese el denominador: ";
    std::cin >> denominador;

    // Verificar si el denominador es cero
    if (denominador == 0) {
        /* Se utiliza la expresión para lanzar una excepción */
        throw std::runtime_error("Error: No se puede dividir por cero.");
    }
    
    // Realizar la división si el denominador no es cero
    double resultado = numerador / denominador;

    // Mostrar el resultado
    std::cout << "Resultado de la división: " << resultado << std::endl;
    
}   catch (const std::exception& e) {   /* Expresión estandar de catch */
    // Capturar y manejar la excepción, en este caso e.what sería lo lanzado por "throw"
    std::cerr << "Excepción: " << e.what() << std::endl;
}
```

5. Excepciones Estándar:
Nombre al menos tres excepciones estándar proporcionadas por C++ y proporcione ejemplos de situaciones en las que podrían ser útiles.

- `std::bad_alloc`: Esta excepción se lanza cuando una operación de asignación de memoria dinámica falla, por ejemplo, al usar el operador `new`. Esta excepción puede ser útil para detectar errores de memoria y liberar recursos antes de terminar el programa, por ejemplo cuando no se utiliza el operador `del` para cada reservación de memoria para un puntero [5].

- `std::out_of_range`: Esta excepción se lanza cuando se intenta acceder a un elemento fuera del rango válido de un contenedor o una cadena. Esta excepción puede ser útil para evitar accesos ilegales a la memoria y manejar los casos de error adecuadamente, en este caso cuando se tiene un `vector` que almacena 5 números y se desea buscar un número en la "sexta posición" que no existe [5].

- `std::invalid_argument`: Esta excepción se lanza cuando se pasa un argumento inválido a una función, por ejemplo, una cadena que no se puede convertir a un número. Esta excepción puede ser útil para validar los parámetros de entrada y proporcionar mensajes de error informativos, como cuando se desea pasar un dato double a una función que solo admite enteros [5].

6. Política de Manejo de Excepciones:
¿Qué es una política de manejo de excepciones y por qué es importante considerarla al diseñar software?

Una política de manejo de excepciones es un conjunto de reglas o principios que definen cómo se deben tratar los errores que ocurren durante la ejecución de un programa. Una política de manejo de excepciones puede especificar, por ejemplo, qué tipos de excepciones se deben lanzar, cómo se deben capturar, qué acciones se deben realizar para recuperarse o informar al usuario, y cómo se deben documentar o registrar los errores [6].

Es importante considerar una política de manejo de excepciones al diseñar software porque ayuda a mejorar la calidad, la seguridad y la usabilidad del programa. Una buena política de manejo de excepciones puede evitar que el programa se cuelgue o se comporte de forma inesperada, que se pierdan o corrompan datos, que se vulneren la seguridad o la privacidad, o que se confunda o frustre al usuario [6]. 

7. Noexcept:
Explica el propósito de la palabra clave noexcept y cómo se utiliza en C++.

La palabra clave noexcept se utiliza para declarar que una función no lanza ninguna excepción en C++11 y posteriores. Esto permite al compilador optimizar el código y evitar el manejo innecesario de excepciones.

La palabra clave noexcept se puede usar de dos formas:

- **Especificador de excepción:** se coloca después de la lista de parámetros de la función y antes del cuerpo {} de la misma. Indica que la función no lanza ninguna excepción y que si lo hace, se invoca std::terminate (es una función que se llama cuando ocurre una excepción no gestionada). 

```cpp
/* Se instancia la función */
void mostrarInfo() noexcept {   /* Esta función no muestra ninguna excepción*/
    // Aquí iría el código
}  
```

- **Operador:** se aplica a una expresión y devuelve un valor booleano que indica si la expresión es no lanzadora o no. Se puede usar dentro de un especificador de excepción para hacerlo condicional al tipo de los argumentos de la función.


```cpp
/* Se instancia la función */
void mostrarCon sinExcepcionesInfo() { 
    // Aquí iría el código
}  

/* Se instancia la función */
void mostrarCon excepcionesInfo() noexcept {   /* Esta función no muestra ninguna excepción*/
    // Aquí iría el código
}  
```

```cpp
/* Usar el operador noexcept para comprobar si una función es no lanzadora de excepciones o no */
bool var1 = noexcept(sinExcepcionesInfo())  // var1 es false
bool var2 = noexcept(excepcionesInfo())     // var2 es true
```

### STL (Standard Template Library):

8. Contenedores STL:
Nombre cinco contenedores diferentes de la STL y explique brevemente en qué situaciones sería apropiado usar cada uno.

Los contenedores de la STL se pueden clasificar en tres categorías: contenedores de secuencia, contenedores asociativos y adaptadores de contenedor. A continuación se muestran 5 ejemplos y se separan por categorías [7]:

- Contenedores de secuencia: son contenedores que almacenan los elementos en el orden en que se insertan o se modifican.
    
    - `std::vector`: es un contenedor que se comporta como un arreglo dinámico, es decir, que puede cambiar de tamaño automáticamente según se necesite. Permite el acceso aleatorio y contiguo a los elementos, y tiene una alta eficiencia en la inserción y eliminación al final. Es el contenedor de secuencia más usado y recomendado para la mayoría de las situaciones.

    - `std::list`: es un contenedor que implementa una lista doblemente enlazada, es decir, que cada elemento tiene un puntero al anterior y al siguiente. Permite el acceso bidireccional y la inserción y eliminación rápidas en cualquier posición, pero no permite el acceso aleatorio ni contiguo. Es adecuado para situaciones en las que se requiere mucha modificación en el medio del contenedor.

- Contenedores asociativos: son contenedores que almacenan los elementos en un orden determinado por una clave o un criterio de comparación.

    - `std::set`: es un contenedor que implementa un conjunto matemático, es decir, que almacena elementos únicos y los ordena según un criterio de comparación. Permite el acceso bidireccional y la búsqueda rápida de los elementos, pero no permite la modificación de los mismos. Es adecuado para situaciones en las que se requiere eliminar los elementos duplicados y mantener un orden determinado.

    - `std::unordered_set`: es un contenedor que implementa un conjunto matemático, pero no lo ordena según un criterio de comparación, sino que lo organiza en grupos o cubetas según una función de hash. Permite el acceso unidireccional y la búsqueda, inserción y eliminación más rápidas que un set, pero no permite la modificación de los elementos. Es adecuado para situaciones en las que se requiere eliminar los elementos duplicados y no se necesita un orden determinado.

- Adaptadores de contenedor: son clases que proporcionan una interfaz específica basada en un contenedor subyacente.

    - `std::stack`: es un adaptador que implementa una pila, es decir, una estructura de datos de tipo LIFO (last in, first out). Permite el acceso y la modificación solo del elemento superior de la pila, y tiene operaciones de inserción y eliminación rápidas. Es adecuado para situaciones en las que se requiere procesar los elementos en orden inverso al que se insertaron.

9. Iteradores en STL:
Explique el concepto de iteradores en la STL y cómo se utilizan para acceder a elementos en contenedores.

Los iteradores en la STL son objetos que se pueden usar para recorrer o acceder a los elementos de los contenedores, como si fueran punteros. Los iteradores permiten abstraer el tipo y la estructura interna de los contenedores, y ofrecen una forma uniforme y genérica de manipular los datos [8].

Los iteradores se pueden clasificar en cinco categorías, según las operaciones que soportan [8]:

- Iteradores de entrada: son iteradores que se pueden usar para leer los elementos de un contenedor una sola vez, y solo se pueden incrementar. A continuación se muestra el uso del iterador `begin()`  y `end()`:

```cpp
std::vector<int> numeros = {1, 2, 3, 4, 5};

// Iterador de entrada
std::vector<int>::const_iterator iterador = numeros.begin();

// Lectura de elementos
while (iterador != numeros.end()) {
    std::cout << *iterador << " ";
    ++iterador;  // Solo se puede incrementar
}
```

- Iteradores de salida: son iteradores que se pueden usar para escribir los elementos de un contenedor una sola vez, y solo se pueden incrementar. A continuación se muestra el uso del iterador `insert(vector, i)`:

```cpp
std::vector<int> numeros;

// Iterador de salida
std::vector<int>::iterator iterador = numeros.begin();

// Escritura de elementos
for (int i = 1; i <= 5; ++i) {
    iterador = numeros.insert(iterador, i);  // Solo se puede incrementar
}

// Mostrar el contenido del contenedor
for (int num : numeros) {
    std::cout << num << " ";
}
```

- Iteradores de avance: son iteradores que se pueden usar para leer o escribir los elementos de un contenedor varias veces, y se pueden incrementar o decrementar. A continuación se muestra el uso del iterador como puntero `*iterador`:

```cpp
std::list<char> caracteres = {'a', 'b', 'c', 'd'};

// Iterador de avance
std::list<char>::iterator iterador = caracteres.begin();

// Leer y escribir elementos
while (iterador != caracteres.end()) {
    std::cout << *iterador << " ";
    ++iterador;  // Se puede incrementar
}
```

- Iteradores bidireccionales: son iteradores que se pueden usar para leer o escribir los elementos de un contenedor varias veces, y se pueden incrementar o decrementar en ambas direcciones. A continuación se muestra el uso del iterador como puntero `*iterador`:

```cpp
std::list<double> numeros = {1.1, 2.2, 3.3, 4.4};

// Iterador bidireccional
std::list<double>::iterator iterador = --numeros.end(); // Se puede decrementar

// Leer y escribir elementos en ambas direcciones
while (iterador != numeros.begin()) {
    std::cout << *iterador << " ";
    --iterador;  // Se puede incrementar o decrementar
}
```

- Iteradores de acceso aleatorio: son iteradores que se pueden usar para leer o escribir los elementos de un contenedor varias veces, y se pueden incrementar, decrementar o desplazar de forma arbitraria.  A continuación se muestra el uso del iterador como puntero `*iterador`:

```cpp
std::vector<std::string> palabras = {"Hola", "Mundo", "C++"};

// Iterador de acceso aleatorio
std::vector<std::string>::iterator iterador = palabras.begin() + 1; // Se puede desplazar de forma arbitraria

// Leer y escribir elementos de forma arbitraria
for (; iterador < palabras.end(); ++iterador) {
    std::cout << *iterador << " ";
}
```

10. Algoritmos STL:
Proporcione ejemplos de al menos tres algoritmos de la STL y describa sus funciones básicas.

Son funciones genéricas que operan sobre rangos de elementos, como los contenedores. Los algoritmos de la STL se pueden clasificar en varias categorías, según el tipo de operación que realizan, como ordenación y búsqueda. Algunos ejemplos de algoritmos de la STL son [9]:

- `sort`: es un algoritmo que ordena los elementos de un rango según un criterio de comparación. Por defecto, usa el operador < para comparar los elementos, pero se puede especificar una función o un objeto de comparación personalizado. Por ejemplo, para ordenar un vector de enteros de forma ascendente:

```cpp
std::vector<int> v = {5, 3, 1, 4, 2}; // Declarar e inicializar un vector de enteros
std::sort(v.begin(), v.end()); // Ordenar el vector de forma ascendente

// Mostrar el vector ordenado
for (int x : v)
{
    std::cout << x << " ";
}

std::cout << std::endl; // Salida: 1 2 3 4 5
```

- `find`: es un algoritmo que busca un elemento en un rango y devuelve un iterador al primer elemento que es igual al valor buscado, o al final del rango si no lo encuentra. Por ejemplo, para buscar el valor 3 en un arreglo de enteros:

```cpp
int a[] = {1, 2, 3, 4, 5}; // Declarar e inicializar un arreglo de enteros

int* p = std::find(a, a + 5, 3); // Buscar el valor 3 en el arreglo en el rango dado

// Mostrar el resultado de la búsqueda
if (p != a + 5) {
        std::cout << "El valor 3 se encontró en la posición " << p - a << std::endl; }
else{
    std::cout << "El valor 3 no se encontró en el arreglo" << std::endl; }

// Salida: El valor 3 se encontró en el indice 2
```

- `accumulate`: es un algoritmo que calcula la suma de los elementos de un rango, opcionalmente con un valor inicial y una función de operación binaria. Por defecto, usa el operador + para sumar los elementos, pero se puede especificar una función o un objeto de operación binaria personalizado. Por ejemplo, para calcular la suma de los elementos de un vector de enteros:

```cpp
std::vector<int> v = {1, 2, 3, 4, 5}; // Declarar e inicializar un vector de enteros

int p = std::accumulate(v.begin(), v.end(), 0); // Calcular la suma de los elementos del vector

// Mostrar el resultado del cálculo
std::cout << "La suma de los elementos del vector es " << p << std::endl;

// Salida: El producto de los elementos del vector es 15
```
11. Algoritmos Personalizados:
¿Cómo podría utilizar un algoritmo personalizado con la STL?

Para utilizar un algoritmo personalizado con la STL, se puede definir una función o un objeto de función que implemente la lógica del algoritmo, y luego aplicarlo a un rango de elementos usando un iterador o un contenedor. La función o el objeto de función debe cumplir con los requisitos de la STL, como aceptar y devolver tipos genéricos, no modificar los elementos del rango, no lanzar excepciones, etc.

Un ejemplo de código sería el sigueinte:

```cpp
int factorial(int n)
{
// Si el número es cero o uno, devolver uno
if (n == 0 || n == 1){
    return 1;
}
// Si no, devolver el producto del número y el factorial del número menos uno
else{
    return n * factorial(n - 1);
}
}
```

```cpp
#include <iostream>     // Incluir el encabezado para la entrada y salida estándar
#include <vector>       // Incluir el encabezado del contenedor vector
#include <algorithm>    // Incluir el encabezado del algoritmo for_each
```

```cpp
std::vector<int> v = {1, 2, 3, 4, 5}; // Declarar e inicializar un vector de enteros

// Usar la función factorial como argumento del algoritmo for_each para calcular el factorial de cada elemento del vector
std::for_each(v.begin(), v.end(),  {
    std::cout << "El factorial de " << x << " es " << factorial(x) << std::endl;
});

// Salida:
// El factorial de 1 es 1
// El factorial de 2 es 2
// El factorial de 3 es 6
// El factorial de 4 es 24
// El factorial de 5 es 120
```

### Expresiones Regulares:

12. Definición de Expresiones Regulares:
Defina qué son las expresiones regulares y proporcione un ejemplo simple.

13. Caracteres Especiales:
Enumere al menos tres caracteres especiales comúnmente utilizados en expresiones regulares y describa sus funciones.

14. Uso de Expresiones Regulares en C++:
¿Cómo se utilizan las expresiones regulares en C++? Proporcione un ejemplo.

15. Validación de Patrones:
¿Por qué las expresiones regulares son útiles para la validación de patrones en cadenas de texto?

## Bibliografía:

[1] “Templates (C++) | Microsoft Learn,” Microsoft, 16-Oct-2022. [En línea]. Disponible: https://learn.microsoft.com/en-us/cpp/cpp/templates-cpp?view=msvc-170. [Accedido: 22-Ene-2024].

[2] “C++ Función de sobrecarga de plantillas - learntutorials.net,” learntutorials.net, 2024. [En línea]. Disponible: https://learntutorials.net/es/cplusplus/topic/4164/funcion-de-sobrecarga-de-plantillas. [Accedido: 22-Ene-2024].

[3] “Plantillas de clase | Microsoft Learn,” Microsoft, 02-Abr-2023. [En línea]. Disponible: https://learn.microsoft.com/es-es/cpp/cpp/class-templates?view=msvc-170. [Accedido: 22-Ene-2024].

[4] “Instrucciones try, throw y catch (C++)”, Microsoft Docs, 2021. [En línea]. Disponible en: https://learn.microsoft.com/es-es/cpp/cpp/try-throw-and-catch-statements-cpp?view=msvc-170. [Accedido: 22-ene-2024].

[5] “Excepciones (C++/CX) | Microsoft Learn,” Microsoft, 02-Abr-2023. [En línea]. Disponible: https://learn.microsoft.com/es-es/cpp/cppcx/exceptions-c-cx?view=msvc-170. [Accedido: 22-Ene-2024].

[6] “Manejo de excepciones en las politicas generales de seguridad informática - 1Library.Co,” 1Library.Co, 2024. [En línea]. Disponible: https://1library.co/article/manejo-de-excepciones-en-las-pol%C3%ADticas-generales.yj7wmpky. [Accedido: 22-Ene-2024].

[7] “Contenedores de la biblioteca estándar de C++ | Microsoft Learn,” Microsoft, 12-Oct-2023. [En línea]. Disponible: https://learn.microsoft.com/es-es/cpp/standard-library/stl-containers?view=msvc-170. [Accedido: 22-Ene-2024].

[8] “Iterators in C++ STL - GeeksforGeeks,” GeeksforGeeks. [En línea]. Disponible: https://www.geeksforgeeks.org/iterators-c-stl/. [Accedido: 22-Ene-2024].

[9] “Algorithms library - cppreference.com,” cppreference.com, 2023. [En línea]. Disponible: https://en.cppreference.com/w/cpp/algorithm. [Accedido: 22-Ene-2024].