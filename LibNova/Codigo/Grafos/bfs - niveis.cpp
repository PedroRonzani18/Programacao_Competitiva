// BFS - por niveis
// 
//  Encontrar distancia entre S e outros pontos em que pontos estao agrupados (terminais)

const int MAXN = 1e4+10;
const int MAXEDG = 1e4+10;

int dist[MAXN];
vector<int> niveisDoNode[MAXN], itensDoNivel[MAXEDG];

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

	int n, ed;
	f(i,0,ed) {
		int q; cin >> q; // quantidade de elementos nesse nivel

		while(q--) {
            int v; cin >> v;
			niveisDoNode[v].push_back(i);
			itensDoNivel[i].push_back(v);
        }
	}

	int s; bfs(s);
}
