#include <bits/stdc++.h>
using namespace std;

#define _   ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)         a.begin(), a.end()
#define int            long long int
#define double         long double
#define vi             vector<int>
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define f(i,s,e)       for(int i=s;i<e;i++)
#define rf(i,e,s)      for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF = 0x7f3f3f3f;
const int MAXN = 1010; 

int resposta;
vector<tuple<int, int, int>> ferrovias, rodovias; // {peso, u, v}

vector<int> id(MAXN), sz(MAXN);

int find(int p){
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void uni(int p, int q) { 

    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p,q);
    id[p] = q, sz[q] += sz[p];
}

int kruskal(vector<tuple<int, int, int>> edg) {

    sort(all(edg));

    int cost = 0;

    for (auto [w, x, y] : edg) {

        if (find(x) != find(y)) {
            cost += w; 
            uni(x, y);
        }
    }

    return cost;
}

void solve() {

    int n, f, r; cin >> n >> f >> r;

    iota(id.begin(), id.end(), 0);

    ferrovias.resize(f);
    rodovias.resize(r);

    f(i,0,f) {
        int u, v, w; cin >> u >> v >> w;
        ferrovias[i] = {w, u, v};
    }

    f(i,0,r) {
        int u, v, w; cin >> u >> v >> w;
        rodovias[i] = {w, u, v};
    }

    resposta += kruskal(ferrovias);
    resposta += kruskal(rodovias);

    cout << resposta << endl;
}

int32_t main() { _
    
    solve();

    return 0;
}
