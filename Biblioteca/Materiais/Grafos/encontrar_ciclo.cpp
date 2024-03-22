// Description: Encontrar ciclo em grafo nao direcionado
// Complexidade: O(n + m)

int n;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> p;
int cycle_start, cycle_end;

bool dfs(int v, int par) {
    vis[v] = true;
    for (int u : adj[v]) {
        if(u == par) continue; 
        if(vis[u]) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        p[u] = v;
        if(dfs(u, p[u]))
            return true;
    }
    return false;
}

vector<int> find_cycle() {
    cycle_start = -1;

    for (int v = 0; v < n; v++)
        if (!vis[v] and dfs(v, p[v]))
            break;

    if (cycle_start == -1) return {};

    vector<int> cycle;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = p[v])
        cycle.push_back(v);
    cycle.push_back(cycle_start);
    return cycle;
}

void solve() {
    int edg; cin >> n >> edg;
    adj.assign(n, vector<int>());
    vis.assign(n, false), p.assign(n, -1);
    while(edg--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> ans = find_cycle();
}