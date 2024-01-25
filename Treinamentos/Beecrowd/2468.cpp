#include <bits/stdc++.h>
using namespace std;

#define _   ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)         a.begin(), a.end()
#define int            long long int
#define double         long double
#define vi 			   vector<int>
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)    for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

const int INF = 0x7f3f3f3f;
const int MAXN = 100010;

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

vector<int> pai(MAXN), peso(MAXN), filhos(MAXN, 1);

int find(int p){
    return pai[p] = (pai[p] == p ? p : find(pai[p]));
}

void uni(int p, int q) { 
    p = find(p), q = find(q);
    if(p == q) return;
    if(peso[p] > peso[q]) swap(p,q);
    pai[p] = q, peso[q] += peso[p], filhos[q] += filhos[p];
}

void solve() {

	int n; cin >> n;

	iota(all(pai), 0);

	f(i,0,n) {
		int a, b, cor; cin >> a >> b >> cor;
		if(!cor) uni(a,b);
	}

	int resposta = 0;

	f(i,1,n+1) {
		if (pai[i] != i) continue;
        resposta += ((n - filhos[i]) * filhos[i]);
	}

	cout << resposta / 2 << endl;

}

int32_t main() { _
	
	clock_t z = clock();

	int t = 1; // cin >> t;
	while (t--) 
	//while(cin >> a >> b)
		solve();

	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
