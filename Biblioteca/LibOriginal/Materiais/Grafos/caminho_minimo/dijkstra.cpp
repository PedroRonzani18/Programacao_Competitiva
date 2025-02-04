// Description: Algoritmo de Dijkstra para caminho mínimo em grafos.
// Complexity: O(E log V)
// Classe: Single Source Shortest Path (SSSP)

vi dist;
vector<vector<pii>> adj;

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
            pq.push({dist[v], v});
        }
    }
}

void solve() {

    int n, ed; cin >> n >> ed;
    adj.assign(n, vector<pii>());
    dist.assign(n, INF); // INF = 1e9

    while (ed--) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }

    int s; cin >> s;
    dijkstra(s);
}