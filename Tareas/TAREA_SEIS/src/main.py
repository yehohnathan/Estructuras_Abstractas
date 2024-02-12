# ------------- # Importar módulos utilizados en el programa # -------------- #
# Del modulo kaggle.api.kaggle_api_extended, se importa la clase KaggleApi para
# interartuar con plataforma de Kaggle
from kaggle.api.kaggle_api_extended import KaggleApi

# -------------- # Importar CSV desde la plataforma de Kaggle # ------------- #
# Se crea un objeto desde la clase KaggleApi
api = KaggleApi()
# Se utiliza un método para autentificar el username y la key, de la cuenta de
# usuario registrado en la plataforma. Accediendo al kaggle.json
api.authenticate()

# Descargar el archivo CSV "CAR DETAILS FROM CAR DEKHO.csv", del conjunto de
# datos de car-details-dataset del usuario akshaydattatraykhare3.
api.dataset_download_file('akshaydattatraykhare/car-details-dataset',
                          file_name='CAR DETAILS FROM CAR DEKHO.csv')
