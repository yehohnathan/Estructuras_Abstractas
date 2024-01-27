"""
    Para no saturar la cantidad de gráficas de un archivo, este se usa para:
        - Colores y estilos
        - Anotaciones
        - Subtramas
        - Gráficas seno y coseno
        - Juntar dos tipos de gráficas
        - Gráfico de barras con grid
"""

# =========================================================================== #
import matplotlib.pyplot as plt     # Se importa un único método
import numpy as np                  # Para trigonometría

# =========================================================================== #
print("Gráfica de linea puntuada:")

# Datos de ejemplo para x,y
x = [1, 2, 3, 4, 5]
y = [10, 12, 5, 8, 14]

# Crear un gráfico de línea personalizado con colores, estilos y marcadores
plt.plot(x, y, color='blue', linestyle='--', marker='o', label='Serie A')

# Personalización de titulos y banderas
plt.xlabel('Eje X')
plt.ylabel('Eje Y')
plt.title('Gráfico Personalizado')
plt.legend()

# Mostrar el gráfico
plt.show()

# =========================================================================== #
print("Anotaciones en gráfico de linea: flecha apuntando al máximo")

# Datos de ejemplo para x,y
x = [1, 2, 3, 4, 5]
y = [10, 12, 5, 8, 14]

# Crear un gráfico de línea con una bandera
plt.plot(x, y, label='Datos de ejemplo')

# Añadir una anotación que apunte al valor máximo
plt.annotate('Valor Máximo', xy=(5, 14), xytext=(3, 16),
             arrowprops=dict(facecolor='black', shrink=0.05))

# Personalización adicional, como etiquetas de ejes y títulos
plt.xlabel('Eje X')
plt.ylabel('Eje Y')
plt.title('Gráfico con Anotación')
plt.legend()

# Mostrar el gráfico
plt.show()

# =========================================================================== #
print("Subtramas en gráficos de linea:")

# Datos de ejemplo para x, y1 e y2
x = [1, 2, 3, 4, 5]
y1 = [10, 12, 5, 8, 14]
y2 = [5, 8, 9, 6, 10]

# Se crean las dos subratramas
fig, axs = plt.subplots(1, 2)   # 1 fila, 2 columnas (dos gráficas)

# Gráfico en la primera subtrama
axs[0].plot(x, y1, label='Serie A')     # Nombre de gráfica
axs[0].set_title('Subtrama 1')

# Gráfico en la segunda subtrama
axs[1].plot(x, y2, label='Serie B', color='red')    # Nombre y color gráfica
axs[1].set_title('Subtrama 2')

# Personalización adicional, como etiquetas de ejes y títulos para ambas
# gráficas lineales
for ax in axs:
    ax.set_xlabel('Eje X')
    ax.set_ylabel('Eje Y')
    ax.legend()

# Ajustar la disposición
plt.tight_layout()

# Mostrar la figura con las subtramas
plt.show()

# =========================================================================== #
print("Gráficas trigonométricas:")

# Generar datos de ejemplo para ambas funciones trigonométricas
x = np.linspace(0, 2*np.pi, 100)    # Valor interior de la función
y1 = np.sin(x)      # Se carga en la función sen
y2 = np.cos(x)      # Se carga en la función cos

# Crear un gráfico de líneas con dos series de datos, con banderas
plt.plot(x, y1, label='Seno')
plt.plot(x, y2, label='Coseno')

# Personalización de titulos y ejees, muestra también la banderas
plt.xlabel('Ángulo (rad)')
plt.ylabel('Valor')
plt.title('Funciones Seno y Coseno')
plt.legend()

# Mostrar el gráfico
plt.show()

# =========================================================================== #
print("Gráfico de barras junto a gráfico lineal:")

# Datos de ejemplo para ambas gráficas
categorias = ['A', 'B', 'C', 'D']
valores = [15, 8, 12, 10]
tendencia = [5, 10, 8, 13]

# Crear una figura con dos subtramas con un tamaño predefinido
fig, axs = plt.subplots(1, 2, figsize=(10, 4))  # Dos gráficas

# Subtrama 1: Gráfico de barras, color y titulo
axs[0].bar(categorias, valores, color='royalblue')
axs[0].set_title('Gráfico de Barras')

# Subtrama 2: Gráfico de linea, color y titulo
axs[1].plot(categorias, tendencia, color='green', marker='o')
axs[1].set_title('Gráfico de Línea')

# Personalización adicional para ambas subtramas
for ax in axs:
    ax.set_xlabel('Categorías')
    ax.set_ylabel('Valores')

# Ajustar la disposición
plt.tight_layout()

# Mostrar la figura con ambas subtramas
plt.show()

# =========================================================================== #
print("Gráfica de barras editada:")

# Datos de ejemplo para etiquetas y valores de las barras
categorias = ['A', 'B', 'C', 'D']
valores = [15, 8, 12, 10]

# Crear un gráfico de barras
plt.bar(categorias, valores, color='royalblue', edgecolor='black')

# Personalizacion de nombres, tamaños y ejes
plt.xlabel('Categorias', fontsize=12)
plt.ylabel('Valores', fontsize=12)
plt.title('Gráfico de Barras', fontsize=14)
plt.xticks(rotation=45)     # Rota las categorias 45 grados
plt.grid(axis='y', linestyle='--', alpha=0.7)

# Añadir etiquetas en las barras
for i, v in enumerate(valores):
    plt.text(i, v + 0.5, str(v), ha='center', va='bottom', fontsize=10)

# Mostrar el gráfico
plt.show()
