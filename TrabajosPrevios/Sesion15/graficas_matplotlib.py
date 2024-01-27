"""
    Se importa y se usa la librería matplotlib siguiente la conveción de
    nombres
"""
# =========================================================================== #
# import matplotlib as mpl          # Libreria para gráficar
import matplotlib.pyplot as plt     # Se importa un único método
# import numpy as np                # Libería de análisis numérico

# =========================================================================== #
print("Gráfica de linea simple: no tiene titulos")
# Se crea una figura que contenga los ejes (x,y)
fig, ax = plt.subplots()  # Create a figure containing a single axes.
# Se le asignan valores a x,t con "äx"
ax.plot([1, 2, 3, 4], [1, 4, 2, 3])
# Se muestra la gráfica
plt.show()

# =========================================================================== #
print("Gráfica de linea simple: contiene titulos en sus ejes y gráfica")
# Se pueden datos de ejemplo para el eje x y y
x = [1, 2, 3, 4, 5]
y = [10, 12, 5, 8, 14]

# Crea un gráfico con las listas anteriores
plt.plot(x, y)

# Personalización de los titulos
plt.xlabel('Eje X')
plt.ylabel('Eje Y')
plt.title('Gráfico de Línea Simple')
plt.grid(True)  # Se colocan los cuadros

# Mostrar el gráfico
plt.show()

# =========================================================================== #
print("Gráfico de dispersión: contiene titulos en sus ejes y gráfica")

# Se pueden datos de ejemplo para el eje x y y
x = [1, 2, 3, 4, 5]
y = [10, 12, 5, 8, 14]

# Crear un gráfico de dispersión con el método scatter
plt.scatter(x, y, label='Puntos')

# Personalización de los titulos
plt.xlabel('Eje X')
plt.ylabel('Eje Y')
plt.title('Gráfico de Dispersión')
plt.legend()    # Se colocan leyenda a los puntos

# Mostrar el gráfico
plt.show()

# =========================================================================== #
print("Gráfica de linea simple: titulos y banderas")
# Se pueden datos de ejemplo para el eje x y y
x = [1, 2, 3, 4, 5]
y = [10, 12, 5, 8, 14]

# Crea un gráfico con las listas anteriores y una bandera
plt.plot(x, y, label='Datos de ejemplo')

# Personalización de los titulos
plt.xlabel('Eje X')
plt.ylabel('Eje Y')
plt.title('Gráfico de Línea Simple')
plt.legend()    # Se colocan la bandera (label)

# Mostrar el gráfico
plt.show()

# =========================================================================== #
print("Gráfica de linea simple: guarda la gráfica en una imagen")
# Se pueden datos de ejemplo para el eje x y y
x = [1, 2, 3, 4, 5]
y = [10, 12, 5, 8, 14]

# Crea un gráfico con las listas anteriores
plt.plot(x, y)

# Personalización de los titulos
plt.xlabel('Eje X')
plt.ylabel('Eje Y')
plt.title('Gráfico de Línea Simple')

# Guardar el gráfico como imagen, en este caso en .png
plt.savefig('grafico_linea.png')

# Mostrar el gráfico
plt.show()

# =========================================================================== #
print("Gráfico de barras verticales:")

# Se colocan los tipos de datos
categorias = ['A', 'B', 'C', 'D']
# Se le asigna un valor a cada dato
valores = [15, 8, 12, 10]

# Gráfico de barras verticales, a partir de las listas anteriores y se le
# asigna un color
plt.bar(categorias, valores, color='green')

# Personalización de los titulos
plt.xlabel('Categorías')
plt.ylabel('Valores')
plt.title('Gráfico de Barras Verticales')

# Mostrar el gráfico
plt.show()

# =========================================================================== #
print("Gráfico de pastel: ")

# Se le asigna un valor a las porciones del pastel
proporciones = [30, 20, 25, 15]
# Se le asigna una etiqueta a cada porción
etiquetas = ['A', 'B', 'C', 'D']

# Se realiza una gráfica de pastel
plt.pie(proporciones, labels=etiquetas, autopct='%1.1f%%', startangle=140,
        colors=['gold', 'lightcoral', 'lightgreen', 'lightskyblue'])

# Se le coloca unicamente el titulo
plt.title('Gráfico de Pastel')

# Mostrar el gráfico
plt.show()

# =========================================================================== #
"""
    La caja representa el rango intercuartílico (IQR, por sus siglas en
    inglés). El IQR es la diferencia entre el tercer cuartil (Q3) y el primer
    cuartil (Q1) del conjunto de datos. Esto significa que la caja abarca el
    50% central de los datos.
"""
print("Gráficos de caja: ")

# Se crea una lista de valores
datos = [15, 25, 30, 35, 40, 45, 50, 60, 70, 80, 90]

# Esos valores se colocan en el gráfico de caja
plt.boxplot(datos)

# Se le colocan los titulos
plt.ylabel('Valores')
plt.title('Gráfico de Caja')

# Mostrar el gráfico
plt.show()
