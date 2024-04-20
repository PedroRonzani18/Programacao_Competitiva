#include <bits/stdc++.h>
using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define pii	         pair<int,int>
#define endl         "\n"
#define print_v(a)   for(auto x : a)cout<<x<<" ";cout<<endl
#define print_vp(a)  for(auto x : a)cout<<x.first<<" "<<x.second<< endl
#define f(i,s,e) 	 for(int i=s;i<e;i++)
#define rf(i,e,s) 	 for(int i=e-1;i>=s;i--)
#define CEIL(a, b)   ((a) + (b - 1))/b
#define TRUNC(x, n)  floor(x * pow(10, n))/pow(10, n)
#define ROUND(x, n)  round(x * pow(10, n))/pow(10, n)
#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF = 1e9;    // 2^31-1
const int LLINF = 4e18; // 2^63-1
const double EPS = 1e-9;
const int MAX = 1e6+10; // 10^6 + 10

vector<int> id, sz;

int counter = 0;

int find(int a){ // O(a(N)) amortizado
    return id[a] = (id[a] == a ? a : find(id[a]));
}

void uni(int a, int b) { // O(a(N)) amortizado
    a = find(a), b = find(b);
    if(a == b) return;

    if(sz[a] > sz[b]) swap(a,b);
    id[a] = b, sz[b] += sz[a];
}

pair<int, vector<tuple<int, int, int>>> kruskal(vector<tuple<int, int, int>>& edg) {

	sort(edg.begin(), edg.end()); // Minimum Spanning Tree 
	
	int cost = 0;
	vector<tuple<int, int, int>> mst; // opcional
	for (auto [w,x,y] : edg) if (find(x) != find(y)) {
		mst.emplace_back(w, x, y); // opcional
		cost += w; 
		uni(x,y);
	}
	return {cost, mst};
}

unordered_map<string,int> mp;

void solve() {

	int n, ed; cin >> n >> ed;

	mp.clear();
	id.clear(); id.resize(n); iota(all(id), 0);
	sz.clear(); sz.assign(n, -1);
	counter = 0;
	vector<tuple<int, int, int>> edg;

	f(i,0,ed) {
		string a, b; int w; cin >> a >> b >> w;

		int ind1 = 0, ind2 = 0;
		if(mp.count(a)) 
			ind1 = mp[a];
		else {
			mp[a] = counter;
			ind1 = counter;
			counter++;
		}

		if(mp.count(b)) 
			ind2 = mp[b];
		else {
			mp[b] = counter;
			ind2 = counter;
			counter++;
		}

		edg.push_back({w, ind1, ind2});
	}

	auto [cost, mst] = kruskal(edg);
	cout << cost << endl;

}

int32_t main() { _
	
	clock_t z = clock();
	int t = 1; cin >> t;
	while (t--) {
		solve();
	}
	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
