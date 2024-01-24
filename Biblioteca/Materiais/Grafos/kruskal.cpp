// Kruskal
//
// Gera e retorna uma AGM e seu custo total a partir do vetor de arestas (edg)
// do grafo
//
// O(m log(m) + m a(m))

vector<tuple<int, int, int>> edg; // {peso,x,y}
vector<int> id, sz;

int find(int p){ // O(a(N)) amortizado
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void uni(int p, int q) { // O(a(N)) amortizado
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p,q);
    id[p] = q, sz[q] += sz[p];
}

pair<int, vector<tuple<int, int, int>>> kruskal(int n) {
	sort(edg.begin(), edg.end());
	int cost = 0;
	vector<tuple<int, int, int>> mst;
	for (auto [w,x,y] : edg) if (find(x) != find(y)) {
		mst.emplace_back(w, x, y);
		cost += w;
		uni(x,y);
	}
	return {cost, mst};
}