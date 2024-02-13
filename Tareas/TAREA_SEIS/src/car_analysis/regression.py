# ----------------- # Librerias Sklearn para regresiones # ------------------ #
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_absolute_error, mean_squared_error

# ------------------------- # Librerías auxiliares # ------------------------ #
import matplotlib.pyplot as plt     # Realiza gráficas
import pandas as pd                 # Para uso de csv


# --------------------- # Clase para Regresion Lineal # --------------------- #
class RegresionLineal():
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

        # Métricas de rendimiento de la regresión lineal
        mse_simple = mean_squared_error(y_test, y_pred_simple)
        print("Error cuadrático medio (MSE) en regresión lineal simple:",
              mse_simple)

        mae_simple = mean_absolute_error(y_test, y_pred_simple)
        print("Error absoluto medio (MAE) en regresión lineal simple:",
              mae_simple)

        # Gráfica de la regresión lineal con una gráfica de dispersión
        plt.scatter(X_test, y_test)
        plt.plot(X_test, y_pred_simple, color='purple', linewidth=3)
        plt.title('Regresion Lineal')
        plt.xlabel(xlabel)
        plt.ylabel(ylabel)
        plt.show()
