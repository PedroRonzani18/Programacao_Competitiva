// Description: Encontra o numero de componentes fortemente conexas em um grafo direcionado
// Complexidade: O(V + E)

int dfsNumberCounter, numSCC;
vector<vii> adj, adj_t;
vi dfs_num, dfs_low, S, visited;
stack<int> St;

void kosarajuUtil(int u, int pass) {
	dfs_num[u] = 1;
	vii &neighbor = (pass == 1) ? adj[u] : adj_t[u];
	for (auto &[v, w] : neighbor)
		if (dfs_num[v] == -1)
		kosarajuUtil(v, pass);
	S.push_back(u);
}

bool kosaraju(int n) {
	
	S.clear();
	dfs_num.assign(n, -1);

	f(u,0,n) {
		if (dfs_num[u] == -1)
			kosarajuUtil(u, 1);
	}

	int numSCC = 0;
	dfs_num.assign(n, -1);
	f(i,n-1,-1) {
		if (dfs_num[S[i]] == -1)
			numSCC++, kosarajuUtil(S[i], 2);
	}

	return numSCC == 1;
}

void solve() {
	
	int n, ed; cin >> n >> ed;
	adj.assign(n, vii());
	adj_t.assign(n, vii());

	while (ed--) {
		int u, v, w; cin >> u >> v >> w;
		AL[u].emplace_back(v, 1);
		adj_t[v].emplace_back(u, 1);
	}

	// Printa se o grafo eh fortemente conexo
	cout << kosaraju(n) << endl; 

	// Printa o numero de componentes fortemente conexas
	cout << numSCC << endl;

	// Printa os vertices de cada componente fortemente conexa
	f(i,0,n){
		if (dfs_num[i] == -1) cout << i << ": " << "Nao visitado" << endl;
		else cout << i << ": " << dfs_num[i] << endl;	
	}
}