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

// Verifica se eh possivel sair de um labirinto
// Complexidade: O(4^(n*m))

vector<pair<int,int>> mov = {{1,0}, {0,1}, {-1,0}, {0,-1}};
vector<vector<int>> labirinto;
vector<vector<bool>> visited;
int L, C;

bool valid(const int& x, const int& y) {
    return x >= 0 and x < L and y >= 0 and y < C and labirinto[x][y] == 0 and !visited[x][y];
}

bool condicaoSaida(const int& x, const int& y) {
    return x == L-1 and y == C-1;
}

bool search(const int& x, const int& y) {

    if(!valid(x, y))
        return false;

    if(condicaoSaida(x,y)) {
        return true;
    }

    visited[x][y] = true;

    for(auto [dx, dy] : mov) 
        if(search(x+dx, y+dy)) 
            return true;

    return false;
}

void solve() {

	labirinto.clear();
	visited.clear();

	int n; cin >> n;
	labirinto.resize(n, vi(n));

	f(i,0,n) {
		f(j,0,n) {
			cin >> labirinto[i][j];
		}
	}

    L = labirinto.size(), C = labirinto[0].size();
    visited.resize(L, vector<bool>(C, false));

    cout << search(0, 0) << endl;
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
