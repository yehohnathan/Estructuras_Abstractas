"""
    Es un patrón de diseño que permite modificar la funcionalidad de una
    función envolviéndola en otra función. La función externa se llama
    decorador, que toma la función original como argumento y devuelve
    una versión modificada de la misma.
"""

# --- # Decoradores usando funciones anidadas # --- #
print("Funciones anidadas:")


def outer(x):
    def inner(y):
        return x + y
    return inner


add_five = outer(5)     # Define x = 5
result = add_five(6)    # Define y = 6
print(result)           # Imprime 11 (5 + 6)

# --- # Decoradores usando funciones como argumentos # --- #
print("\nFunciones como argumento:")


def add(x, y):
    return x + y


def calculate(func, x, y):
    return func(x, y)   # Solicita una función y dos parámetros


result = calculate(add, 4, 6)   # Se instancia la funcion calcular
print(result)                   # Lo mismo que hacer add(4,6)

# --- # Decoradores retornando funciones # --- #
print("\nRetornando funciones:")


def greeting(name):
    def hello():
        return "Hello," + name + "!"
    return hello


greet = greeting("Atlantis")    # Lo mismo que closure
print(greet())   # imprime "Hello Atlantis!"

"""
    Cualquier objeto que implemente el método especial __call__() se denomina
    invocable (callable). Entonces, un decorador es un invocable que devuelve
    un invocable. Básicamente, un decorador toma una función, agrega alguna
    funcionalidad y la devuelve.
"""
# --- # Decorando funciones # --- #
print("\nPrimera forma de decorar funciones:")


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


print("\nSegunda forma de decorar funciones:")


# Lo mismo que la función ya vista
def make_pretty(func):
    def inner():
        print("I got decorated")
        func()
    return inner


# El interprete entiende que la va a decorar make_pretty(ordinary)
@make_pretty
def ordinary():
    print("I am ordinary")


ordinary()

# --- # Decorando funciones que tienen parámetros # --- #
print("\nDecorando funciones que tienen parámetros")


def smart_divide(func):     # Función decoradora
    def inner(a, b):
        print("I am going to divide:", a, "and", b)
        if b == 0:
            print("Whoops! cannot divide")
            return
        return func(a, b)
    return inner


@smart_divide   # Basicamente realiza un smart_divide(divide, a, b)
def divide(a, b):
    return a/b


divide(2, 5)
divide(2, 0)

# --- # Encadenando decoradores # --- #
print("\nEncadenando decoradores")


def star(func):
    def inner(*args, **kwargs):
        print("*" * 15)
        func(*args, **kwargs)
        print("*" * 15)
    return inner


def percent(func):
    def inner(*args, **kwargs):
        print("%" * 15)
        func(*args, **kwargs)
        print("%" * 15)
    return inner


# Eso se interpreta como star(percent(printer(msg)))
@star
@percent
def printer(msg):
    print(msg)


printer("Holas! Esto es un mensaje")    # Imprime todo el conjunto
