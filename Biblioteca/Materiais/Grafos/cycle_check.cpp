// Descriptionn: Checa se um grafo direcionado possui ciclos e imprime os tipos de arestas.
// Complexidade: O(V + E)

vector<vector<pii>> adj;
vi dfs_num, dfs_parent;

void cycleCheck(int u) {
    dfs_num[u] = -2;
    for (auto &[v, w] : adj[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            cycleCheck(v);
        }
        else if (dfs_num[v] == -2) {
            if (v == dfs_parent[u])
                cout << " Bidirectional Edge (" << u << ", " << v << ")-(" << v << ", " << u << ")\n";
            else
                cout << "Back Edge (" << u << ", " << v << ") (Cycle)\n";
        }
        else if (dfs_num[v] == -3)
            cout << "  Forward/Cross Edge (" << u << ", " << v << ")\n";
    }
    dfs_num[u] = -3;
}

void solve() {
    int n, ed; cin >> n >> ed;
    adj.assign(ed, vector<pii>());

    for (int i = 0; i < ed; ++i) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    cout << "Graph Edges Property Check\n";
    dfs_num.assign(ed, -1);
    dfs_parent.assign(ed, -1);
    for (int u = 0; u < n; ++u)
        if (dfs_num[u] == -1)
        cycleCheck(u);  
}