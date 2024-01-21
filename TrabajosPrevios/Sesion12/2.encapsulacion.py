# Encapsulación: modificadores de acceso (publico, privado y protegido)

# Sirven para la misma clase, mismo paquete, clases derivadas y otras clases
class Publicos:
    def __init__(self, name, age):
        self.name = name    # public
        self.age = age      

# Sirven para la misma clase, mismo paquete y clases derivadas
class Protegido:
    def __init__(self, name, age):
        self._name = name    # protected
        self._age = age      

# Sirven para la misma clase unicamente
class Privado:
    def __init__(self, name, age):
        self.name = name    # private
        self.age = age      

persona = Privado("John", 20)
# persona.name -> Arrojaría un error