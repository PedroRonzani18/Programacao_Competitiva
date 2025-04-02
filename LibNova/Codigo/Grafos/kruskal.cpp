// Kruskal
//
// Encontra a Arvore Geradora Minima (AGM) de um grafo
// O(E log V)

const int MAXN = 1e3+10;

int id[MAXN], sz[MAXN];

int find(int a) { 
    return id[a] = (id[a] == a ? a : find(id[a]));
}

void uni(int a, int b) { // O(a(N)) amortizado
    a = find(a), b = find(b);
    if(a == b) return;

    if(sz[a] > sz[b]) swap(a,b);
    id[a] = b, sz[b] += sz[a];
}

int kruskal(vector<tuple<int, int, int>>& edg) {
	
	int cost = 0;
	// vector<tuple<int, int, int>> mst;
	for (auto [w,x,y] : edg) if (find(x) != find(y)) {
		// mst.emplace_back(w, x, y);
		cost += w; 
		uni(x,y);
	}
	return cost;
}

void solve(int n, int ed) {

	vector<tuple<int, int, int>> edg(n);

	for(auto& [w,u,v] : edg) {
		cin >> u >> v >> w; u--, v--;
	}

	f(i,0,n) {
		id[i] = i;
		sz[i] = -1;
	}
	
	sort(all(edg));

	int cost = kuskal(edg);
}

// VARIANTES

// Maximum Spanning Tree: sort(edg.rbegin(), edg.rend());

// 'Minimum' Spanning Subgraph:
//	- Algumas arestas ja foram adicionadas (maior prioridade - Questao das rodovias)
//	- Arestas que nao foram adicionadas (menor prioridade - ferrovias)
//	-> kruskal(rodovias); kruskal(ferrovias);

// Minimum Spanning Forest:
// 	- Queremos uma floresta com k componentes
// 	-> kruskal(edg); if(mst.sizer() == k) break;

//  MiniMax
//	- Encontrar menor caminho entre dous vertices com maior quantidade de arestas
//	-> kruskal(edg); dijsktra(mst);

// Second Best MST
// 	- Encontrar a segunda melhor arvore geradora minima
// 	-> kruskal(edg);
// 	-> flag mst[i] = 1;
// 	-> sort(cmp(edg.flag != -1)) => da prioridade para outras arestas
