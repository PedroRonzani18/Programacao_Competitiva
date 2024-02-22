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

struct Node {
	int Wa, Wfilh;
};

vector<vector<int>> adj;
vector<Node> info; // [Wa, Wfilh, NumFilhos] 
vector<int> cortesNaqueleNode;
int total = 0, cortes = 0;
set<int> removidos;

void dfsFill(int v) {
	
    for (int u : adj[v]) {
		dfsFill(u);
		info[v].Wfilh/*peso filhos v*/ 
			+= info[u].Wfilh/*peso filhos u*/ 
			 + info[u].Wa/*peso u*/;
    }
}

void dfsCount(int v) {

	if(adj[v].empty()) return;

	int cortesIndividuais = 0;

    for (int u : adj[v]) {

		if(info[u].Wa + info[u].Wfilh < 0) {  // se o peso do filho e seus filhos for negativo
			total -= info[u].Wa + info[u].Wfilh;
			cortesIndividuais++;
			continue;
		} 

		dfsCount(u);
    }

	if(cortesIndividuais > 0) 
		removidos.insert(v);

	cortes += cortesIndividuais;

	cortesNaqueleNode[v] = cortesIndividuais;
}

void solve() {

	int n; cin >> n;
	adj.resize(n), info.resize(n), cortesNaqueleNode.resize(n);

	f(i,0,n-1) {	
		int ind, a, b, w; cin >> ind >> a >> b >> w;
		if (a > b) swap(a, b);
		info[b].Wa = w;
		adj[a].push_back(b);
	}

	dfsFill(0);

	total = info[0].Wfilh;

	dfsCount(0);

	cout << total << " " << cortes << endl;
	if(!removidos.empty()) {
		cout << *removidos.begin();

		for(auto it = next(removidos.begin()); it != removidos.end(); it++) {
			cout << " " << *it;
		}
		cout << endl;
	}
}

int32_t main() { _
	
	int t = 1; // cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
