## Clases y objetos en Python: Métodos mágicos

| Inicialización y Construcción | Descripción |
|---|---|
| `__new__(cls, other)` | Se llama en la instanciación de un objeto. |
| `__init__(self, other)` | Se llama por el método `__new__`. |
| `__del__(self)` | Método destructor. |

| Métodos Mágicos de Cadena | Descripción |
|---|---|
| `__str__(self)` | Se llama por el método incorporado str() para devolver una representación de cadena de un tipo. |
| `__repr__(self)` | Se llama por el método incorporado repr() para devolver una representación legible por máquina de un tipo. |
| `__unicode__(self)` | Se llama por el método incorporado unicode() para devolver una cadena unicode de un tipo. |
| `__format__(self, formatstr)` | Se llama por el método incorporado string.format() para devolver un nuevo estilo de cadena. |
| `__hash__(self)` | Se llama por el método incorporado hash() para devolver un entero. |
| `__nonzero__(self)` | Se llama por el método incorporado bool() para devolver Verdadero o Falso. |
| `__dir__(self)` | Se llama por el método incorporado dir() para devolver una lista de atributos de una clase. |

| Métodos Mágicos de Atributo | Descripción |
|---|---|
| `__getattr__(self, name)` | Se llama cuando se accede al atributo de una clase que no existe. |
| `__setattr__(self, name, value)` | Se llama cuando se asigna un valor al atributo de una clase. |
| `__delattr__(self, name)` | Se llama cuando se elimina un atributo de una clase. |

| Métodos Mágicos de Operador | Descripción |
|---|---|
| `__add__(self, other)` | Se llama en la operación de suma usando el operador +. |
| `__sub__(self, other)` | Se llama en la operación de resta usando el operador -. |
| `__mul__(self, other)` | Se llama en la operación de multiplicación usando el operador *. |
| `__floordiv__(self, other)` | Se llama en la operación de división de piso usando el operador //. |
| `__truediv__(self, other)` | Se llama en la operación de división usando el operador /. |
| `__mod__(self, other)` | Se llama en la operación de módulo usando el operador %. |
| `__pow__(self, other[, modulo])` | Se llama al calcular la potencia usando el operador **. |
| `__lt__(self, other)` | Se llama en la comparación usando el operador <. |
| `__le__(self, other)` | Se llama en la comparación usando el operador <=. |
| `__eq__(self, other)` | Se llama en la comparación usando el operador ==. |
| `__ne__(self, other)` | Se llama en la comparación usando el operador !=. |

| Métodos Mágicos de Conversión de Tipo | Descripción |
|---|---|
| `__int__(self)` | Se llama por el método incorporado int() para convertir un tipo a int. |
| `__float__(self)` | Se llama por el método incorporado float() para convertir un tipo a float. |
| `__complex__(self)` | Se llama por el método incorporado complex() para convertir un tipo a complex. |
| `__oct__(self)` | Se llama por el método incorporado oct() para convertir un tipo a octal. |
| `__hex__(self)` | Se llama por el método incorporado hex() para convertir un tipo a hexadecimal. |
| `__index__(self)` | Se llama en la conversión de tipo a int cuando el objeto se usa en una expresión de corte. |
| `__trunc__(self)` | Se llama desde el método math.trunc(). |


## Sobrecarga de operadores

| Operador | Expresión | Internamente |
|---|---|---|
| Adición | `p1 + p2` | `p1.__add__(p2)` |
| Sustracción | `p1 - p2` | `p1.__sub__(p2)` |
| Multiplicación | `p1 * p2` | `p1.__mul__(p2)` |
| Potencia | `p1 ** p2` | `p1.__pow__(p2)` |
| División | `p1 / p2` | `p1.__truediv__(p2)` |
| División de piso | `p1 // p2` | `p1.__floordiv__(p2)` |
| Resto (módulo) | `p1 % p2` | `p1.__mod__(p2)` |
| Desplazamiento a la izquierda | `p1 << p2` | `p1.__lshift__(p2)` |
| Desplazamiento a la derecha | `p1 >> p2` | `p1.__rshift__(p2)` |
| AND bit a bit | `p1 & p2` | `p1.__and__(p2)` |
| OR bit a bit | `p1 \| p2` | `p1.__or__(p2)` |
| XOR bit a bit | `p1 ^ p2` | `p1.__xor__(p2)` |
| NOT bit a bit | `~p1` | `p1.__invert__()` |

## Sobrecarga de operadores de comparación
| Operador | Expresión | Internamente |
|---|---|---|
| Menor que | p1 < p2 | p1.__lt__(p2) |
| Menor o igual que | p1 <= p2 | p1.__le__(p2) |
| Igual a | p1 == p2 | p1.__eq__(p2) |
| No igual a | p1 != p2 | p1.__ne__(p2) |
| Mayor que | p1 > p2 | p1.__gt__(p2) |
| Mayor o igual que | p1 >= p2 | p1.__ge__(p2) |
