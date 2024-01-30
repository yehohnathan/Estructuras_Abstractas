from Alergia import Alergia


class EvaluacionEspecifica(Alergia):
    def __init__(self):
        """
        Constructor de la clase EvaluacionEspecifica.

        Inicializa la puntuación y la lista de alergias.
        """
        super().__init__()
        self.__puntuacion = 0   # Se inicializa puntuación
        self.__lista_alergias = []

    def sumar_valor_alergias(self):
        """
        Método que suma el valor de las alergias que se encuentran en el
        sistema.

        :return: la suma de todos los valores de las alergias
        """
        suma = 0
        for valor in self._alergias.values():
            suma += valor[1]
        return suma

    def evaluar_alergias(self, lista_alergias):
        """
        Método que evalúa las alergias de una persona según una puntuación
        dada.

        :return: Lista de instancias de la clase Alergia a las que la persona
        es alérgica.
        """
        self._alergias = lista_alergias
        self.__puntuacion = 0   # Se inicializa siempre que se llama al método

        while True:
            try:
                self.__puntuacion = int(input("\nIngrese la puntuación de"
                                              " alergia: "))
                break  # Salir del bucle si la conversión a entero es exitosa
            except ValueError as ve:
                print(f"Error: {ve}")

        # Si la puntuación en menor o igual a cero se sale de la función
        if self.__puntuacion <= 0:
            print("No se creó la lista: ingrese una puntuación mayor")
            return
        elif self.__puntuacion > self.sumar_valor_alergias():
            # El número anterior es la suma de todas las alergias
            print("No se creó la lista: ingresa una puntuación más baja")
            return

        self.__lista_alergias = []

        # Se crea un ciclo for para imprimir un diccionario. Se puede
        # interpretar como nombre: (alergia, codigo)
        for nombre, (alergia, codigo) in self._alergias.items():
            # Utilizando una AND  de puntuacion y codigo, se busca que
            # el resultado sea igual a codigo. Esto significa que los
            # unos resultantes son iguales al código y se puede agregar
            if self.__puntuacion & codigo == codigo:
                self.__lista_alergias.append(alergia)

        self.mostrar_alergias()
        return self.__lista_alergias

    def mostrar_alergias(self):
        """
        Método que imprime información completa sobre las alergias de una
        persona.

        Imprime la puntuación general y la información detallada de cada
        alergia.
        """
        print(f"\nLa puntuación general del usuario es: {self.__puntuacion}.")

        if self.__puntuacion == 0:
            print("La puntuación general es 0, no hay información que mostrar")
            return

        print("El usuario tiene las siguientes alergias, cada una con una",
              "puntuación asociada:")

        for nombre, (alergia, codigo) in self._alergias.items():
            # Si alergia (que es un string) está dentro de la lista, entonces
            # se imprime el nombre junto con el valor asociado
            if alergia in self.__lista_alergias:
                print(f"{alergia}: {codigo}")


import cProfile
hola = EvaluacionEspecifica()

alergias = {
            "huevos": ("Huevos", 1),
            "cacahuetes": ("Cacahuetes", 2),
            "mariscos": ("Mariscos", 4),
            "fresas": ("Fresas", 8),
            "tomates": ("Tomates", 16),
            "chocolate": ("Chocolate", 32),
            "polen": ("Polen", 64),
            "gatos": ("Gatos", 128),
            "sardinas": ("Sardinas", 256),
            "gluten": ("Gluten", 512),
            "huevo": ("Huevo", 1024),
            "nueces": ("Nueces", 2048),
            "leche": ("Leche", 4096),
            "soja": ("Soja", 8192),
            "miel": ("Miel", 16384),
            "piña": ("Piña", 32768),
            "ajo": ("Ajo", 65536),
            "maiz": ("Maíz", 131072),
            "kiwi": ("Kiwi", 262144),
            "menta": ("Menta", 524288),
            "gambas": ("Gambas", 1048576),
            "apio": ("Apio", 2097152),
            "pescado": ("Pescado", 4194304),
            "manzanas": ("Manzanas", 8388608),
            "cilantro": ("Cilantro", 16777216),
            "aguacate": ("Aguacate", 33554432),
            "zanahorias": ("Zanahorias", 67108864),
            "berenjenas": ("Berenjenas", 134217728),
            "lentejas": ("Lentejas", 268435456),
            "almendras": ("Almendras", 536870912),
            "canela": ("Canela", 1073741824),
            "altramuces": ("Altramuces", 2147483648),
            "mantequilla": ("Mantequilla", 4294967296),
            "pepino": ("Pepino", 8589934592),
            "cangrejo": ("Cangrejo", 17179869184),
            "almejas": ("Almejas", 34359738368),
            "anacardos": ("Anacardos", 68719476736),
            "coliflor": ("Coliflor", 137438953472),
            "pimienta": ("Pimienta", 274877906944),
            "arandanos": ("Arándanos", 549755813888),
            "pera": ("Pera", 1099511627776),
            "cerveza": ("Cerveza", 2199023255552),
            "guisantes": ("Guisantes", 4398046511104),
            "ciruelas": ("Ciruelas", 8796093022208),
            "trigo": ("Trigo", 17592186044416),
            "higos": ("Higos", 35184372088832),
            "centeno": ("Centeno", 70368744177664),
            "pistachos": ("Pistachos", 140737488355328),
            "cangrejo de río": ("Cangrejo de río", 281474976710656),
            "col": ("Col", 562949953421312)
        }

cProfile.run('hola.sumar_valor_alergias()')
cProfile.run('hola.evaluar_alergias(alergias)')
cProfile.run('hola.mostrar_alergias()')
