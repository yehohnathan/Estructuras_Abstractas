class Person:
    # Se crea el "constructor" y se inicializan las variables
    def __init__(self, name, age):  # El self es el this de python
        self.name = name    # Atributo público
        self.age = age      # Atributo público

    # Método para mostrar la información de los atributos
    def display_info(self):
        print(f"Name: {self.name}\nAge: {self.age}")
