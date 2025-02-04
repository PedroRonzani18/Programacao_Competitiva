Arvore (NDAG): 

* Definicao
    - contém V vertices e V-1 arestas (E = V-1)
    - todo algoritmo O(V+E) numa arvore eh O(V)
    - nao direcionado
    - sem ciclo
    - conexa
    - um unico caminho para todo par de vertices

* Aplicacoes

    -> TREE TRAVERSAL
        pre-order(v):           in-order(v):            post-order(v):
            visit(v)                in-order(left(v))       post-order(left(v))
            pre-order(left(v))      visit(v)                post-order(right(v))
            pre-order(right(v))     in-order(right(v))      visit(v)

    -> Pontos de Articulacao / Pontes
        - todo vertice eh ponto de articulacao

    -> Single Source Shortest Path (SSSP)
        - O(V) para achar o caminho minimo de um vertice para todos os outros
        - BFS ou DFS funcionam, mesmo com pesos

    -> All Pairs Shortest Path (APSP)
        - O(V^2) para achar o caminho minimo de todos para todos
        - V * SSSP

    -> Diametro
        - greatest 'shortest path length' between any pair of vertices
        - 2 * SSSP:
            1. BFS/DFS de qualquer vertice
            2. BFS/DFS do vertice mais distante => diametro = maior distancia

    -> Lowest Common Ancestor (LCA)
        - O(V) para achar o LCA de 2 vertices
        - O(V) para pre-processar
