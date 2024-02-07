# ----- # Se importan las librerías necesaroas para Parte Práctica 2 # ----- #
import pandas as pd     # Para crear el conjunto de datos
import numpy as np      # Para el uso de funciones matemáticas
np.random.seed(50)      # Se selecicona una seed para los números random
# ------------------------- # Programa Principal # ------------------------- #
print("\n=================== Parte Práctica 2 ===================")
"""
    Un diccionario con la información de los nombres de los estudiantes y su
    calificación (inicialmente en 0).
"""
calificaciones_dict = {
    "Estudiante": [
        "José Martínez",
        "María Fernández",
        "Carlos Vargas",
        "Ana Morales",
        "Luis Guzmán",
    ],
    "Circuitos Digitales I": [0, 0, 0, 0, 0],
    "Mecánica II": [0, 0, 0, 0, 0],
    "Máquinas eléctricas I": [0, 0, 0, 0, 0],
    "Electrónica III": [0, 0, 0, 0, 0],
    "Sistemas de Control": [0, 0, 0, 0, 0],
}

"""
    Ahora se le procede a sustituir los ceros de las listas por números
    aleatorios entre 50 y 100 (como era el reglamento universitario).
    Esto se logra con un ciclo for y el función random de numpy.
"""
for asignatura in calificaciones_dict:
    # Si asignatura es igual al string Estudiante, no es nesario modificar algo
    if asignatura == "Estudiante":
        continue
    # De lo contrario, sería una asignatura y se desea colocar calificaciones
    # aleatorias
    else:
        # Genera unicamente 5 números aleatorios entre 50 y 100
        calificaciones_dict[asignatura] = np.random.randint(50, 101, size=5)

"""
    Utilizando pandas se convierte el diccionario a un DataFrame
"""
calificaciones_df = pd.DataFrame(calificaciones_dict)

"""
    Se hace uso de la función np.mean para calcular el promedio de
    calificaciones para cada estudiante
"""
# Se calcula el promedio de calificaciones para cada fila (estudiante),
# mediante el uso de axis=1
promedio_estudiantes = np.mean(calificaciones_df.iloc[:, 1:], axis=1)

"""
    Haciendo uso del np.mean se calcula el promedio de las notas para cada
    asignatura, así que se hacen los cálculos sobre las columnas.
"""
# Se le crea un DataFrame aparte al resultado del promedio para cada asignatura
# mediante la creación
promedio_asignaturas_df = pd.DataFrame(
    {
        # Se hace una lista con el nombre de las asignaturas
        'Asignatura': calificaciones_df.columns[1:],
        # Se calcula el promedio por columna con axis = 0
        'Promedio de la asignatura': np.mean(calificaciones_df.iloc[:, 1:],
                                             axis=0)
    }
)

"""
    Con la función np.max se encuentra la calificación máxima de cada
    estudiante
"""
# Se calcula el promedio de calificaciones para cada fila (estudiante),
# mediante el uso de axis=1
calificacion_maxima_estudiantes = np.max(calificaciones_df.iloc[:, 1:], axis=1)

"""
    Con la función np.sum se encuentra la suma de todas las calificaciones
    para cada estudiante
"""
suma_calificaciones_estudiante = np.sum(calificaciones_df.iloc[:, 1:], axis=1)

"""
    Se crea un nuevo DataFrame con la información promedio, calificación
    máxima y suma de calificaciones para cada estudiante.
"""
# Se crea un DataFrame que solo tenga el nombre de los estudiantes
# y su promedio
# Usar .copy() para evitar la advertencia y no dañar el DataFrame original
estudiantes_df = calificaciones_df.iloc[:, 0:1].copy()
# Se añadé el promedio de los estudiantes al estudiantes_df
estudiantes_df.loc[:, "Promedio"] = promedio_estudiantes

estudiantes_df.loc[:, "Calificación Máxima"] = \
                                            calificacion_maxima_estudiantes

estudiantes_df.loc[:, "Suma de calificaciones"] = \
                                            suma_calificaciones_estudiante


# ----------------------- # Impresión de resultados # ----------------------- #
print("Calificaciones obtenidas en 5 asignaturas de 5 estudiantes:")
print(calificaciones_df.to_string(index=False, header=True))

print("\nPromedio, calificación máxima y suma de calificaciones de cada",
      "estudiante:")
print(estudiantes_df.to_string(index=False, header=True))

print("\nPromedio de calificaciones obtenidas en cada asignatura:")
print(promedio_asignaturas_df.to_string(index=False, header=True))
