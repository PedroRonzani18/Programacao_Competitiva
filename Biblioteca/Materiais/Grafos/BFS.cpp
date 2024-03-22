// BFS com informacoes adicionais sobre a distancia e o pai de cada vertice
// Complexidade: O(V + E), onde V eh o numero de vertices e E o numero de areqas

int n; // n = numero de vertices
vector<bool> vis;
vector<int> d, p;
vector<vector<int>> adj;

void bfs(int s) {

    queue<int> q; q.push(s);
    vis[s] = true, d[s] = 0, p[s] = -1;

    while (!q.empty()) {
        int v = q.front(); q.pop(); 
        vis[v] = true;
        
        for (int u : adj[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
                // d[u] = d[v] + 1;
                // p[u] = v;
            }
        }
    }
}

void solve() {
    cin >> n; 
    adj.resize(n); d.resize(n, -1);
    vis.resize(n); p.resize(n, -1); 
    
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(0);
}

