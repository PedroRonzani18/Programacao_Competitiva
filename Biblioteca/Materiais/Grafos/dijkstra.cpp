// Encontra o menor caminho de um vértice s para todos os outros vértices do grafo.
//Complexidade: O((V + E)logV)

int n; 
vector<vector<pair<int, int>>> adj; // adj[a] = [{b, w}]
vector<int> dist, parent; /*dist[a] = dist(source -> a)*/
vector<bool> vis; 

void dijkstra(int s) {

	dist.resize(n+1, LINF-10);
	vis.resize(n+1, false);
    parent.resize(n+1, -1);
    dist[s] = 0;
    
    priority_queue<pair<int, int>> q;
    q.push({0, s});

    while (!q.empty()) {
        int a = q.top().second; q.pop();

        if (vis[a]) continue;
        vis[a] = true;

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

void solve() {

    adj.resize(n); /*n = nodes*/
    f(i,0,n) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    dijkstra(0);
}

// VARIANTES

/* Menor caminho de todos os vertices para um vertice s
    -> Inverter a direcao das arestas
    -> dijkstra(s)
*/

/* Multi-Sources Shortest Paths
    - Menor caminho de um conjunto de vertices para todos os outros
    -> dist[a] = 0, q.push(a) para todo source a
    -> dijkstra()
*/
