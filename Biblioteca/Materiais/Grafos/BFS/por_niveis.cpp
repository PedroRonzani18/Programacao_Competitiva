// Description: Encontrar distancia entre S e outros pontos em que pontos estao agrupados (terminais)
// EXTRA: BFS diferenciado para armazenar distancias sem VIS

int n; 
vi dist;
vector<vi> niveisDoNode, itensDoNivel;

void bfs(int s) {

    queue<pair<int, int>> q; q.push({s, 0});

    while (!q.empty()) {
        auto [v, dis] = q.front(); q.pop(); 

        for(auto nivel : niveisDoNode[v]) {
            for(auto u : itensDoNivel[nivel]) {
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
	dist.clear(), itensDoNivel.clear(), niveisDoNode.clear();
    itensDoNivel.resize(n);

	f(i,0,ed) {
		int q; cin >> q;
        while(q--) {
            int v; cin >> v;
			niveisDoNode[v].push_back(i);
			itensDoNivel[i].push_back(v);
        }
	}

	bfs(0);
}