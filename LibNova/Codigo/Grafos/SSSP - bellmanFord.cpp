// SSSP - Bellman Ford
//
// Aceita pesos negativos
//
// Conexo: O(VE)
// Desconexo: O(EV^2)

const int MAXEDG = 1e3+10;

tuple<int,int,int>> edg [MAXN];
int dist[MAXN];i

int bellman_ford(int n, int src) {
    dist.assign(n+1, INT_MAX);

    f(i,0,n+2) {
        for(auto& [u, v, w] : edg) {
            if(dist[u] != INT_MAX and dist[v] > w + dist[u])
                dist[v] = dist[u] + w;
        }
    }

    // Possivel checar ciclos negativos (ciclo de peso total negativo)
    for(auto& [u, v, w] : edg) {
        if(dist[u] != INT_MAX and dist[v] > w + dist[u])
            return 1;
    }

    return 0;
}

void solve(int n, int ed) {

	f(i,0,n) { dist[i] = INF; }

	f(i,0,ed) {
        int u, v, w; u--, v--;
		edg[i] = {u,v,w};
    }

    bellman_ford(n, 0);
}
