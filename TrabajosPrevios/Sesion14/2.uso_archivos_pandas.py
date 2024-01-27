# =========================================================================== #
# Se importa la libería de pandas
import pandas as pd

# =========================================================================== #
""" Usando pandas se hace la lectura de csv """
personas = pd.read_csv("datos/ejemplo.csv")
print(f"\nSe realiza una lectura de un csv con pandas:\n{personas}")

# =========================================================================== #
""" Ahora con los datos del titanic, se leen y se convierten a excel """
print("\nSe muestran los datos del titanic.csv\n")
titanic = pd.read_csv("datos/titanic.csv")
print(titanic)

# Se convienten los datos a archivo de excel .xlsx, necesita "openpyxl"
# titanic.to_excel("titanic.xlsx", sheet_name="passengers", index=False)

# =========================================================================== #
""" Uso de métodos para el DataFrame titanic """
# Por defecto el head solo leé 5
print(f"\nImprime los primeros 8 elementos:\n{titanic.head(8)}")
print(f"\nImprime los titpos de datos del DataFrame:\n{titanic.dtypes}")

# =========================================================================== #
""" Usando pandas se hace la lectura de archivos de excel """
# Se leé el documento creado
print("\nMuestra los datos de titanic.xlsx:")
titanic_excel = pd.read_excel("titanic.xlsx", sheet_name="passengers")

# Muestra la información de este nuevo dataframe
print(f"\nLa info de titanic.xlsx es:\n{titanic_excel.info()}")


# =========================================================================== #
""" Ahora se crea una serie a partir de titanic """
ages = titanic["Age"]   # El nombre de la columna debe existir para funcionar
print(f"\nImprime los primeros 5 elmentos de la serie Age:\n{ages.head()}")

# Se puede averiguar el tipo de dato que es ages:
print(type(ages))

# Se puede averiguar la dimensión de la serie:
print(ages.shape)
