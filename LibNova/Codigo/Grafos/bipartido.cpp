// IsBipartido
//
// Verifica se um grafo eh bipartido
// O(V+E)

const int MAXN = 110;

vector<int> adj[MAXN];
int color[MAXN];

bool bipartido(int n) {

    int s = 0;
    queue<int> q; q.push(s);
    color[s] = 0;
    bool ans = true; 

    while (!q.empty() and ans) { 
        int u = q.front(); q.pop();

        for (auto &v : adj[u]) {
            if (color[v] == INF) {                            
                color[v] = 1 - color[u]; 
                q.push(v);
            }
            else if (color[v] == color[u]) {                        
                ans = false; 
                break;               
            }
        }
    }

    return ans;
}

void solve(int n) {

	f(i,0,n) {
		adj[i] = vector<int>();
		color[i] = INF;
	}

	// preenche grafo ...

	bool ans = bipartido(n);
}
