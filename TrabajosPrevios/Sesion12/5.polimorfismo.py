""" 
    Significa más de una forma. Es decir, una misma entidad (método, operador u objeto) puede realizar
    diferentes operaciones en diferentes escenarios. Permite la misma interfaz para diferentes objetos,
    por lo que se puede escribir código eficiente.
"""

""" Polimorfismo con ejemplos simples: usando diferentes interpretaciones de forma interna """
print("Suma 'simple' de enteros:")
num1 = 1
num2 = 2
print(num1+num2)        # Aquí el interprete usa una interpretación para sumar

print("\nSuma 'simple' de strings:")
str1 = "Python"
str2 = "Programming"
print(str1+" "+str2)    # Aquí el interprete usa una interpretación para sumar pero strings

print("\nCalcula el tamaño de un string, lista y set:")
print(len("Programiz"))
print(len(["Python", "Java", "C"]))
print(len({"Name": "John", "Address": "Nepal"}))


""" Polimorfismo usando herencia de clases """
class Polygon:
    # Se crea un método que imprime un string
    def render(self):
        print("Rendering Polygon...")

# Clases derivadas de Polygon:
class Square(Polygon):
    # Se sobreescribe una método heradado de Polygon
    def render(self):
        print("Rendering Square...")

class Circle(Polygon):
    # Se sobreescribe una método heradado de Polygon
    def render(self):
        print("Rendering Circle...")

print("\nUso de las clases derivadas: Square y Circle")
# Se crea un objeto de Square
s1 = Square()
s1.render()     # Utilizo el método de Square

# Se crea un objeto de Circle
c1 = Circle()
c1.render()     # Utilizo el método de Circle


""" Polimorfismo usando sobreescritura de métodos """
from math import pi # Se importa de la librería math el valor de pi

class Shape:
    # Se inicializa la variable name
    def __init__(self, name):
        self.name = name

    # Se cerea un método "vacio"
    def area(self):
        pass

    # Se crea un método que retorna un string
    def fact(self):
        return "I am a two-dimensional shape."

    # Cada vez que se quiera imprimir un objeto imprime lo que haya en la variable name
    def __str__(self):
        return self.name

# Clase herada de Shape
class Square(Shape):

    # Se inicializa, primero con super se dice que name = Square y luego se inicializa una variable
    def __init__(self, length):
        super().__init__("Square")
        self.length = length

    # Sobreescribe el método area que priviene de Shape para adaptarlo a un cuadrado
    def area(self):
        return self.length**2

    # Se brinda una pequeña información del objeto al haber sido creado en esta clase
    def fact(self):
        return "Squares have each angle equal to 90 degrees."

# Se crea otra clase que derivada de Shpae
class Circle(Shape):
    # Se inicializa, primero con super se dice que name = Circle y luego se inicializa una variable radius
    def __init__(self, radius):
        super().__init__("Circle")
        self.radius = radius

    # Se adapta el método de area, sobreescribiendola, a un circulo
    def area(self):
        return pi*self.radius**2

print("\nUso de las clases derivadas: Square y Circle (usando sobreescritura de métodos)")

# Se crea un objeto para Square y Circle
a = Square(4)   # Se le asigna un tamaño para el largo
b = Circle(7)   # Se asigna un tamaño para el radio
print(b.fact()) # Imprime el método sobreescrito es Circle
print(a.fact()) # Imprime el método sobreescrito es Square
print(b.area()) # Retorna al area del objeto (circulo)
