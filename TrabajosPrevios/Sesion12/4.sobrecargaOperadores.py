""" Sobrecarga de operadores """
class Point:

    # Creación de la función init (contructor), inicializando los dos atributos
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    # Cuando se imprime un objeto de la clase Point imprime lo siguiente
    def __str__(self):
        return "({0},{1})".format(self.x, self.y)

    # Cuando yo sumo dos objetos de tipo punto
    def __add__(self, other):
        x = self.x + other.x
        y = self.y + other.y
        return Point(x, y)

print("Uso de la clase Point: ")
# Se crean dos objetos de la clase puntos
p1 = Point(1, 2)
p2 = Point(2, 3)

# Se imprime el contenido de la suma de la suma de las dos clases
print(p1+p2)

# Se imprime el contenido de una sola clase
p3 = Point(6, 6)
print(p3)

""" Sobrecarga de operadores de comparación """
class Person:
    # Creación de la función init (contructor), inicializando los dos atributos
    def __init__(self, name, age):
        self.name = name
        self.age = age

    # Me pregunto cual de los dos objetos creados es menor:
    def __lt__(self, other):
        return self.age < other.age

print("\nUso de la clase Person")

p1 = Person("Alice", 20)
p2 = Person("Bob", 30)

print("Objeto p1 < p2?", p1 < p2)
print("Objeto p2 < p1?",p2 < p1)

