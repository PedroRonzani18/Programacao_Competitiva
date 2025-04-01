// BFS - por niveis
// 
//  Encontrar distancia entre S e outros pontos em que pontos estao agrupados (terminais)

const int MAXN = 510;
const int MAXEDG = 510; // maximo numero de terminais

int dist[MAXN];
vector<int> niveisDoNode[MAXN], nodesDoNivel[MAXEDG];

void bfs(int s) {

    queue<pair<int, int>> q; q.push({s, 0});

	dist[s] = 0;

    while (!q.empty()) {
        auto [v, dis] = q.front(); q.pop(); 

        for(auto nivel : niveisDoNode[v]) {
            for(auto u : nodesDoNivel[nivel]) {
                if (dist[u] == 0) {
                    q.push({u, dis+1});
                    dist[u] = dis + 1;
                }
            }
        }
    }
}

void solve() {

	int n, terminais, s, e;

	f(i,0,terminais) {
		int q; cin >> q;
		while(q--) {
			int v; v--;
			niveisDoNode[v].push_back(i);
			nodesDoNivel[i].push_back(v);
		}
	}

	bfs(s);

	cout << dist[e] << endl;
}
