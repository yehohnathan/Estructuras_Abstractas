### STL (Standard Template Library)

La STL (Standard Template Library) de C++ es una biblioteca de clases y funciones que proporciona un conjunto de herramientas útiles para la programación genérica en C++. Se incluye en el estándar del lenguaje C++, por lo que está disponible en cualquier compilador que cumpla con este estándar.

- Reutilización de código: Proporciona una gran cantidad de algoritmos y estructuras de datos que se pueden reutilizar en 
múltiples proyectos. Esto significa que quienes programan pueden escribir menos código y aumentar su productividad.

- Rendimiento: Está diseñada para ser eficiente en términos de rendimiento. Muchos de los algoritmos y estructuras de datos están altamente optimizados y se han probado rigurosamente en diferentes plataformas.

- Estándar: Es parte de la biblioteca estándar de C++, lo que significa que está disponible en todas las implementaciones de C++.  Esto garantiza la portabilidad del código y facilita el trabajo en equipo.

- Flexibilidad: Es altamente flexible y configurable. Por ejemplo, las plantillas de la STL permiten a quienes programan utilizar diferentes tipos de datos con la misma estructura de datos o algoritmo. Se tienen tres componentes principales: Contenedores, Iteradores y Algoritmos. Además de estas, también proporciona otras características, incluidos, punteros inteligentes y mecanismos de manejo de excepciones

### Containers
Los contenedores almacenan datos y los organizan de una manera específica según sea necesario. Por ejemplo, los vectores almacenan datos del mismo tipo en orden secuencial. Mientras que los mapas almacenan datos en pares clave-valor. Estos se pueden categorizar en tres tipos:
1. Contenedores de secuencia (Sequence containers): Permiten almacenar elementos a los que se puede acceder en orden secuencial. Internamente, los contenedores secuenciales se implementan como arreglos o estructuras de datos de listas  enlazadas.

    ➢ Arreglos, vectores, deque, listas.

2. Contenedores asociativos (Associative containers): Permiten almacenar elementos en orden. El orden no depende de cuándo  se inserta el elemento. Internamente, se implementan como estructuras de datos de árbol binario.

    ➢ Set, multiset, map, multimap.

3. Contenedores asociativos desordenados (Unordered associative containers): Proporcionan las versiones sin ordenar del contenedor asociativo. Internamente, se implementan como estructuras de datos de hash-tables.

    ➢ Unordered_set, unordered_multiset, unordered_map, unordered_multimap.

### Iterators
Un iterador es un objeto similar a un puntero que representa la posición de un elemento en un contenedor. Se utiliza para iterar sobre elementos en un contenedor.Por ejemplo, en un vector llamado nums de tamaño 4., begin() y end() son funciones miembro que devuelven iteradores que apuntan al principio y al final del vector respectivamente.

- nums.begin() apunta al primer elemento del vector, es decir, el índice 0.

- nums.begin() + i apunta al elemento en el índice i.

- nums.end() apunta a un elemento más allá del elemento final en el vector

| Operations | Description |
|------------|-------------|
| *itr       | devuelve el elemento en la posición actual |
| itr->m     | devuelve el valor del miembro m del objeto apuntado por el iterador y es equivalente a (*itr).m |
| ++itr      | mueve el iterador a la siguiente posición |
| --itr      | mueve el iterador a la posición anterior |
| itr + i    | mueve el iterador i posiciones |
| itr1 == itr2 | devuelve verdadero si las posiciones apuntadas por los iteradores son las mismas |
| itr1 != itr2 | devuelve verdadero si las posiciones apuntadas por los iteradores no son las mismas |
| itr = itr1 | asigna |

| Iterator Type           | Supported Operators                     |
|-------------------------|-----------------------------------------|
| Input Iterator          | `++`, `*`, `->`, `==`, `!=`             |
| Output Iterator         | `++`, `*`, `=`                          |
| Forward Iterator        | `++`, `*`, `->`, `==`, `!=`             |
| Bidirectional Iterator  | `++`, `--`, `*`, `->`, `==`, `!=`       |
| Random Access Iterator  | `++`, `--`, `*`, `->`, `[]`, `+`, `-`, `<`, `>`, `<=`, `>=`, `==`, `!=` |

### Algoritmos de la STL:

**Algoritmos de manipulación de rangos:**

| Algoritmo  | Descripción |
|------------|-------------|
| copy       | Copia elementos de un rango a otro. |
| move       | Mueve elementos de un rango a otro. |
| fill       | Asigna un valor dado a todos los elementos en un rango. |
| transform  | Aplica una operación a cada elemento en un rango y almacena el resultado en otro rango. |

**Algoritmos de eliminación y modificación:**

| Algoritmo | Descripción |
|-----------|-------------|
| remove    | Elimina elementos específicos de un rango. |
| replace   | Reemplaza elementos específicos en un rango. |
| reverse   | Invierte el orden de los elementos en un rango. |

**Algoritmos numéricos:**

| Algoritmo     | Descripción |
|---------------|-------------|
| accumulate    | Realiza una operación de acumulación en un rango. |
| inner_product | Calcula el producto escalar de dos rangos. |
| partial_sum   | Calcula la suma acumulativa de un rango. |
| iota          | Llena un rango con valores incrementales. |

**Algoritmos de conjuntos:**

| Algoritmo        | Descripción |
|------------------|-------------|
| set_intersection | Calcula la intersección de dos conjuntos. |
| set_union        | Calcula la unión de dos conjuntos. |
| set_difference   | Calcula la diferencia entre dos conjuntos. |
| includes         | Verifica si un conjunto está incluido en otro. |
