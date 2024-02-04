"""
    K-means: método de agrupación que busca dividir un conjunto de datos en
    k grupos basándose en la similitud de las observaciones. El proceso consta
    de los siguientes pasos:

        1. Inicialización de centroides: Se seleccionan aleatoriamente k puntos
        como centroides iniciales, donde k es el número predefinido de clusters

        2. Asignación de puntos a clusters: Cada punto de datos se asigna al
        cluster cuyo centroide está más cercano

        3. Actualización de centroides: Se recalcula el centroide de cada
        cluster como el promedio de todos los puntos asignados a ese cluster.

        4. Repetición: Los pasos 2 y 3 se repiten hasta que no haya cambios
        significativos en la asignación de puntos a clusters o se alcanza
        un número máximo de iteraciones.

        5. Resultado final: Se obtienen k clusters con centroides
        representativos
"""
# ---------------- # Se instancias las librerías necesarias # --------------- #
from sklearn.cluster import KMeans
import numpy as np
import matplotlib.pyplot as plt

# Para evitar el error de detección de nucleos de mi computadora
import os
os.environ['LOKY_MAX_CPU_COUNT'] = '2'

# -------------------------- # Programa principal # ------------------------- #
# Generar datos aleatorios
np.random.seed(67)                  # Para la reproducibilidad
X = np.random.rand(100, 2) * 10     # 100 puntos bidimensionales de 0 a 10

# Configurar subgráficos
plt.figure(figsize=(12, 5))

# Subgráfico 1: Visualización de puntos de datos aleatorios
plt.subplot(1, 2, 1)
plt.scatter(X[:, 0], X[:, 1], c="blue", marker="o")
plt.title("Puntos de Datos Aleatorios")
plt.xlabel("Característica 1")
plt.ylabel("Característica 2")

# Configuración de K-Means con un número de clusters (k) específico
kmeans = KMeans(n_clusters=3)

# Ajuste del modelo
kmeans.fit(X)

# Etiquetas de los clusters y coordenadas de los centroides
labels = kmeans.labels_
centroids = kmeans.cluster_centers_

# Subgráfico 2: Resultado del clustering con K-Means. Datos ya agrupados
plt.subplot(1, 2, 2)
for i in range(len(X)):
    plt.scatter(X[i][0], X[i][1],
                c=("r" if labels[i] == 0 else "b" if labels[i] == 1 else "g"),
                marker="o")

plt.scatter(centroids[:, 0], centroids[:, 1], c="black", marker="x", s=200,
            label="Centroids")
plt.title("Resultado del Clustering con K-Means")
plt.xlabel("Característica 1")
plt.legend()
plt.ylabel("Característica :2")

# Ajustar el diseño para evitar solapamientos
plt.tight_layout()

# Mostrar los subgráficos
plt.show()
