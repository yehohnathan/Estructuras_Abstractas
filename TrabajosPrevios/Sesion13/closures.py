"""
    Es una función anidada que ayuda a acceder a las variables de la función
    externa incluso después de que la función externa esté cerrada.
"""
# Uso de clousures para funciones anidadas, y retorno de estas mismas #
print("Retorno de una fucnión anónima:")


def greet():
    # Variable definida afuera de la función interna
    name = "John"

    # Retrona una función anónima
    return lambda: "Hi " + name


# Llama a la función externa
mesagge = greet()

# Llama a la función interna
print(mesagge())

# Uso de clousures para evitar usar variables globales #


# Creación de la función closure calculate
def calculate():
    num = 1

    def inner_func():
        nonlocal num
        num += 2
        return num
    return inner_func


# Llamar a la función externa
odd = calculate()

# Llamar a la función interna
print(odd())
print(odd())
print(odd())

# Llamar a la función externa de nuevo
odd2 = calculate()
print(odd2())   # Ya no comparte la suma de odd()


# Creación de la función closure multiplicador
def make_multiplier_of(n):
    def multiplier(x):
        return x * n
    return multiplier


# Multiplicador de 3
times3 = make_multiplier_of(3)

# Multiplicador de 5
times5 = make_multiplier_of(5)

# Salida: 27
print(times3(9))    # Se invoca con el 3 registrado, se multiplica por 9

# Salida: 15
print(times5(3))    # Se invoca con el 5 registrado, se multiplica por 3

# Salida: 30
print(times5(times3(2)))    # Se multiplica 5 * 3 * 2
