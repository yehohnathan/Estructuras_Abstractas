"""
    Los iteradores son métodos que operan en colecciones como listas, tuplas,
    etc. Estos pueden recorrer el objeto y devolver elementos.

    Técnicamente, un objeto iterador de Python debe implementar dos métodos
    especiales, __iter__() y __next__(), denominados colectivamente protocolo
    iterador.
"""

# --- # Impresión de elementos de una lista usando ciclo for # --- #
print("Se usa el ciclo for:")
# define a list
my_list = [4, 7, 0]

# create an iterator from the list
iterator = iter(my_list)

# get the first element of the iterator
print(next(iterator))  # prints 4

# get the second element of the iterator
print(next(iterator))  # prints 7

# get the third element of the iterator
print(next(iterator))  # prints 0

# --- # Impresión de elementos de una lista usando iteradores # --- #
print("\nSe usan iteradores:")
# define a list
my_list = [4, 7, 0]

for element in my_list:
    print(element)

"""
    Iteradores mágicos:
    Construir un iterador desde cero es sencillo en Python. Solo se tiene que
    implementar los métodos __iter__() y __next__().

    __iter__() devuelve el propio objeto iterador. Si es necesario, se puede
    realizar alguna inicialización.

    __next__() debe devolver el siguiente elemento de la secuencia. Al llegar
    al final, y en llamadas posteriores, debe levantar StopIteration.
"""


class PowTwo:   # Se crea un iterador personalizado
    def __init__(self, max=0):
        self.max = max

    def __iter__(self):     # Inicialización del iter
        self.n = 0
        return self

    def __next__(self):     # Iterador para hasta llegar al máximo
        if self.n > self.max:
            raise StopIteration

        result = 2 ** self.n
        self.n += 1
        return result


# Se crea un objeto y con el inicilizador se coloca max = 3
numbers = PowTwo(3)

# Se crea un iterador del objeto
i = iter(numbers)

# Usando next se imprime el siguiente elemento
print(next(i))
print(next(i))
print(next(i))
print(next(i))
print(next(i))  # Esto generará un error StopIteration, n sería mayor que max

# También se puede utilizar un ciclo for para el iterador
for i in PowTwo(3):
    print(i)
