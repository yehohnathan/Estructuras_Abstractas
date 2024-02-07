# ----------- # Se cargan las librerías necesarias el programa # ------------ #
# import pandas as pd                 # Para manejo de CSV
# import matplotlib.pyplot as pt      # Para crear gráficar con la info del CSV
import sys                          # Para terminar el programa

# ----------- # Se importa la clase para manipular DataFrames # ------------- #
from DataFrame import DataFrame

# -------------- # Se carga el csv en un DataFrame de pandas # -------------- #
# Se un objeto de la clase DataFrame
mi_dataFrame = DataFrame()

# Ingresar la dirección donde se encuentra el csv
ruta_csv = "../TAREA_CINCO/Material_Practica/T_T100I_MARKET_ALL_CARRIER.csv"

# instancia el csv en un DataFrame, siempre comprobando que si exista el csv
mi_dataFrame.setCSV(ruta_csv)

# Me pregunto si el DataFrame del objeto no esta vacio para continuar con el
# programa
if mi_dataFrame.getCSV().empty:
    print("Se finalizó el programa.")
    sys.exit()

# ------------- # Limpieza y preparación de datos del DatFrame# ------------- #
# Creación de la lista que contiene las columnas a eliminar del csv
columnas_a_eliminar = [
    "MAIL", "UNIQUE_CARRIER", "AIRLINE_ID", "UNIQUE_CARRIER_ENTITY", "REGION",
    "CARRIER", "CARRIER_NAME", "CARRIER_GROUP", "CARRIER_GROUP_NEW",
    "ORIGIN_AIRPORT_ID", "ORIGIN_AIRPORT_SEQ_ID", "ORIGIN_CITY_MARKET_ID",
    "ORIGIN", "ORIGIN_COUNTRY", "ORIGIN_WAC", "DEST_AIRPORT_ID",
    "DEST_AIRPORT_SEQ_ID", "DEST_CITY_MARKET_ID", "DEST", "DEST_COUNTRY",
    "DEST_WAC", "QUARTER", "DISTANCE_GROUP"
]

# Se ingresa la lista al método del objeto que eliminará las columnas escogidas
mi_dataFrame.eliminarColumnas(columnas_a_eliminar)

# Ahora con otro método se eliminan todos los posibles valores nulos del DF
mi_dataFrame.eliminarValoresNulos()

# Se imprime el contenido del dataframe
mi_dataFrame.mostrarDataFrame()
