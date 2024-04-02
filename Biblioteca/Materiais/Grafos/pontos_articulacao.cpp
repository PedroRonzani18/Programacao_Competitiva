// Description: Encontra os pontos de articulação de um grafo não direcionado
// Complexidade: O(V*(V+E))

int V;
vector<vi> adj;
vi ans;

void dfs(vector<bool>& vis, int i, int curr) {
	vis[curr] = 1;
	for (auto x : adj[curr]) {
		if (x != i) {
			if (!vis[x]) {
				dfs(vis, i, x);
			}
		}
	}
}

void AP() {

    f(i,1,V+1) {
		int components = 0;
		vector<bool> vis(V + 1, 0);
        f(j,1, V+1) {
			if (j != i) {
				if (!vis[j]) {
					components++;
					dfs(vis, i, j);
				}
			}
		}
		if (components > 1) {
			ans.push_back(i);
		}
	}
}

void solve() {

	V = n; 
	adj.clear(), ans.clear(); 
    adj.resize(V+1);
    
	while(edg--) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	AP();

	// Vertices articulacao: ans
}