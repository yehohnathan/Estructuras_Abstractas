"""
    Técnica estadística utilizada para modelar y analizar la relación entre
    una variable dependiente y otras variables independientes. Su objetivo
    principal es entender la relación de estas.

    Una regresión lineal se la relación de una unica variable independiente y
    una variable de salida. Se asume que la relación es una linea recta
"""
# ---------------- # Se importan las librerías del sistema # ---------------- #
import numpy as np                  # Para operaciones matemáticas
import matplotlib.pyplot as plt     # Realiza gráficas
from sklearn.linear_model import LinearRegression   # Metodos regresión lineal


# Generar datos de ejemplo mediante una semilla específica de numpy
np.random.seed(50)
X = 2 * np.random.rand(100, 1)
y = 4 + 3 * X + np.random.randn(100, 1)

# Crear un modelo (objeto) de regresion lineal
modelo = LinearRegression()

# Ajustar el modelo mediante el método fit y le paso los parámetros X e y
modelo.fit(X, y)

# Imprimir coeficiente e intercepcion (atributos)
print("Coeficiente:", modelo.coef_[0][0])
print("Intercepcion:", modelo.intercept_[0])

# Se visualiza la regresión lineal mediante matplotlib
plt.scatter(X, y)
plt.plot(X, modelo.predict(X), color='red', linewidth=3)
plt.title('Regresion Lineal')
plt.xlabel('X')
plt.ylabel('Y')
plt.show()
