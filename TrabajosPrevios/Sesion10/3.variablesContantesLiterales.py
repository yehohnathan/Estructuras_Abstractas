""" Los nombres de constantes y variables deben tener una combinación de letras en minúsculas (a-z) 
    o mayúsculas (A-Z) o dígitos (0 a 9) o un guión bajo (_)"""

"""  Se declaran variables """ 
print("Variables: ")
number = 10     # Se le asigna un número

site_name = "eie.ucr.ac.cr"     # Se le asigna un string
print(site_name)                # Se imprme el contenido de la variable

site_name = "google.com"        # Se le asigna un nuevo string a la misma variable
print(site_name)
#Asignación multiple de variables
a, b, c = 5, 3.2, "Helo"        # Se le asigna un valor en orden a cada variable

print(a)    #Imprime 5
print(b)    #Imprime 3.2
print(c)    #Imprime Hello

""" Se crean literales (valores fijos en un programa): """
print("\nLiterales: ")

result1 = True                          # Booleano
some_string = "Python es divertido"     # String
some_character = "S"                    # Caracter
value = None                            # None
print(value)    #Output: None

""" Se crean literales (valores fijos en un programa): """
print("\nContantes: ")
# Se importan constant arriba del file creado
import constantes

print(constantes.PI)      #Imprime 3.14
print(constantes.GRAVITY) #Imprime 9.8