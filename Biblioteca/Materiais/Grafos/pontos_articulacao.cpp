// Description: Encontra os pontos de articulação e pontes de um grafo não direcionado
// Complexidade: O(n + m)

vector<vector<pair<int,int>>> adj;
vector<int> dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsCounter, dfsRoot, rootChildren;

vector<int> verticesAns;
vector<pair<int,int>> bridgesAns;

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsCounter++;
    for (auto &[v, w] : adj[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            if (u == dfsRoot) ++rootChildren;

            articulationPointAndBridge(v);

            if (dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = 1;
            if (dfs_low[v] > dfs_num[u]) {
                bridgesAns.emplace_back(u, v);    
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if (v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

void findArtBridges(int n) {

    for (int u = 0; u < n; ++u) {
        if (dfs_num[u] == -1) {
            dfsRoot = u; rootChildren = 0;
            articulationPointAndBridge(u);
            articulation_vertex[dfsRoot] = (rootChildren > 1);
        }
    }

    for (int u = 0; u < n; ++u) {
        if (articulation_vertex[u]) {
            verticesAns.push_back(u);
        }
    }
}

void solve() {

    int n, edg; cin >> n >> edg;
    adj.assign(n, vector<pair<int,int>>());
    while(edg--) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
    }

    dfs_num.assign(n, -1); dfs_parent.assign(n, -1);
    dfs_low.assign(n,  0); articulation_vertex.assign(n, 0);
    dfsCounter = 0;

    findArtBridges(n);

    // Vertices: verticesAns
    // Bridges: bridgesAns
}