"""
    En python en dos tipos de funciones:
        1. Funciones de biblioteca estandar
        2. Funciones creadas por el usuario:
            Para poder crearlas es necesario el uso del def

                def function_name(arguyments):
                    # Cuerpo de la función

                    return
"""
#==================================================================================================#
# Se crea una función llamada saludar, para que sumlememte salude
def greet(name = "Sin nombre"):
    print("Hola, especialmente a", name)

#==================================================================================================#
# Función para que sume dos valores
def sumar(valor1, valor2):
    print("La suma de", valor1, "con", valor2, "es:", valor1+valor2)

#==================================================================================================#
# Se crea una función parecida a sumar, vista en la diapositiva de clases
def add(num1, num2):
    sum = num1 + num2
    # print("Sum:", sum)
    return sum  # Retorna el valor de la suma, sino no lo declaro retorna None

#==================================================================================================#
# Se crea una función parecida a add, esta por defecto tienen valores para realizar una suma
def add_numbers(a = 7, b = 8):
    sum = a + b
    print("Sum:", sum)

#==================================================================================================#
# Se importa la librería math para usar sus funciones internas math.sqrt() y pow()
import math

#==================================================================================================#
# Se crea una función que usa strings
def display_info(primer_nombre, segundo_nombre):
    print("Primer nombre", primer_nombre)
    print("Segundo nombre", segundo_nombre)

#==================================================================================================#
# Se crea una función que admite múltiples nombres:
def find_sum(*numbers):
    result = 0

    for num in numbers:
        result += num

    print("Sum =", result)

#==================================================================================================#
# Función recursiva para calcular el factorial:
def factorial(x):
    """ Esto es una función recursiva para encontrar
    el valor factorial de un entero"""
    
    if x == 1:
        return 1
    else:
        return(x * factorial(x-1))

#==================================================================================================#
print("Función greet(): ")
greet("mi mamá")    # Utilizo la función saludar

#==================================================================================================#
print("\nFunción sumar(): ")
sumar(15,14)        # Me muestra el resultado de la suma

#==================================================================================================#
print("\nFunción add(): ")
print("Sum:",add(2,3))  # Me muestra el resultado de la suma de 2 + 3

#==================================================================================================#
print("\nFunción add_numbers(): ")
add_numbers(2,3)    # Se llama a la función con dos argumentos
add_numbers(a = 2)  # Se llama a la función con un unico elemento
add_numbers()       # No se ponen argumentos

#==================================================================================================#
print("\nUso de funciones de la librería math:")
raiz = math.sqrt(4) # Se saca la raiz cuadrada de 4
print("La raíz cuadrada de 4 es:", raiz)
power = math.pow(2,3)   # Se calcula el valor de 2^3
print("2 a la potencia de 3 es:", power)

#==================================================================================================#
print("\nFunción display_info():")
display_info(primer_nombre="Cartman", segundo_nombre="Eric")

#==================================================================================================#
print("\nFunción find_sum():")
find_sum(1,2,3,4,5)

#==================================================================================================#
print("\nFunción factorial():")
num = 5
print("El factorial de", num, "es", factorial(num))

#==================================================================================================#
# Uso de la función "lambda": es una forma de definir una función en medio código
# Se declara la función lamda
print("\nFunción lambda: ")
saludar = lambda : print("Hola mundo")

# Llamar la función lamda
saludar()   # Output: Hola mundo

# Se declara una función lambda que acepta un solo argumento
greet_user = lambda name : print("Hey there", name)

# Llamar al función lambda
greet_user("Delilah")   # Output: Hey there Delilah

# Programa para filtrar solo los elementos pares de una lista
my_list = [1, 5, 4, 6, 8, 11, 3, 12]
new_list = list(filter(lambda x: (x%2 == 0), my_list))  # Utiliza la función filter para ello
print(new_list)     # Output: [4, 6, 8, 12]

# Programa para multiplicar por dos cada elemento de una lista usando map()
my_list = [1, 5, 4, 6, 8, 11, 3 ,12]
new_list = list(map(lambda x: x * x *2 , my_list))
print(new_list)     # Output: [2 ,10 ,8 ,12 ,16 ,22 ,6 ,24]
