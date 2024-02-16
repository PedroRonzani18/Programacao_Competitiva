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

void printFila(queue<int> q) {
	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void solve() {

	int e, imp, v; cin >> e >> imp >> v;

	// vector<pair<int, int>> implicacoes(imp);

	vector<unordered_set<int>> consequenciasDeA(e+1); // passado um A, retorna os B's
	vector<unordered_set<int>> causadoresDeB(e+1);  // passado um B, retorna os A's

	f(i,0,imp) {
		int a, b; cin >> a >> b;
		// implicacoes[i] = {a, b};
		consequenciasDeA[a].insert(b);
		causadoresDeB[b].insert(a);
	}

	cout << "Consequencias de A" << endl;
	f(i,1,e+1) {
		if(consequenciasDeA[i].empty()) continue;
		cout << i << " -> ";
		for(auto x : consequenciasDeA[i]) {
			cout << x << " ";
		}
		cout << endl;
	}

	cout << endl;

	cout << "Causadores de B" << endl;
	f(i,1,e+1) {
		if(causadoresDeB[i].empty()) continue;
		cout << i << " > ";
		for(auto x : causadoresDeB[i]) {
			cout << x << " ";
		}
		cout << endl;
	}

	cout << endl;

	set<int> verdadeiros;
	queue<int> q;

	f(i,0,v) {
		int a; cin >> a;
		verdadeiros.insert(a);
		q.push(a);

		while(!q.empty()) {

			int a = q.front(); q.pop();

			int aux = a;

			dbgl(aux);
			while(!causadoresDeB[aux].size() and !verdadeiros.count(*causadoresDeB[aux].begin())) {
				aux = *causadoresDeB[aux].begin();
				verdadeiros.insert(aux);
				q.push(aux);

				cout << "Fila: ";
				printFila(q);
			}

			

			for(auto b : consequenciasDeA[a]) {
				if(!verdadeiros.count(b)) {
					verdadeiros.insert(b);
					q.push(b);
				}
			}
		}

	}

	for(auto verdade : verdadeiros) {
		cout << verdade << " ";
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
