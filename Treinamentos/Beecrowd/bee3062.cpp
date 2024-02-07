#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define endl         "\n"
#define printall(a)  if(!a.empty()){cout<<*a.begin();for(auto x=++a.begin();x!=a.end();x++)cout<<" "<<*x;}
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

void printset(unordered_set<int>& s) {
	for(auto x : s) cout << x << " ";
	cout << endl;

}

void solve() {

	int upas, n; cin >> upas >> n;
	unordered_set<int> baniuQuem [upas+1];
	unordered_set<int> foiBanidoPorQuem [upas+1];
	unordered_set<int> removidosConfirmed;

	f(i,0,n) {

		int a, b; cin >> a >> b;
		int oprimido = min(a,b);
		int banidor = max(a,b);

		if(removidosConfirmed.count(banidor)) continue;
		
		if(!baniuQuem[oprimido].empty()) {// se o oprimido baniu akguem, tem q tentar desbanir esse povo
		
			queue<int> currentOprimidos; currentOprimidos.push(oprimido);

			while(!currentOprimidos.empty()) {
				
				int top = currentOprimidos.front(); currentOprimidos.pop();

				for(int banidoErrado : baniuQuem[top]) { // itera pelos banidos errados
					currentOprimidos.push(banidoErrado);
					foiBanidoPorQuem[banidoErrado].erase(top); // remove o oprimido, ja q ele vai ser banido
					if(foiBanidoPorQuem[banidoErrado].empty())  // se assim ele n foi banido por ngm, ele e aceito
						removidosConfirmed.erase(banidoErrado);
				}
				baniuQuem[top].clear();
			}
		}
		
		baniuQuem[banidor].insert(oprimido);
		foiBanidoPorQuem[oprimido].insert(banidor);
		removidosConfirmed.insert(oprimido);
	}

	cout << upas - removidosConfirmed.size() << endl;
	bool p =false;
	f(i,1,upas+1) {
		if(!removidosConfirmed.count(i)) {
			if(!p) p = true, cout << i;
			else  cout << " " << i;
		}
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
