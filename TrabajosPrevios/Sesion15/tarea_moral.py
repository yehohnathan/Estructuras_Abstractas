"""
    El código genera un gráfico visualmente que compara dos series de datos
    (valores1 y valores2) mediante barras agrupadas y, al mismo tiempo, muestra
    una línea de tendencia. También agrega etiquetas a las barras y líneas de
    referencia en el eje y para mejorar la interpretación del gráfico.
"""
# Se importan las librerías
import matplotlib.pyplot as plt
import numpy as np

# Definir las categorías y valores para las tres series
categorias = ['A', 'B', 'C', 'D']
valores1 = [15, 8, 12, 10]
valores2 = [12, 10, 15, 7]
tendencia = [11, 9, 13, 9]

# Crear la figura y los ejes
fig, ax = plt.subplots()

# Configuraciones para el gráfico de barras agrupadas
ancho_barra = 0.35
indice = np.arange(len(categorias))

# Gráficos de barras agrupados
bar1 = ax.bar(indice - ancho_barra / 2, valores1, ancho_barra, label="Serie 1",
              color="royalblue")
bar2 = ax.bar(indice + ancho_barra / 2, valores2, ancho_barra, label="Serie 2",
              color="lightcoral")

# Linea de tendencia
ax.plot(indice, tendencia, label="Tendencia", marker="o", color="green")

# Configuraciones adicionales y personalización del gráfico
ax.set_xlabel('Categorías')
ax.set_ylabel('Valores')
ax.set_title('Gráfico de Barras Agrupadas con Tendencia')
ax.set_xticks(indice)
ax.set_xticklabels(categorias)
ax.legend()

# Añadir etiquetas en las barras
for bar in [bar1, bar2]:
    for rect in bar:
        height = rect.get_height()
        ax.annotate('{}'.format(height),
                    xy=(rect.get_x() + rect.get_width() / 2, height),
                    xytext=(0, 3),
                    textcoords="offset points",
                    ha='center', va='bottom')

# Mostrar líneas de referencia en el eje y (grid)
plt.grid(axis='y', linestyle='--', alpha=0.7)

# Ajustar el diseño del gráfico para que se vea mejor
plt.tight_layout()

# Mostrar el gráfico
plt.show()
