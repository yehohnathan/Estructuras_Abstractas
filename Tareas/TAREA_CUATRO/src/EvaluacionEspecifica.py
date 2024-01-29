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
            return "No se creó la lista: ingrese una puntuación mayor"
        elif self.__puntuacion > 1125899906842623:
            # El número anterior es el resultado del valor esperado de cada
            # alergia
            return ("No se creó la lista: ingresaste una puntuación" +
                    " más baja")

        self.__lista_alergias = []

        # Se crea un ciclo for para imprimir un diccionario. Se puede
        # interpretar como nombre: (alergia, codigo)
        for nombre, (alergia, codigo) in self._alergias.items():
            # Utilizando una AND  de puntuacion y codigo, se busca que
            # el resultado sea igual a codigo. Esto significa que los
            # unos resultantes son iguales al código y se puede agregar
            if self.__puntuacion & codigo == codigo:
                self.__lista_alergias.append(alergia)

        return self.__lista_alergias

    def imprimir_informacion_completa(self):
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

        print("Este tiene las siguientes alergias, cada una con una",
              "puntuación asociada):")

        for nombre, (alergia, codigo) in self._alergias.items():
            # Si alergia (que es un string) está dentro de la lista, entonces
            # se imprime el nombre junto con el valor asociado
            if alergia in self.__lista_alergias:
                print(f"{alergia}: {codigo}")


hola = EvaluacionEspecifica()
hola.evaluar_alergias()
hola.imprimir_informacion_completa()
