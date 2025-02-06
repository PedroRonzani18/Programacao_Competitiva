// Description: BFS para listas de adjacencia por nivel
// Complexidade: O(V + E)

int n; 
unordered_map<string, int> dist;
unordered_map<string, vector<int>> niveisDoNode;
vector<vector<string>> itensDoNivel;

void bfs(string s) {

    queue<pair<string, int>> q; q.push({s, 0});

    while (!q.empty()) {
        auto [v, dis] = q.front(); q.pop(); 

        for(auto linha : niveisDoNode[v]) {
            for(auto u : itensDoNivel[linha]) {
                if (dist[u] == 0) {
                    q.push({u, dis+1});
                    dist[u] = dis + 1;
                }
            }
        }
    }
}

void solve() {

    int n, ed; cin >> n >> ed;
	dist.clear(), itensDoNivel.clear(), niveisDoNode.clear();
    itensDoNivel.resize(n);

	f(i,0,ed) {
		int q; cin >> q;
		while(q--) {
			string str; cin >> str;
			niveisDoNode[str].push_back(i);
			itensDoNivel[i].push_back(str);
		}
	}

    string src; cin >> src;
	bfs(src);
}