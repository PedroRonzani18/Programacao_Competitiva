// Description: Encontra o número de caminhos entre dois vértices em um grafo acíclico direcionado.
// Complexity: O(V + E)

const int MAXN = 1e5 + 5;

int dp[MAXN], 
int mod = 1e9 + 7, n;
vector<vector<int>> adj;

int countPaths(int s, int d) {
	if (s == d) return 1;
	if (dp[s] != -1) return dp[s];

	int c = 0;
	for (int& neigh : adj[s]) {
		int x = countPaths(neigh, d);
		if (x != -1)
			c = (c % mod + x % mod) % mod;
	}
	return (dp[s] = (c == 0) ? -1 : c);
}

int countPossiblePaths(int s, int d) {
	memset(dp, -1, sizeof dp);
	int c = countPaths(s, d);
	if (c == -1) return 0;
	return c;
}

void solve() {
    int n, ed; cin >> n >> ed;
    adj.resize(n);

    for (int i = 0; i < ed; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    int src, end; cin >> src >> end; // 0-based
    cout << countPossiblePaths(src, end) << endl;
}

