# ------------------ # Librerias Sklearn para clustering # ------------------ #
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import silhouette_score

# ------------------------- # Librerías auxiliares # ------------------------ #
import matplotlib.pyplot as plt     # Realiza gráficas
import pandas as pd                 # Para uso de csv
import numpy as np

# Para evitar el error de detección de nucleos de mi computadora
import os
os.environ['LOKY_MAX_CPU_COUNT'] = '2'


# ------------------------ # Clase para Clustering # ------------------------ #
class Clusters:
    def __init__(self) -> None:
        self.__dataframe = pd.DataFrame()

    def setDataFrame(self, dataframe):
        # Verifica si dataframe es algo diferente a lo esperado
        if not isinstance(dataframe, pd.core.frame.DataFrame):
            raise ValueError("\nNo se ingresó un DataFrame.")
        self.__dataframe = dataframe

    def __verificador_columnas(self, colum1, colum2):
        # Verifica que colum1, colum2, xlabel y ylabel sean tipo string
        var_list = [colum1, colum2]
        for var in var_list:
            if not isinstance(var, str):
                raise ValueError("Se ingreso un dato que no es una cadena de",
                                 " texto.")

        # Verificar que colum1 y colum2 sean nombres de columnas válidos dentro
        # del DataFrame
        if colum1 not in self.__dataframe.columns:
            raise ValueError("La columna 1 no existe dentro del DataFrame.")
        if colum2 not in self.__dataframe.columns:
            raise ValueError("La columna 2 no existe dentro del DataFrame.")

    def metodo_elbow(self, colum1, colum2):
        self.__verificador_columnas(colum1, colum2)

        # Se selecciona las dos columas que se quieren utilizar
        data = self.__dataframe[[colum1, colum2]]

        # Promesamiento de los datos, para crear un ajuste bidimensional
        scaler = StandardScaler()                   # Crea un objeto
        scaler_data = scaler.fit_transform(data)    # Entrena los datos

        # Selección del número de clusters usando el método Elbow
        inercia = []
        for k in range(1, 11):
            kmeans = KMeans(n_clusters=k, random_state=42)
            kmeans.fit(scaler_data)
            inercia.append(kmeans.inertia_)

        # Graficar el Método del Codo
        plt.plot(range(1, 11), inercia, marker='o')
        plt.title('Método del Codo para Selección de k')
        plt.xlabel('Número de Clusters (k)')
        plt.ylabel('Inercia')
        plt.show()
        pass

    def metodo_silhouette(self, colum1, colum2):
        self.__verificador_columnas(colum1, colum2)

        # Se selecciona las dos columas que se quieren utilizar.
        data = self.__dataframe[[colum1, colum2]]

        # Promesamiento de los datos, para crear un ajuste bidimensional
        scaler = StandardScaler()                   # Crea un objeto
        scaler_data = scaler.fit_transform(data)    # Entrena los datos

        # Calcular el coeficiente de silueta para diferentes valores de k
        silhouette_scores = []
        for k in range(2, 20):
            kmeans = KMeans(n_clusters=k, random_state=42)
            kmeans.fit(scaler_data)
            score = silhouette_score(scaler_data, kmeans.labels_)
            silhouette_scores.append(score)

        # Encontrar el valor de K con el puntaje de silueta más alto
        mejor_k = np.argmax(silhouette_scores) + 2  # Suma porque empieza en 2
        mejor_puntuacion = silhouette_scores[mejor_k - 2]

        # Se le muestra al usuario el resultado
        print(f"Valor de K con mejor coeficiente: {mejor_k}")

        # Graficar el método de la silueta
        plt.plot(range(2, 20), silhouette_scores, marker='o',
                 label=f"K={mejor_k}, Coeficiente={mejor_puntuacion:.2f}")
        plt.title('Método de la Silueta')
        plt.xlabel('Número de Clusters (K)')
        plt.ylabel('Coeficiente de Silueta')
        plt.legend()
        plt.show()

        # Retorna el valor de k clusters
        return int(mejor_k)

    def grafica_KMeans(self, colum1, colum2, xlabel, ylabel, k_clusters):
        self.__verificador_columnas(colum1, colum2)

        # Verifica que el número de clusters sea permitido
        if not isinstance(k_clusters, int):
            raise ValueError("El número de clusters debe ser entero.")
        if k_clusters < 1:
            raise ValueError("El número de clusters debe ser mayor a 1.")

        # Se selecciona las dos columas que se quieren utilizar.
        data = self.__dataframe[[colum1, colum2]]

        # n_init inicializa 10 veces Kmeans con semillas aleatorias
        # nuevo de clusters decidido por k_clusters
        kmeans = KMeans(n_clusters=k_clusters, random_state=42, n_init=10)

        # Se crea una nueva columna con el nombre de "clusters_kmeans" con los
        # datos del entrenamiento de predicción del kmeans (configurado)
        self.__dataframe['cluster_kmeans'] = kmeans.fit_predict(data)

        # Graficar el KMeans
        plt.scatter(self.__dataframe[colum1], self.__dataframe[colum2],
                    c=self.__dataframe['cluster_kmeans'],
                    cmap='viridis', marker='.')
        plt.title('Clusters usando K-means')
        plt.xlabel(str(xlabel))
        plt.ylabel(str(ylabel))
        plt.show()
