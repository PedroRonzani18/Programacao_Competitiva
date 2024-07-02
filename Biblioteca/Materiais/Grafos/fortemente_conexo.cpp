// Description: Checa se um grafo direcionado eh fortemente conexo
// Complexidade: O(V + E)

const int MAX = 10010;

vector<int> adj[MAX], transp[MAX];
bool visited[MAX];

void bfs(int v, vector<int> adj[]) { 
	
	queue<int> q; q.push(v); 
	visited[v] = true; 
	
	while (!q.empty()) { 
		v = q.front(); q.pop(); 

		for(auto i : adj[v]) {
			if (!visited[i]) { 
				visited[i] = true; 
				q.push(i); 
			} 
		} 
	} 
} 

bool isSC(int n) { 

	bfs(0, adj); 

	f(i,0,n) {
		if (!visited[i]) 
			return false; 
	}

	f(i,0,n) {
		visited[i] = false; 
	}

	bfs(0, transp);

	f(i,0,n) {
		if (!visited[i]) 
			return false; 
	}

	return true; 
} 

void solve() {

	int n; cin >> n;

	f(i,0,n) {
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
		transp[b].push_back(a);
	}

	cout << (isSC(n) ? "S" : "N") << endl;
}