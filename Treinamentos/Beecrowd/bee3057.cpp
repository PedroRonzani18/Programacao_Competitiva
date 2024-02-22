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
const int MAXN = 1e5+10; // 10^6 + 10

vector<vector<int>> adj;
set<int> verdades;
unordered_set<int> possivelmenteVerdades;
vector<unordered_set<int>> asLigadosAoB;

int dfs(int v, int verdadePai) {


	cout << "\nVerdades: "; print_v(verdades);
	cout << "Current: " << v << " | Pai: " << verdadePai << endl;

	// se ele ja for verdade, ou for uma folha
	if(!asLigadosAoB[v].empty() and adj[v].empty()) {
		if(verdadePai == 1) verdades.insert(v); // se seu pai for completamente verdadeiro, eu sou verdadeiro 
		cout << "Folha: " << v << " -> " << verdades.count(v) << endl;
		return verdades.count(v);
	}
		
	// se todos os pais forem verdadeiros, eu sou verdadeiro
	if(!asLigadosAoB[v].empty()) {
		bool paisVerdadeiros = true;
		for(auto a : asLigadosAoB[v]) {
			if (!verdades.count(a)) {
				paisVerdadeiros = false;
				break;
			}
		}
		if (paisVerdadeiros) {
			verdades.insert(v);
			cout << "todos meus "<<asLigadosAoB[v].size()<<" pais sao verdadeiros" << endl;
		}
	}

	if(verdades.count(v) and adj[v].empty()) {
		int quantidadeDePais = asLigadosAoB[v].size();
		dbgl(quantidadeDePais);
		if(quantidadeDePais > 1) return 0; // sou marromeno verdadeiro
		return 1; // sou verdadeiro ou sou um axioma
	}

	int unclearCount = 0, falseCount = 0, trueCount = 0;

    for (int u : adj[v]) {
		int ret = dfs(u, (verdades.count(v) || verdadePai == 1) ? 1 : -1);
		if(ret == -1) falseCount++;
		else if(ret == 1) trueCount++;
		else unclearCount++;
    }

	cout << "\nVerdades: "; print_v(verdades);
	cout << "Current: " << v << endl;
	cout << "Unclear: " << unclearCount << " False: " << falseCount << " True: " << trueCount << endl;

	int filhos = adj[v].size();

	// se sou um intermadiario
	if(asLigadosAoB[v].size()) {
		if(trueCount + unclearCount == filhos) {
			possivelmenteVerdades.insert(v);
			return 1;
		}
	} else { // se sou um axioma	
		if(unclearCount + trueCount == filhos) {
			verdades.insert(v);
			possivelmenteVerdades.erase(v);
			return 0;
		}

		possivelmenteVerdades.erase(v);
		return -1;
	}

	return 0;
}

void solve() {

	int e, imp, v; cin >> e >> imp >> v;
	
	adj.resize(e+1);
	asLigadosAoB.resize(e+1);

	f(i,0,imp) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		asLigadosAoB[b].insert(a);
	}

	f(i,0,v) {
		int verdade; cin >> verdade;
		verdades.insert(verdade);
	}

	unordered_set<int> axiomas;
	f(i,1,e+1) {
		if (asLigadosAoB[i].empty()) {
			axiomas.insert(i);
		}
	}

	for(auto x : axiomas) {
		cout << "\n------------- Ponta: " << x << "---------------------------" << endl;
		dfs(x, verdades.count(x) ? 1 : -1);

	}

	cout << *verdades.begin();

	for(auto it = ++verdades.begin(); it != verdades.end(); it++) {
		cout << " " << *it;
	}
	cout << endl;
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
