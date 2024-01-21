""" Varios ejercicios enfocado en el tipo de datos """
#==================================================================================================#
print("\nPrimer ejemplo: uso del random")
 
import random 

# Imprime un número aleatorio dentro del rango de 10 a 20
print(random.randrange(10, 20))

# Se crea una lista de strings
list1 = ['d', 'b', 'c', 'e', 'a']

# Selecciona un elemento aleatorio de list1
print(random.choice(list1))

# Imprime el contenido de la lista
print(list1)

# Imprime un elemento aleatorio
print(random.random())

#==================================================================================================#
print("\nSegundo ejemplo: listas")
# Se crea una lista de tres elementos enteros
# index    0  1  2
numbers = [1, 2, 5]
print(numbers)

# Se crea una lista de tres elementos string
# index          0        1       2
#               -3       -2      -1
lenguajes = ["Python", "Swift", "C++"]

# Se accede al elemento de indice 0
print(lenguajes[0])

# Se accede al elemento de indice 2
print(lenguajes[2])

# Se accede al elemento de indice -1
print(lenguajes[-1])

# Se accede al elemento de indice -3
print(lenguajes[-3])

print("") # Separador de resultados

# List slicing in Python
my_list = ["p","r","o","g","r","a","m","a","c","i","o","n",]

# Elementos del indice 2 al 4
print(my_list[2:5])     # El indice final es exclusivo, por eso no se imprime

# Elementos del indice 5 hasta el final
print(my_list[5:])    

# Elementos del indice inicio hasta el final
print(my_list[:])       # También podría ser print(my_list) 

#==================================================================================================#
print("\nTercer ejemplo: uso de método append")

numbers = [21, 34, 54, 12]
print("Antes del Append:", numbers) # Se imprime la lista

# Usando el método append
numbers.append(32)          # Se agrega el número 32 a la lista

print("Despues del Append:",numbers)

#==================================================================================================#
print("\nCuarto ejemplo: modificación de la listas")

lenguajes = ["Python", "Swift", "C++"]

# Cambiando el tercer elemento a "C"
lenguajes[2] = "C"

print(lenguajes)    # ["Python", "Swift", "C"]

#==================================================================================================#
print("\nQuinto ejemplo: extensión de la una lista")

prime_numbers = [2, 3, 5]
print("Lista 1:", prime_numbers)

even_numbers = [4, 6, 8]
print("Lista 2:", even_numbers)


# Se ingresa la lista even_number a la lista prime_numbers
prime_numbers.extend(even_numbers)

print("Lista despues del extend:", prime_numbers)

#==================================================================================================#
print("\nSexto ejemplo: eliminación de los elementos de listas")

lenguajes = ["Python", "Swift", "C++", "C", "Java", "Rust", "R"]

# Eliminación del segundo item
del lenguajes[1]
print(lenguajes)    # Elimina swift

# Eliminación del ultimo item
del lenguajes[-1]
print(lenguajes)    # Elimina R

# Eliminación de los primeros 2 items
del lenguajes[0:2]
print(lenguajes)    # Elimina Python y C++

# Eliminación de elementos con el nombre:
lenguajes = ["Python", "Swift", "C++", "C", "Java", "Rust", "R"]
print("Recarga la lista y se elimina Python:")
lenguajes.remove("Python")
print(lenguajes)

#==================================================================================================#
print("\nSeptimo ejemplo: list comprehensions")
lenguajes = ["Python", "Swift", "C++"]

# Iterar atravez de la lista
for lenguage in lenguajes:
    print(lenguage)         # Imprime individualmente un elemento de la lista

# Se preguna si hay elementos dentro de la lista
print("C esta dentro de la lista?", "C" in lenguajes)
print("Python esta dentro de la lista?", "Python" in lenguajes)

# Devuelve el tamaño de la lista:
print("Total de elementos de la lista:", len(lenguajes))

# Se crea una lista que imprime los cuadrados perfectos del 1 al 5
print("\nSe crea una lista con los números cuadrados perfectos")

# El ciclo for sirve para que number agarre valores del 1 al 6 (limite exclusivo)
numbers = [number*number for number in range(1,6)]
print(numbers)

# Se crea una lista que imprime los cuadrados perfectos del 1 al 5
print("\nSe crea otra lista con los números cuadrados perfectos")

numbers = []
for x in range(6,10):
    numbers.append(x*x) # Se incrementa 1 en x empezando por 6, se multiplica y se guarda con append en numbers
print(numbers)

#==================================================================================================#
print("\nOctavo ejemplo: uso de tuplas")

# Se crea una tupla vacia
my_tuple = ()
print("La tupla contiene", my_tuple)

# Se crea una tupla con numeros enteros
my_tuple = (1, 2, 3)
print("La tupla contiene", my_tuple)

# Se crea una tupla con elementos mixtosa
my_tuple = (1, "Hello", 3.4)
print("La tupla contiene", my_tuple)

# Se crea una tupla anidada o matriz tupla
my_tuple = ("mouse", [8, 4, 6], (1, 2, 3))
print("La tupla contiene", my_tuple)

#==================================================================================================#
print("\nNoveno ejemplo: manejo de strings (tuplas)")

# Creo dos variables que contenga un string
name = "Python"
message = "I love Python"

# Imprimo el contenido de las variables
print(name) 
print(message)

# Creo una nueva variable con un string y se "manipula"
greet = "hello"

print(greet[1])     # Se accede al index 1 del string "e"
print(greet[-1])    # Se accede al index -1 del string "o"
print(greet[1:4])   # Se accede al index 1 al 3 del string "e"

# Se intenta modificar el contenido de un string
message = "Hola amigos"     # Se sobreescribe el valor de la variable message
#message[0] = "H"
#print(message)
#   > TypeError: 'str' object does not support item assignment

# Se crea una variable con un multiples string
message = """
    Never gonna give you up
    Never gonna let you down
    Rick Roll
"""

print(message)

# Se crean 3 variables con string y se comparan entre ellas
str1 = "Hola, mundo!"
str2 = "I love Python."
str3 = "Hola, mundo!"

# Compara str1 frente a str2
print("str1 es igual a str2?", str1 == str2)
# Compara str1 frente a str2
print("str1 es igual a str3?", str1 == str3)

# Se hacen comparaciones sin tener variables
print("a esta dentro de program?", "a" in "program")
print("at no esta dentro de battle?", "at" not in "battle")

# Suma de dos variables que contienen strings
greet = "Hello, "
name = "Jack"
result = greet + name
print("\nResultado de sumar dos strings",result)

# Se imprime letra por letra de un string
greet = "Hello"

for letter in greet:    # Itera la variable greet
    print(letter)   

print(len(greet))       # Tamaño de la letra, es 5 porque se cuenta el null

#==================================================================================================#
print("\nDecimo ejemplo: secuencias de escape")

# Escape con double comillas
example = "He said, \"What's there?\""
print(example)

# Escape con comillas simples
example = 'He said, "What\'s there?"'
print(example)

# Uso del print con format
name = "Cathy"
country = "UK"
print(f"{name} if from {country}")  #Se debe utilizar f al inicio

#==================================================================================================#
print("\nUndécimo ejemplo: elementos set")

# Se crea un set con al menos un número repetido:
numbers = {2, 4, 6, 6, 2, 8}
print(numbers)  # Output = {8, 2, 4, 6} -> elimina números repetidos

# se cambie el contenido del set de numbers:
numbers = {21, 34, 54, 12}
print("\nInitial set:", numbers)

# Se agrega un número al set con el método add
numbers.add(32)
print("Updated set:", numbers, "\n")

# Adición de una lista a un set
companies = {"Lacoste", "Ralph Lauren"}         # Se crea en set
tech_companies = ["apple", "google", "apple"]   # Se crea una lista

companies.update(tech_companies)    # Se actualiza el set con los valores presentes en la lista

print(companies)    # Imprime lo que había en el set y la lista, pero sin repetir items

# Se vuelve a crear otro set con strings pero se prueva con eliminar elementos con discard
lenguajes = {"Swift", "Java", "Python"}

print("\nInitial set:", lenguajes)

removedValue = lenguajes.discard("Java") # Elimina un item y se guarda en una variable

print('Set after remove():', lenguajes)

# Se crea un set de valores enteros
student_id = {112, 114, 116, 118, 115}
print("\nStuden ID", student_id)

# Se crea un set tipo string
vowel_letters = {'a', 'e', 'i', 'o', 'u'}
print('Vowel Letter:', vowel_letters)

# Se crea un set de tipos de datos mixtos
mixed_set = {"Hello", 101, -2, "Bye"}
print("Set of mixed data types:", mixed_set)

# Creación de un set vacio 
empty = set()

# Creación de un diccionario vacio, lo cual podría indicar que es un set pero no
empty_dictionary = { }

# Se observa cual es el tipo de dato de empty y empty_dictionary
print("\nData type of empty:", type(empty))
print("Data type of empty_dictionary:", type(empty_dictionary), "\n")

# Se crea un set y se imprimen sus elementos por aparte con un ciclo for
fruits = {"Apple", "Peach", "Mango"}

for fruit in fruits:
    print(fruit)

# Se crea un set y luego se pregunta por el tamaño del mismo con el método len
even_numbers = {2, 4, 6, 8}
print("\nSet:", even_numbers)
print("Totoal de elementos:", len(even_numbers))

#==================================================================================================#
print("\nDuodécimo ejemplo: uso de diccionarios")

# Se crea un diccionario con nombre de ciudades famosas
capital_city = {"Nepal": "Kathmandu", "Italy": "Rome", "England": "London"}
print(capital_city)

# Se crea un diccionario con enteros y strings
numbers = {1: "One", 2: "Two", 3: "Three"}
print(numbers)

# Se actualiza el diccionario capital_city con un nuevo elemento
capital_city["Japan"] = "Tokyo"
print("Updated Dictionary:", capital_city)

# Se crea otro set de datos mixtos y se le agrega un nuevo elemento
student_id = {111: "Eric", 112: "Kyle", 113: "Butters"}
print("\nInitial Dictionary:", student_id)

student_id[112] = "Stan"    # Se sobreescribe y se borra Kyle
print("Updated Dictionary:", student_id)

# Se imprimen valores indivuales del diccionario
print(student_id[111])  # Eric
print(student_id[113])  # Butters

# Ahora se desea borrar un elemento del diccionario
student_id = {111: "Eric", 112: "Kyle", 113: "Butters"}
print("\nInitial Dictionary:", student_id)

del student_id[111]     # Se elimina a eric

print("Updated Dictionary:", student_id)

# Se decide borrar todo el diccionario
del student_id

#print(student_id)  -> da error porque ya no existe y no esta definido

# Ahora se crea nuevo diccionario y se pregunta por los miembros de la misma
squares = {1: 1, 3: 9, 5: 25, 7: 49, 9: 81}

# Se hacen preguntas con condicionales
print("\n1 esta en squares?", 1 in squares)
print("2 no esta en squares?", 2 not in squares)
print("49 esta en squares?", 49 in squares)     # Es falso porque la membresia es para la llave y no para el valor

# Ahora se itera a partir de squares
print("\nSe imprime el valor asociado a cada key: ")
for i in squares:
    print(squares[i])

print("\nSe imprime el número de las Keys de squares: ")
for i in squares:
    print(i)