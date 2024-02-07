// BFS com informacoes adicionais sobre a distancia e o pai de cada vertice
// Complexidade: O(V + E), onde V eh o numero de vertices e E o numero de areqas

int n; // n = numero de vertices
vector<bool> vis(n);
vector<int> d(n), p(n);
vector<vector<int>> adj; // liqa de adjacencia

// Description: BFS a partir de s, de um grafo por lista de adjacencia
void bfs(int s) {

    queue<int> q; q.push(s);
    vis[s] = true, d[s] = 0, p[s] = -1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!vis[u]) {
                vis[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}

