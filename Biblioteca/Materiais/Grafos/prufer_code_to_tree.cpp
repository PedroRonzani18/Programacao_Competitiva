bool vis [MAX];
vector<int> adj[MAX];
int freq[MAX];

void dfs (int a) {
    vis[a] = true;
    cout << "(" << a;
    for (const auto& p : adj[a]) {
        if (!vis[p]) {
            cout << " ";
            dfs(p);
        }
	}
    
    cout << ")";
}

// Description: Dado um código de Prufer, construir a árvore correspondente, prenchendo a lista de adjacência
// Complexidade: O(V^2)
void pruferCodeToTree(queue<int>& q, int V) {

	f(j,1,V) {
		f(i,1,V+1) {
			if (freq[i] == 0) {

				int front = q.front(); q.pop();

				freq[i] = -1; // mark as visited 
				freq[front]--; // decrease the frequency of the front element

				adj[front].push_back(i);
				adj[i].push_back(front);
				
				break;
			}
		}
	}
}

void solve(string s) {

	int testNum = s[0];

	if(!('0' <= testNum and testNum <= '9')) {
		cout << "(1)" << endl; 
		return;
	}

	memset(freq, 0, sizeof(freq));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < MAX; i++) adj[i].clear(); // 

	stringstream ss(s);
	int v;
	
	queue<int> q;
	while (ss >> v) {
		freq[v]++; 
		q.push(v);
	}

	int V = q.back(); // quantidade de vertices

	pruferCodeToTree(q, V);

	dfs(V);

	cout << endl;
}
