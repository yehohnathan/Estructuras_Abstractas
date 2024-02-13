# ------------------------- # Librerías auxiliares # ------------------------ #
import pandas as pd     # Para uso de DataFrame con CSV

# ------------------------ # Se importa el paquete # ------------------------ #
from regression import RegresionLineal

# -------------- # Importar CSV desde la plataforma de Kaggle # ------------- #
# Bloque de excepción si no esta el kaggle.json
try:
    # Del modulo kaggle.api.kaggle_api_extended, se importa la clase KaggleApi
    # para interartuar con plataforma de Kaggle
    from kaggle.api.kaggle_api_extended import KaggleApi

    # Se crea un objeto desde la clase KaggleApi
    api = KaggleApi()

    # Se utiliza un método para autentificar el username y la key, de la cuenta
    # de usuario registrado en la plataforma. Accediendo al kaggle.json
    api.authenticate()

    # Descargar el archivo CSV "CAR DETAILS FROM CAR DEKHO.csv", del conjunto
    # de datos de car-details-dataset del usuario akshaydattatraykhare3.
    api.dataset_download_file('akshaydattatraykhare/car-details-dataset',
                              file_name='CAR DETAILS FROM CAR DEKHO.csv',
                              path="../TAREA_SEIS/CSV_KAGGLE")

    # Se instancia el nombre del csv:
    name_csv = ("../TAREA_SEIS/CSV_KAGGLE/" +
                "CAR%20DETAILS%20FROM%20CAR%20DEKHO.csv")
except Exception:
    print("Ha ocurrido un error. Posiblemente el kaggle.json no se encuentre",
          "en el directorio esperado **LEE EL README**.")
    print("Se procederá a utilizar el CSV de respaldo.")
    name_csv = "../TAREA_SEIS/Respaldo/Respaldo_CSV.csv"

# --------------------- # Análisis y limpieza del CSV # --------------------- #
# Se carga el CSV en un DataFrame:
vehiculos_df = pd.read_csv(name_csv)

# Se muestra la información del DataFrame al usuario:
print("\n========== Datos originales del DataFrame: ==========")
print(vehiculos_df)

# Análisis exploratorio de datos:
print("\n========== Información del DataFrame: ==========")
vehiculos_df.info()

# Verifica que no haya valores faltantes:
if vehiculos_df.isnull().sum().any():
    # Si hay valores faltantes, por lo que se procede a remplazarlos por
    # valor promedio de la columna pra no desviar tanto los datos de la
    # posible regresion o cluster.
    print("\n========== Hay valores faltantes dentro del DataFrame.",
          "Remplazando... ==========")
    vehiculos_df.fillna(vehiculos_df.mean(), inplace=True)
else:
    print("\n========== No hay valores faltantes dentro del DataFrame",
          "==========")

# Verifica que no haya filas con datos repetidos:
if vehiculos_df.duplicated().any():
    print("\n========== Hay valores duplicados en el DataFrame.",
          "Eliminando... ==========")
    # Como si hay valores repetidos, se eliminan y se modifica el DataFrame
    # original
    vehiculos_df.drop_duplicates(inplace=True)

    # Se restablece el indice, elimnandolo y emplazandolo del DataFrame
    # original
    vehiculos_df.reset_index(drop=True, inplace=True)
else:
    print("\n========== No hay valores duplicados en el DataFrame. ==========")

# Se muestra la información del DataFrame al usuario:
print("\n========== Datos del DataFrame posterior a la limpieza: ==========")
print(vehiculos_df)

# =========================================================================== #
"""                       ESPACIO PARA REGRESSION.PY                        """
# =========================================================================== #
# Sea crea un objeto del paquete car_analysis
regresion_lineal = RegresionLineal()

# Se ingresa el DataFrame al objeto
regresion_lineal.setDataFrame(vehiculos_df)

regresion_lineal.regresion_lineal_simple("year", "selling_price",
                                         "Año de venta", "Precio de venta")
