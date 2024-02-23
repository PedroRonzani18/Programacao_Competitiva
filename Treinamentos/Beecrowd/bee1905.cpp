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

vector<pair<int,int>> mov = {{1,0}, {0,1}, {-1,0}, {0,-1}};
vector<vector<int>> labirinto, sol;
vector<vector<bool>> visited;
int L, C;

bool valid(const int& x, const int& y) {
    return x >= 0 and x < L and y >= 0 and y < C and labirinto[x][y] == 0 and not visited[x][y];
}

bool condicaoSaida(const int& x, const int& y) {
    return x == L-1 and y == C-1;
}

bool search(const int& x, const int& y) {

    if(!valid(x, y)) // se estiver fora dos limites ou for obstaculo 
        return false;

    if(condicaoSaida(x,y)) {
        sol[x][y] = 2;
        return true;
    }

    sol[x][y] = 1; // caminho leva a uma possivel solucao
	visited[x][y] = true;

    for(auto [dx, dy] : mov) 
        if(search(x+dx, y+dy)) 
            return true;

    // chegou aqui -> caminho que passa por aqui eh invalido
    sol[x][y] = 0; // backtracking
    return false;
}

void solve() {

	L = 5; C = 5;

	labirinto.clear(); labirinto.resize(L, vi(C));
	f(i,0,L) {
		f(j,0,C) {
			cin >> labirinto[i][j];
		}
	}

	sol.clear(); sol.resize(L, vi(C, 0));
	visited.clear(); visited.resize(L, vector<bool>(C, false));

	if(search(0,0)) cout << "COPS" << endl;
	else cout << "ROBBERS" << endl;
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
