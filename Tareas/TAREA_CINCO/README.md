# TAREA 5: Uso de Pandas, Matplotlib y Numpy en Python


## Ejecución del programa:

## Análisis de parte práctica I:
> Para acceder al CSV utilizado en el análisis y codificación de la Parte Práctica I de la tarea, puedes visitar la siguiente página: [Air Carriers : T-100 International Market (All Carriers)](https://www.transtats.bts.gov/DL_SelectFields.aspx?gnoyr_VQ=FJD&QO_fu146_anzr=Nv4%20Pn44vr45). Es importante seleccionar la opción "Select all fields" en la página antes de proceder con la descarga para asegurarse de obtener la misma cantidad de información que se utilizó en el análisis.

### Información correspondiente a las columnas del CSV empleado:
| Categoría          | Columna                   | Descripción                                                                                            |
|--------------------|---------------------------|--------------------------------------------------------------------------------------------------------|
| ***Summaries***          | **Passengers**            | Mercado a bordo Pasajeros embarcados                                                                  |
|                    | **Freight**               | Mercado a bordo Carga embarcada (libras)                                                              |
|                    | **Mail**                  | Correo del mercado a bordo embarcado (libras)                                                         |
|                    | **Distance**              | Distancia entre aeropuertos (millas)                                                                  |
| ***Carrier***      | **UniqueCarrier**         | Código de Transportista Único. Este campo se utiliza para análisis a lo largo de varios años.          |
|                    | **AirlineID**             | Número de Identificación asignado por el Departamento de Transporte de EE. UU. para identificar una aerolínea única. |
|                    | **UniqueCarrierName**     | Nombre de Transportista Único                                                                         |
|                    | **UniqCarrierEntity**     | Entidad Única para la Región de Operación de un Transportista.                                         |
|                    | **CarrierRegion**         | Región de Operación del Transportista.                                                                |
|                    | **Carrier**               | Código asignado por IATA para identificar un transportista.                                            |
|                    | **CarrierName**           | Nombre del Transportista                                                                              |
|                    | **CarrierGroup**          | Código de Grupo de Transportista utilizado en análisis heredados.                                      |
|                    | **CarrierGroupNew**       | Nuevo Grupo de Transportista. Análisis                                                                |
| ***Origin***             | **OriginAirportID**       | ID del Aeropuerto de Origen                                                                           |
|                    | **OriginAirportSeqID**    | ID de Secuencia del Aeropuerto de Origen                                                              |
|                    | **OriginCityMarketID**    | ID del Mercado de la Ciudad de Origen del Aeropuerto                                                  |
|                    | **Origin**                | Aeropuerto de Origen                                                                                  |
|                    | **OriginCityName**        | Nombre de la Ciudad del Aeropuerto de Origen                                                          |
|                    | **OriginCountry**         | País de Origen del Aeropuerto                                                                         |
|                    | **OriginCountryName**     | Nombre del País de Origen del Aeropuerto                                                              |
|                    | **OriginWac**             | Código de Área Mundial del Aeropuerto de Origen                                                       |
| ***Destination***            | **DestAirportID**         | ID del Aeropuerto de Destino                                                                          |
|                    | **DestAirportSeqID**      | ID de Secuencia del Aeropuerto de Destino                                                             |
|                    | **DestCityMarketID**      | ID del Mercado de la Ciudad de Destino del Aeropuerto                                                 |
|                    | **Dest**                  | Aeropuerto de Destino                                                                                 |
|                    | **DestCityName**          | Nombre de la Ciudad del Aeropuerto de Destino                                                         |
|                    | **DestCountry**           | País de Destino del Aeropuerto                                                                        |
|                    | **DestCountryName**       | Nombre del País de Destino del Aeropuerto                                                             |
|                    | **DestWac**               | Código de Área Mundial del Aeropuerto de Destino                                                      |
| ***Time Period***  | **Year**                  | Año                                                                                                    |
|                    | **Quarter**               | Trimestre                                                                                               |
|                    | **Month**                 | Mes                                                                                                    |
| ***Other***              | **DistanceGroup**         | Intervalos de Distancia, cada 500 Millas, para Segmentos de Vuelo                                      |
|                    | **Class**                 | Clase de Servicio                                                                                      |


#### Las clases de servicio existentes: 
- **A**: "Servicio de Pasajeros de Primera Clase Programado/ Servicio de Carga A"
- **C**: "Servicio de Pasajeros de Clase Económica Programado/ Servicio de Carga C"
- **E**: "Servicio Programado de Pasajeros y Carga Mixta, de Primera Clase y Clase Económica E"
- **F**: "Servicio Programado de Pasajeros y Carga F"
- **G**: "Servicio Programado de Carga Únicamente G"
- **H**: "Razón Humanitaria No Programada, No Generadora de Ingresos"
- **K**: "Servicio Programado K (F+G)"
- **L**: "Servicio No Programado Civil de Pasajeros y Carga L"
- **N**: "Servicio No Programado Militar de Pasajeros y Carga N"
- **P**: "Servicio No Programado Civil de Carga Únicamente P"
- **Q**: "Servicios No Programados (Excepto Chárter) Q"
- **R**: "Servicio No Programado Militar de Carga Únicamente R"
- **V**: "Servicio No Programado V (L+N+P+R) para Transportista de EE. UU. y (L+P+Q) para Transportista Extranjero"
- **Z**: "Todo Servicio Z (K+V)"


## Parte teórica:
### Iteradores
1. ¿Qué es un iterador en Python y cuál es su propósito?
Los iteradores son métodos que iteran (se mueven a travez de la información) listas, tuplas, ordered sets, diccionarios y cualquiera otro tipo dato que almacene información en su interior separada por indices. Se utiliza para recorrer un coleccionable (objeto) y devolver sus elementos.

Un objeto iterador en Oython debe usar métodos mágicos como `__iter__()` y `__next()__`, denominados protocolos iterador, para recorrer un coleccionable. 

2. Explica la diferencia entre un iterable y un iterador.

Un **iterable** es un objeto que se puede recorrer con un bucle `for`, como una lista, una tupla o una cadena de texto. 

Un iterable hace uso de los protocolos iterador: `__iter__()` que devuelve un **iterador** y `__next__()` que devuelve el siguiente elemento del iterable. Un iterador se agota cuando no hay más elementos que devolver y lanza una excepción `StopIteration`.

Por ejemplo, si se tiene un coleccionable tupla, este es un iterable, y cuando se usa el método `iter(tupla)` pasa a ser un iterador y al usar el método `next()` se obtienen elementos del iterador uno a uno, hasta que se agote.

```python
# Se crea una tupla
tupla = (1, 2, 3, 4, 5)

# Se saca un iterador de la tupla
iterador = iter(tupla)

# Método next() para obtener los elementos del iterador
print(next(iterador))   # Output: 1
print(next(iterador))   # Output: 2
print(next(iterador))   # Output: 3
print(next(iterador))   # Output: 4
print(next(iterador))   # Output: 5
print(next(iterador))   # Output: Error StopIteration
```

### Excepciones
1. Define qué es una excepción en Python.

Una excepción es un objeto (como todo en Python) que representa una condición inusual que ocurre durante la ejecución de un programa, principalmente ocurre cuando se sale del *HappyPath*. Este objeto puede ser lanzado o lanzados cuando ocurre un error o una condición especial, y pueden ser capturados y manejados para evitar que el programa se detenga abruptamente. 

2. ¿Cuál es el propósito de la cláusula try...except en el manejo de excepciones?

El propósito del try/except es gestionar los errores y excepciones que puedan ocurrir durante la ejecución de un programa, impidiendo que el programa se pare o haciendo que el usuario solo ingrese lo esperado. 

Para hacer uso de esta cláusula, en el bloque `try` se coloca el código que se va a ejecutar y en uno o varios bloques `except` se coloca lo que se va a desplegar si ocurre un comportamiento no deseado.

Un ejemplo de uso puede ser cuando hay una división y el denominador es 0:

```python
try:
  resultado = num1 / num2
  print(f"El resultado de la división es {resultado}")
except ZeroDivisionError:
  # Si num2 es 0, se despliega la siguiente excepción
  print("Error: No se puede dividir por cero")
```

3. Explica la diferencia entre las cláusulas except y finally en el manejo de excepciones.

El `except` se ejecuta cuando el bloque try lanza una excepción de un tipo específico que se indica en la cláusula. Esta cláusula permite capturar y manejar el error, evitando que el programa se detenga o se comporte de forma inesperada. Se puede tener más de una cláusula except para diferentes tipos de excepciones.

El `finally` se ejecuta siempre, independientemente de si el bloque try lanza una excepción o no, o si se captura o no. Esta cláusula permite liberar recursos, como cerrar un file previamente abierto, o realizar acciones de limpieza que se deben hacer siempre al finalizar la ejecución de un bloque de código.

Reutizando el ejemplo anterior:

```python
try:
    resultado = num1 / num2
    print(f"El resultado de la división es {resultado}")
except ZeroDivisionError:
    # Si num2 es 0, se despliega la siguiente excepción
    print("Error: No se puede dividir por cero")
finally:
    # Esto siempre se ejecutará, con o sin presencia de excepción
    print("Se término la división de num1 y num2")
```
### Generadores
1. ¿Qué es un generador en Python y cuál es su ventaja sobre las listas tradicionales?

Un generador es una función que devuelve un iterador que puede producir una secuencia de valores de unicamente cuando se le solicita, sin generarlos todos de una vez. Su principal ventaje sobre las listas tradicionales es que son más eficientes en el uso de la memoria, ya que solo almacenan el estado de la función y no toda la secuencia de valores [1]. Además, los generadores pueden operar sobre muy grandes o casi infinitos, que no cabrían en una lista por el espacio de memoria que requieren [1].

2. Explica cómo se puede crear un generador usando la función yield.

Se puede definir una función generadora usando la palabra calve `yield` dentro de la definición de la función en lugar del `return`. La función yield devuelve un valor y pausa la ejecución de la función, conservando su estado para reanudarla cuando se le vuelva a llamar. 

Por ejemplo, el siguiente código define un generador que produce los números pares:

```python
def generador_pares(loop):
    n = 0
    while n < loop*2:
        yield n
        n += 2


# Se coloca la cantidad de número pares que se desean obtener
pares_generados = generador_pares(3)

# Iterar sobre los valores generados e imprimirlos
for valor in pares_generados:
    print(valor)        # Output: 0 > 2 > 4
```

3. ¿Cuándo es más apropiado usar generadores en lugar de listas?

Es más apropiado usar generadores en lugar de listas cuando se quiere procesar una secuencia de datos de forma en varias ocasiones dentro del código, sin necesidad de almacenarla toda en memoria, o cuando se quiere trabajar con datos infinitos o muy grandes, que no se podrían generar o almacenar en una lista [1].


### Pandas
1. ¿Cuál es la diferencia entre una Serie y un DataFrame en Pandas?

Una Serie es un objeto de una sola dimensión que puede contener cualquier tipo de datos, como enteros, flotantes, cadenas, etc; como lo sería una lista. Estos tienen un índice que identifica cada elemento de la Serie y se puede considerar como una columna de un conjunto de datos. 

Un DataFrame es un objeto dos dimensiones que puede contener varias Series, cada una con su propio nombre y tipo de datos. Tiene un índice de filas y un índice de columnas que identifican cada fila y cada columna del DataFrame y se puede considerar como una tabla de datos de un excel. 

Otra diferencia es como se crea una Serie y Un DataFrame en Pandas:

```python
# Se importa la librería de pandas
import pandas as pd

# Serie con números enteros y un índice alfabético
s = pd.Series([10, 20, 30, 40], index=["a", "b", "c", "d"])

# DataFrame con dos Series, una de números enteros y otra de cadenas, y un índice numérico
df = pd.DataFrame({"numeros": [1, 2, 3, 4], "nombres": ["Ana", "Beto", "Carlos", "Diana"]}, index=[1, 2, 3, 4])
```

2. Explica cómo manejar valores nulos o faltantes en un DataFrame.

Los valores nulos o faltantes en un DataFrame se representan con el valor especial NaN, y la libería de pandas ofrece varios métodos para manejar estos valores [2]. Algunas de las opciones más comunes investigadas son las siguientes:

- Eliminar las filas o columnas que contengan valores nulos con el método `dropna()`. Se puede especificar el eje (0 para filas, 1 para columnas), el umbral (número mínimo de valores no nulos para conservar la fila o columna) y el subconjunto (lista de columnas a considerar para la eliminación) [3].

- Rellenar los valores nulos con un valor constante con el método `fillna()`. Se puede especificar el valor a usar, el eje, el método (para usar el valor anterior o posterior al nulo) y el límite (número máximo de valores nulos a rellenar) [3].

- Reemplazar los valores nulos con un valor calculado con el el método `replace()`. Se puede especificar el valor a reemplazar, el valor a usar (casi siempre 0), el método y el límite. También se puede usar una función o un diccionario para definir el valor a usar según el valor a reemplazar [2].

- Interpolar los valores nulos con un valor estimado con el el método `interpolate()`. Se puede especificar el método de interpolación (lineal, cuadrático, cúbico, etc.), el eje, el límite y el orden (para los métodos polinomiales) [2].

3. ¿Cuál es la diferencia entre loc y iloc en Pandas?

Ambos métodos el`loc` e `iloc` tiene la función de seleccionar filas y columnas de un DataFrame. La diferencia entre ellos es que `loc` se basa en las etiquetas de los índices, mientras que `iloc` se basa en las posiciones de los índices [4].

## Bibliografía:

[1] “Generators - Learn Python - Free Interactive Python Tutorial,” Learn Python, [Online]. Disponible: https://www.learnpython.org/es/Generators. [Accedido: 04- Feb- 2024].

[2] "N. Urrego, 'Tratamiento de valores vacíos I: Cómo abordar datos incompletos en tu dataset,' Medium, 25-Jul-2023. [Online]. Disponible: https://medium.com/@nicolasurrego/tratamiento-de-valores-faltantes-i-c%C3%B3mo-abordar-datos-incompletos-en-tu-dataset-35d51c522842. [Accedido: 04- Feb- 2024]."

[3] S. Kundu, “The Pandas fillna and dropna Methods”, Medium, 2020. [Online]. Disponible: https://medium.com/@sagnikkundu25/the-pandas-fillna-and-dropna-methods-1fecad724aa9#:~:text=In%20many%20cases%2C%20you%20will%20want%20to%20replace,value.%20This%20is%20what%20the%20dropna%20method%20does.. [Accessed: 04- Feb- 2024].

[4] “Difference between loc() and iloc() in Pandas DataFrame,” GeeksforGeeks, [Online]. Disponible: https://www.geeksforgeeks.org/difference-between-loc-and-iloc-in-pandas-dataframe/. [Accedido: 04- Feb- 2024].