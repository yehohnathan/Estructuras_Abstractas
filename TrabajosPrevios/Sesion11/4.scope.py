"""
    En este espacio se va a hablar sobre el alcace de las variables:
"""

#==================================================================================================#
print("Primer ejemplo: Variable local")
def invalid_greet():
    # variable local
    message = "Hello"
    print("Local", message)

invalid_greet()
# Intenta acceder a la variable message
# fuera de la función greet()
# print(message)
# NameError: name 'message' is not defined

#==================================================================================================#
print("\nSegundo ejemplo: Variable global")
message = "Hello"   # declara variable global
def greet():
    # declara variable local
    print("Local", message)
greet()

print("Global", message)

#==================================================================================================#
print("\nTercer ejemplo: nonlocal variable")

# Afuera de la función
def outer():
    # declara variable con el string local
    message = "local"
    
    # Función anidada
    def inner():

        # Se declara una nonlocal variable, y se le car encima al mensaje inicial "local"
        nonlocal message

        message = "nonlocal"
        print("inner:", message)
        
    inner() # 
    print("outer:", message)

outer()

#==================================================================================================#
print("\nCuarto ejemplo: no se modifica la variable global")
c = 1   # Variable global
def add():
    print(c)
     
add()   # Output = 1

#==================================================================================================#
print("\nQuinto ejemplo: se desea modificar variable global")
c = 1  # Variable global

def add(): 
    # Uso de la palabra clave global 
    global c

    # Incrementa c por 2 
    c = c + 2

    return c 
     
print(add()) 

#==================================================================================================#
print("\nSexto ejemplo: variable global y funciones anidadas")
def outer_function():
    num = 20

    def inner_function():
        global num

        num = 25
    
    print("Antes de llamar a inner_function():", num)   # num = 20
    inner_function()
    print("Despues de llamar a inner_function():", num) # num = 20 porque el num de outer_function no es global

outer_function()
print("Afuera de ambas funciones:", num)