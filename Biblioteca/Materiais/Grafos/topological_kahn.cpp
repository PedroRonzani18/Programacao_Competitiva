// Description: Ordenamento topologico usando o algoritmo de Kahn.
// Complexidade: O(V+E)
vector<vector<int>> adj;

vector<int> topologicalSort(int V) {

	vector<int> indegree(V);
	for (int i = 0; i < V; i++) {
		for (auto it : adj[i]) {
			indegree[it]++;
		}
	}

	queue<int> q;
	for (int i = 0; i < V; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	vector<int> result;
	while (!q.empty()) {

		int node = q.front(); q.pop();
		result.push_back(node);

		for (auto it : adj[node]) {
			indegree[it]--;
			if (indegree[it] == 0)
				q.push(it);
		}
	}

	if (result.size() != V) {
		cout << "Graph contains cycle!" << endl;
		return {};
	}

	return result;
}

void solve() {

	int n = 4; adj.resize(n);
	vector<pair<int, int>> edges = { { 0, 1 }, { 1, 2 }, { 3, 1 }, { 3, 2 } };
	for (auto& [a,b] : edges) {
		adj[a].push_back(b);
	}

	vector<int> ans = topologicalSort(n);
}

int main() {
    solve();
}
