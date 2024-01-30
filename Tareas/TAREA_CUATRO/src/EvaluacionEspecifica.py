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

    def evaluar_alergias(self):
        """
        Método que evalúa las alergias de una persona según una puntuación
        dada.

        :return: Lista de instancias de la clase Alergia a las que la persona
        es alérgica.
        """
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
