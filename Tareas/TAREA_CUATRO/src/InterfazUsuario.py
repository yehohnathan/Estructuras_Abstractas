# --------------- # Instanciación de las clases a utilizar # --------------- #

from Alergia import Alergia
from EvaluacionEspecifica import EvaluacionEspecifica
from TiposAlergias import TiposAlergias
from EvaluacionGeneral import EvaluacionGeneral

# ------------------- # Instanciación del modulo Timeit # ------------------- #
import timeit


# ---------------- # Creación de los objetos de cada clase # ---------------- #
alergia = Alergia()
evaluacion_especifica = EvaluacionEspecifica()
tipos_alergias = TiposAlergias()
evaluacion_general = EvaluacionGeneral()


# ----------------- # Creación de la interfaz de usuario # ------------------ #
def programa_principal():
    while True:
        print("\n================================================" +
              "================================================")
        print("Tecleé un número asociado a una opción para acceder a una",
              "funcionalidad del Sistema de Alergias",
              "\n1. Para ingresar un puntaje y ver la lista de",
              "alergias a las que es sensible.",
              "\n2. Para ingresar los tipos de alergias que tiene.",
              "\n3. Para ingresar una nueva alergia a la lista.",
              "\n4. Para finalizar el programa.")
        try:
            opcion = int(input("Ingrese una opción: "))

            if opcion == 1:
                print("\n================================================" +
                      "================================================")
                alergias = alergia.get_lista_alergias()
                evaluacion_especifica.evaluar_alergias(alergias)

            elif opcion == 2:
                print("\n================================================" +
                      "================================================")
                tipos_alergias.agregar_alergia()
                lista_alergias = tipos_alergias.get_lista_alergias()
                evaluacion_general.datos_alergias(lista_alergias)
                evaluacion_general.calcular_promedio()

            elif opcion == 3:
                alergia.agregar_alergia()
                alergia.imprimir_informacion_completa()

            elif opcion == 4:
                print("=======================================",
                      "FIN DEL PROGRAMA",
                      "=======================================")
                break

        except ValueError:
            print("Error: No se ingresó una opción válida.,"
                  "Inténtelo de nuevo.\n")


"""
Uso del modulo de timeit para medir el tiempo de ejecución del programa con
las siguientes intrucciones:
    1. Se ingresa el peor caso del puntaje, alergico a todos los alimentos.
    2. Se agregan dos elementos de los 3 casos posibles cuando el usuario
       desea ingresar elementos
    3. Se añaden dos nuevas alergias

Las condiciones que van a cambiar es si la lista de alergias inicial varia de:
    1. 10 alergias -> 56.49701900000218 segundos
    2. 30 alergias -> 59.47061409999151 segundos
    3. 50 alergias -> 63.73561440000776 segundos
"""

tiempo = timeit.timeit(programa_principal, number=1)
print(f"Tiempo de ejecución agregar_alergia: {tiempo} segundos")
