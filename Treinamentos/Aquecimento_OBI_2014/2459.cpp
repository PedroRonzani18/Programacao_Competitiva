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
const int MAXN = 1010; 

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

int pai[MAXN], peso[MAXN], n, f, r, resposta; // peso = rank 
pair<int, pair<int, int>> ferrovias[MAXN], rodovias[MAXN]; // {peso, {u, v}}

// DSU - Disjoint Set Union (Union Find): encontrar o representante (ou raiz) de um conjunto ao qual um elemento pertence
int find(int x) {

    if (x == pai[x]) return x;
    return pai[x] = find(pai[x]);
}

// DSU - Disjoint Set Union (Union Find): unir dois conjuntos disjuntos
void join(int x, int y) {

    x = find(x); // representante de x
    y = find(y); // representante de y

    if (x == y) return; // se ja estao no mesmo conjunto disjunto (mesma raiz) nao precisa unir
    
    if (peso[x] < peso[y]) // se o rank de x for menor que o rank de y, x passa a ser filho de y
        pai[x] = y;
    else if (peso[x] > peso[y])
        pai[y] = x;
    else { // se os ranks forem iguais, x passa a ser filho de y e o rank de y aumenta em 1
        pai[x] = y;
        peso[y]++;
    }
}

void solve() {

    cin >> n >> f >> r;

    f(i,1,n+1)
        pai[i] = i;

    f(i,0,f) {
        int u, v, w;
        cin >> u >> v >> w;
        ferrovias[i] = {w, {u, v}};
    }

    f(i,0,r) {
        int u, v, w;
        cin >> u >> v >> w;
        rodovias[i] = {w, {u, v}};
    }

    sort(ferrovias, ferrovias + f); 
    sort(rodovias, rodovias + r);
    
    f(i,0,f) { // para cada aresta (u, v) de ferrovias

        if (find(ferrovias[i].second.first) != find(ferrovias[i].second.second)) { // se nao estao no mesmo conjunto disjunto (mesma raiz)
            resposta += ferrovias[i].first; // adiciona o peso da aresta na resposta final (custo total)
            join(ferrovias[i].second.first, ferrovias[i].second.second); // une os conjuntos disjuntos (uniao de arvores)
        }
    }

    f(i,0,r) {

        if (find(rodovias[i].second.first) != find(rodovias[i].second.second)) {
            resposta += rodovias[i].first;
            join(rodovias[i].second.first, rodovias[i].second.second);
        }
    }

    cout << resposta << endl;
}

int32_t main() { _
	
    solve();

	return 0;
}