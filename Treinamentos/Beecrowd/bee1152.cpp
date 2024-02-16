#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define endl         "\n"
#define print_v(a)   for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)  for(auto x : a) cout << x.F << " " << x.S << endl
#define f(i,s,e) 	 for(int i=s;i<e;i++)
#define rf(i,e,s) 	 for(int i=e-1;i>=s;i--)
#define CEIL(a, b)   ((a) + (b - 1))/b   // Arredonda para cima
#define TRUNC(x, n)  floor(x * pow(10, n))/pow(10, n) // Trunca n casas
#define ROUND(x, n)  round(x * pow(10, n))/pow(10, n) // Arreddonda n c 

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF =  0x7f3f3f3f; // 0x7f com 3 3f's (10^9)
const int LINF = 0x3f3f3f3f3f3f3f3f; // 0x com 7 3f's (10^18)
const int MAXN = 200010;
const int MAXM = 200010;

vector<int> id, sz;

int find(int p){ // O(a(N)) amortizado
    return id[p] = (id[p] == p ? p : find(id[p]));
}

void uni(int p, int q) { // O(a(N)) amortizado
    p = find(p), q = find(q);
    if(p == q) return;
    if(sz[p] > sz[q]) swap(p,q);
    id[p] = q, sz[q] += sz[p];
}

int kruskal(vector<tuple<int, int, int>>& edg) {

	sort(edg.begin(), edg.end());
	
	int cost = 0;
	for (auto [w,x,y] : edg) if (find(x) != find(y)) {
		cost += w; 
		uni(x,y);
	}
	return cost;
}

void solve(int m, int n) {

	id.resize(m); iota(all(id), 0);
	sz.resize(m, -1);
	vector<tuple<int, int, int>> edg;

	int total = 0;

	for(int i=0; i<2*n; i += 2) {
		int a, b, w; cin >> a >> b >> w; 
		total += w;
		edg.push_back({w, a, b});
		edg.push_back({w, b, a});
	}
	
	int cost = kruskal(edg);

	cout << total - cost << endl;
}

int32_t main() { _
	
	clock_t z = clock();

	int t = 1; // cin >> t;
	int m, n; 
	while (cin >> m >> n) {
		if(!m and !n) break;
		solve(m, n);
	}

	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
