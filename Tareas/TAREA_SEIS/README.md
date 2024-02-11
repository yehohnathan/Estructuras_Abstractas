# Tarea 6: Regresiones, clustering y servicios web

## Ejecución del programa:

Para ejecutar el programa, asegúrese de estar en el directorio del repositorio en su computadora y escriba el comando `make`, como se muestra a continuación:

```go
...\ie0217\Tareas\TAREA_SEIS> make
```

## Parte teórica:
### Regresión:
1. ¿Qué es la regresión lineal y cómo se diferencia de la regresión no lineal?

Una regresión lineal es un método aleatorio que trata de modelar la relación entre una variable dependiente y una o más variables independientes mediante el ajuste de una ecuación lineal ***y = a + m\*b***. Mientras que una regresión no lineal utiliza funciones no lineales para ajustar los datos, usualmente de carácter polinomial, permitiendo capturar relaciones más complejas y curvas entre variables.

2. ¿Qué son los coeficientes de regresión y qué información proporcionan sobre la relación entre las variables?

Los coeficientes de regresión (β) son los valores que multiplican a las variables independientes (X) en la ecuación lineal [1]. En el siguiente ejemplo se  una regresión lineal simple:

$$
Y_{i}= β_{0} + β_{1}X_{i}
$$

Estos coeficientes indican el efecto promedio que tiene cada variable independiente sobre la variable dependiente, manteniendo constantes al resto de variables [1]. En el siguiente ejemplo de una regresión lineal múltiple:

$$
Y_{i}= β_{0} + β_{1}X_{1} + β_{2}X_{1}
$$

El coeficiente β1 representa el cambio esperado en y por cada unidad que aumenta X1, asumiendo que X2 se mantiene fijo.

3. ¿Qué es el error cuadrático medio (MSE) y cómo se utiliza para evaluar la precisión de un modelo de regresión?

El error cuadrático medio (MSE) es una medida de la diferencia entre los valores reales y los valores predichos por un modelo de regresión; y se calcula como el promedio de los cuadrados de las diferencias entre cada valor real y su valor predicho.

Este se utiliza para evaluar la precisión de un modelo de regresión, de forma que cuanto menor sea el MSE, mejor será el ajuste del modelo a los datos. También se puede utilizar para comparar diferentes modelos de regresión y elegir el que tenga el menor.

4. ¿Cuál es la diferencia entre regresión simple y regresión múltiple y cuándo se utiliza cada una?

La principal diferencia entre una regresión simple y regresión múltiple es el número de variables independientes que se utilizan para predecir la variable dependiente. La regresión simple usa una sola variable independiente, y si tiene más de una variable independiente se considera regresión múltiple.

La regresión simple se utiliza cuando se quiere estudiar la relación entre una variable dependiente y una sola variable independiente, y la regresión múltiple se utiliza cuando se quiere estudiar la relación entre una variable dependiente y varias variables independientes, o cuando se quiere controlar el efecto de otras variables que pueden influir en la variable dependiente, siendo este más completo pero más complejo.



### Clustering:
1. ¿Qué es el clustering y cuál es su objetivo principal en el análisis de datos?
2. Describa brevemente los algoritmos K-Means y DBSCAN y cómo funcionan.
3. ¿Qué es la inercia en el contexto del clustering y cómo se utiliza para evaluar la calidad de un agrupamiento?
4. ¿Qué son los centroides y cómo se utilizan en el algoritmo K-Means?
5. Escriba la diferencia entre datos estructurados y no estructurados para análisis de datos.

### Paquetes en Python (`__init__.py`):
1. ¿Qué es un paquete en Python y cómo se diferencia de un módulo?
2. ¿Cuál es la función del archivo `__init__.py` dentro de un paquete de Python?
3. ¿Cómo se importa un módulo o función desde un paquete en Python?
4. ¿Qué es la variable `__all__` en el archivo `__init__.py` y cuál es su propósito?
5. ¿Cuál es la ventaja de organizar el código en paquetes y módulos en Python?

### Python HTTP y Servicios Web (API):
1. ¿Qué es una API y cuál es su función en el contexto de los servicios web?
2. ¿Cuál es la diferencia entre una API RESTful y una API SOAP?
3. Describa los pasos básicos para consumir una API utilizando Python.
4. ¿Qué es la autenticación de API y por qué es importante?
5. ¿Cuál es el papel de los verbos HTTP (GET, POST, PUT, DELETE) en las solicitudes a una API y HTTP?

## Bibliografía

[1] J. A. Rodrigo, “Regresión lineal con python,” Ciencia de datos, Oct. 2020. [En línea]. Disponible: https://cienciadedatos.net/documentos/py10-regresion-lineal-python.html. [Accedido: 11- Feb- 2024].