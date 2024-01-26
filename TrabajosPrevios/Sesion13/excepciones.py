"""
    Excepciones: es algo que sucedio en nuestro programa y no queríamos.
"""
# --- # Bloque de excepción cuando se realiza una división entre 0 # ---- #
print("Primer bloque de excepción: divisiones")
try:
    numerator = 10
    denominator = 0
    result = numerator/denominator
    print(result)
except ZeroDivisionError:   # Siendo este el unico error permisible
    print("Error: El denominador no puede ser 0")
finally:    # Se ejecuta despues del bloque de excepcion
    print("Se ha finalizado el bloque 1")

# --- # Bloque de excepción se sale del indice de la lista # ---- #
print("\nSegundo bloque de excepción: lista de numeros")
try:
    even_numbers = [2, 4, 6, 8]
    print(even_numbers[5])
except ZeroDivisionError:
    print("Denominator cannot be 0.")
except IndexError:
    print("Index Out of Bound.")

# --- # Bloque de excepción para encontrar el recíproco # ---- #
print("\nTercer bloque de excepción: encontrar reciproco")
try:
    num = int(input("Enter a number: "))
    assert num % 2 == 0     # Esto debe ser verdadero
except AssertionError:
    print("Not an even number!")    # Cuando assert es false
else:
    try:
        reciprocal = 1/num      # Se imprime el reciprocó
        print(reciprocal)
    except ZeroDivisionError:   # Num = 0, lanzó otra excepción
        print("El número no puede ser cero!")

# --- # Bloque de excepción con excepción personalizada # ---- #
print("\nCuarto bloque de excepción: creación de excepcion")


# Se define una excepción sucede cuando numero es < 18
class InvalidAgeException(Exception):
    "Raised when the input value is less than 18"
    pass


# Edad minima permitida
number = 18

try:
    input_num = int(input("Enter a number: "))
    if input_num < number:
        raise InvalidAgeException   # Se levanta la excepción si no cumple
    else:
        print("Eligible to Vote")

except InvalidAgeException:
    print("Exception occurred: Invalid Age")

# --- # Otro bloque de excepción con excepción personalizada # ---- #
print("\nQuinto bloque de excepción: otra creación de excepcion")


class SalaryNotInRangeError(Exception):
    """Exception se levanta cuando hay errores al ingresar el salario.

    Attributes:
        salary -- input salary which caused the error
        message -- explanation of the error
    """
    # Contructor
    def __init__(self, salary, message="Salary is not in (5000, 15000) range"):
        self.salary = salary
        self.message = message
        super().__init__(self.message)  # Metodo de la clase excepción


try:
    salary = int(input("Enter salary amount: "))
    if not 5000 < salary < 15000:
        raise SalaryNotInRangeError(salary)
except SalaryNotInRangeError:
    print("Exception occurred: Salario inválido")
