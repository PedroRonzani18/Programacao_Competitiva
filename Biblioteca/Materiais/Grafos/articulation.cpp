// Description: Encontra pontos de articulacao e pontes em um grafo nao direcionado
// Complexidade: O(V + E)

vector<vector<pii>> adj;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
vector<pii> bridgesAns;

void articulationPointAndBridgeUtil(int u) {

    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for (auto &[v, w] : adj[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            if (u == dfsRoot) ++rootChildren;

            articulationPointAndBridgeUtil(v);

            if (dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = 1;
            if (dfs_low[v] > dfs_num[u])
                bridgesAns.push_back({u, v});
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void articulationPointAndBridge(int n) {
    dfsNumberCounter = 0;
    f(u,0,n) {
        if (dfs_num[u] == -1) {
            dfsRoot = u; rootChildren = 0;
            articulationPointAndBridgeUtil(u);
            articulation_vertex[dfsRoot] = (rootChildren > 1);
        }
    }
}

void solve() {

    int n, ed; cin >> n >> ed;
    adj.assign(n, vector<pii>());

    f(i,0,ed) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    dfs_num.assign(n, -1); dfs_low.assign(n, 0);
    dfs_parent.assign(n, -1); articulation_vertex.assign(n, 0);

    articulationPointAndBridge(n);

    // Vertices: articulation_vertex[u] == 1
    // Bridges: bridgesAns
}
