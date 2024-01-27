# Tarea 4: Uso de clases y tiempo de ejecuión en python, y teoría.
## Ejecución del programa:


## Parte teórica:
### 1. Explique la diferencia entre una lista y una tupla en Python.

Una lista y una tupla son dos tipos de estructuras de datos que pueden almacenar una colección de elementos, los cuales pueden ser de distintos tipos de datos. La principal diferencia es que una lista es mutable, es decir, se puede modificar después de su creación accediendo a sus elementos mediante un indice, mientras que una tupla es inmutable, es decir, no se puede cambiar una vez creada.

Algunas consecuencias de esta diferencia son:

- Las listas se crean con corchetes `[]` o con el método `list()`. Las tuplas se crean con paréntesis `()` o con el método `tuple()`. 

- Las listas ocupan más memoria que las tuplas, ya que tienen que reservar espacio para posibles cambios.

- Las listas se pueden mediante métodos como `append`, `insert`, `remove` o `pop`. Las tuplas no tienen estos métodos y solo se pueden crear o acceder a sus elementos.

### 2. ¿Qué es la sobrecarga de operadores en Python y cómo se implementa?

La sobrecarga de operadores es una técnica que permite definir el comportamiento de los operadores nativos (+, -, *, etc) del lenguaje cuando se aplican a objetos de una clase personalizada [2].

Para implementar la sobrecarga de operadores en Python, *se debe definir un método especial dentro de la clase* que corresponda al operador que se quiere sobrecargar. Estos métodos siguen la convención de nomenclatura `__action__`, donde `action` es el nombre del operador o la acción que se quiere realizar [2]. 

Un ejemplo de sobrecarga de operadores en Python es el siguiente:

>Utilizan la nomenclatura de `__action__` el método `__add__` se usa para sobrecargar el operador `+`, el método `__sub__` se usa para sobrecargar el operador `-`, el método `__mul__` se usa para sobrecargar el operador `*`.

```python
# Definir una clase OperacionBasica que representa un vector de dos dimensiones
# realizando operaciones en dos ejes
class OperacionBasica:
    # Constructor de la clase
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Sobrecargar el operador + para sumar dos vectores
    def __add__(self, other):
        return OperacionBasica(self.x + other.x, self.y + other.y)

    # Sobrecargar el operador - para restar dos vectores
    def __sub__(self, other):
        return OperacionBasica(self.x - other.x, self.y - other.y)

    # Sobrecargar el operador * para multiplicar un vector por una contante
    def __mul__(self, scalar):
        return OperacionBasica(self.x * scalar, self.y * scalar)

    # Sobrecargar el método __repr__ para mostrar una representación del vector
    # del vector actual
    def __repr__(self):
        return f"OperacionBasica({self.x}, {self.y})"

# Crear dos instancias de la clase Vector
v1 = OperacionBasica(3, 5)
v2 = OperacionBasica(2, 7)

# Usar los operadores sobrecargados para realizar operaciones entre vectores
print(v1 + v2)      # Output: OperacionBasica(5, 12)
print(v2 - v1)      # Output: OperacionBasica(-1, 2)
print(v2 * 1.3)     # Output: OperacionBasica(2.6, 9.1)
```

### 3. Explique el concepto de "alcanzabilidad" (scope) de una variable en Python.

El concepto de "alcanzabilidad" (scope) de una variable en Python se refiere al ámbito o región del código donde una variable es accesible o visible. Esto depende de dónde y cómo se declara la variable [3].

Eexisten cuatro niveles de scope para las variables:

- **Local**: Es el scope más interno, y corresponde a las variables que se declaran dentro de una función o un bloque de código. Estas variables solo se pueden usar dentro de ese contexto, y no son visibles desde fuera [3]. Por ejemplo:

```python
def suma(a, b):
    c = a + b   # La variable c es local a la función suma
    return c

print(c)    # Output: Error: name 'c' is not defined
```

- **Nonlocal**: Es el scope que se aplica a las variables que se declaran dentro de una función anidada. Estas variables se pueden usar dentro de la función anidada y en la función que la contiene, pero no fuera de ella. Para declarar una variable como nonlocal, se usa la palabra reservada `nonlocal`. Por ejemplo:

```python
def externa():
    # La variable x es local a la función externa
    x = 10
    def interna():
        # Para acceder y modificar la variable x de la función externa, se usa nonlocal
        nonlocal x
        x = x + 1
        print(x) # 11
    interna()
    print(x) # 11

print(x)    # Output: Error: name 'x' is not defined
```

- **Global**: Es el scope que se aplica a las variables que se declaran fuera de cualquier función o bloque de código, es decir, en el nivel más externo del módulo o archivo. Estas variables se pueden usar en cualquier parte del programa, pero solo se pueden modificar dentro del scope global. Para modificar una variable global dentro de una función, se usa la palabra reservada `global`. Por ejemplo:

```python
# La variable y es global
y = 20

def prueba():
    # Para modificar la variable y global, se usa global
    global y
    y = y + 2
    print(y)

print(prueba(20))   # Output: 22
```

- **Built-in**: Es el scope que se aplica a las variables que están predefinidas en Python, como las funciones, los tipos de datos, las excepciones, etc. Estas variables se pueden usar en cualquier parte del programa, pero no se deben modificar. Por ejemplo:

```python
# La variable len es una función built-in de Python
print(len("Hola")) # 4

# No se debe modificar la variable len
len = 5
print(len("Hola")) # Error: 'int' object is not callable
```

### 4. ¿Qué es un decorador en Python y cuál es su función principal?

### 5. ¿Cómo se gestionan las excepciones en Python? Proporcione ejemplos de uso de bloques try, except y finally.

### 6. ¿Qué son los generadores en Python y para qué se utilizan?

### 7. Explique la diferencia entre `__init__` y `__call__` en clases de Python.

### 8. ¿Cómo se organizan los módulos y paquetes en Python? ¿Qué es `__init__.py`?

### 9. Explique la diferencia entre los métodos `append()` y `extend()` en listas de Python.

### 10. ¿Cuál es la diferencia entre un método de clase y un método estático en Python?

### 11. Hable sobre las diferencias entre herencia simple y herencia múltiple en Python.

### 12. ¿Cómo se manejan los errores de importación de módulos en Python?

### 13. ¿Cuál es la diferencia entre una clase y un objeto en Python?

### 14. Hable sobre la diferencia entre una clase abstracta y una interfaz en Python.

### 15. Explique el concepto de sobreescritura de métodos en Python y cómo se realiza.


## Bibliografía:

[1] L. M. Báez, “(Overloading) — Sobrecargar Operadores en Python,” Medium, 5 de agosto de 2019. [En línea]. Disponible: https://medium.com/@LuisMBaezCo/overloading-sobrecargar-operadores-en-python-5d7a75e2bfdf. [Accedido: 27- Ene- 2024].

[2] G. Canepa, “Alcance de las variables en Python,” El Camino del Sysadmin, 17 de junio de 2017. [En línea]. Disponible: https://blog.carreralinux.com.ar/2017/06/alcance-de-las-variables-en-python/. [Accedido: 27- Ene- 2024].