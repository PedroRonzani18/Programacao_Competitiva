// Description: LCA com Sparse Table
// Utilidades: 1. Encontrar o lowest common ancestor entre dois nós de uma árvore
//             2. Encontrar a distância entre dois nós de uma árvore
// Complexidade Build: O(n log n)
// Complexidade LCA: O(log n)

const int maxN = 1e5;
const int maxLog = 17; // ceil(log2(maxN));

vector<int> adj[maxN];
int n, logn, 
	level[maxN], 
	sparseTable[maxN][maxLog], 
	logDP[maxN + 1];

void dfs(int u = 0, int prv = -1) {
    for (int v : adj[u])
        if (v != prv) {
            level[v] = level[u] + 1, sparseTable[v][0] = u;
            dfs(v, u);
        }
}

void buildLCA() {

    level[0] = sparseTable[0][0] = 0;

    dfs(0);
    
	for (int i = 1; i < logn; i++)
        for (int u = 0; u < n; u++)
            sparseTable[u][i] = sparseTable[sparseTable[u][i - 1]][i - 1];
}

int LCA(int u, int v) {

    if (level[v] > level[u])
        swap(u, v);
    for (int diff = level[u] - level[v], i = 0; diff; diff >>= 1, i++)
        if (diff & 1)
            u = sparseTable[u][i];
    if (u == v)
        return (u);
    for (int i = logDP[level[u] - 1]; sparseTable[u][0] != sparseTable[v][0]; i--)
        if (sparseTable[u][i] != sparseTable[v][i])
            u = sparseTable[u][i], v = sparseTable[v][i];
    return (sparseTable[u][0]);
}

int dist(int a, int b) { 
	return (level[a] + level[b] - 2 * level[LCA(a, b)]); 
}

int main() {
    f(i,2,maxN+1) { logDP[i] = logDP[i >> 1] + 1; }
    
    // No caso de ser uma arvore + 0 based
	f(i,0,n-1) {
        int u, v; scanf("%d %d", &u, &v); u--, v--;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    buildLCA();

    int nodeA, nodeB; scanf("%d %d", &nodeA, &nodeB);
    printf("Distancia entre %d e %d: %d\n", nodeA, nodeB, dist(nodeA, nodeB));
}