# 📌 Implementación de Relaciones Binarias en C++

Este proyecto implementa y analiza distintas propiedades de una **relación binaria** usando C++.

Se trabajan las siguientes propiedades:

- Reflexiva  
- Irreflexiva  
- Simétrica  
- Transitiva  

---

## 🧠 ¿Cómo funciona?

El programa le pide al usuario:

1. La **cardinalidad de un conjunto** de enteros  
2. Los **elementos del conjunto**  
3. La **cardinalidad de la relación binaria**  
4. Los **pares ordenados (tuplas)** que pertenecen a la relación  

💡 Cada par ingresado `(a, b)` representa un elemento de la relación binaria.

Internamente:
- El conjunto se guarda en un **vector**
- La relación se representa como:
  - una **matriz (vector de pares)** para iterar
  - un **set** para búsquedas eficientes

---

## ⚙️ Funciones

### 🔁 `Reflexive`

Esta función verifica si la relación es **reflexiva**.

👉 Lógica:
- Para cada elemento `i` del conjunto, se busca la tupla `(i, i)` en el `set`

👉 Complejidad:
- El `for` recorre `m` elementos (tamaño del conjunto)
- Cada búsqueda en el `set` cuesta `O(log n)`

\[
\text{Complejidad: } O(m \log n)
\]

---

### 🚫 `Irreflexive`

Verifica si la relación es **irreflexiva**.

👉 Lógica:
- Para cada `i`, si existe `(i, i)` en el `set`, se regresa `false`

👉 Complejidad:

\[
O(m \log n)
\]

---

### 🔄 `Simmetry`

Verifica si la relación es **simétrica**.

👉 Lógica:
- Para cada tupla `(i, j)` en la matriz:
  - se busca `(j, i)` en el `set`

👉 Complejidad:
- Se recorre `n` elementos (tuplas)
- Cada búsqueda cuesta `O(log n)`

\[
O(n \log n)
\]

---

### 🔗 `Transitive`

Verifica si la relación es **transitiva**.

👉 Lógica:
- Se usan ciclos anidados para encontrar pares `(i, j)` y `(j, k)`
- Si se cumple esa condición, se verifica que exista `(i, k)`
- Si no se encuentra ningún caso, se cumple por **vacuidad**

👉 Complejidad:
- Dos ciclos → \( O(n^2) \)
- Cada búsqueda → \( O(\log n) \)

\[
O(n^2 \log n)
\]

---

## 🧩 Notas

- El uso de `set` permite búsquedas eficientes con complejidad \( O(\log n) \)
- Se podría optimizar usando `unordered_set` para lograr búsquedas promedio \( O(1) \)
- La combinación de estructuras (vector + set) permite balancear **iteración + eficiencia**

---

## 🚀 Conclusión

Este proyecto demuestra cómo modelar propiedades fundamentales de relaciones binarias en C++, combinando estructuras de datos y análisis de complejidad.

Además, permite entender cómo decisiones de implementación (como usar `set`) impactan directamente en el rendimiento.