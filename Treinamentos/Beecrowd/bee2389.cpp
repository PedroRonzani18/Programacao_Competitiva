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

struct PairHash {
    size_t operator()(const pair<long long, long long>& p) const {
        return hash<long long>()(p.first) ^ hash<long long>()(p.second);
    }
};

int c;

// y = (c-x)/(2x+1)
// numerador = c - x
int numerador(int x) { return c - x; }

// denominador = (2x+1)
int denominador(int x) { return 2 * x + 1; }

// Dada uma equacao de 2 variaveis, calcular quantos valores inteiros para {x,y} resolvem ela 
int count2VariableIntegerEquationAnswers() {

    unordered_set<pair<int,int>, PairHash> ans; int lim = sqrt(c);
    for(int i=1; i<= lim; i++) {
        if (numerador(i) % denominador(i) == 0) {
            int x = i, y = numerador(i) / denominador(i);
            if(!ans.count({x,y}) and !ans.count({y,x}))
                ans.insert({x,y});
        }
    }

    return ans.size();
}

void solve() {

    cin >> c; c--;

    cout << count2VariableIntegerEquationAnswers() << endl;
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