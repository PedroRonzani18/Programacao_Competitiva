// Description: Encontrar distancia entre S e outros pontos em que pontos estao agrupados (terminais)
// EXTRA: BFS diferenciado para armazenar distancias sem VIS

int n; 
vi dist;
vector<vi> gruposDoItem, itensDoGrupo;

void bfs(int s) {

    queue<pair<int, int>> q; q.push({s, 0});

    while (!q.empty()) {
        auto [v, dis] = q.front(); q.pop(); 

        for(auto grupo : gruposDoItem[v]) {
            for(auto u : itensDoGrupo[grupo]) {
                if (dist[u] == 0) {
                    q.push({u, dis+1});
                    dist[u] = dis + 1;
                }
            }
        }
    }
}

void solve() {

    int n, ed; cin >> n >> ed;
	dist.clear(), itensDoGrupo.clear(), gruposDoItem.clear();
    itensDoGrupo.resize(n);

	f(i,0,ed) {

		int q; cin >> q;
        while(q--) {
            int v; cin >> v;
			gruposDoItem[v].push_back(i);
			itensDoGrupo[i].push_back(v);
        }
	}

	bfs(0);
}