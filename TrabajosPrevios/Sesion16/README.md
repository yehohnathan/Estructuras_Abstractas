### Métricas de Evaluación en Modelos de Regresión

En la evaluación de modelos de regresión, se emplean diversas métricas para medir la precisión y el rendimiento. A continuación, se describen algunas de las métricas comúnmente utilizadas:

#### Error Medio Absoluto (MAE):
Es una medida que cuantifica la magnitud promedio de los errores absolutos entre las predicciones de un modelo y los valores reales. MAE es útil cuando se busca una métrica que no penalice fuertemente los valores atípicos, proporcionando una indicación directa de la magnitud promedio de los errores.

#### Error Cuadrático Medio (MSE):
Calcula el promedio de los errores cuadrados entre las predicciones y los valores reales. MSE otorga un peso más significativo a los errores más grandes y destaca las discrepancias entre predicciones y valores reales. La penalización cuadrática lo hace sensible a valores atípicos.

#### Raíz Cuadrada del Error Cuadrático Medio (RMSE):
Es la raíz cuadrada del MSE y proporciona una medida en la misma escala que la variable de respuesta. El RMSE es valioso para interpretar la magnitud promedio de los errores en términos de la variable de interés, siendo su interpretación más intuitiva.

#### Error Absoluto Relativo (RAE):
Indica la proporción de la suma de errores absolutos en relación con la suma total de las diferencias entre predicciones y valores reales. Es útil para expresar el error en términos de la variabilidad absoluta de los datos.

#### Error Cuadrático Relativo (RSE):
Proporciona una perspectiva relativa de los errores cuadráticos, normalizando la suma de errores cuadrados por la variabilidad total de los datos. RSE es especialmente útil para comparar modelos en términos de su capacidad para explicar la variabilidad en diferentes contextos.

#### Coeficiente de Determinación \(R^2\):
Es una medida estadística que indica la proporción de la variabilidad en la variable de respuesta explicada por el modelo de regresión. Toma valores entre 0 y 1, donde \(R^2 = 0\) indica que el modelo no explica ninguna variabilidad, mientras que \(R^2 = 1\) indica que el modelo explica toda la variabilidad.

### Regularización:

Es una técnica utilizada en el aprendizaje automático para evitar el sobreajuste (overfitting) y mejorar la generalización del modelo. Consiste en agregar términos adicionales a la función de costo del modelo para penalizar la complejidad del modelo, lo que puede ayudar a prevenir que los coeficientes de las características alcancen valores extremadamente altos Dos formas comunes de regularización son L1 (regularización de la norma L1 o "Lasso") y L2 (regularización de la norma L2 o "Ridge"). Ambas añaden términos a la función de costo, pero penalizan de manera diferente.


#### L1 (Lasso): 
Agrega la suma de los valores absolutos de los coeficientes multiplicados por un parámetro de regularización. L1 tiene la propiedad de realizar selección de características, es decir, puede llevar algunos coeficientes a cero, eliminando así esas características del modelo.

#### L2 (Ridge): 
Agrega la suma de los valores cuadrados de los coeficientes multiplicados por un parámetro de regularización. Ridge no lleva los coeficientes a cero, pero tiende a reducir su magnitud, evitando valores extremadamente altos.
