"""
    A partir del archivo titanic.csv hacer otros DataFrames
"""

import pandas as pd

# Se crea un DataFrame titanic
titanic = pd.read_csv("datos/titanic.csv")


# =========================================================================== #
""" A partir de titanic se crean otros DF con información selecta """
# A partir de dos columnas:
print("Sea crea un df con las columnas Age y Sex:")
age_sex = titanic[["Age", "Sex"]]
print(age_sex.head())
print(type(age_sex))    # Tipo de dato del nuevo df
print(age_sex.shape)    # Dimensión del df

# A partir de un filtro todos los datos a partir de una sola columna
print("\nSe crea un df con todos los datos que tengan un Age > 35:")
above_35 = titanic[titanic["Age"] > 35]
print(above_35.head())
print(above_35.shape)

# Filtrar todos los datos que en Pclass tengan un dos o un 3
print("\ndf con todos los datos con un Pclass 2 o 3:")
class_23 = titanic[titanic["Pclass"].isin([2, 3])]
#        = [titanic["Pclass"] == 2 | titanic["Pclass"] == 3]
print(class_23.head())

# Filtra unicamente los elementos de Age que si tengan un valor numérico
print("\ndf con todos los datos donde Age si sea un valor numérico:")
age_no_na = titanic[titanic["Age"].notna()]
print(age_no_na.head())
print(age_no_na.shape)

# Filtrado por condiciones de fila y columna. Solo la columna Name
adult_name = titanic.loc[titanic["Age"] > 35, "Name"]
print("\ndf de los nombres de las personas cuya edad es mayor a 35:")
print(adult_name.head())

# Filtrado utilizando indices con iloc
print("\nUnicamente muestra las filas 9 a 25, columnas 2 a 5 de titanic.csv")
print(titanic.iloc[9:25, 2:5])

# También se pueden modificar datos, columna 3 (Name)
titanic.iloc[0:3, 3] = "anonymous"  # En filas del 0 al 3
