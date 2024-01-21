"""
    La programación orientada a objetos es un paradigma de programación donde los problemas se modelan en 
    forma de clases y objetos. El foco principal está en los datos (objeto) más que en el procedimiento o 
    las funciones utilizadas para manipular esos datos.

    Un objeto es una representación abstracta de cosas y conceptos que encontramos en el mundo real, como empleados,
    organizaciones, automóviles, productos electrónicos, etc. Y una clase es un modelo para crear objetos.

    Las clases son pequeños fragmentos de código reutilizable a partir de los cuales se pueden crear múltiples
    objetos. Esto hace que los programas escritos con programación orientada a objetos sean fáciles de ejecutar,
    modificar y depurar. 

        Las clases contendrán:
            - datos de los empleados en forma de variables (nombre, salario, puesto de trabajo, etc.)
            - métodos para procesar esos datos (cálculo de bonificación, evaluación del desempeño, etc.).
"""

""" Ejemplo de construcción de una clase y objeto """

class ClassName:
    #class definition
    pass    # Se utiliza para validar la clase sin usar código

objectName = ClassName()    # Forma en la que se crea un objeto


""" Clase Bike: contiene un atributo string y un atributo entero (marcha)"""

class Bike:
    name = ""
    gear = 0

print("Uso de clase Bike: ")

bike1 = Bike()  # Se crea un objeto a partir de la clase Bike
bike1.name = "Montain Bike" # Se modifica el atributo name
bike1.gear = 11             # Se modifica el atributo gear

bike2 = Bike()  # Se crea un objeto a partir de la clase Bike
bike2.name = "Race Bike"    # Se modifica el atributo name
bike2.gear = 3             # Se modifica el atributo gear

print(f"Name: {bike1.name}, Gears: {bike1.name}")   # Se imprime el contenido del objeto bike1
print(f"Name: {bike2.name}, Gears: {bike2.name}")   # Se imprime el contenido del objeto bike2

""""Clase Employee: contiene un unico atributo entero para asignar un id a cada empleado """

class Employee:
    # Se define un atributo
    employee_id = 0

print("\nUso de clase Employee: ")

# Se crea dos objetos a partir de la clase Employee
employee1 = Employee()
employee2 = Employee()

# Se accede al atributo usando employee1
employee1.employee_id = 1001
print(f"Employee ID: {employee1.employee_id}")
# Se accede al atributo usando employee2
employee2.employee_id = 1002
print(f"Employee ID: {employee2.employee_id}")

""""Clase Room: esta contiene dos atributos flotantes y un método """

class Room:
    # Se define dos atributos
    length = 0.0
    breadth = 0.0

    # Método para calcular el area. El self es un indicador para decirle a la función que use
    # los atributos de la clase donde se encuentra
    def calculate_area(self):
        print("Area of Room =", self.length*self.breadth)

print("\nUso de clase Room: ")

# Se crea un objeto de la clase Room
study_room = Room()

# Se asignar valores a todos los atributos
study_room.length = 42.5
study_room.breadth = 30.8

# Se accede al método de la clase
study_room.calculate_area()

""" Clase Bike: se sobreescribe la clase para agregarle un contructor """

class Bike:
    # Contructor: lo cual sería la primera función.
    # Por convención al __init__ se le llama contructor a pesar de que no es lo primero en ejecutarse
    def __init__(self, name = ""):
        self.name = name

print("\nUso de clase Bike con contructor: ")

# Se crea el mismo objeto pero con esta clase:
bike1 = Bike("Mountain Bike")

print(bike1.name)

""" Clase Point: esta utiliza lo que sería el verdadero constructor, y encuentra un par ordenado """

class Point(object):

    # __new__ es un método especial que se llama antes de __init__.
    # Este método se encarga de crear y retornar una nueva instancia del objeto.
    def __new__(cls, *args, **kwargs):
        print("From new")
        print(cls)      # Imprime la clase actual (Point)
        print(args)     # Imprime los argumentos de atributos recibidos
        print(kwargs)   # Imprime los argumentos de palabra clave recibidos

        # Crea nuestro objeto y lo retorna
        # permitiendo que se realicen las tareas de inicialización necesarias antes 
        # de que se devuelva la instancia del objeto.
        obj = super().__new__(cls)
        return obj
    
    # Se utiliza para inicializar los atributos del objeto.
    def __init__(self, x = 0, y = 0):
        print("From init")
        self.x = x
        self.y = y

print("\nUso de clase Point: ")

# Se crea un objeto de la clase Point
objeto1 = Point(5,7)    # Se agregan valores a los atributos
print(f"Par ordenado en ({objeto1.x}, {objeto1.y})")    # Se imprime el contenido del objeto

""" Clase SqPoint: utiliza el verdadero constructor para no crear muchos objetos, y tiene dos valores"""

class SqPoint():
    MAX_Inst = 4
    Inst_created = 0

    # Contructor: se encarga de asegurar que el usuario no pueda crear más de 4 objetos
    def __new__(cls, *args, **kwargs):
        if (cls.Inst_created >= cls.MAX_Inst):
            raise ValueError("Cannor create more objets")
        cls.Inst_created += 1   # Este un valor que incremente indiferentemente del objeto

        # Crea nuestro objeto y lo retorna
        # permitiendo que se realicen las tareas de inicialización necesarias antes 
        # de que se devuelva la instancia del objeto.
        return super().__new__(cls)

print("\nUso de clase SqPoint: ")

# Se crean más de 4 objetos 
sq1 = SqPoint()
sq2 = SqPoint()
sq3 = SqPoint()
sq4 = SqPoint()
sq4.Inst_created = 0    # Esto no afecta al contador Inst_created
# sq5 = SqPoint()  