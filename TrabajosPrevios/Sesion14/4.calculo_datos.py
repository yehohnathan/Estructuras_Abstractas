"""
    A partir del archivo titanic.csv calcular valores estadisticos
"""

import pandas as pd

# Se crea un DataFrame titanic
titanic = pd.read_csv("datos/titanic.csv")


# =========================================================================== #
print(f"Media de Age: {titanic["Age"].mean()}")
print(f"\nMediana de Age y Fare:\n{titanic[["Age", "Fare"]].median()}")
print(f"\nInformación de Age y Fare:\n{titanic[["Age", "Fare"]].describe()}")

# Que realice una agregación de Age y Fare
age_fare = titanic.agg(
    {
        "Age": ["min", "max", "median", "skew"],
        "Fare": ["min", "max", "median", "mean"]
    }
)
print(f"\nMuestra valores especificos de Age y Fare:\n{age_fare}")

# Filtra Sex y Age, agrupa por Sex y saca la media
print(f"\nMedia de Age agrupado por Sex: \
      \n{titanic[["Sex", "Age"]].groupby("Sex").mean()}")

# Agrupando por Sex y Pclass, se calcula la media de Fare
print(f"\nAgrupa Sex y Pclass, calcula la media de Fare: \
      \n{titanic.groupby(["Sex", "Pclass"])["Fare"].mean()}")

# Agrupa Sex y calcula la media en aquellos que si hay valor numérico
print(f"\nAgrupa Sex y calcula la media de los datos: \
      \n{titanic.groupby("Sex").mean(numeric_only=True)}")

# Agrupa Sex y calcula la media para Age
print(f"\nAgrupa Sex y calcula la media de Age: \
      \n{titanic.groupby("Sex")["Age"].mean()}")

# Cuente los valores de Pclass
print(f"\nCuente los valores de Pclass: \
      \n{titanic["Pclass"].value_counts()}")

# Cuente los valores de Pclass pero agrupados
print(f"\nCuente los valores de Pclass pero agrupados: \
      \n{titanic.groupby("Pclass")["Pclass"].value_counts()}")

# Ordene los valores por edad
print(f"\nOrdena los datos por Edad: \
      \n{titanic.sort_values(by="Age").head()}")

# Ordene los valores por Pclass y Age
print(f"\nOrdena los datos Pclass y Age de forma desendente: \
      \n{titanic.sort_values(by=["Pclass", "Age"], ascending=False).head()}")
