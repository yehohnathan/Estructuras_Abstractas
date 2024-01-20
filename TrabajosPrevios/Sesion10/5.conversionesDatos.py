""""Existen dos tipos de conversiones:
    1. Implícita: conversión de tipo automática
    1. Explicita: conversión de tipo manual
"""

print("Conversión implícita: ")
integer_number = 123
float_number = 1.23

new_number = integer_number + float_number

# Miestra el resultado en pantalla
print("Value: ", new_number)
print("Data Type: ", type(new_number))


print("Conversión explicita: ")
num_string = '12'
num_integer = 23

print("Tipo de dato de num_string: ", type(num_string))

# Conversion explicita:

num_string = int(num_string)
print("Tipo de dato de num_string despues del Type Casting: ", type(num_string))

num_sum = num_integer + num_string
print("Sum: ", num_sum)
print("Data Type: ", type(num_sum))