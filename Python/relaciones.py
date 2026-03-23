import re
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt

# Obtiene el conjunto de elementos de la relacion asi como la tupla de relaciones
Patron = r'(\w+)R(\w+)'

ElementosInput = input('Ingresa los elementos (ej: a b c d): \n')
RelacionesInput = input('Ingresa las relaciones (ej: aRb aRc): \n')

Coincidencias = re.findall(Patron, RelacionesInput)

ConjuntoRelaciones = []
for a, b in Coincidencias:
    tupla = (str(a), str(b))
    if tupla not in ConjuntoRelaciones:
        ConjuntoRelaciones.append(tupla)

Elementos = {}
i = 0
for a in ElementosInput:
    if a != " " and str(a) not in Elementos:
        Elementos[str(a)] = i
        i += 1

# Obtiene y crea la matriz de Adyacencia
Matriz = np.zeros((len(Elementos), len(Elementos)), dtype=int)
for a,b in ConjuntoRelaciones:

    Matriz[Elementos[a]][Elementos[b]] = 1

#Grafica el Grafo de las relaciones
G = nx.DiGraph()
G.add_nodes_from(Elementos.keys())
G.add_edges_from(ConjuntoRelaciones)

nx.draw(G, 
        with_labels=True, 
        node_color='black', 
        font_color='white', 
        node_size=2000, 
        arrows=True, 
        arrowsize=25, 
        connectionstyle='arc3, rad=0.1')

print("\n--- Listas de Relaciones ---")
print(ConjuntoRelaciones)
print("\n--- Elementos ---")
print(Elementos)
print("\n--- Matriz de adyacencia ---")
print(Matriz)
plt.show()
