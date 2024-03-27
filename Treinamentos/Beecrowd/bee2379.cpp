#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define pii          pair<int,int> 
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

vector<pair<int,int>> indigenas;
unordered_set<int> condicaoParada;

bool baterTamborIVezes(int n, int i) {
	unordered_set<int> toras;
	for(auto [tora, sentido] : indigenas) {
		tora = (tora + i * sentido + n) % n;
		if(!condicaoParada.count(tora) or toras.count(tora))
			return false;
		toras.insert(tora);
	}

	return false;
}

int countTambor(int n) {

	int minBatidas = n;

	vi distancias;

	for(auto x : condicaoParada) {
		auto [tora, sentido] = indigenas[0];
		distancias.push_back((sentido & (x - tora) + n - 1) % n + 1);
	}

	sort(all(distancias));

	for(auto dist : distancias) {
		if(baterTamborIVezes(n, dist))
			minBatidas = min(minBatidas, dist);
	}

}

void solve() {

	int n, e; cin >> n >> e;

	f(i,0,e) {
		int v, d; cin >> v >> d; v--;
		indigenas.push_back({v,d});
		condicaoParada.insert(v);
	}

	cout << countTambor(n) << endl;

}

int32_t main() { _
	
	// clock_t z = clock();
	int t = 1; // cin >> t;
	while (t--) {
		solve();
	}
	// cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
