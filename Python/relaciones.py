import re
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt
from relaciones_aleatorias import lista_aleatoria

Patron = r'(\w+)R(\w+)'

if input('¿Quieres ingresar una lista manual? (y/n): ') == 'y':
    ElementosInput = input('Ingresa los elementos (ej: a b c d): \n').split()
    RelacionesInput = input('Ingresa las relaciones (ej: aRb aRc): \n')
else:
    n_random = int(input("Número de elementos de la lista aleatoria: "))
    ElementosInput, relaciones_lista = lista_aleatoria(n_random)
    RelacionesInput = " ".join(relaciones_lista)

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

n = len(Elementos)

Matriz = np.zeros((n, n), dtype=int)
for a, b in ConjuntoRelaciones:
    Matriz[Elementos[a]][Elementos[b]] = 1

num_1 = 0
num_0 = 0

for a in range(n):
    if Matriz[a][a] == 1:
        num_1 += 1
    elif Matriz[a][a] == 0:
        num_0 += 1

if num_1 == n:
    Reflexividad = 'Reflexiva'
elif num_0 == n:
    Reflexividad = 'Irreflexiva'
else:
    Reflexividad = 'Ni Reflexiva Ni Irreflexiva'

if np.array_equal(Matriz, Matriz.T):
    Simetria = 'Simétrica'
else:
    Simetria = 'No Simétrica'

Matriz_2 = np.linalg.matrix_power(Matriz, 2)
EsTransitiva = np.all((Matriz_2 > 0) <= (Matriz > 0))

if EsTransitiva:
    Transitividad = 'Transitiva'
else:
    Transitividad = 'No Transitiva'

print(f"La relación es {Reflexividad}")
print(f"La relación es {Simetria}")
print(f"La relación es {Transitividad}")
print(f"Elemento de la relacion: {ElementosInput}")
print(f"Relacion: {RelacionesInput}")

G = nx.DiGraph()
G.add_nodes_from(Elementos.keys())
G.add_edges_from(ConjuntoRelaciones)

tamano_figura = max(8, int(n / 2.5))
plt.figure(figsize=(tamano_figura, tamano_figura))

plt.title("Grafo de la Relación", fontsize=16, fontweight='bold', pad=20)

pos = nx.circular_layout(G)

tamano_nodo = max(250, 1200 - (n * 25))
tamano_fuente = max(7, 14 - (n // 4))
tamano_flecha = max(10, 20 - (n // 4))

nx.draw(G, pos,
        with_labels=True, 
        node_color='black', 
        font_color='white', 
        node_size=tamano_nodo, 
        font_size=tamano_fuente,
        font_weight='bold',
        arrows=True, 
        arrowsize=tamano_flecha, 
        edge_color='#444444',
        width=1.0)

plt.margins(0.3)

texto_cuadro = (
    " Propiedades de la Relación \n"
    "────────────────────────────\n"
    f" • {Reflexividad}\n"
    f" • {Simetria}\n"
    f" • {Transitividad}"
) 

plt.text(1.0, 0.0, texto_cuadro, transform=plt.gca().transAxes,
         fontsize=12, verticalalignment='bottom', horizontalalignment='right',
         multialignment='left',
         fontfamily='monospace', fontweight='bold', color='#2b2d42',
         bbox=dict(boxstyle='round,pad=0.8', facecolor='#f8f9fa', 
                   edgecolor='#8d99ae', alpha=0.95, linewidth=1.5))

plt.show()