// Description: Retorna ordenacao topologica de adj, e vazio se nao for DAG
// Complexidade: O(V+E)
// Explicacao: usado para ordenar vercies de um DAG de forma que para cada aresta direcionada uv, o vértice u aparece antes do vértice v na ordenacao

#define MAXN 50010

int grauEntrada[MAXN];
vi adj[MAXN];

vi topologicalSort(int n) {

	priority_queue<int, vi, greater<int>> pq;

	f(i,0,n) {
		if(!grauEntrada[i])
			pq.push(i);
	}

	vi ans;

	while (!pq.empty()) {
		int node = pq.top(); pq.pop();

		for(auto x : adj[node]) {
			grauEntrada[x]--;
			if (!grauEntrada[x])
				pq.push(x);
		}

		ans.push_back(node);
	}

	return ans.size() == n ? ans : vi();
}

void solve() {

	int n, ed; cin >> n >> ed;

	memset(grauEntrada, 0, sizeof grauEntrada);

	while(ed--) {
		int a, b; cin >> a >> b;
		grauEntrada[b]++;
		adj[a].push_back(b);
	}

	vi ans = topologicalSort(n);
}
