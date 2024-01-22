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

5. Excepciones Estándar:
Nombre al menos tres excepciones estándar proporcionadas por C++ y proporcione ejemplos de situaciones en las que podrían ser útiles.

6. Política de Manejo de Excepciones:
¿Qué es una política de manejo de excepciones y por qué es importante considerarla al diseñar software?

7. Noexcept:
Explica el propósito de la palabra clave noexcept y cómo se utiliza en C++.

### STL (Standard Template Library):

8. Contenedores STL:
Nombre cinco contenedores diferentes de la STL y explique brevemente en qué situaciones sería apropiado usar cada uno.

9. Iteradores en STL:
Explique el concepto de iteradores en la STL y cómo se utilizan para acceder a elementos en contenedores.

10. Algoritmos STL:
Proporcione ejemplos de al menos tres algoritmos de la STL y describa sus funciones básicas.

11. Algoritmos Personalizados:
¿Cómo podría utilizar un algoritmo personalizado con la STL?

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