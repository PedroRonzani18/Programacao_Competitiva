// Description: encontra os pontos de articulação de um grafo
// Complexidade: O(V+E)

const int MAX = 410;

vector  <int> adj[MAX];

void APUtil(int u, bool visited[], int disc[], int low[], int& time, int parent, bool isAP[]) {
    int children = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    for (auto v : adj[u]) {
        if (!visited[v]) {
            children++;
            APUtil(v, visited, disc, low, time, u, isAP);

            low[u] = min(low[u], low[v]);

            if (parent != -1 && low[v] >= disc[u])
                isAP[u] = true;
        }

        else if (v != parent)
            low[u] = min(low[u], disc[v]);
    }

    if (parent == -1 && children > 1)
        isAP[u] = true;
}

void AP(int V) {
    int disc[V] = { 0 };
    int low[V];
    bool visited[V] = { false };
    bool isAP[V] = { false };
    int time = 0, par = -1;

    for (int u = 0; u < V; u++)
        if (!visited[u])
            APUtil(u, visited, disc, low, time, par, isAP);

    bool printed = false;

    for (int u = 0; u < V; u++) {
        if (isAP[u] == true) {
            cout << u+1 << " ";
            printed = true;
        }
    }

    if (!printed) cout << "nenhum" << endl;
    else cout << endl;
}

void solve() {

    int n, ed; cin >> n >> ed;

    for(int i = 0; i < n; i++) 
        adj[i].clear();

    while(ed--) {
        int a, b; cin >> a >> b; a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    AP(n);
}