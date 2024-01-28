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

vector<int> adj[20 * MAX];
int vis[20 * MAX], profundidade[20 * MAX], cartasIndex[20 * MAX];
vector<int> euTree(20 * MAX);

namespace seg {
	int seg[20 * MAX];
	int nSeg;
	vector<int> vec;

	int op (int a, int b) {
		
		if(a == INT_MAX) return b;
		if(b == INT_MAX) return a;
		
		return profundidade[a] < profundidade[b] ? a : b;}		

	int build(int p=1, int l=0, int r=nSeg-1) {
		if (l == r) return seg[p] = vec[l];
		int m = (l+r)/2;

		return seg[p] = op(build(2*p, l, m), build(2*p+1, m+1, r));

	}

	void build(int n2, vector<int> v2) {
		nSeg = n2, vec = v2;
		build();
	}

	int query(int a, int b, int p=1, int l=0, int r=nSeg-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return INT_MAX; 
		int m = (l+r)/2;


		return op(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
}

int firstOccurency[20 * MAX]; 

void eulerTree(int u, int &index) { 

	if(firstOccurency[cartasIndex[u]] == 0)
		firstOccurency[cartasIndex[u]] = index;

	vis[u] = 1;
	euTree[index++] = cartasIndex[u];
	for (auto it : adj[u]) {
		if (!vis[it]) {
			eulerTree(it, index);
			euTree[index++] = cartasIndex[u];
		}
	}
}

void mountEulerTree(int n) {

	memset(vis, 0, sizeof(vis));
	int index = 0; eulerTree(1, index);

}

int pai[20 * MAX];

void dfs(int v, int prof=0) { 

	if(profundidade[cartasIndex[v]] == 0) profundidade[cartasIndex[v]] = prof;
		
	for(auto x: adj[v]){
		if(pai[x] != -1) continue;
		pai[x] = v;
		dfs(x, prof+1); 
	}
}

void preenchecartasIndex(int n) {

	bool adicionados[20 * MAX]; 
	memset(adicionados, false, sizeof(adicionados));

	for(int i=1; i<=n; i++) {
		
		int num; cin >> num;
		if(adicionados[num])  num += 60000;
		else adicionados[num] = true;	
		cartasIndex[i] = num;
	}
}

void findAns(int n) {
    int ans = 0;
    for(int i=1; i<=n/2; i++) {
        int f1 = firstOccurency[i], f2 = firstOccurency[i + 60000];
        if(f1 > f2) swap(f1, f2);
        
        ans += (profundidade[i] + profundidade[i+60000] - 2 * profundidade[seg::query(f1, f2)]);
    }
    cout << ans << endl;
}


void solve() {

	int n; cin >> n;

	preenchecartasIndex(n);

	for(int i=0; i<n-1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	memset(pai, -1, sizeof(pai));
	dfs(1);

	mountEulerTree(n);

	seg::build(2 * n -1, euTree);

	findAns(n);
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
