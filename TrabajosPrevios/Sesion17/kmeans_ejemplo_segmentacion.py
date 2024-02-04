"""
    Ejemplo de K-Means

    ** El csv utilizado se genero con un código de python con números
       aleatorios
"""

# 1. Preparación de dados. Se cargan los datos que contiene información con la
# que se va a trabajar
from sklearn.preprocessing import StandardScaler
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

# Para evitar el error de detección de nucleos de mi computadora
import os
os.environ['LOKY_MAX_CPU_COUNT'] = '2'

# Conjunto de datos
data = pd.read_csv('data.csv')

# 2. Exploración y preprocesamiento. Se explorar y preprocesan los datos según
# sea necesario, como la presencia de N/A.
print(data.head())

# Preprocesamiento
scaler = StandardScaler()
scaled_data = scaler.fit_transform(data)


# 3. Selección de número de clusters, en este caso se utiliza el Elbow Method
inertia = []
for k in range(1, 11):
    kmeans = KMeans(n_clusters=k, random_state=42)
    kmeans.fit(scaled_data)
    inertia.append(kmeans.inertia_)

# Graficar el Método del Codo
plt.plot(range(1, 11), inertia, marker='o')
plt.title('Método del Codo para Selección de k')
plt.xlabel('Número de Clusters (k)')
plt.ylabel('Inercia')
plt.show()

# 4. Se ajusta el modelo de K-Means con el mejor número de clusters observados
# mediante el método escogido, en este caso se escoje 4 clusters,
kmeans = KMeans(n_clusters=4, random_state=42)
cluster_labels = kmeans.fit_predict(scaled_data)

# Agregamos las etiquetas de cluster al conjunto de datos original
data['Cluster'] = cluster_labels

# 5. Se analiza y se describe los segmentos de clientes identificados
segment_analysis = data.groupby('Cluster').mean()

# Visualización de segmentos
plt.figure(figsize=(12, 6))
for cluster in range(4):
    plt.scatter(data[data['Cluster'] == cluster]['Frequency'],
                data[data['Cluster'] == cluster]['Avg_Spend'],
                label=f'Cluster {cluster}')

plt.title('Segmentación de Clientes por Frecuencia y Gasto Promedio')
plt.xlabel('Frecuencia de Visita')
plt.ylabel('Gasto Promedio')
plt.legend()
plt.show()
