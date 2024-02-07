# ----------- # Se cargan las librerías necesarias el programa # ------------ #
# import pandas as pd                 # Para manejo de CSV
# import matplotlib.pyplot as plt     # Para crear gráficar con la info del CSV
# import seaborn as sns
import sys                          # Para terminar el programa

# ----------- # Se importa la clase para manipular DataFrames # ------------- #
from DataFrame import DataFrame


# ----- # Función para realizar gráficos de barras para dos columnas # ------ #
import Funciones as func_graph

# -------------------- # Mensaje de inicio del programa # ------------------- #
print("\n=================== Parte Práctica 1 ===================")
print("Creando dataframe...")

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

# ----- # Relación de cantidad de pasajeros por vuelo, con generadores # ---- #
print("\nA continuación se muestra la cantidad de pasajeros por aerolinea",
      "con su respectiva cantidad de vuelos: (Presione una tecla)")
input()
for informacion_vuelos in func_graph.generarDatos_Columnas_Agrupados(
                          mi_dataFrame.getCSV(), "UNIQUE_CARRIER_NAME",
                          "PASSENGERS", "Aerolinea", "Cantidad de vuelos",
                          "Total de pasajeros"):
    print(informacion_vuelos)

# ------------- # Relación de cantidad de vuelos por aerolinea # ------------ #
print("\nA continuación se muestra la cantidad de vuelos por aerolinea:",
      "(Presione una tecla)")
input()
for cantidad_vuelos in func_graph.generarRepeticion_Datos(
                                mi_dataFrame.getCSV(), "UNIQUE_CARRIER_NAME",
                                "Aerolinea", "Cantidad de vuelos"):
    print(cantidad_vuelos)

# ------------ # Relación del CLASS y la cantidad de pasajeros # ------------ #
clase_y_pasajeros = mi_dataFrame.sumaColumnasAgrupadas("CLASS",
                                                       "PASSENGERS")

# Se muestra el gráfico de barras de la tabla
print("\nGenerando gráfico de barras.. (Presione una tecla).")
input()
func_graph.graficoBarras_Dos_Columnas(clase_y_pasajeros,
                                      "Distribución de pasajeros por clase",
                                      "Clase",
                                      "Pasajeros")

# -------------- # Relación del CLASS y la cantidad de peso # --------------- #
clase_y_peso = mi_dataFrame.sumaColumnasAgrupadas("CLASS",
                                                  "FREIGHT")

# Se muestra el gráfico tipo pastel de la tabla
print("\nGenerando gráfico de pastel... (Presione una tecla)")
input()
func_graph.graficoPastel_Dos_Columnas(clase_y_peso,
                                      "Distribución de peso por clase")


# ----------- # Relación de la aerolinea y la cantidad de peso # ------------ #
aerolinea_y_pajeros = mi_dataFrame.sumaColumnasAgrupadas("UNIQUE_CARRIER_NAME",
                                                         "PASSENGERS")

# Se muestra el gráfico tipo pastel de la tabla
print("\nGenerando gráfico de puntos... (Presione una tecla)")
input()
func_graph.graficoPuntos_Dos_Columnas(
                                    aerolinea_y_pajeros,
                                    "Distribución de pasajeros por aerolinea",
                                    "Aerolinea",
                                    "Pasajeros")

# ---------- # Relación de la areolina con la distancia y país # ------------ #
print("\nGenerando dos gráficos de barra... (Presione una tecla)")
input()
archivo = mi_dataFrame.getCSV()
func_graph.aerolineas_distancia(mi_dataFrame.getCSV())
