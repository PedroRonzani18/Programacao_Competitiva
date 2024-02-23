#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define endl         "\n"
#define print_v(a)   for(auto x : a) cout << x << ","; cout << endl
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
const int MAX = 1e6+10; // 10^6 + 10

map<char, vector<char>> adj;
map<char, set<char>> components;
unordered_set<char> visited;
map<char, char> stored;

void dfs(char v) {

    visited.insert(v);
    for (int u : adj[v]) {
        if (!visited.count(u)) {
			components[v].insert(u);
            dfs(u);
		} else {
			set<char> s = components[v];
			for(auto a : s) 
				components[u].insert(a);
			components[v].clear();
		}
    }
}

void solve(int cas) {

	cout << "Case #"<<cas<<endl;
	adj.clear();
	components.clear();
	visited.clear();

	int v, e; cin >> v >> e;
	f(i,0,e) {
		char a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	f(i,0,v) {
		components[(char)('a'+i)].insert((char)('a'+i));
		dfs((char)('a'+i));
	}


	int counter = 0;
	f(i,0,v) {
		if(!components[(char)('a'+i)].empty()) {
			counter++;
			cout << (char)('a'+i) << ": "; print_v(components[(char)('a'+i)]);
		}
	}
	cout << counter << " connected components" << endl << endl;

}

int32_t main() { _
	
	clock_t z = clock();

	int t = 1; cin >> t;
	f(i,0,t) {
		solve(i+1);
	}

	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
