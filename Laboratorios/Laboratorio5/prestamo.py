# --- # Se importan librerías # --- #
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


# --- # Creación de la clase prestamo # --- #
class Prestamo:
    def __init__(self, monto_prestamo, taza_interes_anual, cuotas):
        """
        Inicializa la clase Prestamo con los parámetros proporcionados.

        Args:
            monto_prestamo (float): Monto total del préstamo.
            taza_interes_anual (float): Tasa de interés anual.
            cuotas (int): Número de cuotas o pagos mensuales.
        """
        self.monto_prestamo = monto_prestamo
        self.taza_interes_anual = taza_interes_anual
        self.cuotas = cuotas
        self.amortizacion = self.calcular_amortizacion()

    def calcular_amortizacion(self):
        """
        Calcula la tabla de amortización del préstamo.

        Returns:
            list: Lista de diccionarios representando cada cuota con sus
            detalles.
        """
        try:
            # Convertir tasa de interés anual a mensual y decimal
            tasa_interes_mensual = (self.taza_interes_anual / 12) / 100

            # Calcular cuota mensual utilizando la fórmula de amortización
            cuota_mensual = ((tasa_interes_mensual * self.monto_prestamo) /
                             (1 - (1 + tasa_interes_mensual) ** -self.cuotas))

            saldo_restante = self.monto_prestamo
            amortizacion = []

            for cuota in range(1, self.cuotas + 1):
                # Calcular interés pendiente y amortización principal
                interes_pendiente = saldo_restante * tasa_interes_mensual
                amortizacion_principal = cuota_mensual - interes_pendiente

                # Actualizar saldo restante
                saldo_restante -= amortizacion_principal

                # Agregar detalles de la cuota a la lista
                amortizacion.append({'Cuota': cuota,
                                     'Interes': interes_pendiente,
                                     'Amortizacion': amortizacion_principal,
                                     'Saldo Restante': saldo_restante})

            return amortizacion
        except ZeroDivisionError:
            print("Error: La cantidad de cuotas no puede ser cero.")
            return []

    def generar_reporte(self, archivo_salida):
        """
        Genera un reporte en formato CSV con la tabla de amortización.

        Args:
            archivo_salida (str): Nombre del archivo de salida.
        """
        try:
            # Crear un DataFrame a partir de la lista de amortización
            df = pd.DataFrame(self.amortizacion)

            # Guardar el DataFrame como un archivo CSV
            df.to_csv(archivo_salida, index=False)
            print(f"Reporte generado con éxito: {archivo_salida}")

        except Exception as e:
            print(f"Ocurrió un error al generar el reporte: {str(e)}")

    def graficar_amortizacion(self):
        """
        Genera un gráfico de barras para visualizar la distribución de interés
        y amortización en cada cuota.

        Utiliza la tabla de amortización previamente calculada.

        Returns:
            None
        """
        # Crear un DataFrame a partir de la lista de amortización
        df = pd.DataFrame(self.amortizacion)

        # Crear un array bidimensional con las columnas 'Interes' y
        # 'Amortizacion'
        data = np.array([df['Interes'], df['Amortizacion']])

        # Crear un gráfico de barras apiladas para visualizar interés y
        # amortización por cuota
        plt.bar(df['Cuota'], data[0], label='Interés')
        plt.bar(df['Cuota'], data[1], bottom=data[0], label='Amortización')

        # Configurar etiquetas y título del gráfico
        plt.xlabel('Número de cuotas')
        plt.ylabel('Monto ($)')  # Ajustar según la unidad de la moneda
        plt.title('Amortización e Interés por Cuota')

        # Mostrar leyenda para diferenciar entre interés y amortización
        plt.legend()

        # Mostrar el gráfico
        plt.show()


# Se crea una función llamada main, que simula el main de c++
def main():
    # Se le solicita al usuario que ingrese un monto, taza de interés anual (%)
    # y la cantidad de cuotas.
    while True:
        try:
            # Solicita los datos
            monto_prestamo = float(input("Ingrese el monto del préstamo: "))

            if monto_prestamo <= 0:
                raise ValueError("El monto del préstamo no puede ser negativo",
                                 "o cero")

            tasa_interes_anual = float(input("Ingrese la tasa de interés"
                                             " anual (%): "))

            if tasa_interes_anual < 0 or tasa_interes_anual > 100:
                raise ValueError("El rango de interés (%) debe ir entre",
                                 " 0 a 100.")

            cuotas = int(input("Ingrese la cantidad de cuotas: "))

            if cuotas <= 0:
                raise ValueError("Las cuotas deben ser mayores a 0.")

            # Salir del bucle
            break

        except ValueError as ve:
            print(f"Error: {ve}\n")
        except Exception as e:
            print(f"Ocurrió un error genérico: {str(e)}\n")

    # Crea un objeto de la clase Prestamo y se le ingresan los datos
    prestamo_usuario = Prestamo(monto_prestamo, tasa_interes_anual, cuotas)

    # Muestra los atributos del objeto:
    print(f"\nMonto Préstamo: {prestamo_usuario.monto_prestamo}")
    print(f"Tasa de interés anual: {prestamo_usuario.taza_interes_anual}")
    print(f"Número de cuotas: {prestamo_usuario.cuotas}")

    # Genera el reporte
    prestamo_usuario.generar_reporte("reporte_prestamo.csv")

    # Genera una gráfica de amortización
    prestamo_usuario.graficar_amortizacion()


if __name__ == "__main__":
    main()
