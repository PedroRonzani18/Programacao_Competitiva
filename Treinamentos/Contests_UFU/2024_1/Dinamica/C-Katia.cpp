/*--------------------------------------------------------
Nomes (email):
Pedro Augusto (pedroaugustogabironzani@gmail.com)
Ulisses Andrade (carvalhoandradeulisses@gmail.com)
Lucas Andrade (andradelucasbrandao@gmail.com)
----------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define pii	         pair<int,int>
#define endl         "\n"
#define print_v(a)   for(auto x : a)cout<<x<<" ";cout<<endl
#define print_vp(a)  for(auto x : a)cout<<x.first<<" "<<x.second<< endl
#define f(i,s,e) 	 for(int i=s;i<e;i++)
#define rf(i,e,s) 	 for(int i=e-1;i>=s;i--)
#define CEIL(a, b)   ((a) + (b - 1))/b
#define TRUNC(x, n)  floor(x * pow(10, n))/pow(10, n)
#define ROUND(x, n)  round(x * pow(10, n))/pow(10, n)
#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF = 1e9;    // 2^31-1
const int LLINF = 4e18; // 2^63-1
const double EPS = 1e-9;
const int MAX = 1e6+10; // 10^6 + 10
#define MAXN 1010 // maior peso / valor 
#define MAXS 1010 // maior capacidade mochila

int n, valor[MAXN], peso[MAXN], tab[MAXN][MAXS];

// Description: Retorna o maior valor que pode ser colocado na mochila
// Complexidade: O(n*capacidade)
int mochila(int obj, int aguenta){
	
	if(tab[obj][aguenta]>=0) return tab[obj][aguenta];
	if(obj==n or !aguenta) return tab[obj][aguenta]=0;
	
	int nao_coloca = mochila(obj+1, aguenta);
	
	if(peso[obj] <= aguenta){
		int coloca = valor[obj] + mochila(obj+1, aguenta-peso[obj]);
		return tab[obj][aguenta] = max(coloca, nao_coloca);
	}
	
	return tab[obj][aguenta]=nao_coloca;
}

void solve(int t) {
	n = t;
	memset(tab, -1, sizeof(tab));
	for (int i = 0; i < n; i++) 
		cin >> valor[i] >> peso[i];
	int aguenta; cin >> aguenta;
	cout << mochila(0, aguenta) << endl; 
}


int32_t main() { _
	
	clock_t z = clock();
	int t = 1; // cin >> t;
	while (cin >> t) {
		if(t==0) break;
		solve(t);
	}
	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
