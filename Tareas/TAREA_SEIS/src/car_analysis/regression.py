# ----------------- # Librerias Sklearn para regresiones # ------------------ #
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.preprocessing import PolynomialFeatures
from sklearn.pipeline import make_pipeline
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score

# ------------------------- # Librerías auxiliares # ------------------------ #
import matplotlib.pyplot as plt     # Realiza gráficas
import numpy as np
import pandas as pd                 # Para uso de csv


# ------------------------ # Clase para Regresiones # ----------------------- #
class Regresiones():
    def __init__(self) -> None:
        self.__dataframe = pd.DataFrame()

    def setDataFrame(self, dataframe):
        # Verifica si dataframe es algo diferente a lo esperado
        if not isinstance(dataframe, pd.core.frame.DataFrame):
            raise ValueError("\nNo se ingresó un DataFrame.")
        self.__dataframe = dataframe

    def regresion_lineal_simple(self, colum1, colum2, xlabel, ylabel):
        # Verifica que colum1, colum2, xlabel y ylabel sean tipo string
        var_list = [colum1, colum2, xlabel, ylabel]
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

        # Se extraen los datos para la variable dependiente
        X_simple = self.__dataframe[colum1].values.reshape(-1, 1)
        # Se extraen los datos para la variable independiente
        y_simple = self.__dataframe[colum2].values

        # Luego se crean los datos de entrenamiento y prueba
        X_train, X_test, y_train, y_test = train_test_split(X_simple, y_simple,
                                                            test_size=0.2,
                                                            random_state=42)

        # Se crea un objeto la regresión lineal simple
        model_simple = LinearRegression()

        # Se entrenan los datos con el método fit
        model_simple.fit(X_train, y_train)

        # Se realizan predicciones sobre los datos de prueba
        y_pred_simple = model_simple.predict(X_test)

        # Mensaje al usuario:
        # Métricas de rendimiento de la regresión lineal
        mse_simple = mean_squared_error(y_test, y_pred_simple)
        print("Error cuadrático medio (MSE) en regresión lineal simple:",
              mse_simple)

        r2_simple = r2_score(y_test, y_pred_simple)
        print("Coeficiente de determinación (R^2) en regresión lineal simple:",
              r2_simple)

        mae_simple = mean_absolute_error(y_test, y_pred_simple)
        print("Error absoluto medio (MAE) en regresión lineal simple:",
              mae_simple)

        # Gráfica de la regresión lineal con una gráfica de dispersión
        plt.scatter(X_test, y_test, label="Datos de prueba", color="blue")
        plt.plot(X_test, y_pred_simple,
                 label=f"Regresion Lineal (R^2={r2_simple:.2f})",
                 color='red', linewidth=3)
        plt.title('Regresion Lineal')
        plt.xlabel(xlabel)
        plt.ylabel(ylabel)
        plt.legend()
        plt.show()

    def regresion_no_lineal_polinomica(self, colum1, colum2, xlabel, ylabel,
                                       grado=2):
        # Verifica que colum1, colum2, xlabel y ylabel sean tipo string
        var_list = [colum1, colum2, xlabel, ylabel]
        for var in var_list:
            if not isinstance(var, str):
                raise ValueError("Se ingreso un dato que no es una cadena de",
                                 " texto.")

        # Verifica si el grado es un número entero mayor que 2, para que
        # funcione la regresion no lineal
        if not isinstance(grado, int):
            raise ValueError("No se ingreso un número entero al grado.")
        elif grado < 2:
            raise ValueError("El valor del grado polinómico debe ser mayor",
                             "a 2")
        # Verificar que colum1 y colum2 sean nombres de columnas válidos dentro
        # del DataFrame
        if colum1 not in self.__dataframe.columns:
            raise ValueError("La columna 1 no existe dentro del DataFrame.")
        if colum2 not in self.__dataframe.columns:
            raise ValueError("La columna 2 no existe dentro del DataFrame.")

        # Se extraen los datos para la variable dependiente
        X_simple = self.__dataframe[colum1].values.reshape(-1, 1)
        # Se extraen los datos para la variable independiente
        y_simple = self.__dataframe[colum2].values

        # Luego se crean los datos de entrenamiento y prueba
        X_train, X_test, y_train, y_test = train_test_split(X_simple, y_simple,
                                                            test_size=0.2,
                                                            random_state=42)

        # Se crea el modelo de regresión polinómica
        model_poly = make_pipeline(PolynomialFeatures(grado),
                                   LinearRegression())

        # Se entrenan los datos con el método fit
        model_poly.fit(X_train, y_train)

        # Se genera un rango continuo de valores de X_test para predecir
        X_range = np.linspace(X_test.min(),
                              X_test.max(),
                              len(self.__dataframe)).reshape(-1, 1)

        # Se realizan predicciones sobre el rango X_range
        y_pred_range = model_poly.predict(X_range)

        # Mensaje al usuario:
        # Métricas de rendimiento de la regresión lineal
        mse_poly = mean_squared_error(y_test, model_poly.predict(X_test))
        print("Error cuadrático medio (MSE) en regresión no lineal:",
              mse_poly)

        r2_poly = r2_score(y_test, model_poly.predict(X_test))
        print("Coeficiente de determinación (R^2) en regresión no lineal:",
              r2_poly)

        mae_poly = mean_absolute_error(y_test, model_poly.predict(X_test))
        print("Error absoluto medio (MAE) en regresión no lineal:",
              mae_poly)

        # Gráfica de la regresión no lineal con una gráfica de dispersión
        plt.scatter(X_test, y_test, label="Datos de prueba", color="green")
        plt.plot(X_range, y_pred_range,  # Sobre el rango para una sola recta
                 label=f"Regresion no lineal (R^2={r2_poly:.2f})",
                 color="purple", linewidth=3)
        plt.title(f"Regresion No Lineal Polinómica (Grado {grado})")
        plt.xlabel(xlabel)
        plt.ylabel(ylabel)
        plt.legend()
        plt.show()
