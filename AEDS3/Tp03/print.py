# Universidade Federal de Alfenas (UNIFAL) - 2024
#
# Gabriel Pereira Soares
# Letícia Freitas de Oliveira
# Gustavo Fernandez Paschoaleto
# Pedro Henrique de Almeida
# Lucas Pessoa Oliveira Alves  
# Jorran Luka Andrade dos Santos   
#
# Docente: Iago Carvalho - Algoritimo e Estrutura de Dados III
# 
# Trabalho com o objetivo adquirir conhecimentos em algoritmo de caminho mínimo 
# de grafo, utilizando C++ e Python.
#

import networkx as nx
import matplotlib.pyplot as plt
import matplotlib.colors as colors
import sys

# Inicializa o grafo
G = nx.Graph()
filename = sys.argv[1]

# Lê as arestas do arquivo e adiciona ao grafo
with open(filename, 'r') as edges_file:
    for line in edges_file:
        u, v, w = map(int, line.split())
        G.add_edge(u, v, weight=w)

# Lê os valores de closeness centrality do arquivo
closeness_centrality = {}
with open('saida.txt', 'r') as closeness_file:
    for line in closeness_file:
        node, value = line.split()
        closeness_centrality[int(node)] = float(value)

# Desenha o grafo
pos = nx.spring_layout(G, seed=17)
plt.figure(figsize=(15, 8))

# Define a cor de cada nó baseado no valor de closeness centrality
node_colors = [closeness_centrality.get(node, 0) for node in G.nodes()]

node_colors = [1 - color for color in node_colors]

# Desenha os nós
sc = nx.draw_networkx_nodes(G, pos, node_color=node_colors, cmap=plt.cm.jet, node_size=300)

# Desenha as arestas
nx.draw_networkx_edges(G, pos, alpha=0.5)

# Desenha os rótulos dos nós
nx.draw_networkx_labels(G, pos, font_size=8)

# Adiciona a barra de cores para mostrar os valores de closeness centrality
plt.colorbar(sc, orientation='horizontal')

# Mostra o grafo
plt.axis('off')
plt.show()