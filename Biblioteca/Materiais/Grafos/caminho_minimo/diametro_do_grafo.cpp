// Description: Encontra o diametro de um grafo
//  => maximum shortest path between any two vertices
// Complexidade: O(n^3)

int adj[MAX_V][MAX_V];

int diameter(int n) {
    int ans = 0;
    f(u,0,n) {
        f(v,0,n) {
            if (adj[u][v] != INF) {
                ans = max(ans, adj[u][v]);
            }
        }
    }
    return ans;
}

void floyd_warshall(int n) {

	for (int k = 0; k < n; ++k)
	for (int u = 0; u < n; ++u)
	for (int v = 0; v < n; ++v)
		adj[u][v] = min(adj[u][v], adj[u][k]+adj[k][v]);
}

void solve() {

	int n, ed; cin >> n >> ed;
	f(u,0,n) {
		f(v,0,n) {
			adj[u][v] = INF;
		}
		adj[u][u] = 0;
	}

	f(i,0,ed) {
		int u, v, w; cin >> u >> v >> w;
		adj[u][v] = w;
	}

	floyd_warshall(n);
    cout << diameter(n) << endl;
}