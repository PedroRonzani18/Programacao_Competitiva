// SSSP - Dijktra
//
// O(E log V)

const int MAXN = 1e4+10;

vector<pair<int,int>> adj[MAXN];
int dist[MAXN];
// int parent[MAXN];

void dijkstra(int s) {
    dist[s] = 0; // se eventualmente puder voltar pra ca, tipo ciclo | salesman | remover essa linha
    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
		 // if(u == s and dist[u] < INF) break; | pra quando tiver que fazer um ciclo

        for (auto &[v, w] : adj[u]) {
            if (dist[u] + w >= dist[v]) continue;
            dist[v] = dist[u]+w;
			// parent[v] = u;
            pq.push({dist[v], v});
        }
    }
}

void solve() {

	int v, ed; cin >> v >> ed;
	f(i,0,v) { 	dist[i] = INF; }

	while(ed--) {
		int a, b, w; cin >> a >> b >> w; a--, b--;
		adj[a].emplace_back(b,w);
		// adj[b].emplace_back(a,w);
	}
	int s; dijkstra(s);
}
