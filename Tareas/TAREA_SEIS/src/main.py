# ------------- # Importar módulos utilizados en el programa # -------------- #
import pandas as pd

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
except Exception as e:
    print("Ha ocurrido un error. Posiblemente el kaggle.json no se encuentre",
          "en el directorio esperado **LEE EL README**.")
    print(e)
    print("Se procederá a utilizar el CSV de respaldo.")
    name_csv = "../TAREA_SEIS/Respaldo/Respaldo_CSV.csv"

# --------------------------- # Lectura del CSV # --------------------------- #
df = pd.read_csv(name_csv)
print(df.head())
