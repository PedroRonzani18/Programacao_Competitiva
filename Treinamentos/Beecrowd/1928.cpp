#include <bits/stdc++.h>
using namespace std;

#define _   ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)         a.begin(), a.end()
#define int            long long int
#define double         long double
#define vi 			   vector<int>
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)    for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF = 0x7f3f3f3f;
const int MAX = 60010;

namespace seg {
    int seg[4*MAX];
	int n;
    vector<int> v;

	int op(int a, int b) { return min(a, b); }

	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = op(build(2*p, l, m), build(2*p+1, m+1, r));
	}

	void build(int n2, vector<int> v2) {
		n = n2, v = v2;
		build();
	}

    int query(int a, int b, int p=1, int l=0, int r=n-1) {
        if (a <= l and r <= b) return seg[p];
        if (b < l or r < a) return INT_MAX;  // Return the neutral element for min operation
        int m = (l+r)/2;
        return op(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
    }


	int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = op(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
};

unordered_map<int,int> firstOccurency; 

vector<vector<int>> adj(MAX);
int vis[MAX], profundidade[MAX], cartasRev[3 * MAX];
vector<int> euTree(MAX);

void eulerTree(int u, int &index) { 

	if(firstOccurency.count(cartasRev[u]) == 0)
		firstOccurency[cartasRev[u]] = index+1;

    vis[u] = 1;
    euTree[index++] = profundidade[cartasRev[u]];
    for (auto it : adj[u]) {
        if (!vis[it]) {
            eulerTree(it, index);
            euTree[index++] = profundidade[cartasRev[u]];
        }
    }
}

vector<int> pai(MAX, -1);

void dfs(int v, int prof=0) { 

	int cv = cartasRev[v];
	if(profundidade[cv] == 0)
		profundidade[cv] = prof;
		
	for(auto x: adj[v]){
		if(pai[x] != -1) continue;
		pai[x] = v;
		dfs(x, prof+1); 
	}
}

void solve() {

	int n; cin >> n;
	vector<bool> adicionados(n+1, false);

	f(i,1,n+1) {
		
		int carta; cin >> carta;
		if(adicionados[carta]) 
			carta += 60000;
		else adicionados[carta] = true;
	
		cartasRev[i] = carta;
	}


	f(i,0,n-1) {
		
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);

	int index = 0; eulerTree(1, index);

	seg::build(2 * n - 1, euTree);

	int ans = 0;
	for(int i=1; i<=n/2; i++) {

		int f1 = firstOccurency[i]-1, f2 = firstOccurency[i + 60000]-1;
		if(f1 > f2) swap(f1, f2);

		ans += (profundidade[i] + profundidade[i+60000] - 2 * seg::query(f1, f2));
	}
	cout << ans << endl;

}

int32_t main() { _
	
	clock_t z = clock();

	int t = 1; // cin >> t;
	while (t--) 
	//while(cin >> a >> b)
		solve();

	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
