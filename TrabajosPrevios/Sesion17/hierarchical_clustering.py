"""
    Es un método de agrupamiento que construye una jerarquía de clusters. En
    lugar de asignar directamente los datos a un número predefinido de
    clusters, este enfoque comienza considerando cada punto como un cluster
    individual y, gradualmente, fusiona o divide clusters según la proximidad
    entre ellos. No requiere que se especifique el número de clusters de
    antemano y puede ser útil para explorar la estructura jerárquica en los
    datos.
"""
# ---------------- # Se instancias las librerías necesarias # --------------- #
import matplotlib.pyplot as plt
from scipy.cluster.hierarchy import dendrogram, linkage
from sklearn.datasets import make_blobs
from sklearn.cluster import AgglomerativeClustering

# -------------------------- # Programa principal # ------------------------- #
# Generar datos de ejemplo, para hacer unas muestras (manchas)
X, y = make_blobs(n_samples=50, centers=3, random_state=42, cluster_std=1.0)

# Configuración de Hierarchical Clustering con enlace completo
Z = linkage(X, method='complete')

# Visualizar el dendrograma
plt.figure(figsize=(10, 5))
dendrogram(Z)
plt.title('Dendrograma Hierarchical Clustering')
plt.xlabel('Índice del Punto de Datos')
plt.ylabel('Distancia')
plt.show()

# Configuración de Hierarchical Clustering con scikit-learn
agg_clustering = AgglomerativeClustering(n_clusters=3)
agg_labels = agg_clustering.fit_predict(X)

# Visualizar resultados
plt.scatter(
    X[:, 0], X[:, 1], c=agg_labels, cmap='viridis', edgecolor='k', s=50)
plt.title('Resultado del clustering Jerárquico')
plt.xlabel('Característica 1')
plt.ylabel('Característica 2')
plt.show()
