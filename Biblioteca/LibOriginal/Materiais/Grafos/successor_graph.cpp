// Encontra sucessor de um vertice dentro de um grafo direcionado
// Pre calcular: O(nlogn)
// Consulta: O(logn)

vector<vector<int>> adj;

int succ(int x, int u) {
    if(k == 1) return adj[x][0];
    return succ(succ(x, k/2), k/2); 
}