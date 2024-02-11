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

Es una técnica de aprendizaje no supervisado que cuya función es agrupar en clusters (grupos) un conjunto de datos, de forma que los datos dentro de cada grupo sean similares entre si y diferentes a otros grupos.

Su objetico principal es encontrar patrones mediante el análisis de estos datos, estructuras o segmentos ocultos en los datos, que pueden ser usados en diferentes campos como el Marketing, Medicina, Internet, etc.

2. Describa brevemente los algoritmos K-Means y DBSCAN y cómo funcionan.

Algoritmo **K-Means**: requiere que el usuario especifique el número de clusters (k) e inicializar k puntos aleatorios como centrodes, luego, itera los siguientes pasos hasta que los centroides converjan o se alcance un número máximo de iteraciones: asignar cada observación al centroide más cercano, y recalcular los centroides como el promedio de las observaciones asignadas a cada grupo [2].

Algoritmo **K-DBSCAN**: no requiere que el usuario especifique el número de grupos, sino que los detecta automáticamente en función de la densidad de los datos. 

Se necesita dos parámetros: el radio (eps) y el número mínimo de puntos (minPts) para considerar una zona como densa. Luego, clasifica cada observación en uno de los siguientes tipos: punto núcleo (core point), si tiene al menos minPts puntos dentro de su radio; punto frontera (border point), si no es un punto núcleo pero tiene al menos un punto núcleo dentro de su radio; y punto ruido (noise point), si no es ni núcleo ni frontera. Finalmente, se asigna cada punto núcleo y sus puntos frontera alcanzables al mismo grupo, y deja los puntos ruido sin asignar [3].

3. ¿Qué es la inercia en el contexto del clustering y cómo se utiliza para evaluar la calidad de un agrupamiento?

La inercia es una medida de la dispersión de los datos dentro de los grupos, que se calcula como la suma de las distancias al cuadrado de cada observación a su centroide asignado. Se utiliza para evaluar la calidad de un agrupamiento, de forma que cuanto menor sea la inercia, mejor será el ajuste de los datos a los grupos, ya que indica que las observaciones están más cerca de sus centroides. 

Sin embargo, la inercia no es una medida absoluta, sino que depende del número de grupos, la escala de los datos y la medida de distancia utilizada.

4. ¿Qué son los centroides y cómo se utilizan en el algoritmo K-Means?

Los centroides son los puntos centrales de cada grupo, que representan el promedio o la posición media de las observaciones asignadas a ese grupo. Se utilizan en el algoritmo K-Means para definir y actualizar los grupos, de forma que cada observación se asigna al centroide más cercano según alguna medida de distancia, y cada centroide se recalcula como el promedio de las observaciones asignadas a su grupo.

5. Escriba la diferencia entre datos estructurados y no estructurados para análisis de datos.

Los datos estructurados son aquellos que tienen una estructura predefinida y esperada, que se almacenan en tablas, filas y columnas, y que se pueden consultar y analizar fácilmente. Los datos estructurados suelen provenir de fuentes como bases de datos relacionales, hojas de cálculo, formularios o transacciones [4]. 

Por otro lado, los datos no estructurados son aquellos que no tienen una estructura definida ni un formato específico, que se almacenan en formatos diversos y muy diferentes, y que requieren de procesos complejos para poder analizar su contenido y extraer información valiosa de ellos [4].

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

[2] T. Sequeira, “Clustering en Python: Implementando K-means paso a paso,” Medium, 2024. [En línea]. Disponible: https://thiagosequeira.medium.com/clustering-en-python-implementando-k-means-paso-a-paso-9d19875dfabc. [Accedido: 11- Feb- 2024].

[3] Exponentis, Ejemplo de uso de DBSCAN en Python para detección de outliers, Exponentis, 10 Mar. 2020. [En línea]. Disponible: http://exponentis.es/ejemplo-de-uso-de-dbscan-en-python-para-deteccion-de-outliers. [Accedido: 11- Feb- 2024].

[4] “Tipos de datos: datos estructurados, semiestructurados y no estructurados,” Blogs de IMF, Jun. 2020. [En línea]. Disponible: https://blogs.imf-formacion.com/blog/tecnologia/tipos-de-datos-datos-estructurados-semiestructurados-y-no-estructurados-202006/. [Accedido: 11- Feb- 2024]