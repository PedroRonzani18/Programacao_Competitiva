// Description: Encontra menor caminho em grafos com pesos negativos
/* Complexidade: 
    Conexo: O(VE)
    Desconexo: O(EV^2)
*/
// Classe: Single Source Shortest Path (SSSP)

vector<tuple<int,int,int>> edg; // edge: u, v, w
vi dist;

int bellman_ford(int n, int src) {
    dist.assign(n+1, INT_MAX);

    f(i,0,n+2) {
        for(auto& [u, v, w] : edg) {
            if(dist[u] != INT_MAX and dist[v] > w + dist[u])
                dist[v] = dist[u] + w;
        }
    }

    // Possivel checar ciclos negativos (ciclo de peso total negativo)
    for(auto& [u, v, w] : edg) {
        if(dist[u] != INT_MAX and dist[v] > w + dist[u])
            return 1;
    }

    return 0;
}

int main() {

    int n, edges; cin >> n >> edges;
    f(i,0,edges) {
        int u, v, w; cin >> u >> v >> w;
        edg.push_back({u, v, w});
    }
    bellman_ford(n, 1);
}
