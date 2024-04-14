// Description: Encontra SSSP (Single Source Shortest Path) em um grafo acíclico direcionado.
// Complexity: O(V + E)
// OBS: Nao testado
vector<vector<pair<int,int>>> adj;

vector<int> dagShortestPath(int s, int n) {

    vector<int> topsort = topologicalSort();
    vector<int> dist(n, INT_MAX);
    dist[s] = 0;

    for (int i = 0; i < n; i++) {
        int nodeIndex = topsort[i];
        if (dist[nodeIndex] != nodeIndex) {
            auto adjacentEdges = adj[nodeIndex];
            for (auto [u, w] : adjacentEdges) {
                int newDist = dist[nodeIndex] + w;
                if (dist[u] == INT_MAX) dist[u] = newDist;
                else dist[u] = min(dist[u], newDist);
            }
        }
    }

    return dist;
}
