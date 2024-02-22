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
const int MAX = 1e5+10; // 10^6 + 10

vector<vector<int>> adj;
vi somaLigadoAMim, caixas;
vector<bool> calculated;
int visited[MAX];

void dfs(int v, int origem) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
			if(!calculated[u])
            	dfs(u, origem);
			somaLigadoAMim[origem] += caixas[u] + somaLigadoAMim[u];
		}
    }
}

void solve() {

	int n, m; cin >> n >> m;
	somaLigadoAMim.resize(n+1);
	calculated.resize(n+1, false);

	caixas.resize(n+1);
	f(i,1,n+1) {
		cin >> caixas[i];
	}

	adj.resize(n+1);

	f(i,0,m) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	f(i,1,n+1) {
		dfs(i, i);
		memset(visited, 0, sizeof(visited));
	}

	f(i,1,n+1) {
		cout << somaLigadoAMim[i] + caixas[i] << " ";
	}

}

int32_t main() { _
	
	clock_t z = clock();

	int t = 1; // cin >> t;
	while (t--) {
		solve();
	}

	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
