class EvaluacionGeneral():
    def __init__(self):
        """
        Constructor de la clase EvaluacionGeneral.

        Inicializa la instancia con una lista de alergias vacía.
        """
        self._lista_alergias = []

    def datos_alergias(self, lista):
        """
        Muestra información sobre las alergias proporcionadas por el usuario.

        :param lista: Lista de alergias proporcionada por el usuario.
        """
        # Se almacena el contenido de lista en el atributo de la clase
        self._lista_alergias = lista
        # Se crea una variable que almacena la puntuación global de alergias
        # conocidas
        puntuacion_general = 0
        # Lista que almacena los valores de las alergias que no tienen nombre
        # asociado
        resultados_desconocidos = []

        print("\nLas alergias ingresadas por el usuario son las siguientes:")

        # A continuación se accede a un ciclor for, que solo funciona con la
        # lista de alergias generada por el usuario. Esta dependiendo del tipo
        # de dato realiza una acción u otra.
        for sublista in self._lista_alergias:
            # Es una lista, por ende es una alergia conocida
            if isinstance(sublista, list):
                # Se imprime el nombre de la alergia y su valor
                print(f"{sublista[0].capitalize()}: {sublista[1]}")
                # Se suma el valor que se va a imprimir al final
                puntuacion_general += sublista[1]

            elif isinstance(sublista, str):
                # Si el valor unicamente es string, se indica que el valor
                # es desconocido
                print(f"{sublista.capitalize()}: valor desconocido")

            elif isinstance(sublista, int):
                # Si el valor unicamente es entero, entonces se va agregando a
                # una lista de resultados que será impresa al final
                resultados_desconocidos.append(str(sublista))

        # Muestra la puntuación general final
        print("La puntuación general de las alergias del usuario es:",
              puntuacion_general)

        # Muestra los resultados desconocidos en orden, separados por comas.
        print("Resultados desconocidos: " + ', '.join(resultados_desconocidos))

    def calcular_promedio(self):
        """
        Calcula el promedio de lo que se pudo determinar como alergia y lo
        que es desconocido.
        """
        # Se inicializan las variables para calcular el promedio de
        # suma_alergias/total_alergias para alergias validas y
        # suma_alergias_desconocidas/total_alergias para alergias invalidas
        total_alergias = 0
        total_desconocidos = 0
        suma_alergias = 0
        suma_alergias_desconocidas = 0

        # Lo siguiente es un ciclo for que detecta el tipo de dato actual
        # de la lista, y dependiendo de ello se suman las variables
        # correspondientes
        for sublista in self._lista_alergias:
            if isinstance(sublista, list):
                total_alergias += 1
                suma_alergias += sublista[1]
            elif isinstance(sublista, (int)):
                suma_alergias_desconocidas += sublista
                total_desconocidos += 1
            elif isinstance(sublista, (str)):
                total_desconocidos += 1

        # Ciclo if, para mostrar el promedio de alergias determinadas si
        # el total es mayor a 0
        if total_alergias > 0:
            print("Promedio de alergias determinadas:",
                  suma_alergias / total_alergias)
        else:
            print("No se determinaron alergias.")

        # Ciclo if, para mostrar el promedio de alergias desconocidos si
        # el total es mayor a 0
        if total_desconocidos > 0:
            print("Promedio de resultados desconocidos:",
                  suma_alergias_desconocidas / total_desconocidos)
        else:
            print("No hay resultados desconocidos.")
