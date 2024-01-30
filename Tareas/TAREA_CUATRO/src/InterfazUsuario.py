# --------------- # Instanciación de las clases a utilizar # --------------- #

from Alergia import Alergia
from EvaluacionEspecifica import EvaluacionEspecifica
from TiposAlergias import TiposAlergias
from EvaluacionGeneral import EvaluacionGeneral

# ---------------- # Creación de los objetos de cada clase # ---------------- #
alergia = Alergia()
evaluacion_especifica = EvaluacionEspecifica()
tipos_alergias = TiposAlergias()
evaluacion_general = EvaluacionGeneral()

# ----------------- # Creación de la interfaz de usuario # ------------------ #
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
