// Description: Finds SSLP (Single Source Longest Path) in a directed acyclic graph.
// Complexity: O(V + E)
// OBS: Not tested
vector<vector<pair<int,int>>> adj;

vector<int> dagLongestPath(int s, int n) {

    vector<int> topsort = topologicalSort();
    vector<int> dist(n, INT_MIN);
    dist[s] = 0;

    for (int i = 0; i < n; i++) {
        int nodeIndex = topsort[i];
        if (dist[nodeIndex] != INT_MIN) {
            auto adjacentEdges = adj[nodeIndex];
            for (auto [u, w] : adjacentEdges) {
                int newDist = dist[nodeIndex] + w;
                if (dist[u] == INT_MIN) dist[u] = newDist;
                else dist[u] = max(dist[u], newDist);
            }
        }
    }

    return dist;
}
