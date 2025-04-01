// BFS
//
// O(V + E)

const int MAXN = 1e4+10;

bool vis[MAXN];
int d[MAXN], p[MAXN];
vector<int> adj [MAXN];

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
    int n, ed; 
    
	f(i,0,n) { d[i] = -1, p[i] = -1; }    
	
	while(ed--) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

	int s; bfs(s);
}
