/*--------------------------------------------------------
Nomes (email):
Pedro Augusto (pedroaugustogabironzani@gmail.com)
Ulisses Andrade (carvalhoandradeulisses@gmail.com)
Lucas Andrade (andradelucasbrandao@gmail.com)
----------------------------------------------------------*/
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

bool valid(pair<int,int> p, int l, int c) {
	auto[x,y] = p;
	return (0 <= x and x < l and 0 <= y and y < c);
}

void solve() {

	int l, c; cin >> l >> c; cin.ignore();
	vector<string> tab(l);
	f(i,0,l) {
		getline(cin, tab[i]);
	}	

	int firstO = tab[0].find('o');

	queue<pair<int,int>> chuvas; chuvas.push({0,firstO});
	vi move = {-1, 1};

	while(!chuvas.empty()) {

		auto [x, y] = chuvas.front(); 
		chuvas.pop();

		if(x == l-1) continue;

		if(tab[x+1][y] == '.') {
			tab[x+1][y] = 'o';
			chuvas.push({x+1, y});
			continue;
		} 

		for(auto& u : move) {
			bool pushed = false;
			if(valid({x, y+u}, l, c)) {
				if(valid({x-1, y}, l, c)) {
					if(tab[x][y+u] == '.' and tab[x-1][y] == '#') {
						pushed = true;
						tab[x][y+u] = 'o';
						chuvas.push({x, y+u});
					}
				} 
				if(valid({x+1, y}, l, c) and !pushed) {
					if(tab[x][y+u] == '.' and tab[x+1][y] == '#') {
						tab[x][y+u] = 'o';
						chuvas.push({x, y+u});
					}
				}
			}
		}

	}

	for(string s : tab) {
		cout << s << endl;
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
