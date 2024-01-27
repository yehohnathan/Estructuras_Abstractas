# =========================================================================== #
# Se importa la libería de pandas
import pandas as pd

# =========================================================================== #
""" Un DataFrame es lo que tiene filas y columnas, como excel """
# Se crea un diccionario, y lo convierto en DataFrame con pandas
df = pd.DataFrame(
    {
        "Name": [
            "Braud, Mr. Owen Harris",
            "Allen, Mr. William Henry",
            "Bonnel, Miss. Elizabeth"
        ],
        "Age": [22, 32, 58],
        "Sex": ["male", "male", "female"]
    }
)


# Se muestra el contenido del dataframe:
print(f"Se imprime el DataFrame creado:\n{df}")

# =========================================================================== #
"""Ahora se crea una serie en pandas, no tiene columnas """
# Se crea una serie y se le asigna un nombre y contenido
ages = pd.Series([22, 35, 52], name="Age")
print(f"\nSe impreme la serie creada:\n{ages}")

# Se calcula el punto máximo de la serie:
print(f"\nLa edad máxima registrada en la serie es: {ages.max()}")

# Se imprime la columna Age del DataFrame df
print(f"\nSe imprime una serie/columna a partir del DataFrame:\n{df["Age"]}")

# Se calcula el punto máximo de la serie:
print(f"\nLa edad máxima registrada en la columna es: {df["Age"].max()}")

# =========================================================================== #
""" Se usa describe() para descripción rápida de datos númericos """
print(f"\nDescripción numérica del DataFrame:\n{df.describe()}")
print(f"\nDescripción numérica de la Serie:\n{ages.describe()}")
