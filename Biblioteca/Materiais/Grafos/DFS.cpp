vector<int> adj[MAXN], parent;
int visited[MAXN];

// DFS com informacoes adicionais sobre o pai de cada vertice
// Complexidade: O(V + E), onde V eh o numero de vertices e E o numero de areqas
void dfs(int p) {
    memset(visited, 0, sizeof visited);
    stack<int> st;
    st.push(p);

    while (!st.empty()) {
        int v = st.top(); st.pop();

        if (visited[v]) continue;
        visited[v] = true;
        
        for (int u : adj[v]) {
            if (!visited[u]) {
                parent[u] = v;
                st.push(u);
            }
        }
    }
}

// DFS com informacoes adicionais sobre o pai de cada vertice
// Complexidade: O(V + E), onde V eh o numero de vertices e E o numero de areqas
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            parent[u] = v;
            dfs(u);
        }
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
}