"""
    Grafica la varianza explicada en función de k y buscar el codo de la curva
    y busca el punto en el que la inercia deja de disminuir rápidamente,
    formando un codo en la gráfica. Ese valor de k es una buena elección.
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
np.random.seed(42)  # Para reproducibilidad
X = np.random.rand(100, 2) * 10  # 100 puntos bidimensionales de 0 a 10

# Calcular la inercia para diferentes valores de k
inertias = []
for k in range(1, 11):
    kmeans = KMeans(n_clusters=k, random_state=42)
    kmeans.fit(X)
    inertias.append(kmeans.inertia_)

# Graficar el método del codo
plt.plot(range(1, 11), inertias, marker='o')
plt.title('Método del Codo')
plt.xlabel('Número de Clusters (k)')
plt.ylabel('Inercia')
plt.show()

# Segun la gráfica nos podríamos quedar con 3 o 4 clusters
