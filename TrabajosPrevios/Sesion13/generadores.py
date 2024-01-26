"""
    Es una función que devuelve un iterador que produce una secuencia de
    valores cuando se repite. No los almacena en memoria.

    Se define una función generadora usando la palabra clave def, pero en
    lugar de la declaración de retorno , está la declaración de yield.

    def genearator_name(arg):
        # statements
        yield someting
"""

# --- # Función generadora # --- #
print("Función generadora")


def my_generator(n):
    # Valor inicial de contador
    value = 0

    while value < n:
        # Produce el valor concurrente del contador
        yield value
        # Incrementa contador
        value += 1


# Itera sobre el generador producido por my_generator
for value in my_generator(3):
    # Imprime cada value producido por el generador
    print(value)

"""
Expresiones generadoras:
    Una expresión generadora es una forma concisa de crear un objeto
    generador. Es similar a la list comprehension, pero en lugar de crear
    una lista, crea un objeto generador que se puede iterar para producir los
    valores en el generador.
"""
print("\nExpresiones generadoras:")

# Crea un objeto generador
squares_generator = (i*i for i in range(5))

# Se itera sobre el iterador para observar sus valores
for i in squares_generator:
    print(i)


# Implementando lo anterior con generadores
def square(nums):
    for num in nums:
        yield num**2


# Implementando un generador de numeros de Fibonacci
def fibonacci_numbers(nums):
    x, y = 0, 1
    for _ in range(nums):
        x, y = y, x+y
        yield x


# Estas pueden hacer pipeline
print("La suma de los cuadradon perfectos usando serie de Fibonacci es:")
print(sum(square(fibonacci_numbers(10))))
