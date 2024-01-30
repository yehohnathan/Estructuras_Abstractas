from Alergia import Alergia


class TiposAlergias(Alergia):
    """
    Clase que gestiona diferentes tipos de alergias.
    Hereda de la clase Alergia.
    """

    def __init__(self):
        """
        Constructor de la clase TiposAlergias.
        Inicializa listas para almacenar información de alergias.
        """
        super().__init__()
        self._lista_alergias = []
        self._lista_nombre = []
        self._lista_puntos = []

    def __agregar_nombre(self):
        """
        Método privado que solicita al usuario ingresar el nombre de una
        alergia.
        Verifica que el nombre solo contenga caracteres alfabéticos.

        :return: el nombre de la alergia.
        """
        while True:
            try:
                # Solicita el nombre de la alergia, pero este no debe contener
                # números. Si no cumple entonces vuelve a solicitar el nombre
                alergia_nombre = input("Ingrese el nombre de una alergia: ")

                if not alergia_nombre.replace(" ", "").isalpha():
                    raise ValueError("El nombre de la alergia debe contener",
                                     "solo caracteres alfabéticos.")

                break
            except ValueError as e:
                print(f"Error: {e}. Inténtelo de nuevo.\n")

        # Retorna el nombre de la alergia
        return alergia_nombre

    def __agregar_valor(self):
        """
        Método privado que solicita al usuario ingresar el valor numérico de
        una alergia.
        Verifica que se ingrese un valor numérico entero.

        :return: el valor de la alergia.
        """
        while True:
            try:
                # Solicita el valor de la alergia a ingresar, y si no es entero
                # lo vuelve a solicitar
                alergia_valor = int(input("Ingrese el valor de una alergia: "))
                break
            except ValueError as e:
                print(f"Error: {e}. Debe ingresar un valor numérico entero.",
                      "Inténtelo de nuevo.\n")

        # Retorna el valor de la alergia
        return alergia_valor

    def __busca_nombre(self, nombre):
        """
        Método privado que busca una alergia por nombre en el diccionario de
        alergias.

        :return: una lista con la información de la alergia si se encuentra,
        o None si no.
        """
        # Hace que la cadena ingresada este en minusculas
        nombre = nombre.lower()
        # Extrae el elemento del diccionario, unicamente si nombre esta dentro
        alergia = self._alergias.get(nombre)

        # Si nombre si esta dentro del disccionario, retorna su contenido
        # y lo pasa de tupla a lista
        if alergia:
            return list(alergia)
        else:
            # Si no estaba retorna none
            return None

    def __busca_valor(self, valor):
        """
        Método privado que busca una alergia por valor en el diccionario de
        alergias.
        :return:  una lista con la información de la alergia si se encuentra,
        o None si no.
        """
        # Ciclo for que accede a cada elemento del diccionario, con el fin de
        # buscar verificar que el valor ingresado coincide con algun elemento
        # del diccionario, si es así lo retorna.
        for nombre, (alergia, codigo) in self._alergias.items():
            if codigo == valor:
                return [alergia, codigo]
        return None

    def __analiza_alergias(self):
        """
        Método privado que analiza la lista de alergias y actualiza las listas
        de nombre y valor.
        """
        # Crear una copia de la lista para evitar problemas cuando se eliminan
        # elementos
        copia_alergias = list(self._lista_alergias)

        # Ciclo for que verifica si un nombre o valor asociado está existente
        # en el diccionario para complementarlo. Si solo está valor, se le pone
        # el nombre asociado, y viceversa.
        for sublista in copia_alergias:
            # Si el primer elemento es None, significa que en ese elemento el
            # usuario solo ingresó Nombre o Valor en agregar_alergia().
            if sublista[0] is None:
                # Se pregunta si segundo elemento es Nombre o Valor, para hacer
                # la búsqueda en el diccionario. Si el elemento está se hace un
                # asocié y se ingresa completo a la lista, sino se elimina y se
                # agrega a una de las dos listas que solo admiten Nombres y
                # Valores que no fueron encontrados.
                if isinstance(sublista[1], str):
                    verificador = self.__busca_nombre(sublista[1])
                    if verificador is None:
                        # Nombre no encontrado en el diccionario, se agrega a
                        # una lista diferente y se borra de lista_alergias
                        self._lista_nombre.append(sublista[1])
                        self._lista_alergias.remove(sublista)
                    else:
                        # El nombre si se encontró en el diccionario, por
                        # lo que se modifica el contenido malo que esta en
                        # indice y se coloca el nuevo
                        indice = self._lista_alergias.index(sublista)
                        self._lista_alergias[indice] = verificador

                elif isinstance(sublista[1], int):
                    verificador = self.__busca_valor(sublista[1])
                    if verificador is None:
                        # Valor no encontrado en el diccionario, se agrega a
                        # una lista diferente y se borra de lista_alergias
                        self._lista_puntos.append(sublista[1])
                        self._lista_alergias.remove(sublista)
                    else:
                        # El valor si se encontró en el diccionario, por
                        # lo que se modifica el contenido malo que esta en
                        # indice y se coloca el nuevo
                        indice = self._lista_alergias.index(sublista)
                        self._lista_alergias[indice] = verificador

    def agregar_alergia(self):
        """
        Método público para agregar una alergia.
        Permite al usuario elegir entre ingresar nombre y valor, solo nombre
        o solo valor.
        """
        # Reinicio de las listas cada vez que se accede a este método:
        self._lista_alergias = []
        self._lista_nombre = []
        self._lista_puntos = []
        while True:
            print("\nTecleé un número asociado a una opción para agregar una",
                  "alergia",
                  "\nOpción '1': ingrese el nombre y valor de la alergia",
                  "a agregar.",
                  "\nOpción '2': ingrese el nombre de la alergia a agregar.",
                  "\nOpción '3': ingrese el valor de la alergia a agregar.",
                  "\nOpción '4': para dejar de agregar alergias.")
            try:
                opcion = int(input("Ingrese una opción: "))

                if opcion == 1:
                    nombre = self.__agregar_nombre()
                    valor = self.__agregar_valor()
                    self._lista_alergias.append([nombre, valor])

                elif opcion == 2:
                    nombre = self.__agregar_nombre()
                    self._lista_alergias.append([None, nombre])

                elif opcion == 3:
                    valor = self.__agregar_valor()
                    self._lista_alergias.append([None, valor])

                elif opcion == 4:
                    if len(self._lista_alergias) == 0:
                        print("No haz ingresado ninguna alergia")
                        continue
                    else:
                        break

            except ValueError:
                print("Error: No se ingresó una opción válida.",
                      "Inténtelo de nuevo.\n")

        # Se analizan los datos ingresados por el usuario, para verificar si
        # los valores ya existen dentro del programa
        self.__analiza_alergias()

        # Modifica el valor de lista, ya estando ordenada
        self._lista_alergias = (self._lista_alergias + self._lista_nombre
                                + self._lista_puntos)

    def get_lista_alergias(self):
        """
        Método público que retorna la lista de alergias.
        """
        return self._lista_alergias

    def get_nombre_no_alergias(self):
        """
        Método público que retorna la lista de nombres no asociados a alergias.
        """
        return self._lista_nombre

    def get_valor_no_alergias(self):
        """
        Método público que retorna la lista de valores no asociados a alergias.
        """
        return self._lista_puntos
