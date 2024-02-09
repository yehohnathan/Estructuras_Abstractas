import requests
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_squared_error

# Cargar datos
# Obtener datos de https://raw.githubusercontent.com/ageron/handson-ml/master/datasets/housing/housing.csv
# y almacenarlos en data/dataset.csv
# URL del archivo CSV

# Creación del csv:
url = "https://raw.githubusercontent.com/ageron/handson-ml/master/datasets/housing/housing.csv"
df = pd.read_csv(url)
df.to_csv("dataset.csv", index=False)

# Se leé el csv creado
data = pd.read_csv("dataset.csv")

# -----------
#     1
# -----------

X_simple = data['median_income'].values.reshape(-1, 1)
y_simple = data['median_house_value'].values


X_train, X_test, y_train, y_test = train_test_split(X_simple, y_simple, test_size=0.2, random_state=42)


model_simple = LinearRegression()
model_simple.fit(X_train, y_train)


y_pred_simple = model_simple.predict(X_test)


mse_simple = mean_squared_error(y_test, y_pred_simple)
print(f"Error cuadrático medio (MSE) en regresión lineal simple: {mse_simple}")

# -----------
#     2
# -----------

X_multiple = data[['median_income', 'housing_median_age', 'population']]
y_multiple = data['median_house_value'].values


X_train_multi, X_test_multi, y_train_multi, y_test_multi = train_test_split(X_multiple, y_multiple, test_size=0.2, random_state=42)


model_multiple = LinearRegression()
model_multiple.fit(X_train_multi, y_train_multi)


y_pred_multiple = model_multiple.predict(X_test_multi)


mse_multiple = mean_squared_error(y_test_multi, y_pred_multiple)
print(f"Error cuadrático medio (MSE) en regresión lineal múltiple: {mse_multiple}")

# -----------
#     3
# -----------
from sklearn.preprocessing import PolynomialFeatures
from sklearn.pipeline import make_pipeline


X_nonlinear = data['housing_median_age'].values.reshape(-1, 1)
y_nonlinear = data['median_house_value'].values


X_train_nonlinear, X_test_nonlinear, y_train_nonlinear, y_test_nonlinear = train_test_split(X_nonlinear, y_nonlinear, test_size=0.2, random_state=42)


degree = 2
model_nonlinear = make_pipeline(PolynomialFeatures(degree), LinearRegression())
model_nonlinear.fit(X_train_nonlinear, y_train_nonlinear)


y_pred_nonlinear = model_nonlinear.predict(X_test_nonlinear)


mse_nonlinear = mean_squared_error(y_test_nonlinear, y_pred_nonlinear)
print(f"Error cuadrático medio (MSE) en regresión no lineal: {mse_nonlinear}")

# -----------
#     4
# -----------
from sklearn.linear_model import Ridge, Lasso


model_ridge = Ridge(alpha=1.0)
model_ridge.fit(X_train_multi, y_train_multi)


model_lasso = Lasso(alpha=1.0)
model_lasso.fit(X_train_multi, y_train_multi)

# -----------
#     5
# -----------
from sklearn.cluster import KMeans, DBSCAN
import matplotlib.pyplot as plt

# Se extraen los datos de dos columnas de data (que proviene del url)
X_cluster = data[['longitude', 'latitude']]

# =============================================================================== #
# n_clusters = 3, cantidad grupos
# random
# n_init inicializa 10 veces Kmeans con semillas aleatorias
kmeans = KMeans(n_clusters=3, random_state=42, n_init=10)

# Se crea una nueva columna con el nombre de "clusters_kmeans" con los datos
# del entrenamiento de predicción del kmeans (configurado)
data['cluster_kmeans'] = kmeans.fit_predict(X_cluster)

# Primera gráfica de dispersión con los datos de las columnas longitude y latitude,
# c=data['cluster_kmeans'] colorea los datos de la gráfica a partir del modelo de
# entramiento de 3 clusters obtenido
# cmap para definir la paleta de colores
plt.scatter(data['longitude'], data['latitude'], c=data['cluster_kmeans'], cmap='viridis', marker='.')
plt.title('Clusters usando K-means')
plt.show()

# =============================================================================== #
# Radio del vecindario alrededor de un punto 0.5, distancia entre dos puntos
# min_samples número minimo de puntos que deben estar dentro de la distncia de eps
# para que se considere un punto central, sino se clasifica como ruido
dbscan = DBSCAN(eps=0.5, min_samples=5)

# A cada dato se le asigna un número de cluster
data['cluster_dbscan'] = dbscan.fit_predict(X_cluster)

# Segunda gráfica
plt.scatter(data['longitude'], data['latitude'], c=data['cluster_dbscan'], cmap='viridis', marker='.')
plt.title('Clusters usando DBSCAN')
plt.show()

# Explicación: los puntos amarillos representan un cluster. Los puntos oscuros
# parecen ser ruido o valores atípicos, ya que no forman parte del cluster.
