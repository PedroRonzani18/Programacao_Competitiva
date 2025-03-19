// Lowest Common Ancestor (LCA) com peso
//
// Encontra o LCA de uma arvore com peso, assim como a distancia 
// entre 2 vertices.
//
// Assume que um vertice eh ancestral dele mesmo, ou seja,
// se a eh ancestral de b, lca(a, b) = a
// dist(a, b) retorna a distancia entre a e b
//
// build - O(n)
// lca - O(1)
// dist - O(1)

const int MAXN = 1e5+10;

template<typename T> 
struct rmq {
    vector<T> v;
    int n; 
    static const int b = 30;
    vector<int> mask, t;

    int op(int x, int y) { return v[x] < v[y] ? x : y; }
    int msb(int x) { return __builtin_clz(1) - __builtin_clz(x); }
    
    rmq() {}
    rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
        for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
            at = (at << 1) & ((1 << b) - 1);
            while (at and op(i, i - msb(at & -at)) == i)
                at ^= at & -at;
        }
        for (int i = 0; i < n / b; i++) 
            t[i] = b * i + b - 1 - msb(mask[b * i + b - 1]);
        for (int j = 1; (1 << j) <= n / b; j++) 
            for (int i = 0; i + (1 << j) <= n / b; i++)
                t[n / b * j + i] = op(t[n / b * (j - 1) + i],
                                       t[n / b * (j - 1) + i + (1 << (j - 1))]);
    }
    
    int small(int r, int sz = b) { 
        return r - msb(mask[r] & ((1 << sz) - 1)); 
    }
    
    T query(int l, int r) {
        if (r - l + 1 <= b) return small(r, r - l + 1);
        int ans = op(small(l + b - 1), small(r));
        int x = l / b + 1, y = r / b - 1;
        if (x <= y) {
            int j = msb(y - x + 1);
            ans = op(ans, op(t[n / b * j + x], t[n / b * j + y - (1 << j) + 1]));
        }
        return ans;
    }
};

namespace lca {
    vector<pair<int,int>> g[MAXN];
    
    int v[2 * MAXN];
    int pos[MAXN];
    int level[2 * MAXN];
    int t;
    rmq<int> RMQ;
    
    int dist[MAXN];

    void dfs(int i, int l = 0, int p = -1, long long d = 0) {
        v[t] = i;
        pos[i] = t;
        level[t] = l;
        dist[i] = d;
        t++;
        for (auto edge : g[i]) {
            int nxt = edge.first;
            int w = edge.second;
            if (nxt == p) continue;
            dfs(nxt, l + 1, i, d + w);
            v[t] = i;
            level[t] = l;
            t++;
        }
    }
    
    void build(int n, int root = 0) {
        t = 0;
        dfs(root);
        vector<int> levelVec(level, level + (2 * n - 1));
        RMQ = rmq<int>(levelVec);
    }
    
    int lca(int a, int b) {
        a = pos[a], b = pos[b];
        if (a > b) swap(a, b);
        return v[RMQ.query(a, b)];
    }
    
    long long queryDist(int a, int b) {
        int anc = lca(a, b);
        return dist[a] + dist[b] - 2LL * dist[anc];
    }
}

void solve() {
	
	int n; cin >> n;

	f(i,0,n)
		lca::g[i].clear();
	
	f(i,1,n) {
		int a, b, w; cin >> a >> b >> w;
		lca::g[a].push_back({b, w});
		lca::g[b].push_back({a, w});
	}
	
	lca::build(n, 0); // arvore com n vertices com raiz em 0

	int lowestCommonAncertor = lca::lca(0,1); // LCA entre 0 e 1
	int dist = lca::queryDist(0,1); // Distancia entre 0 e 1

}
