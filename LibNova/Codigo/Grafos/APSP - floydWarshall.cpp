// APSP - Floyd Warshall
//
// Calcula caminho minimo entre todos os pares de vertices
// O(V^3)

const int MAXN = 110;

int adj[MAXN][MAXN];

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

vector<int> restorePath(int u, int v) {

	if (adj[u][v] == INF) return {};
	vector<int>  path;
	for (; v != u; v = p[u][v]) {
		if (v == -1) return {};
		path.push_back(v);
	}
	path.push_back(u);
	reverse(path.begin(), path.end());
	return path;
}

void floyd_warshall(int n) {
	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

void solve(int n, int ed) {

	f(i,0,n) {
		f(j,0,n) {
			adj[i][j] = INF;
		}
		adj[i][i] = 0;
	}

	while(ed--) {
		int u, v, w; cin >> u >> v >> w; u--, v--;
		adj[u][v] = adj[v][u] = w;
	}

	floyd_warshall(n);

	// prepareParent();
	// auto path = restorePath(0, 3);
}

// Diametro do Grafo: maior valor de adj[u][v] != INF
