"""
    Sirve para evitar el sobreajuste y mejorar la generalización del modelo.
    ¿Cúando preferir un polinomio de grado 2 frente a uno de grado superior?
"""
# ---------------- # Se importan las librerías del sistema # ---------------- #
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression, Lasso, Ridge
from sklearn.preprocessing import PolynomialFeatures
from sklearn.pipeline import make_pipeline

# -------------------------- # Programa principal # ------------------------- #
# Generar datos de ejemplo no lineales
np.random.seed(42)
X = 2 * np.random.rand(100, 1)
y = 0.5 * X**2 + X + 2 + np.random.randn(100, 1)

# Dividir en conjuntos de entrenamiento y prueba
X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42)

# Crear modelo de regresión polinómica de grado 2
modelo_polinomico = make_pipeline(PolynomialFeatures(degree=2),
                                  LinearRegression())
modelo_polinomico.fit(X_train, y_train)

# Crear modelo Lasso (l1)
modelo_lasso = make_pipeline(PolynomialFeatures(degree=2), Lasso(alpha=0.1))
modelo_lasso.fit(X_train, y_train)

# Cream modelo Ridge (l2)
modelo_ridge = make_pipeline(PolynomialFeatures(degree=2), Ridge(alpha=0.1))
modelo_ridge.fit(X_train, y_train)

# Visualizar los resultados
X_test_sorted, y_pred_polinomico_sorted = \
    zip(*sorted(zip(X_test, modelo_polinomico.predict(X_test))))
X_test_sorted, y_pred_lasso_sorted = \
    zip(*sorted(zip(X_test, modelo_lasso.predict(X_test))))
X_test_sorted, y_pred_ridge_sorted = \
    zip(*sorted(zip(X_test, modelo_ridge.predict(X_test))))


plt.scatter(X_test, y_test, label='Datos de prueba', color='blue')
plt.plot(X_test_sorted, y_pred_polinomico_sorted,
         label='Regresión Polinómica', color='green')
plt.plot(X_test_sorted, y_pred_lasso_sorted,
         label='Lasso (L1)', color='red')
plt.plot(X_test_sorted, y_pred_ridge_sorted,
         label='Ridge (L2)', color='orange')

plt.title('Comparación de Modelos con Regularización')
plt.xlabel('x')
plt.ylabel('y')
plt.legend()
plt.show()
