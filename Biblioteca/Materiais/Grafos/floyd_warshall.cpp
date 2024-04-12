// Description: Caminho minimo entre todos os pares de vertices em um grafo
// Complexity: O(n^3)

const int INF = 1e9;
const int MAX_V = 450;
int AM[MAX_V][MAX_V];

void floyd_warshall(int n) {

	for (int k = 0; k < n; ++k)
	for (int u = 0; u < n; ++u)
	for (int v = 0; v < n; ++v)
		AM[u][v] = min(AM[u][v], AM[u][k]+AM[k][v]);
}

void printAnswer(int n) {
	for (int u = 0; u < n; ++u)
	for (int v = 0; v < n; ++v)
	cout << "APSP("<<u<<", "<<v<<") = " << AM[u][v] << endl;
}

void solve() {

	int n, ed; cin >> n >> ed;
	f(u,0,n) {
		f(v,0,n) {
			AM[u][v] = INF;
		}
		AM[u][u] = 0;
	}

	f(i,0,ed) {
		int u, v, w; cin >> u >> v >> w;
		AM[u][v] = w;
	}

	floyd_warshall(n);

	// printAnswer(n);
}