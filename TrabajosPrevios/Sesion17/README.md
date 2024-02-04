## Conceptos claves en Hierarchical Clustering
### Enlaces
Enlace (Linkage): determina cómo se miden las distancias entre clusters. Hay varios métodos de enlace comunes, como:

- Enlace Completo (Complete Linkage): Distancia entre clusters basada en los puntos más alejados entre sí.
- Enlace Simple (Single Linkage): Distancia entre clusters basada en los puntos más cercanos entre sí.
- Enlace Promedio (Average Linkage): Distancia entre clusters basada en el promedio de todas las distancias entre puntos.

### Dendrogramas
Es un diagrama de árbol que representa la jerarquía de clusters. Cada nodo en el dendrograma representa un cluster y las hojas son los puntos de datos individuales. La altura en el dendrograma representa la distancia entre clusters. Los cortes en el dendrograma indican la formación de clusters.

## DBSCAN (Density-Based Spatial Clustering of Applications with Noise)**

Es un algoritmo de clustering basado en la densidad. A diferencia de K-Means y Hierarchical Clustering, DBSCAN no requiere especificar la cantidad de clusters de antemano y puede identificar clusters de formas y tamaños arbitrarios. Algunas características clave incluyen:

- **Densidad como criterio**
  - Identifica clusters basándose en la densidad de los puntos en lugar de en la distancia.
  - Puede descubrir clusters de formas irregulares y manejar puntos de ruido.

- **Tres tipos de puntos**
  - **Core Points (Puntos Núcleo):** Puntos con al menos un número mínimo de puntos en su vecindario.
  - **Border Points (Puntos de Borde):** Puntos que tienen menos vecinos que el número mínimo pero están dentro del vecindario de un Core Point.
  - **Noise Points (Puntos de Ruido):** Puntos que no son Core ni Border Points.

- **Parámetros**
  - `eps` (Épsilon): Radio del vecindario alrededor de un punto.
  - `min_samples` (Mínimo de Puntos): Número mínimo de puntos requeridos para formar un cluster
