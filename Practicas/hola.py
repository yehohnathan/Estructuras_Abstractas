# Obtener los números y la operación del usuario
num1 = float(input("Ingresa el primer número: "))
num2 = float(input("Ingresa el segundo número: "))
operacion = input("Ingresa la operación (sum, rest, mult, div): ")

# Realizar la operación seleccionada
resultado = None

if operacion == "sum":
    resultado = num1 + num2
elif operacion == "rest":
    resultado = num1 - num2
elif operacion == "mult":
    resultado = num1 * num2
elif operacion == "div":

    if num2 != 0:  # Verificar que el divisor no sea cero
        resultado = num1 / num2
    else:
        print("Error: No se puede dividir por cero.")
else:
    print("Error: Operación no válida.")

# Imprimir el resultado si está definido
if resultado is not None:
    print(f"El resultado de {num1} {operacion} {num2} es: {resultado}")