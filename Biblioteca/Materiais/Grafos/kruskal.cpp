// Kruskal
//
// Gera e retorna uma AGM e seu custo total a partir do vetor de arestas (edg) do grafo
//
// Complexidade: O(ElogE) onde E eh o numero de arestas
// 
// O(m log(m) + m a(m)) = O(m log(m))

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

	sort(edg.begin(), edg.end());
	
	int cost = 0;
	vector<tuple<int, int, int>> mst; // opcional
	for (auto [w,x,y] : edg) if (find(x) != find(y)) {
		mst.emplace_back(w, x, y); // opcional
		cost += w; 
		uni(x,y);
	}
	return {cost, mst};
}

int main() {

	int n/*nodes*/, ed/*edges*/;

	id.resize(n); iota(all(id), 0);
	sz.resize(n, -1);
	vector<tuple<int, int, int>> edg;

	f(i,0,ed) {
		int a, b, w; cin >> a >> b >> w;
		edg.push_back({w, a, b});
	}

	auto [cost, mst] = kruskal(edg);
}