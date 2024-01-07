# TAREA 1: Teoría, juego y makefiles.

## Instrucciones del juego: Adivina el entero


## Parte Teórica:
### Aprendamos más sobre C++

1. ¿Cuál es la principal diferencia entre C y C++?

Las principales diferencias entre C++ y C se centran en el paradigma de programación, la seguridad y características, la estructura del código, la compatibilidad y el manejo de variables. C++ incorpora la orientación a objetos, proporciona mayor seguridad con la encapsulación, tiene una librería estándar más amplia, organiza el código mediante clases y funciones, es compatible con C pero la conversión puede ser complicada, introduce la variable de referencia y cuenta con más palabras clave y tipos de datos básicos en comparación con C. Estas diferencias influyen en la elección del lenguaje según las necesidades y preferencias del desarrollo de software [1].

2. ¿Cuáles son las diferencias fundamentales entre un lenguaje de programación compilado y uno interpretado? Proporcione ejemplos de situaciones en las que sería más óptimo utilizar un lenguaje compilado y otras en las que sería más adecuado un lenguaje interpretado.

Un lenguaje de programación compilado requiere un paso adicional antes de ser ejecutado, la compilación, que convierte el código que escribes a lenguaje de máquina. Un lenguaje interpretado, por otro lado, es convertido a lenguaje de máquina a medida que es ejecutado [2].

3. Explique qué es un linker en el contexto de un lenguaje de programación compilado. ¿Cuál es su función principal y por qué es esencial en el proceso de compilación?

Un linker es un programa que toma los objetos generados en los primeros pasos del proceso de compilación y los combina en un único archivo. Por lo que su función principal es la de relocalización de archivos en un invisible unicó archivo.

4. Describa las diferencias clave entre los tipos de datos derivados y primarios en C++.

Los datos primarios (o primitivos) estan definidos por el compilador, los cuales pueden ser tipos enteros (int, short, char, etc.) o tipos reales(float, double y long double) [3]. 

Los datos derivados, al contrario, son controidos a partir de los datos primarios; entre ellos se encuentran: arrays, estructuras, punteros y funciones.

5. Defina qué significa inicializar y declarar una variable.

Inicializar una variable es otorgarle un valor inicial en el momente de la construcción de un programa. Declarar una variable es indicar el tipo de dato primario asociada a ella.

6. ¿Qué es la sobrecarga de funciones en C++ y cuáles son sus beneficios?

La sobrecarga de funciones en C++ permite especificar más de una función con el mismo nombre en el mismo ámbito. Las funciones sobrecargadas permiten proporcionar una semántica diferente para una función, dependiendo de los tipos y el número de argumentos [4].

7. ¿Qué es un puntero y cómo se utiliza? Explique con un ejemplo de la vida real.

El puntero es una variable que almacena la dirección de memoria de otro valor. Esto permite que se pueda acceder o modificar el contendio de la dirección a la que apunta el puntero.

Un ejemplo concreto en la vida real podría ser la apertura de una cuenta bancaria recién establecida. Al decidir el tipo de cuenta (similar a un dato primitivo asociado a un puntero), el banco asigna un número de identificación IBAN (equivalente a una dirección en memoria) a la cual nuestros fondos (representando el valor) serán depositados o retirados. De manera análoga, el datafono en un supermercado puede considerarse como un puntero, ya que, mediante la conexión a nuestra cuenta IBAN con nuestra tarjeta, modifica el total de dinero asociado a nuestra cuenta durante las transacciones.

8. ¿Una variable global almacena el valor original de una operación en una función o una copia? Explique su respuesta. Explique por qué se elige usar variables globales en lugar de locales en ciertos contextos.

Una variable global puede ser utilizada durante todo el programa y puede ser utilizada en cualquier función. Al ser una variable esta debe poseer una dirección de memoria unica, por lo que no se crea una copia en cada función; esto a su vez significa que no importa en qué instancia del programa se modifique una variable global siempre accederá a la misma dirección de memoria.

La elección de variables globales en lugar de variables locales puede ser a la necesidad de tener una variable que pueda ser accedida y modificada en clualquier instance del programa para tomar decisiones o simplificar procesos. Por ejemplo, una variable global podría utilizarse para iterar un ciclo hasta que sea modificada por una función y concluya con las operaciones del programa.


9. Investigue y explique tres métodos comunes de la biblioteca string en C++.

La biblioteca string permite manipular de forma sencilla cadenas de carácteres, entre los métodos más comunes encontrados son [5]:

* `size()`: devuelve el número de carácteres que contiene la cadena.
* `append()`: añade una cadena o un carácter al final de la cadena original, modificándola.
* `substr()`: devuelve el número de carácteres que contiene la cadena.

10. ¿Cuál es la principal diferencia entre un bucle do-while y un bucle while?

En un bucle do-while primero se ejecuta una serie de instrucciones y luego se evalúa si es necesario seguir ejecutanlas, mientras que en un bucle while hay que evaluar antes de ejecutar. Por lo que su principal diferencia en el instancia en el que se evalua una condición.

11. ¿Es permitido almacenar funciones en una estructura en C++? En el caso de los datos, ¿se pueden encapsular en miembros privados y públicos dentro de una estructura? Explique su respuesta.

Es permitido almacenar funciones en estructuras, siempre y cuando se declaren como miembros de la estructura (de la misma que una variable entera, por ejemplo). Las funciones miembro de una estructura pueden acceder y modificar datos miembro de la misma, así como invocar a otras funciones.

Las funciones se pueden encapsular como miebros privados o públicos usando palabras clave `private`  o `public`. Las funciones dentro de *private* solo pueden ser accesibles delas las funciones miembro de la estructura, mientras que las funciones dentro de `public` pueden ser accedidas desde cualquier parte del programa.

12. Explique por qué es útil y común dividir el código en archivos .hpp, .cpp y main.cpp en C++. Describa el propósito específico de cada tipo de archivo.

Su utilidad y uso común se debe a que dividir el código en archivos facilita la organización, la reutilización, la legibilidad y la compilación del código.

* Los archivos `.hpp` contienen las declaraciones de las librerías, las clases, los prototipos de funciones, las variables y las constantes que se van a utilizar en el programa. Se les suele llamar `header` y se inclyen con la instrucción `include` en los archivos .cpp que lo necesiten [6].

* Los archivos `.cpp` contienen las implementaciones de las clases, funciones y las variables que se han declarado en los archivos .hpp. Estos archivos se conocen como archivos de código fuente, y se compilan por separado para generar archivos objeto que luego se enlazan para formar el ejecutable del programa [6].

* El archivo `main.cpp` contiene la función principal main() del programa, que es el punto de entrada y de salida del mismo. Este archivo también es un archivo de código fuente, y suele incluir los archivos .hpp que contienen las clases, las funciones y las variables que se van a usar en el programa [6].

13. Defina qué es el Type Casting en C++ y explique su utilidad. Proporcione ejemplos de situaciones en las que se emplea el Type Casting y cómo se realiza.

El Type Casting en C++ es la conversión explícita de un tipo de dato a otro, que se realiza mediante un operador de conversión. El Type Casting es útil cuando se quiere cambiar el tipo de una de una variable para adaptarlo a las necesidades del programa, por ejemplo, para evitar pérdidas de precisión [7]. Algunos ejemplos serían:

* Convertir un tipo `int` a `char` para sar un código ASCCI a su equivalente en letra.

* Realizar operaciones con más cifras significativas al convertir un tipo `int` a `double`.

14. ¿Por qué la sentencia goto no es recomendable en programación moderna? Mencione ejemplos de cómo se pueden lograr los mismos resultados sin el uso de goto.

No se recomienda el uso de goto debido a que complica la lectura del código y de depurar, además de que altera modificaciones en el código provocando saltos no previstos haciendo que no se inicialicen variables o recursos sin liberar. Para evitar usar goto existen alternativas como los ya clásicos bucles junto con el uso de la instrucción `break` o `continue` o el uso de condiciones booleanas con sentencias if, las cuales por el uso de las llaves, identación y editor de código se hacen mucho más legibles.

Por ejemplo, en lugar de utilizar un goto para salir de un for que todavía no ha terminado, se puede utilizar una sentencia if que evalué la condición deseada y luego usar un break; y si se trata de una función y ya se terminó la operación se podría utilizar un `return`.

15. ¿Dónde y cómo se guardan las variables que se crean en C++? Explique la diferencia entre el almacenamiento de variables locales y globales.

Las variables que se crean en un código siempre serán guardadas en regiones de la memoria dependiendo de su tipo, duración y ámbito. 

Las variables globales se guardan en regiones estáticas de la memoria, se crean al inicio del programa y se destruyen al final del mismo. Mientras que las variables globales, debido a que unicamente dentro de una función o bloque de código, se almacenan en una pila de memoria utilizada para las funciones y variables locales; y su vida util está limitada al tiempo de ejecución de la función o bloqué en el que se declará [8].


16. ¿Cuál es la diferencia entre pasar parámetros por valor, por referencia y por puntero?

* Pasar parámetros por valor significa crear una copia del valor del argumento que se pasa a la función, y trabajar con esa copia dentro de la función. Esto implica que cualquier modificación que se haga sobre el parámetro dentro de la función no afectará al argumento original que se pasó [9].

* Pasar parámetros por referencia `&` significa crear un alias o un nombre alternativo para el argumento que se pasa a la función, y trabajar con ese alias dentro de la función. Esto implica que cualquier modificación que se haga sobre el parámetro dentro de la función afectará al argumento original que se pasó, ya que ambos se refieren al mismo valor [9]. 

* Pasar parámetros por puntero `*` significa crear un puntero que apunta a la dirección de memoria del argumento que se pasa a la función, y trabajar con ese puntero dentro de la función. Esto implica que se puede acceder y modificar el valor al que apunta el puntero dentro de la función, lo que afectará al argumento original que se pasó, pero también se puede modificar el valor del puntero en sí, lo que no afectará al argumento original que se pasó [9].

17. Cuando se usa un puntero para apuntar a un arreglo en C++, ¿a qué valor o dirección apunta inicialmente? Describa cómo sería la forma de acceder a todos los datos de ese arreglo mediante el puntero.

Cuando se utiliza un puntero para apuntar a un arreglo en C++, el puntero inicialmente apunta inicialmente a la dirección del primer elemento del arreglo.

Suponiendo que se tiene un arreglo `char arr[4] = "Hola"`, la forma de acceder a todos los datos sería mediante un ciclo for que itere una cantidad de veces igual al tamaño total del arreglo y cada vez que se itere se le sume 1 `*(ptr + i)` a la dirección inicial que esta almacenada por el puntero `char* ptr = &arr[0]`. 

18. Explique para qué son empleados los punteros dobles en C++. Proporcione ejemplos de situaciones en las que los punteros dobles son necesarios o beneficiosos.

Los punteros sobles son punteros que apuntan a otros punteros. Se emplean para pasar punteros por referencia a una función, crear arreglos de dos dimensiones o gestionar la memoría dinámica. Como ejemplos [10]:

1. **Matrices bidimencionales:** Un uso común de los punteros dobles es en la gestión de matrices bidimensionales o arreglos de arreglos. Cuando declaras un puntero doble y lo asignas a una matriz, puedes acceder a elementos individuales de la matriz utilizando dos niveles de indirección.

2.  **Paso de parámetros a funciones:** Los punteros dobles también pueden ser útiles cuando se pasa una matriz o una estructura de datos dinámica a una función y se necesita modificar la dirección del puntero original.

19. ¿Cuál es la diferencia entre un break y un continue en los bucles de C++?

El `break` termina el buclé inmediatamente y se sale de él, mientras que el `continue` termina la iteración actual del buclé y salta a la siguiente.

20. ¿Para qué se utiliza la directiva #ifndef?

La directiva `#ifndef` se utiliza para evitar la inclusión múltiple de un archivo header en un programa. La directiva `#ifndef` comprueba si una macro está definida o no, y si no lo está, ejecuta el código entre ella y la directiva `#endif` correspondiente. Esto evita que el mismo archivo header se incluya más de una vez, lo que podría causar errores de redefinición o duplicación [11].  

21. ¿Qué es el puntero this en C++?

El puntero `this` en C++ es un puntero que está disponible solo dentro de las funciones miembro no estáticas de una clase, estructura o unión. El puntero `this` apunta al objeto para el que se llama a la función miembro. Las funciones miembro estáticas no tienen un puntero `this`. El puntero `this` se usa implícitamente para acceder a los miembros de la clase, pero también se puede usar explícitamente [12].


Un ejemplo sencillo:
```
#include <iostream>

class Ejemplo {
private:
    int valor;

public:
    void asignarValor(int nuevoValor) {
        // Uso implícito del puntero this
        this->valor = nuevoValor;
    }

    void imprimirValor() {
        // Uso implícito del puntero this
        std::cout << "Valor: " << this->valor << std::endl;
    }
};

int main() {
    Ejemplo objeto;
    objeto.asignarValor(42);
    objeto.imprimirValor();

    return 0;
}
```

22. ¿Qué es un puntero nullptr?
Un puntero `nullptr` en C++ es un literal de puntero nulo que representa un valor de puntero que no apunta a ningún objeto o función. El puntero `nullptr` tiene un tipo especial llamado `std::nullptr_t`, que se puede convertir a cualquier tipo de puntero sin formato. El puntero `nullptr` se usa para indicar que un puntero no tiene una dirección válida, o para inicializar punteros que no se asignan todavía [13].

23. ¿Cuál es la diferencia entre un arreglo y una lista en C++?

Un arreglo es una colección ordenada de variables del mismo tipo que tiene un tamaño fijo y se almacena de forma contigua en la memoria, mientras que una lista es una colección secuelcial de elementos del mismo tipo que tienen diferentes tamaños y se almacena de forma dispersa en la memoria [14].

24. ¿Qué es una función prototipo?
Una función prototipo es una declaración de una función que especifica el nombre, el tipo de retorno y los parámetros de la función antes de su definición. Los prototipos de función se usan para permitir al compilador realizar una verificación de tipos más robusta, para evitar errores de coincidencia entre los argumentos y los parámetros, y para declarar funciones que se definen en otros archivos [15].

25. ¿Investigue qué es un memory leak?
Un memory leak en C++ es un error que ocurre cuando se reserva memoria dinámica usando `new` o `malloc` y se olvida de liberarla usando `delete` o `free`. Esto hace que la memoria reservada no esté disponible para otros usos y que el programa consuma más memoria de la necesaria. Un memory leak puede causar problemas de rendimiento, errores de memoria insuficiente o incluso el bloqueo del programa.



### Automatización con Makefile

1. ¿Qué suelen contener las variables CC, CFLAGS, CXXFLAGS y LDFLAGS en un Makefile?

2. ¿De qué se compone una regla en un Makefile?

3. Defina qué es un target y cómo se relaciona con sus prerequisitos.

4. ¿Para qué se utiliza la bandera -I, -c y -o del compilador gcc?

5. ¿Cómo se definen y se utilizan las variables en un Makefile? ¿Qué utilidad tienen?

6. ¿Qué utilidad tiene un @ en un Makefile?

7. ¿Para qué se utiliza .PHONY en un Makefile?

### Conocimientos importantes

1. Investigue qué es Doxygen y cómo se utiliza. Utilice lo aprendido al documentar su código, incluyendo agregar un encabezado a cada archivo con una licencia definida.

2. Investigue cuál es la convención mayormente utilizada en C++ para nombrar variables, clases, funciones, atributos, etc. (CamelCase, snake case, etc.) y utilícela en el desarrollo de su programa.


## Bibliografía
[1] SoftZone, "Diferencias entre C y C++: ¿qué lenguaje de programación es mejor?", SoftZone, 28 oct. 2020. [En línea]. Disponible en: https://www.softzone.es/noticias/general/diferencias-c-c-plus-plus/. [Consultado: 7 ene. 2024].

[2] AulaB, "Diferencia entre lenguajes de programación compilados e interpretados", AulaB, 9 jul. 2019. [En línea]. Disponible en: https://aulab.es/noticia/18/diferencia-entre-lenguajes-de-programacion-compilados-e-interpretados. [Consultado: 7 ene. 2024].


[3] J. A. P. Sandoval, "Tipos de datos en C", Pleets Blog, 8 nov. 2019. [En línea]. Disponible en: https://blog.pleets.org/article/es/tipos-de-datos-en-c. [Consultado: 7 ene. 2024].

[4] Microsoft, "Sobrecarga de funciones (C++)", Microsoft Learn, 2021. [En línea]. Disponible en: https://learn.microsoft.com/es-es/cpp/cpp/function-overloading?view=msvc-170. [Consultado: 7 ene. 2024].

[5] J. M. C., "Manejo de cadenas de texto en C", Stack Overflow en español, 9 ago. 2016. [En línea]. Disponible en: https://es.stackoverflow.com/questions/16633/manejo-de-cadenas-de-texto-en-c. [Consultado: 7 ene. 2024].

[6] J. A. García, "Estructura del código fuente en C", Genbeta, 14 jul. 2010. [En línea]. Disponible en: https://www.genbeta.com/desarrollo/estructura-del-codigo-fuente-en-c. [Consultado: 7 ene. 2024].

[7] GeeksforGeeks, "Type Conversion in C - GeeksforGeeks", 2023. [En línea]. Disponible en: https://www.geeksforgeeks.org/type-conversion-in-c/. [Consultado: 7 ene. 2024].

[8] E. Hack, "Variables globales y locales en C", eHack, 14 may. 2019. [En línea]. Disponible en: https://ehack.info/variables-globales-y-locales-en-c/. [Consultado: 7 ene. 2024].

[9] Blogg, "Programacion C++: Paso de parámetros en C++" Ejercicioscpp.blogspot.com, 2013. [En línea]. Disponible en: https://ejercicioscpp.blogspot.com/2013/07/paso-de-parametros-en-c.html. [Consultado: 7 ene. 2024].

[10] J. A. M. G., "¿Cómo acceder al método de un objeto usando un puntero doble en C++?", Stack Overflow en español, 17 dic. 2020. [En línea]. Disponible en: https://es.stackoverflow.com/questions/361089/c%C3%B3mo-acceder-al-metodo-de-un-objeto-usando-un-puntero-doble-en-c. [Consultado: 7 ene. 2024].

[11] Microsoft, "Directivas #ifdef y #ifndef (C/C++)", Microsoft Learn, 2021. [En línea]. Disponible en: https://learn.microsoft.com/es-es/cpp/preprocessor/hash-ifdef-and-hash-ifndef-directives-c-cpp?view=msvc-170. [Consultado: 7 ene. 2024].

[12] Microsoft, "El puntero this (C++)", Microsoft Learn, 2021. [En línea]. Disponible en: https://learn.microsoft.com/es-es/cpp/cpp/this-pointer?view=msvc-170. [Consultado: 7 ene. 2024].

[13] Microsoft, "nullptr (C++)", Microsoft Learn, 2021. [En línea]. Disponible en: https://learn.microsoft.com/es-es/cpp/cpp/nullptr?view=msvc-170. [Consultado: 7 ene. 2024].

[14] Microsoft, "Clase list (C++)", Microsoft Learn, 2021. [En línea]. Disponible en: https://learn.microsoft.com/es-es/cpp/standard-library/list-class?view=msvc-170. [Consultado: 7 ene. 2024].

[15] Microsoft, "Prototipos de función (C)", Microsoft Learn, 2021. [En línea]. Disponible en: https://learn.microsoft.com/es-es/cpp/c-language/function-prototypes?view=msvc-170. [Consultado: 7 ene. 2024].

[16] A. K. Singh, "Memory leak in C++ and How to avoid it?", GeeksforGeeks, 16 jul. 2019. [En línea]. Disponible en: https://www.geeksforgeeks.org/memory-leak-in-c-and-how-to-avoid-it/. [Consultado: 7 ene. 2024].
