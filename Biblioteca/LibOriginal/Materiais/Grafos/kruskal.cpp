// DEscricao: Encontra a arvore geradora minima de um grafo
// Complexidade: O(E log V)

vector<int> id, sz;

int find(int a){ // O(a(N)) amortizado
    return id[a] = (id[a] == a ? a : find(id[a]));
}

void uni(int a, int b) { // O(a(N)) amortizado
    a = find(a), b = find(b);
    if(a == b) return;

    if(sz[a] > sz[b]) swap(a,b);
    id[a] = b, sz[b] += sz[a];
}

pair<int, vector<tuple<int, int, int>>> kruskal(vector<tuple<int, int, int>>& edg) {

	sort(edg.begin(), edg.end()); // Minimum Spanning Tree 
	
	int cost = 0;
	vector<tuple<int, int, int>> mst; // opcional
	for (auto [w,x,y] : edg) if (find(x) != find(y)) {
		mst.emplace_back(w, x, y); // opcional
		cost += w; 
		uni(x,y);
	}
	return {cost, mst};
}

void solve() {

	int n, ed;

	id.resize(n); iota(all(id), 0);
	sz.resize(n, -1);
	vector<tuple<int, int, int>> edg;

	f(i,0,ed) {
		int a, b, w; cin >> a >> b >> w;
		edg.push_back({w, a, b});
	}

	auto [cost, mst] = kruskal(edg);
}

// VARIANTES

// Maximum Spanning Tree: sort(edg.rbegin(), edg.rend());

/* 'Minimum' Spanning Subgraph:
	- Algumas arestas ja foram adicionadas (maior prioridade - Questao das rodovias)
	- Arestas que nao foram adicionadas (menor prioridade - ferrovias)
	-> kruskal(rodovias); kruskal(ferrovias);
*/

/* Minimum Spanning Forest:
	- Queremos uma floresta com k componentes
	-> kruskal(edg); if(mst.sizer() == k) break;
*/

/* MiniMax
	- Encontrar menor caminho entre dous vertices com maior quantidade de arestas
	-> kruskal(edg); dijsktra(mst);
*/

/* Second Best MST
	- Encontrar a segunda melhor arvore geradora minima
	-> kruskal(edg); 
	-> flag mst[i] = 1;
	-> sort(cmp(edg.flag != -1)) => da prioridade para outras arestas
*/

