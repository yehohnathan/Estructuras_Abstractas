# ----------- # Se cargan las librerías necesarias el programa # ------------ #
import pandas as pd                 # Para manejo de CSV
import matplotlib.pyplot as plt     # Para crear gráficar con la info del CSV
import seaborn as sns               # Más opciones de gráficas


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


# ---- # Función para realizar gráficos de puntos para dos columnas # ----- #
# En el caso de esta función graficadora pasa que los puntos son un
# complicados de observar. Por se limita la cantidad de datos de la columna1
# a unicamente 20 (10 primeras y 20 ultimas filas).
def graficoPuntos_Dos_Columnas(columna1_y_columna2, title, xlabel, ylabel):
    # Extraer las etiquetas y los valores de la tabla columna1_y_columna2
    columna1 = columna1_y_columna2.iloc[:, 0]
    columna2 = columna1_y_columna2.iloc[:, 1]

    # Seleccionar solo las primeras y últimas 10 filas de la columna 1
    columna1 = pd.concat([columna1.head(10), columna1.tail(10)])

    # Seleccionar los valores correspondientes a las filas seleccionadas
    columna2 = columna2.iloc[columna1.index]

    # Crear el gráfico de puntos con Seaborn
    plt.figure(figsize=(10, 6))
    sns.scatterplot(x=columna1, y=columna2, hue=columna1, palette='Set2',
                    data=columna1_y_columna2, s=50)

    # Se nombra el gráfico
    plt.title(title)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)

    # Se mueve la leyenda a la derecha y se elimina el eje x
    plt.legend(bbox_to_anchor=(1.05, 1), loc='upper left', borderaxespad=0.)
    plt.xticks([])

    # Se cambia el color del fondo a blanco
    plt.gca().set_facecolor('white')

    # Se agregan las etiquetas de texto sobre cada punto
    for x, y in zip(columna1, columna2):
        plt.annotate(f'{y:.0f}', xy=(x, y), xytext=(0, 5),
                     textcoords='offset points', ha='center', va='bottom')

    # Muestra el gráfico
    plt.show()


# --- # Función que relaciona a las aerolineas y la distancia recorrida # --- #
def aerolineas_distancia(df):
    # Agrupar por nombre de la aerolinea y sumar las distancias
    distancia_vuelo = df.groupby('UNIQUE_CARRIER_NAME')['DISTANCE'].sum()

    # Se obtienen las aerolineas con mayor distancia recorrieda
    aerolineas_mas_distancia = distancia_vuelo.nlargest(5)

    # Se obtienen las aerolineas con menor distancia recorrieda
    aerolineas_menos_distancia = distancia_vuelo.nsmallest(5)

    # Obtener los países de origen de las empresas
    paises_origen_mas = (df[df['UNIQUE_CARRIER_NAME'].
                            isin(aerolineas_mas_distancia.index)]
                         ['ORIGIN_COUNTRY_NAME'])

    paises_origen_menos = (df[df['UNIQUE_CARRIER_NAME'].
                              isin(aerolineas_menos_distancia.index)]
                           ['ORIGIN_COUNTRY_NAME'])

    # Crear una sola figura con dos subgráficos
    plt.figure(figsize=(14, 6))

    # Subgráfico 1: Aerolineas con más distancia recorrida
    plt.subplot(1, 2, 1)

    # Se coloca los valores de los eje (x,y)
    ax1 = sns.barplot(x=aerolineas_mas_distancia.index,
                      y=aerolineas_mas_distancia.values)

    # Nombre de del titulo, ejes, orientación del eje x y tamaño
    plt.title('Aerolineas con Más Distancia Recorrida')
    plt.xlabel('Aerolineas')
    plt.ylabel('Distancia Total Recorrida')
    plt.xticks(rotation=45, fontsize=8)

    # Se coloca el nombre de los paises en cada respectiba barrar de los
    # paises con mayor distancia
    for i, p in enumerate(ax1.patches):
        ax1.annotate(paises_origen_mas.iloc[i],
                     (p.get_x() + p.get_width() / 2., p.get_height()),
                     ha='center', va='center', xytext=(0, 10),
                     textcoords='offset points')

    # Subgráfico 2: Aerolineas con menos distancia recorrida
    plt.subplot(1, 2, 2)

    # Se coloca los valores de los eje (x,y)
    ax2 = sns.barplot(x=aerolineas_menos_distancia.index,
                      y=aerolineas_menos_distancia.values)

    # Nombre de del titulo, ejes, orientación del eje x y tamaño
    plt.title('Aerolineas con Menos Distancia Recorrida')
    plt.xlabel('Aerolineas')
    plt.ylabel('Distancia Total Recorrida')
    plt.xticks(rotation=45, fontsize=8)

    # Se coloca el nombre de los paises en cada respectiba barrar de los
    # paises con menor distancia
    for i, p in enumerate(ax2.patches):
        ax2.annotate(paises_origen_menos.iloc[i],
                     (p.get_x() + p.get_width() / 2., p.get_height()),
                     ha='center', va='center', xytext=(0, 10),
                     textcoords='offset points')

    # Se muestra el gráfico
    plt.tight_layout()
    plt.show()
