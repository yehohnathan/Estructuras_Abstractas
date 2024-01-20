> Lo que aparecé en el presente Markdown es matería extraida de la presentación del curso *Python 0*.

### Identificadores en Python

1. Los identificadores no pueden ser una palabra clave.

2. Los identificadores distinguen entre mayúsculas y minúsculas.

3. Puede tener una secuencia de letras y dígitos. Sin embargo, debe comenzar con una letra o _. La primera letra de un identificador no puede ser un dígito.

4. Es una convención comenzar un identificador con una letra en lugar de _.

5. No se permiten espacios en blanco.

6. No podemos usar símbolos especiales como !, @, #, $, etc.

Se debe asignar a los identificadores un nombre que tenga sentido. Si bien `c = 10` es un nombre válido, escribir count = 10 tendría más sentido, y sería más fácil averiguar qué representa cuando observa su código después de un largo intervalo.Se pueden separar varias palabras con un guión bajo, como `this_is_a_long_variable`.

### Tipos de datos:

| Data Types | Classes            | Description                       |
|------------|--------------------|-----------------------------------|
| Numeric    | int, float, complex| holds numeric values              |
| String     | str                | holds sequence of characters      |
| Sequence   | list, tuple, range | holds collection of items         |
| Mapping    | dict               | holds data in key-value pair form |
| Boolean    | bool               | holds either True or False        |
| Set        | set, frozenset     | hold collection of unique items   |


## Operadores en Python:

### Aritméticos:
| Operator | Operation      | Example       |
|----------|----------------|---------------|
| +        | Addition       | 5 + 2 = 7     |
| -        | Subtraction    | 4 - 2 = 2     |
| *        | Multiplication | 2 * 3 = 6     |
| /        | Division       | 4 / 2 = 2     |
| //       | Floor Division |10 //3 =3      |
| %        | Modulo         |5 %2=1         |
| **       | Power          |4 **2=16       |

### Asignación: 
| Operator | Name                     | Example          |
|----------|--------------------------|------------------|
| =        | Assignment Operator      | a = 7            |
| +=       | Addition Assignment      | a += 1 # a = a + 1 |
| -=       | Subtraction Assignment   | a -= 3 # a = a - 3 |
| *=       | Multiplication Assignment| a *= 4 # a = a * 4 |
| /=       | Division Assignment      | a /= 3 # a = a / 3 |
| %=       | Remainder Assignment     | a %= 10 #a =a %10|
| **=      | Exponent Assignment      |a **=10#a=a**10   |

### Comparación:
| Operator | Meaning                     | Example                |
|----------|-----------------------------|------------------------|
| ==       | Is Equal To                 | 3 == 5 gives us False  |
| !=       | Not Equal To                | 3 != 5 gives us True   |
| >        | Greater Than                | 3 > 5 gives us False   |
| <        | Less Than                   | 3 < 5 gives us True    |
| >=       | Greater Than or Equal To    | 3 >= 5 give us False   |
| <=       | Less Than or Equal To       | 3 <= 5 gives us True   |


### Lógicos:
| Operator | Meaning                   | Example                |
|----------|---------------------------|------------------------|
| and      | Logical AND               | a and b                |
| or       | Logical OR                | a or b                 |
| not      | Logical NOT               | not a                  |


### Bitwise:
| Operator | Meaning             | Example                |
|----------|---------------------|------------------------|
| &        | Bitwise AND         | x & y = 0 (0000 0000)  |
| \|       | Bitwise OR          | x \| y = 14 (0000 1110)|
| ~        | Bitwise NOT         | ~x = -11 (1111 0101)   |
| ^        | Bitwise XOR         | x ^ y = 14 (0000 1110) |
| >>       | Bitwise right shift | x >> 2 = 2 (0000 0010) |
| <<       | Bitwise left shift  | x << 2 =40 (0010 1000) |

### Identidad:
| Operador | Meaning                                             | Example       |
|----------|-----------------------------------------------------|---------------|
| is       | True if the operands are identical                   | x is True     |
| is not   | True if the operands are not identical               | x is not True |

### Membrecia:
| Operador | Meaning                                             | Example       |
|----------|-----------------------------------------------------|---------------|
| in       | True if value/variable is found in the sequence      | 5 in x        |
| not in   | True if value/variable is not found in the sequence  | 5 not in x    |
