// Description: Encontra os pontos de articulação e pontes de um grafo não direcionado
// Complexidade: O(n + m)

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<vii> adj;
vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsCounter, dfsRoot, rootChildren;

void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsCounter++;  // dfs_low[u]<=dfs_num[u]
    for (auto &[v, w] : adj[u]) {
        if (dfs_num[v] == -1) {               // a tree edge
            dfs_parent[v] = u;
            if (u == dfsRoot) ++rootChildren;          // special case, root

            articulationPointAndBridge(v);

            if (dfs_low[v] >= dfs_num[u])              // for articulation point
                articulation_vertex[u] = 1;              // store this info first
            if (dfs_low[v] > dfs_num[u])               // for bridge
                cout << " Edge (" << u << ", " << v << ") is a bridge" << endl;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);  // subtree, always update
        }
        else if (v != dfs_parent[u])                 // if a non-trivial cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);  // then can update
    }
}

int main() {
    /*
    // Left graph in Figure 4.6/4.7/4.8
    6
    1 1 0
    3 0 0 2 0 4 0
    1 1 0
    1 4 0
    3 1 0 3 0 5 0
    1 4 0

    // Right graph in Figure 4.6/4.7/4.8
    6
    1 1 0
    5 0 0 2 0 3 0 4 0 5 0
    1 1 0
    1 1 0
    2 1 0 5 0
    2 1 0 4 0
    */

   int n, edg; cin >> n >> edg;
    adj.assign(n, vii());
    while(edg--) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
    }

    dfs_num.assign(n, -1); dfs_low.assign(n, 0);
    dfs_parent.assign(n, -1); articulation_vertex.assign(n, 0);
    dfsCounter = 0;
    cout << "Bridges:" << endl;
    for (int u = 0; u < n; ++u)
        if (dfs_num[u] == -1) {
            dfsRoot = u; rootChildren = 0;
            articulationPointAndBridge(u);
            articulation_vertex[dfsRoot] = (rootChildren > 1); // special case
        }

    cout << "Articulation Points:" << endl;
    for (int u = 0; u < n; ++u)
        if (articulation_vertex[u])
            cout << " Vertex " << u << endl;

    return 0;
}