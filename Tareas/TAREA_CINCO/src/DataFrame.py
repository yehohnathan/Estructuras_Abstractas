# ------------- # Se crea una clase genérica para manejar CSV # ------------- #
import pandas as pd     # Se instancia la librería de pandas


class DataFrame:
    def __init__(self):
        self.__archivo_df = pd.DataFrame()
        self.__csv_vacio = True
        pass

    def getCSV(self):
        return self.__archivo_df

    def setCSV(self, csv):
        # Se instancia el csv en un DataFrame, siempre comprobando que si
        # exista el csv
        try:
            self.__archivo_df = pd.read_csv(csv)
        except FileNotFoundError:
            print("No se encontró el .CSV que desea utilizar.",
                  f"Verificar: {csv}")

        return self.getCSV()

    def ingresarDataFrame(self, df=pd.DataFrame()):
        if not isinstance(df, pd.DataFrame):
            print("Error: Lo ingresado no es un DataFrame.")
        else:
            print("Se ingreso un DataFrame.")
            self.__archivo_df = df

    def mostrarDataFrame(self):
        if self.__archivo_df.empty:
            print("El DataFrame está vacío, no hay nada que mostrar.")
        else:
            print(self.__archivo_df)

    def __contenidoCSV(self):
        # Verifica que el csv no este vacio
        if self.__archivo_df.empty:
            print("El DataFrame está vacío.")
        else:
            self.__csv_vacio = False
        return self.__csv_vacio

    def eliminarColumnas(self, columnas_a_eliminar):
        # Verifica que si haya un csv a manipular
        if self.__contenidoCSV() is True:
            return
        # Verificar si columnas_a_eliminar es una lista o una tupla
        if not isinstance(columnas_a_eliminar, (list, tuple)):
            print("Error: la variable debe ser una lista o una tupla.")
            return
        # Se crea un iterador para eliminar los items de la lista en el
        # DataFrame. Esto permite que usando un bloque de excepción para
        # todas aquellas columnas de la lista que no tienen relación la
        # las columnas del DataFrame
        for columna in columnas_a_eliminar:
            try:
                # Se elimina la "columna" utilizando el método drop
                self.__archivo_df = self.__archivo_df.drop(columns=columna)
            except KeyError as e:
                print(f"La columna \"{columna}\" no existe dentro del",
                      f"DataFrame.Error: {e}")
                continue    # Sigue con el siguiente elemento.
        print("Se eliminaron todas las columnas y se actualizo el DataFrame.")

    def eliminarValoresNulos(self):
        # Verifica que si haya un csv a manipular
        if self.__contenidoCSV() is True:
            return
        # Ahora se buscan valores nulos en las columnas restantes del
        # DataFrame, de esta forma se determina si hay filas que se podrían
        # eliminar. Además se suman todas las posibles filas que podría haber
        # en una columna que haya que eliminar.
        valores_nulos = self.__archivo_df.isnull().sum()
        # Luego se se suman todos los posibles valores nulos, de haber se
        # imprime un mensaje y sino se continua con el código
        if valores_nulos.sum() > 0:
            # Se muestra la cantidad de valores nulos por columna
            print(f"\nValores nulos por columna:\n{valores_nulos}")
            self.__archivo_df = self.__archivo_df.dropna()
            print("Se actualizó el contenido del DataFrame.")
        else:
            print("No se encontraron valores nulos en el DataFrame.")

    def crearCSV(self):
        # Verifica que si haya un csv a manipular
        if self.__contenidoCSV() is True:
            return
        else:
            self.__archivo_df.to_csv("nuevo_archivo.csv")
