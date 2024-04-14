// Description: Verifica se o vertice i esta diretamente conectado ao vertice j
// Complexity: O(n^3)

const int INF = 1e9;
const int MAX_V = 450;
int adj[MAX_V][MAX_V];

void transitive_closure(int n) {

    for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
        adj[i][j] |= (adj[i][k] & adj[k][j]);
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

	transitive_closure(n);

    int i = 0, j = 0; cin >> i >> j;
    cout << (adj[i][j] == INF ? "Nao" : "Sim") << endl;
}