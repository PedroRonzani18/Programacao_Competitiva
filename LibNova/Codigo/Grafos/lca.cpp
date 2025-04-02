// LCA com RMQ
//
// Assume que um vertice eh ancestral dele mesmo, ou seja,
// se a eh ancestral de b, lca(a, b) = a
// dist(a, b) retorna a distancia entre a e b
//
// build - O(n)
// lca - O(1)
// dist - O(1)

template<typename T> 
struct rmq {
    vector<T> v;
    int n; 
    static const int b = 30;
    vector<int> mask, t;

    int op(int x, int y) { 
        return v[x] < v[y] ? x : y; 
    }
    int msb(int x) { 
        return __builtin_clz(1) - __builtin_clz(x); 
    }
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
                t[n / b * j + i] = op(t[n / b * (j - 1) + i], t[n / b * (j - 1) + i + (1 << (j - 1))]);
    }
    int small(int r, int sz = b) { 
        return r - msb(mask[r] & ((1 << sz) - 1)); 
    }
    T query(int l, int r) {
        if (r - l + 1 <= b)
            return small(r, r - l + 1);
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
    vector<int> g[MAXN];
    int v[2 * MAXN], pos[MAXN], dep[2 * MAXN];
    int t;
    rmq<int> RMQ;
    
    void dfs(int i, int d = 0, int p = -1) {
        v[t] = i;
        pos[i] = t;
        dep[t] = d;
        t++;
        for (auto j : g[i])
            if(j != p) {
                dfs(j, d + 1, i);
                v[t] = i;
                dep[t] = d;
                t++;
            }
    }
    
    void build(int n, int root) {
        t = 0;
        dfs(root);
        vector<int> depVec(dep, dep + 2 * n - 1);
        RMQ = rmq<int>(depVec);
    }
    
    int lca(int a, int b) {
        a = pos[a], b = pos[b];
        if(a > b) swap(a, b);
        return v[RMQ.query(a, b)];
    }
    
    int dist(int a, int b) {
        int l = lca(a, b);
        return dep[pos[a]] + dep[pos[b]] - 2 * dep[pos[l]];
    }
}

   
void solve(int n) {
    
	f(i,0,n-1){
        int a, b; cin >> a >> b; a--; b--;
        lca::g[a].push_back(b);
        lca::g[b].push_back(a);
    }
    
    lca::build(n, 0); // raiz nesse caso eh 0
  
	cout << lca::dist(1,2) << endl // distancia entre vertices 1 e 2 da arvore
}

