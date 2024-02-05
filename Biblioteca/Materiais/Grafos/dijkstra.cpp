int n; 
vector<vector<pair<int, int>>> adj(n); // adj[a] = [{b, w}]
vector<int> dist(n, INF);
vector<int> parent(n, -1);
vector<bool> used(n); 

// Encontra o menor caminho de um vértice s para todos os outros vértices do grafo.
//Complexidade: O((V + E)logV)
void dijkstra(int s) {

    dist[s] = 0;
    
    priority_queue<pair<int, int>> q;
    q.push({0, s});

    while (!q.empty()) {
        int a = q.top().second; q.pop();

        if (used[a]) continue;
        used[a] = true;

        for (auto [b, w] : adj[a]) {
            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
                parent[b] = a;
                q.push({-dist[b], b});
            }
        }
    }
}

//Complexidade: O(V)
vector<int> restorePath(int v) {
    vector<int> path;
    for (int u = v; u != -1; u = parent[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}

void call() {
    // ... read the graph ...
    f(i,0,n) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    dijkstra(0);
    // ... use dist[] and parent[] ...
}