"""
    Tipo Int
"""
print("\nEntero: ")
num1 = 5
print(num1, 'es de tipo', type(num1))

"""
    Tipo Float
"""
print("\nFlotante: ")
num2 = 2.0
print(num2, 'es de tipo', type(num2))

"""
    Tipo Complex
"""
print("\nComplejo: ")
num3 = 1+2j
print(num3, 'es de tipo', type(num3))

"""
    Tipo String
"""
print("\nString: ")

name = 'Python'
print(name, 'es tipo', type(name))

message = "Python para principiantes"
print(message, 'es tipo', type(message))

"""
    Tipos List y Tuple (acceso más rapido)
""" 
print("\nLista: ")
languages = ["Swift", "Java", "Python"] # accede al elemento en el índice 0 
print(languages, 'es tipo', type(languages)) # Swift 
print(languages[0]) # Swift 

print("\nTupla: ")
product = ("Microsoft", "Xbox", 499.99) # accede al elemento en el índice 0 
print(product, 'es tipo', type(languages)) # Swift 
print(product[0]) # Microsoft


"""
    Tipo Set: valores no rapetidos
"""
print("\nSet: ")
# Crea un set llamado student_id 
student_id = {112, 114, 115, 116, 118}

# Mestra los elementos de student_id 
print(student_id)

# Muestra el tipo de student_id 
print(type(student_id)) 

"""
Tipo Dictionary
"""  
print("\nDiccionario: ")
# crea un diccionario llamado capital_city 
capital_city = {'Nepal': 'Kathmandu', 'Italia': 'Roma', 'Inglaterra': 'Londres'} 

# imprime los elementos del diccionario capital_city 
print(capital_city, 'es tipo', type(capital_city)) 
print(capital_city['Nepal']) 
# print(capital_city['Kathmandu']) da error
