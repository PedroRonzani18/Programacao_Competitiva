// Pontos de Articulacao + Pontes
//
// Computa os pontos de articulacao (vertices criticos) de um grafo
//
// art[i] armazena o numero de novas componentes criadas ao deletar vertice i
// se art[i] >= 1, entao vertice i eh ponto de articulacao
// 
// O(V + E)

const int MAXN = 410;

vector<int> adj[MAXN];
int id[MAXN], art[MAXN];
stack<int> s;

int dfs_art(int i, int &t, int p = -1) {
    int lo = id[i] = t++;
    int children = 0;
    s.push(i);
    for (int j : adj[i]) {
        if (j == p) continue;
        if (id[j] == -1) {
            children++;
            int val = dfs_art(j, t, i);
            lo = min(lo, val);
            if (val >= id[i]) {
                art[i]++;
                while (s.top() != j) s.pop();
                s.pop();
            }
			// if (val > id[i]) aresta i-j eh ponte
        }
        else {
            lo = min(lo, id[j]);
        }
    }
    
	if (p == -1) {
        if (children > 1)
            art[i] = children - 1;
        else
            art[i] = -1;
    }
    return lo;
}

void AP(int n) {

	s = stack<int>();
    
	f(i,0,n) { 
        id[i] = -1; 
        art[i] = -1; 
    }
    int t = 0;
    f(i,0,n) {
        if (id[i] == -1)
            dfs_art(i, t, -1);
    }
}

void solve(int n, int ed) {

	int n, ed;
	f(i,0,n)
        adj[i] = vector<int>();

    while(ed--) {
        int a, b; 
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    AP(n);
    
    vector<int> pontos;
    // Para vertices nao-raiz, art[i] >= 0 indica que eh ponto de articulacao.
    // Para a raiz (i==0) ela so deve ser considerada se tiver 2 ou mais filhos, ou seja, se art[0] > 0.
    f(i,0,n) {
        if (i == 0) {
            if (art[i] > 0) pontos.push_back(i+1);
        } else {
            if (art[i] >= 0) pontos.push_back(i+1);
        }
    }
}

