# ----------- # Se cargan las librerías necesarias el programa # ------------ #
# import pandas as pd                 # Para manejo de CSV
import matplotlib.pyplot as plt     # Para crear gráficar con la info del CSV
# import seaborn as sns


# ----- # Función para realizar gráficos de barras para dos columnas # ------ #
def graficoBarras_Dos_Columnas(columna1_y_columna2, title, xlabel, ylabel):
    # Extraer las etiquetas y los valores de la tabla clase_y_pasajeros
    columna1 = columna1_y_columna2.iloc[:, 0]
    columna2 = columna1_y_columna2.iloc[:, 1]

    # Crear el gráfico de barras
    plt.figure(figsize=(10, 6))
    barras = plt.bar(columna1, columna2, color='skyblue')

    # Añadir el valor de "Passengers" encima de cada barra
    for barra in barras:
        # Obtener la altura de la barra
        yval = barra.get_height()
        # Colocar el valor de la Columna2 encima de la barra, centrado
        # horizontalmente y justo encima de la parte superior de la barra, con
        # un pequeño desplazamiento vertical hacia abajo (va='bottom')
        plt.text(barra.get_x() + barra.get_width() / 2,
                 yval, round(yval, 2), va='bottom')

    # Se nombra el gráfico
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)

    # Muestra el gráfico
    plt.show()


# ---- # Función para realizar gráficos tipo pastel para dos columnas # ----- #
def graficoPastel_Dos_Columnas(columna1_y_columna2, title):
    # Extraer las etiquetas y los valores de la tabla columna1_y_columna2
    etiquetas = columna1_y_columna2.iloc[:, 0]
    valores = columna1_y_columna2.iloc[:, 1]

    # Crear el gráfico de pastel
    plt.figure(figsize=(8, 8))
    plt.pie(valores, labels=etiquetas, autopct='%1.1f%%', startangle=140)
    plt.title(title)

    # Aspecto igual asegura que el pastel se dibuje como un círculo
    plt.axis('equal')

    # Muestra el gráfico de pastel
    plt.show()


# --- # Generador de datos información para columna con datos agrupados # --- #
# Se crea un generador que itera para poder encontrar la cantidad de datos de
# una columna agrupada (Columna1) de otra columna (Columna2). Un ejemplo
# sería agrupar la cantidad de vuelos y de a
def generarDatos_Columnas_Agrupados(dataframe, columna1, columna2,
                                    text1, text2, text3):
    # Agrupar los datos por filas de columna 1
    archivo_df = dataframe.groupby(columna1)

    # Iterar sobre cada fila de columna1
    for nombre_fila, datos_fila in archivo_df:
        # Calcular la cantidad de veces que se repite el nombre de una fila
        # de la columna 1
        fila_repetida = len(datos_fila)
        # Suma el valor de todas las filas asociadas de columna 2 al nombre
        # de una fila de columna 2
        suma_repeticiones = datos_fila[columna2].sum()

        # Muestra la observación obtenida:
        informe = f"{text1}: {nombre_fila}\n{text2}: {fila_repetida}\n" +\
                  f"{text3}: {suma_repeticiones}\n"

        # Retorna el forma de generador
        yield informe


# - # Generador de datos información para filas repetidas de una columna # - #
# Lo que se busca lograr con este generador es buscar la cantidad de veces que
# se repite el nombre de una fila de una columna. Un ejemplo sería contar
# la cantidad de vuelos de una aerolinea.
def generarRepeticion_Datos(dataframe, columna1, text1, text2):
    # Agrupar los datos por filas de columna 1
    archivo_df = dataframe.groupby(columna1)

    # Iterar sobre cada fila de columna1
    for nombre_fila, datos_fila in archivo_df:
        # Calcular la cantidad de veces que se repite el nombre de una fila
        # de la columna 1
        fila_repetida = len(datos_fila)

        # Muestra la observación obtenida:
        informe = f"{text1}: {nombre_fila}\n{text2}: {fila_repetida}\n"

        # Retorna el forma de generador
        yield informe
