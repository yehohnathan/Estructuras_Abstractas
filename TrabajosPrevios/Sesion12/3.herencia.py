""" La nueva clase que se crea se conoce como subclase (clase secundaria o derivada) y 
    la clase existente de la que se deriva la clase secundaria se conoce como superclase    
    (clase principal o base).
"""

""" Ejemplo de esqueleto de una herencia """

# Se define una superclass
class super_class:
    # atributos y métodos de la clase
    pass

# Se creea una clase heredada
class sub_class(super_class):
    # atributos y métodos de la clase super_class
    # atributos y métodos de la clase sub_class
    pass

""" Class mandre Animal y clase hija Perro """

class Animal:
    # atributo de la clase
    name = ""

    # método de la clase
    def eat(self):
        print("I can eat")

class Dog(Animal):  # clase heredada de Animal
    # nuevo método de la clase heredada
    def display(self):
        # accede al atributo de la clase madre
        print("My name is", self.name)

print("Clase derivada Dog: ")

# Se crea un objeto de la clase Dog
labrador = Dog()

# Accede a un atributo y el método de la clase Animal
labrador.name = "Rohu"
labrador.eat()

# Accede al método de la clase Dog
labrador.display()

""" Class mandre Polygon y clase hija Triangle """
class Polygon:

    # Función de init
    def __init__(self, no_of_sides):
        self.n = no_of_sides    # Define una varible n que se carga con el número de lados
        self.sides = [0 for i in range(no_of_sides)]    # Crea un arreglo de tamaño número de lados

    # Método que le solicita al usuario la cantidad de lados, según el contenido del atributo n
    def inputSides(self):
        # Se guarda el valor de los lados en el arreglo creado self.sodes
        self.sides = [float(input("Enter side" + str(i + 1) + " : ")) for i in range(self.n)]

    # Recorre el arreglo self.sides para imprimir sus resultados
    def dispSides(self):
        for i in range(self.n):
            print("Side", i+1, "is", self.sides[i])

class Triangle(Polygon):

    # Hereda de la clase polígono y en mi inicializor llama a la clase madre para que use
    # su inicializar y coloque n = 3 (lados)
    def __init__(self):
        Polygon.__init__(self,3)    # Llama a la función de init de Polygon

    # Se cálcula el area utilizando la formula de Heron
    def findArea(self):
        a, b, c = self.sides

        # Calcula el semipreimetro
        s = (a + b + c)/2
        area = (s*(s-a)*(s-b)*(s-c)) ** 0.5

        print("El area del triangulo es %0.2f" %area)   # Presión de dos decimales de un número flotante

print("\nClase derivada Triangle: ")

# Se crea un objeto de la clase Triangle
t = Triangle()

# Se solicita al usuario que ingrese el tamaño de cada lado (side)
t.inputSides()

# Le muestra al usuario el tamaño que tiene cada lado (side)
t.dispSides()

# Calcula el area del triangulo y muestra el resultado
t.findArea()

""" Se utiliza la sobreescritura de métodos con la clase Animal y Dog """

class Animal:
    # atributo de la clase
    name = ""

    # método de la clase
    def eat(self):
        print("I can eat")

class Dog(Animal):  # clase heredada de Animal
    
    # Sobreescribe el método eat() que proviene de la clase Animal
    def eat(self):
        print("I like to eat bones")

print("\nClase derivada Dog: utilizando sobreescritura de métodos")

# Se crea un objeto de la clase Dog
labrador = Dog()

# Se llama al unico método que tiene la clase Dog
labrador.eat()

""" Se utiliza el método super() con la clase Animal y Dog """

class Animal:
    # atributo de la clase
    name = ""

    # método de la clase
    def eat(self):
        print("I can eat")

class Dog(Animal):  # clase heredada de Animal
    
    # Sobreescribe el método eat() que proviene de la clase Animal. Llama al método original
    # y le agrega un print
    def eat(self):
        
        # Llama al método eat() que proviene de Animal
        super().eat()

        print("I like to eat bones")

print("\nClase derivada Dog: utilizando el método super()")

# Se crea un objeto de la clase Dog
labrador = Dog()

# Se llama al unico método que tiene la clase Dog
labrador.eat()

""" Uso de herencia múltiple con las clases madres Mammal y WingedAnimal y la clase derivada Bat """

class Mammal:
    def mammal_info(self):
        print("Mammals can give direct birth")

class WingedAnimal:
    def winged_animal_info(self):
        print("Winged animals can fly")

class Bat(Mammal, WingedAnimal):
    pass

print("\nUso de la clase derivada Bat: ")
# Crear un objeto de la clase murcielago
b1 = Bat()

b1.mammal_info()
b1.winged_animal_info()

""" Herencia multinivel con las clase madre SuperClass, la clase derivada DerivedClass1 y otra clase que 
    derivada de esta DerivedClass2 """

class SuperClass:
    def super_method(self):
        print("Super Class method called")

# La siguiente clase derivada obtiene el método super_method
class DerivedClass1(SuperClass):
    def derived1_method(self):
        print("Derived class 1 method called")

# La siguiente clase derivada obtiene el método super_method y derived1_method
class DerivedClass2(DerivedClass1):
    def derived2_method(self):
        print("Derived class 2 method called")

print("\nUso de la clase derivada Derived2:")

# Se crea un objeto de la clase DerivedClass2
d2 = DerivedClass2()

d2.super_method()       # Output: "Super Class method called"
d2.derived1_method()    # Output: "Derived class 1 method called"
d2.derived2_method()    # Output: "Derived class 2 method called"


""" Herencia: orden de resolución de métodos (MRO) """
class SuperClass1:
    def info(self):
        print("Super Class 1 method called")

class SuperClass2:
    def info(self):
        print("Super Class 2 method called")

class Derived(SuperClass1, SuperClass2):
    pass

print("\nUso de la clase derivada Derived:")

# Aquí se muestra el orden de prioridad, mostrando el métood info de SuperClass1
d1 = Derived()
d1.info()