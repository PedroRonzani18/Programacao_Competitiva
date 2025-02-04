// Descricao: Encontra a euler tree de um grafo
// Complexidade: O(n)
vector<vector<int>> adj(MAX);
vector<int> vis(MAX, 0);
vector<int> euTree(MAX);

void eulerTree(int u, int &index) {
    vis[u] = 1;
    euTree[index++] = u;
    for (auto it : adj[u]) {
        if (!vis[it]) {
            eulerTree(it, index);
            euTree[index++] = u;
        }
    }
}

void solve() {

	f(i,0,n-1) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

    int index = 0; eulerTree(1, index);
}