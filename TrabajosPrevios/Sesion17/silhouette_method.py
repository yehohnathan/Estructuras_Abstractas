"""
    Evalua la coherencia de los clusters formados para diferentes valores de k
    y busca el valor de k que maximiza el coeficiente de silueta.
    Valores cercanos a 1 indican clusters bien definidos.

"""
# ---------------- # Se instancias las librerías necesarias # --------------- #
from sklearn.cluster import KMeans
from sklearn.metrics import silhouette_score
import matplotlib.pyplot as plt
import numpy as np

# Para evitar el error de detección de nucleos de mi computadora
import os
os.environ['LOKY_MAX_CPU_COUNT'] = '2'

# -------------------------- # Programa principal # ------------------------- #
# Generar datos aleatorios
np.random.seed(42)  # Para reproducibilidad
X = np.random.rand(100, 2) * 10  # 100 puntos bidimensionales de 0 a 10

# Calcular el coeficiente de silueta para diferentes valores de k
silhouette_scores = []
for k in range(2, 20):
    kmeans = KMeans(n_clusters=k, random_state=42)
    kmeans.fit(X)
    score = silhouette_score(X, kmeans.labels_)
    silhouette_scores.append(score)

# Graficar el metodo de la silueta
plt.plot(range(2, 20), silhouette_scores, marker='o')
plt.title('Método de la Silueta')
plt.xlabel('Número de Clusters (K)')
plt.ylabel('Coeficiente de Silueta')
plt.show()
