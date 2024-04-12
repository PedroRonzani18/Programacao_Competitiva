// Description: Caminho minimo entre todos os pares de vertices em um grafo
// Complexity: O(n^3)

const int INF = 1e9;
const int MAX_V = 450;
int adj[MAX_V][MAX_V];

void printAnswer(int n) {
	for (int u = 0; u < n; ++u)
	for (int v = 0; v < n; ++v)
	cout << "APSP("<<u<<", "<<v<<") = " << adj[u][v] << endl;
}

void prepareParent() {
	f(i,0,n) {
		f(j,0,n) {
			p[i][j] = i;
		}
	}

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (adj[i][k] + adj[k][j] < adj[i][j]) {
					adj[i][j] = adj[i][k]+adj[k][j];
					p[i][j] = p[k][j];
				}
}

vi restorePath(int u, int v) {

	if (adj[u][v] == INF) return {};
	vi path;
	for (; v != u; v = p[u][v]) {
		if (v == -1) return {};
		path.push_back(v);
	}
	path.push_back(u);
	reverse(path.begin(), path.end());
	return path;
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

	// prepareParent();
	// vi path = restorePath(0, 3);
}