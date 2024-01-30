# Tarea 4: Uso de clases y tiempo de ejecuión en python, y teoría.
## Ejecución del programa:

Para ejecutar el programa, asegúrese de estar en el directorio del repositorio en su computadora y escriba el comando `make`, como se muestra a continuación:

```go
...\ie0217\Tareas\TAREA_CUATRO> make
```

Luego se le despliegará un menú de opciones:
```go
================================================================================================
Tecleé un número asociado a una opción para acceder a una funcionalidad del Sistema de Alergias 
1. Para ingresar un puntaje y ver la lista de alergias a las que es sensible.
2. Para ingresar los tipos de alergias que tiene.
3. Para ingresar una nueva alergia a la lista.
4. Para finalizar el programa.
Ingrese una opción:
```

Este menú indica las acciones que tomará el programa dependiendo del número que ingrese, y cualquier número o dato que no corresponda a lo esperado conllevará a que el programa le vuelva a solicitar una opción.

Dependiendo de la opción a escoger, se le despliegará un nuevo menú. Cada menú es igual de claro que el mostrado y se le indicará cuando este cometiendo un error.

## Evaluación del rendimiento del código:
### Medición de Tiempo de Ejecución:

Utilizando el modulo `timeit` se analiza el tiempo de ejecución del programa, el cual se refiere al uso del usuario de todas sus funciones sin excepción, cambiando unicamente la cantidad de elementos que hay presentes en la lista.

Para llevar esto acabo se ingresa el equivalente del `main` dentro de la siguiente función: 
```py
# ----------------- # Creación de la interfaz de usuario # ------------------ #
def programa_principal():
    while True:
        print("\n================================================" +
              "================================================")
        print("Tecleé un número asociado a una opción para acceder a una",
              "funcionalidad del Sistema de Alergias",
              "\n1. Para ingresar un puntaje y ver la lista de",
              "alergias a las que es sensible.",
              "\n2. Para ingresar los tipos de alergias que tiene.",
              "\n3. Para ingresar una nueva alergia a la lista.",
              "\n4. Para finalizar el programa.")
        try:
            opcion = int(input("Ingrese una opción: "))

            if opcion == 1:
                print("\n================================================" +
                      "================================================")
                alergias = alergia.get_lista_alergias()
                evaluacion_especifica.evaluar_alergias(alergias)

            elif opcion == 2:
                print("\n================================================" +
                      "================================================")
                tipos_alergias.agregar_alergia()
                lista_alergias = tipos_alergias.get_lista_alergias()
                evaluacion_general.datos_alergias(lista_alergias)
                evaluacion_general.calcular_promedio()

            elif opcion == 3:
                alergia.agregar_alergia()
                alergia.imprimir_informacion_completa()

            elif opcion == 4:
                print("=======================================",
                      "FIN DEL PROGRAMA",
                      "=======================================")
                break

        except ValueError:
            print("Error: No se ingresó una opción válida.,"
                  "Inténtelo de nuevo.\n")
```

Luego se procede a realizar las siguientes pruebas, segun el orden de presedencia:

1. Se ingresa el peor caso del puntaje, el cual muestra todos los elementos de la lista a los que podría ser alergico.
2. Se agregan dos elementos de los 3 casos posibles cuando el usuario desea ingresar elementos.
    - 2 elementos con su nombre y puntaje
    - 2 elementos, uno cuyo nombre no esta en la lista y otro cuyo nombre si esta en la lista.
    - 2 elementos, uno cuyo valor no esta en la lista y otro cuyo valor si esta en la lista.
3. Se añaden una nuevaa alergia, despues del punto 1 y 2.
4. Se repite estos puntos con 10 elementos, 30 elementos y 50 elementos en la lista de alergias.

Utilizando la intrucción:

```py
tiempo = timeit.timeit(programa_principal, number=1)
print(f"Tiempo de ejecución agregar_alergia: {tiempo} segundos")
```

Se muestra el tiempo en segundos de una única ejecución. Por lo que para los 3 casos, en donde se varia la cantidad de alergias, se obtuvieron los siguientes valores:

| Número de Alergias | Tiempo de Ejecución (segundos) |
|---------------------|--------------------------------|
| 10                  | 56.49701900000218              |
| 30                  | 59.47061409999151              |
| 50                  | 63.73561440000776              |

La diferencia entre los valores fueron los siguientes:

| Diferencia de Alergias | Diferencia de Tiempo (segundos) |
|-------------------------|---------------------------------|
| 30 - 10                 | 2.97359509998933                |
| 50 - 10                 | 7.23859540000558                |
| 50 - 30                 | 4.26500030001625                |

La duración del código podría ser mucho mayor o mucho menor, dependiendo de las acciones del usuario, esta prueba la cual usa todas las funciones del programa permite tener un acercamiento del rendimiento del sistema y su comportamiento.

Como se puede observar, al sacar la diferencia entre todas las pruebas, hay un crecimiento lineal en la duración de ejecución dependiendo de lo larga que sea la lista de alergias del sistema. Esto debido a que por cada 20 alergias que se agreguen al sistema hay un aumento de 3.5 segundos en la ejecución del programa.

Aparte de esas 3 pruebas se hicieron busquedas de cuellos de botellas, forzando al programa tomar caminos complicados pero el tiempo no vario mucho y esto se debe a como esta estructurada la interfaz del usuario, ya que esta es sencilla y limitada. 

Respecto a los tiempos de ejecución obtenidos son buenos, al realizar las pruebas no hay ningun tipo de relantización que el usuario pueda percibir o que resulte llamativo. El hecho que el tiempo de ejecución no sea un problema es más que todo por tener que tomar desiciones dentro del código, leer lo que hay que hacer y ello conlleva más tiempo de lo que python es capaz de ejecutar el programa.

### Perfilado de código:

Al utilizar el módulo `cProfile` los siguientes códigos:
- Alergia.py
- EvaluacionEspecifica.py
- TiposAlergias.py
- EvaluacionGeneral.py

Se encontró que el tiempo de cada método de cada clase que utiliza el programa es el siguiente:

| Clase                    | Método                            | Tiempo de Ejecución (segundos) |
|--------------------------|-----------------------------------|---------------------------------|
| Alergia                  | imprimir_informacion_completa()   | 0.004                           |
| Alergia                  | imprimir_alergia("col")           | 0.000                           |
| Alergia                  | agregar_alergia()                 | 6.168                           |
| Alergia                  | get_lista_alergias()              | 0.000                           |
| EvaluacionEspecifica     | sumar_valor_alergias()            | 0.000                           |
| EvaluacionEspecifica     | evaluar_alergias()                | 3.913                           |
| EvaluacionEspecifica     | mostrar_alergias()                | 0.006                           |
| TiposAlergias            | agregar_alergia()                 | 25.192                          |
| TiposAlergias            | analiza_alergias()                | 0.000                           |
| TiposAlergias            | agregar_nombre()                  | 5.477                           |
| TiposAlergias            | agregar_valor()                   | 0.000                           |
| TiposAlergias            | get_lista_alergias()              | 0.000                           |
| TiposAlergias            | get_nombre_no_alergias()          | 0.000                           |
| TiposAlergias            | get_valor_no_alergias()           | 0.000                           |
| EvaluacionGeneral        | datos_alergias(lista)             | 0.002                           |
| EvaluacionGeneral        | calcular_promedio()               | 0.000                           |

Los métodos que más consumen recursos y tiempo con diferencia son los sigueintes:


| Clase                    | Método                   | Tiempo de Ejecución (segundos)  |
|--------------------------|--------------------------|---------------------------------|
| Alergia                  | agregar_alergia()        | 6.168                           |
| EvaluacionEspecifica     | evaluar_alergias()       | 3.913                           |
| TiposAlergias            | agregar_nombre()         | 5.477                           |
| TiposAlergias            | agregar_alergia()        | 25.192                          |

Siendo que la diferencia entre consumo entre los métodos de la tabla anterior y los demás es sustancial, se procede a analizar el motivo del consumo de tiempo de estos métodos y verificar si se podría optimizar más.

#### clase Alergia:
- `agregar_alergia()` es el método encargado de incorporar una nueva alergia a la lista existente al inicio del programa. Durante las pruebas, la lista contenía 50 elementos, lo que implica que para agregar una alergia se verificaba primero si el nombre no existía previamente. Luego, se multiplicaba por dos el valor asociado al último elemento en ese instante para asignar un nuevo valor.

    Esto indica que no hay una forma sencilla de simplificar su implementación, ya que aunque permitir un valor arbitrario para la nueva alergia reduciría el tiempo, implicaría verificar que ese valor no coincida con ningún otro en la lista.

#### clase EvaluacionEspecifica:
- `evaluar_alergias()` es el método que determina si el único nombre o valor ingresado por el usuario puede asociarse con algún elemento de la lista de alergias. En el momento de la prueba, la lista contenía 50 elementos. Dado que la comparación implica evaluar con cada elemento de la lista, no existe un método eficiente para optimizar este proceso.

    Sin embargo, la detección de si un elemento en la lista necesita ser asociado está optimizada. Previo a esta evaluación, todos los elementos individuales de nombre o valor agregados se acompañan con un `None` para simplificar la detección.

#### clase TiposAlergias:
- `agregar_nombre()` es un método usado para ingresar un nombre a una lista, su duración se debe a la cantidad de excepciones que hay dentro de este método. Si el método contiene letras mayusculas, son pasadas a minusculas para que coincidan con el nombre del diccionario usado para las alergias, luego verifica que no tenga números en su nombre y que permita espacios; además de las clasicas excepciones para evitar que se ingrese otro tipo de dato. Esto significa que reducir su tiempo conlleva a quitar cualquier cosa que es necesaria.

- `agregar_alergia() ` es el método con más duración y también el más complejo, de el se desprenden otro métodos protegidos de la misma clase y su función es crear una lista de listas de los elementos alergias nombre/alergia, nombre o solo alergia. Su complejidad es basada a lo extensa que es, su necesidad de solicitar valores al usuario para decidir qué elemento añadir y las excepciones. No hay una forma viable de cambiar su uso que no sea restructurar los demás métodos y clases.

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

- **Local**: Es el scope más interno, y corresponde a las variables que se declaran dentro de una función o un bloque de código. Estas variables solo se pueden usar dentro de ese contexto, y no son visibles desde fuera. Por ejemplo:

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

Un decorador es una función que toma como argumento otra función y devuelve una nueva función que modifica el comportamiento de la función original, esto significa que la función ahora esta decorada. 

La función principal de un decorador es añadir funcionalidades extra a una función sin tener que cambiar su código fuente. Por ejemplo, un decorador puede añadir un mensaje de registro, una validación de datos o un manejo de excepciones a una función existente.

Un ejemplo de un decorador, visto en clase, es el siguiente:

```python
# Definimos un decorador llamado registrar
def make_pretty(func):
    # Se define la función interna
    def inner():
        # Se agrega un print para decir que fue decorada
        print("I got decorated")
        # Llama a la función ordinaria de make_pretty(func)
        func()
    return inner


# Se define la función ordinaria que será llamada
def ordinary():
    print("I am ordinary")


# Se decora a la función ordinaria llamandola dentro de otra función
decorated_func = make_pretty(ordinary)

# Hace la llamada a la función decorada "inner()"
decorated_func()    

# Output: I got decorated
#         I am ordinary
```

### 5. ¿Cómo se gestionan las excepciones en Python? Proporcione ejemplos de uso de bloques try, except y finally.

Las excepciones en Python son errores que ocurren durante la ejecución del programa y que interrumpen el flujo normal del mismo. Para evitar que el programa se cierre abruptamente se debe manejar las excepciones usando los bloques try, except y finally [3].

El bloque try contiene el código que puede generar una excepción. El bloque except contiene el código que se ejecuta cuando se produce una excepción. El bloque finally contiene el código que se ejecuta siempre, independientemente de si hay o no una excepción [3].

Un ejemplo de uso de los bloques try, except y finally:

```python
try:
    # código que puede causar una excepción
    num = int(input("Ingrese un número: "))
    print("El número ingresado es:", num)
except ValueError:
    # código que se ejecuta cuando se produce una excepción ValueError
    print("Error: debe ingresar un número válido")
finally:
    # código que se ejecuta siempre
    print("Fin del programa")
```

Se pide al usuario que ingrese un número, y si el usuario ingresa un valor que no se puede convertir a un número entero, se genera una excepción ValueError. El bloque except captura esta excepción y muestra un mensaje de error. El bloque finally se ejecuta siempre y muestra un mensaje de fin del programa.


### 6. ¿Qué son los generadores en Python y para qué se utilizan?

Los generadores en Python son funciones que producen una secuencia de valores, uno a la vez, cuando se iteran sobre ella pero sin almacenar todos ellos en la memoria a la vez.

Estos utilizan la palabra clave yield en lugar de la palabra clave return. La palabra clave yield produce un valor del generador y pausa la ejecución de la función hasta que se solicita el siguiente valor.

Los generadores se pueden crear de dos formas: mediante una función generadora o mediante una expresión generadora [4]. 

Una función generadora tiene la siguiente sintaxis:

```python
def nombre_generador(arg):
    # instrucciones
    yield algo
```

Una expresión generadora tiene la siguiente sintaxis:

```python
(expresión for item in iterable)
```

Un ejemplo de una función generadora que produce los números pares del 0 al 10:

```python
def pares(n):
    for i in range(n):
        if i % 2 == 0:
            yield i

# iterar sobre el objeto generador
for i in pares(11):
    print(i)
```

### 7. Explique la diferencia entre `__init__` y `__call__` en clases de Python.

La diferencia entre `__init__` y `__call__` en clases de Python es la siguiente [5]:

- `__init__` es un método especial que se usa para inicializar los atributos de un objeto cuando se crea, mientras que `__call__` es un método especial que permite que un objeto se llame como una función.

- `__init__` se llama automáticamente cuando se crea un objeto, mientras que `__call__` se llama cuando se invoca el objeto como una función.

- `__init__` recibe como argumentos los valores que se asignan a los atributos del objeto, mientras que `__call__` recibe como argumentos los valores que se pasan al objeto como función.

- `__init__` no devuelve ningún valor, mientras que `__call__` puede devolver un valor o no, dependiendo de la lógica del método.

Un ejemplo de una clase de Python que define ambos métodos:

```python
class Saludo:
    def __init__(self, nombre):
        # inicializar el atributo nombre
        self.nombre = nombre
    
    def __call__(self, mensaje):
        # devolver un saludo personalizado
        return f"Hola, {self.nombre}. {mensaje}"

# crear un objeto de la clase Saludo
s = Saludo("Juan")

# llamar al objeto como una función
print(s("¿Cómo estás?"))        # Output: Hola, Juan. ¿Cómo estás?
```

### 8. ¿Cómo se organizan los módulos y paquetes en Python? ¿Qué es `__init__.py`?

Los módulos y paquetes son formas de organizar el código en unidades lógicas y reutilizables. Un módulo es un archivo que contiene definiciones y declaraciones de Python, como funciones, clases, variables, etc. Un paquete es un directorio que contiene uno o más módulos, y un archivo especial llamado `__init__.py` que indica que el directorio es un paquete.

El archivo `__init__.py` se usa para inicializar el paquete cuando se importa, y puede contener código que se ejecuta al importar el paquete, o definiciones que se exponen al nivel del paquete. También se puede usar para controlar cómo se importan los módulos del paquete, usando la variable `__all__` o los imports relativos.

### 9. Explique la diferencia entre los métodos `append()` y `extend()` en listas de Python.

Los métodos `append()` y `extend()` se usan en listas para agregar elementos al final de la lista, pero tienen algunas diferencias [6]:

- `append()` agrega un solo elemento como un objeto al final de la lista, sin importar el tipo o la estructura del elemento. Por ejemplo, si se agrega una lista con `append()`, se crea una lista anidada.

- `extend()` agrega cada elemento de un iterable al final de la lista, extendiendo la lista. El iterable puede ser otra lista, una tupla, una cadena, etc. Por ejemplo, si se agrega una lista con `extend()`, se concatenan las dos listas.

### 10. ¿Cuál es la diferencia entre un método de clase y un método estático en Python?

Un método de clase y un método estático en Python son dos tipos de métodos que se pueden definir dentro de una clase, pero que tienen algunas diferencias [7]:

- Un método de clase es un método que recibe la clase como primer argumento implícito, en lugar de la instancia. Se usa para realizar operaciones relacionadas con la clase, como crear objetos de la clase o modificar el estado de la clase. Se define con el decorador `@classmethod`.

- Un método estático es un método que no recibe ningún argumento implícito, ni la instancia ni la clase. Se usa para realizar operaciones independientes de la clase, como funciones de utilidad o de ayuda. Se define con el decorador `@staticmethod`.

```python
class Persona:
    # atributo de clase
    contador = 0

    def __init__(self, nombre):
        # atributo de instancia
        self.nombre = nombre
        # incrementar el contador de la clase
        Persona.contador += 1
    
    # método de clase
    @classmethod
    def crear_persona(cls, nombre):
        # crear un objeto de la clase usando el argumento cls
        return cls(nombre)
    
    # método estático
    @staticmethod
    def saludar(nombre):
        # devolver un saludo usando el argumento nombre
        return f"Hola, {nombre}"

# crear un objeto de la clase Persona usando el método de clase
p1 = Persona.crear_persona("Ana")
print(p1.nombre)            # Output: Ana
print(Persona.contador)     # Output: 1

# crear otro objeto de la clase Persona usando el constructor
p2 = Persona("Luis")
print(p2.nombre)            # Output: Luis
print(Persona.contador)     # Output: 2

# llamar al método estático de la clase Persona
saludo = Persona.saludar("Pedro")
print(saludo)               # Output: Hola, Pedro
```

### 11. Hable sobre las diferencias entre herencia simple y herencia múltiple en Python.

La herencia es una característica de la programación orientada a objetos que permite definir una nueva clase a partir de una clase existente. La nueva clase se llama clase derivada o hija, y la clase existente se llama clase base o padre. La clase derivada hereda los atributos y métodos de la clase base, y puede agregar o modificar algunos de ellos.

La herencia simple se da cuando una clase derivada solo hereda de una clase base. Por ejemplo:

```python
# Herencia simple
class Poligono:
    def __init__(self, n):
        self.n = n # número de lados
        self.lados = [0] * n # longitud de cada lado
    
    def input_lados(self):
        for i in range(self.n):
            self.lados[i] = float(input(f"Ingrese el lado {i+1}: "))
    
    def mostrar_lados(self):
        for i in range(self.n):
            print(f"Lado {i+1} tiene longitud {self.lados[i]}")

class Triangulo(Poligono): # clase derivada de Poligono
    def __init__(self):
        Poligono.__init__(self, 3) # llamamos al constructor de la clase base con n = 3
    
    def area(self):
        # usamos la fórmula de Herón para calcular el área
        a, b, c = self.lados
        s = (a + b + c) / 2 # semiperímetro
        area = (s * (s - a) * (s - b) * (s - c)) ** 0.5 # área
        print(f"El área del triángulo es {area}")
```

La herencia múltiple se da cuando una clase derivada hereda de más de una clase base. Por ejemplo:

```python
# Herencia múltiple
class Animal:
    def __init__(self, nombre):
        self.nombre = nombre # nombre del animal
    
    def comer(self):
        print(f"{self.nombre} está comiendo")

class Volador:
    def __init__(self, velocidad):
        self.velocidad = velocidad # velocidad de vuelo
    
    def volar(self):
        print(f"Volando a {self.velocidad} km/h")

class Aguila(Animal, Volador): # clase derivada de Animal y Volador
    def __init__(self, nombre, velocidad, altura):
        Animal.__init__(self, nombre) # llamamos al constructor de Animal
        Volador.__init__(self, velocidad) # llamamos al constructor de Volador
        self.altura = altura # altura de vuelo
    
    def planear(self):
        print(f"Planeando a {self.altura} metros de altura")
```

La herencia múltiple puede ser útil para combinar las funcionalidades de varias clases, pero también puede generar problemas de ambigüedad o inconsistencia si las clases base tienen atributos o métodos con el mismo nombre. Python resuelve estos problemas usando un algoritmo llamado **method resolution order (MRO)**, que determina el orden en que se buscan los atributos y métodos en la jerarquía de clases.

### 12. ¿Cómo se manejan los errores de importación de módulos en Python?

Los errores de importación de módulos pueden ocurrir por varias razones, como el nombre del módulo incorrecto, el espacio de nombres incorrecto o la ruta de acceso incorrecta. Para manejar estos errores se puede hacer lo siguiente:

- Verificar el nombre del módulo: asegurarse de que el nombre del módulo coincida exactamente con el nombre del archivo en el sistema de archivos. Python es sensible a mayúsculas y minúsculas, por lo que hay que tener cuidado con las diferencias entre mayúsculas y minúsculas.

- Usar el operador de punto: utilizar el operador de punto (.) para acceder a las funciones o clases dentro del módulo. Por ejemplo, si el módulo se llama `mi_modulo` y la función se llama `mi_funcion`, se debe escribir `mi_modulo.mi_funcion()` para llamar a la función.

- Corregir la ruta de acceso: asegurarse de que la ubicación del módulo sea correcta y de que Python pueda encontrarlo. Se puede utilizar la función `sys.path` para verificar las rutas de acceso que Python está buscando. Si el módulo no está en ninguna de esas rutas, se puede agregar la ruta del módulo al `sys.path` o utilizar el módulo `os` para cambiar el directorio de trabajo.

### 13. ¿Cuál es la diferencia entre una clase y un objeto en Python?

Una clase es modelo que define los atributos y los métodos comunes a un tipo de objeto. Un objeto es una instancia o una copia concreta de una clase, que tiene valores específicos para los atributos y puede usar los métodos definidos en la clase [8]. 

Por ejemplo, si tenemos una clase `Persona` que tiene los atributos `nombre` y `edad`, y el método `saludar`, podemos crear un objeto `p` que sea una instancia de `Persona`, y asignarle valores a sus atributos, como `p.nombre = "Ana"` y `p.edad = 25`. También podemos invocar el método `saludar` del objeto, como `p.saludar()`, que podría imprimir algo como "Hola, soy Ana y tengo 25 años".

### 14. Hable sobre la diferencia entre una clase abstracta y una interfaz en Python.

- Una clase abstracta es una clase que tiene al menos un método abstracto, es decir, un método que se declara pero no se implementa. Una clase abstracta no se puede instanciar, solo se puede heredar. Una clase abstracta puede tener métodos concretos, es decir, métodos que sí tienen una implementación. Una clase abstracta puede heredar de otra clase abstracta o concreta, pero solo puede tener una clase padre [9].

- Una interfaz es una clase que solo tiene métodos abstractos, es decir, ningún método tiene una implementación. Una interfaz no se puede instanciar ni heredar, solo se puede implementar. Una interfaz no puede tener atributos ni métodos concretos. Una interfaz puede extender de otras interfaces, y puede tener varias interfaces padres [9].

Python no tiene una palabra clave para definir interfaces, pero se pueden simular usando clases abstractas y el módulo `abc`. El módulo `abc` proporciona una metaclase llamada `ABCMeta`, que permite crear clases abstractas y verificar si una clase implementa los métodos abstractos de una interfaz [9].

Un ejemplo de código de definir e implementar una interfaz en Python:

```python
# Importamos el módulo abc
from abc import ABC, abstractmethod

# Definimos una interfaz llamada Figura, que tiene dos métodos abstractos: area y perimetro
class Figura(ABC):
    @abstractmethod
    def area(self):
        pass
    
    @abstractmethod
    def perimetro(self):
        pass

# Definimos una clase llamada Circulo, que implementa la interfaz Figura
class Circulo(Figura):
    # Definimos el método constructor, que recibe el radio del círculo
    def __init__(self, radio):
        self.radio = radio
    
    # Definimos el método area, que calcula el área del círculo usando la fórmula $\pi r^2$
    def area(self):
        return 3.14 * self.radio ** 2
    
    # Definimos el método perimetro, que calcula el perímetro del círculo usando la fórmula $2 \pi r$
    def perimetro(self):
        return 2 * 3.14 * self.radio

# Creamos un objeto c que es una instancia de la clase Circulo
c = Circulo(5)          # Pasamos el valor del radio como argumento

# Invocamos los métodos area y perimetro del objeto c
print(c.area())         # Output: 78.5
print(c.perimetro())    # Output: 31.400000000000002
```

### 15. Explique el concepto de sobreescritura de métodos en Python y cómo se realiza.

La sobreescritura de métodos es una característica de la programación orientada a objetos que permite a una clase hija modificar el comportamiento de un método heredado de una clase madre. Se realiza definiendo un método en la clase hija con el mismo nombre, número y tipo de argumentos que el método de la clase madre. De esta forma, el método de la clase hija reemplaza al método de la clase madre cuando se invoca desde un objeto de la clase hija [10].

Por ejemplo, si se tiene una clase `Animal` que tiene un método `sonar` que imprime "El animal hace un sonido", sobreescribiendo este método en una clase `Perro` que hereda de `Animal` y hacer que imprima "El perro ladra".

```python
# Definimos la clase madre Animal
class Animal:
    # Definimos el método sonar, que imprime un mensaje genérico
    def sonar(self):
        print("El animal hace un sonido")

# Definimos la clase hija Perro, que hereda de Animal
class Perro(Animal):
    # Definimos el método sonar, que imprime un mensaje específico
    def sonar(self):
        print("El perro ladra")

# Creamos un objeto a que es una instancia de la clase Animal
a = Animal()

# Invocamos el método sonar del objeto a
a.sonar() # Imprime El animal hace un sonido

# Creamos un objeto p que es una instancia de la clase Perro
p = Perro()

# Invocamos el método sonar del objeto p
p.sonar() # Imprime El perro ladra
```

## Bibliografía:

[1] L. M. Báez, “(Overloading) — Sobrecargar Operadores en Python,” Medium, 5 de agosto de 2019. [En línea]. Disponible: https://medium.com/@LuisMBaezCo/overloading-sobrecargar-operadores-en-python-5d7a75e2bfdf. [Accedido: 27- Ene- 2024].

[2] G. Canepa, “Alcance de las variables en Python,” El Camino del Sysadmin, 17 de junio de 2017. [En línea]. Disponible: https://blog.carreralinux.com.ar/2017/06/alcance-de-las-variables-en-python/. [Accedido: 27- Ene- 2024].

[3] E. Cassingena Navone, “How to Handle Exceptions in Python: A Detailed Visual Introduction,” freeCodeCamp.org, 22-Dec-2019. [En línea]. Disponible: https://www.freecodecamp.org/news/exception-handling-python/. [Accedido: 28-Ene-2024].

[4] “Python Generators (With Examples) - Programiz,” Programiz, [En línea]. Disponible: https://www.programiz.com/python-programming/generator. [Accedido: 28-Ene-2024].

[5] “Diferencia entre init y call,” GeeksforGeeks, [En línea]. Disponible: https://www.geeksforgeeks.org/what-is-the-difference-between-init-and-call/. [Accedido: 28-Ene-2024].

[6] “Difference between Append, Extend and Insert in Python,” GeeksforGeeks, [En línea]. Disponible: https://www.geeksforgeeks.org/difference-between-append-extend-and-insert-in-python/. [Accedido: 28-Ene-2024].

[7] “Diferencia entre el método de clase y el método estático en Python,” GeeksforGeeks, [En línea]. Disponible: https://www.geeksforgeeks.org/class-method-vs-static-method-python/. [Accedido: 28-Ene-2024].

[8] “Classes and Objects - Learn Python - Free Interactive Python Tutorial,” LearnPython.org, [En línea]. Disponible: https://www.learnpython.org/es/Classes%20and%20Objects. [Accedido: 28-Ene-2024].

[9] “Interfaces y Abstract Base Class - El Libro De Python,” El Libro De Python, [En línea]. Disponible: https://ellibrodepython.com/abstract-base-class. [Accedido: 28-Ene-2024].

[10] L. M. Báez, “(Overloading) — Sobrecargar Operadores en Python,” Medium, 05-Ago-2019. [En línea]. Disponible: https://medium.com/@LuisMBaezCo/overloading-sobrecargar-operadores-en-python-5d7a75e2bfdf. [Accedido: 28-Ene-2024].