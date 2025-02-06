// Descricao: Verifica se dois grafos sao isomorfos (possuem a mesma estrutura)
// Complexidade: O(n^2)

struct Node {
	unordered_map<int, int> edges;
	int grau;
};

Node adj1[MAX], adj2[MAX];

bool verify(int a, int b, int origemA, int origemB) {

	Node& node1 = adj1[a], node2 = adj2[b];

	if (node1.grau != node2.grau) 
		return false;

	int n = node1.grau;
	bool usedA[n], usedB[n];

	f(i,0,n) {
		usedA[i] = (node1.edges[i] == origemA);
		usedB[i] = (node2.edges[i] == origemB);
	}

	f(i,0,n) {

		if (usedA[i]) continue;

		f(j,0,n) {
			if (usedB[j]) continue;

			if (verify(node1.edges[i], node2.edges[j], a, b)) {
				usedA[i] = usedB[j] = true;
				break;
			}
		}
		if (!usedA[i]) 
			return false;
	}
	return true;
}

bool areIsomorphic(int n) {

	f(i,0,n) {
		if (verify(0, i, -1, -1)) 
			return true;
	}

	return false;
}

void solve(int n) {

	f(i,0,n) {
		adj1[i].edges.clear(), adj2[i].edges.clear();
		adj1[i].grau = 0, adj2[i].grau = 0;
	}

	f(i,0,n-1) {
		int a, b; cin >> a >> b; a--, b--;
		adj1[a].edges[adj1[a].grau++] = b;
		adj1[b].edges[adj1[b].grau++] = a;
	}

	f(i,0,n-1) {
		int a, b; cin >> a >> b; a--, b--;
		adj2[a].edges[adj2[a].grau++] = b;
		adj2[b].edges[adj2[b].grau++] = a;
	}

	bool ans = areIsomorphic(n);
}