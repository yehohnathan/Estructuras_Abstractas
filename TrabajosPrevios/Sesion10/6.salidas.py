"""
object: Valor(es) a imprimir
sep (opcional): Permite separar varios objetos dentro de print().
end (opcional): Permite agregar agregar valores específicos como nueva línea "\n", tab "\t".
file (opcional): Donde se imprimen los valores. Su valor predeterminado es sys.stdout (pantalla).
flush (opcional): Booleano que especifica si la salida se vacía o se almacena en búfer. Valor predeterminado: False.
"""

number = -10.6  # Variable tipo float
name = "IE0217" # Variable tipo string

# Imprimir literales
print(5)

# Imprimir variables
print(number)
print(name)

# Join string
print('Este curso es ' + name)

# Imprimir usando el sep = .
print("Nuevo año", 2023, "Nos vamos pronto!", sep= ". ")

# Imprimir con espacios en blanco de por medio
print("Buenos días!", end= " ")

print("Esta lloviendo hoy")

# Imprimiendo utilizando el format
x = 5
z = 10
print("El valor de X es {} y Z es {}".format(x,z))