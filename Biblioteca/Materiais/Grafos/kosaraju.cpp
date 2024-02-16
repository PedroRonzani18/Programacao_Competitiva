// Kosaraju
//
// Complexidade: O(n + m)

int n;
vector<int> g[MAX], gi[MAX]; // grafo invertido
int vis[MAX], comp[MAX]; // componente de cada vértice 
stack<int> S;

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);

	S.push(k);
}

// Descricao: Calcula as componentes fortemente conexas de um grafo
void scc(int k, int c) { 
	vis[k] = 1;
	comp[k] = c; // componente de k eh c
	for (int i = 0; i < (int) gi[k].size(); i++)
		if (!vis[gi[k][i]]) scc(gi[k][i], c);
}

void kosaraju() {
    
	memset(vis, 0, sizeof(vis));    
    for(int i=0; i<n; i++) if(!vis[i]) dfs(i);
	memset(vis, 0, sizeof(vis));
    
	while (S.size()) {
		int u = S.top(); S.pop();
		if (!vis[u]) scc(u, u);
	}
}