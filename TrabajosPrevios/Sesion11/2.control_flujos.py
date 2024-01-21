# Uso del control de flujos
#==================================================================================================#
print("Uso del if, else e elif:")

""" Ejemplo del video """
contador = 15   # Se cera una variable contador

if contador > 10:   # Y se realiza un control de flujos alrededor de contador
    print("Contador es mayor a 10")
    print("Hola desde el if")

    if contador < 18:
        print("Y además es menor que 18")

print("Esto esta afuera del if\n")

""" Ejemplo de la presentación """
number = 10

# Se pregunta si el número es mayor a 0
if number > 0:
    print("Number es positivo")
elif number == 0:
    print("Number es cero")
else:
    print("Number es negativo")

print("This stament is always exucuted\n")

#==================================================================================================#
""" Control de flujo: ciclo for"""
print("Uso del ciclo For:")

# Imprime cada elemento por separado de la palabra en python
for x in "Python":
    print(x)

print("")   # Para separar los resultados del ciclo for

# Imprime cada elemento por separado de la lista
for x in [1, 6, 9, 5]:
    print(x)

print("")   # Para separar los resultados del ciclo for

# Ciclo for con el uso de la variable tipo rango
values = range(4)

for i in values:    # itera desde i = 0 hasta i = 3
    print(i)

print("")   # Para separar los resultados del ciclo for

# Ciclo for con lista de string
lenguages = ["Swift", "Python", "Go"]

for _ in lenguages: # Como hay 3 elementos, se imprime los mismo 3 veces
    print("Hello")
    print("Hi")

print("")   # Para separar los resultados del ciclo for

# Ciclo for con un else
digits = (1, 2, 3, 4)
for i in digits:
    print(i)
else:
    print("No faltan items")    # Siempre se ejecuta cuando acaba el ciclo for

#==================================================================================================#
""" Control de flujos: uso del ciclo while"""
print("\nUso del ciclo While:")

# Programa muestra los números del 1 al 5
# Se inicializan las variables:
i = 1
n = 5

# ciclo while desde el i = 1 hasta 5
while i <= n:
    print(i)
    i += 1

print("")   # Para separar los resultados 

# Ciclo while que se ejecuta hasta que el usuario ingrese un cero
total = 0
number = int(input("Ingrese un número (0 si desea parar): "))

# Suma todos los número hasta que se ingrese un cero
while number != 0:
    total += number # Suma todos los números ingresados en total

    # Le solicita al usuario otro número
    number = int(input("Ingrese un número (0 si desea parar): "))

print("Total =", total, "\n")

# Ciclo while con la variable llamada contador
contador = 0

while contador < 3:
    print("Dentro del loop")
    contador += 1
else: 
    print("Dentro del else\n")

""" Lo siguiente es un programa con ciclo while que se encicla
age = 32

while age > 18:
    print("Puedes votar")   # Esto siempre se imprimiría en la pantalla
"""

""""""

#==================================================================================================#
""" Control de flujos: break y continue"""
print("Uso del break y continue")

# Ciclo for de i = 0 hasta i = 5
for i in range(5):
    if i == 3:  # Rompe el for cuando i = 3
        break
    print(i)

print("")   # Para separar los resultados 

# Ciclo for de i = 0 hasta i = 5
for i in range(5):
    if i == 3:
        continue    # Continua y salta el print (no imprime el 3)
    print(i)

print("")   # Para separar los resultados

# Ciclo para encontrar los primeros 5 múltiplos de 6
i = 1

while i <= 10:
    print('6 * ',i, '=',6 * i)
    if i >= 5:
        break
    i = i + 1 

print("")   # Para separar los resultados 

# Ciclo while para encontrar los números impares menores que 10
num = 0 

while num < 10: 
     num +=1 
     if (num %2) ==0: 
         continue 
     print(num)  

#==================================================================================================#
""" Control de flujos: pass"""
print("\nUso del pass")

# Uso simple del pass
n = 10

if n > 10:
    pass    # Este pass es para que el código no haga mada

print('Hello')

# También se puede usar para hacer funciones y clases despues
def function(args):
    pass
    
class Example:
    pass
