# ----------- # Se cargan las librerías necesarias el programa # ------------ #
import pandas as pd                 # Para manejo de CSV
# import matplotlib.pyplot as pt      # Para crear gráficar con la info del CSV

# -------------- # Se carga el csv en un DataFrame de pandas # -------------- #
# Ingresar la dirección donde se encuentra el csv
ruta_csv = "../TAREA_CINCO/Material_Practica/T_T100I_MARKET_ALL_CARRIER.csv"
# Transformar el csv a un DataFrame de pandas
air_carries_df = pd.read_csv(ruta_csv)
