vi dist;
vector<vector<pii>> adj;

void dijkstra(int s) {

    dist[s] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq; pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue;
        
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