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
const int MAX = 1e6+10; // 10^6 + 10

vector<bool> visited;
vector<vector<int>> adj;
bool traveled = false;

void dfs(int v, int profundidade) {

    visited[v] = true;

    for (int u : adj[v]) {
		string spaces(2*profundidade, ' ');

        if (!visited[u]) {
			
			cout <<spaces<<v<<'-'<<u<<" pathR(G,"<<u<<")" << endl;
			traveled = true;
            dfs(u, profundidade+1);
		} else {
			cout <<spaces<<v<<'-'<<u<< endl;
		}
    }
}

void solve(int caso) {

	cout << "Caso "<<caso<<":"<<endl;

	int v, e; cin >> v >> e;

	visited.clear(); visited.resize(v);
	adj.clear(); adj.resize(v);

	f(i,0,e) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}

	f(i,0,e) {
		sort(all(adj[i]));
	}

	f(i,0,v) {
		if(!visited[i]) {
			traveled = false;
			dfs(i, 1);
			if(traveled)
				cout  << endl;
		}
	}

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
