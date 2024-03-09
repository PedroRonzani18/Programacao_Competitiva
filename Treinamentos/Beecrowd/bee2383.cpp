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
const int MAXN = 900; 

vector<vector<int>> dp;

int minTests(int size, int remainingBalloons) { 

    if (dp[size][remainingBalloons] != -1) return dp[size][remainingBalloons]; 

    if (size == 0 || remainingBalloons == 1) return dp[size][remainingBalloons] = size; 

    int best = size; 

    f(sz,1,size+1) {
        best = min(best, 
        1 + max(    
                minTests(sz - 1, remainingBalloons - 1), // número de testes necessário para a parte do balão que estourou
                minTests(size - sz, remainingBalloons)  // parte que não estourou
               )
        ); 
    }
    return dp[size][remainingBalloons] = best; 
}

void solve() {

    int n, k; cin >> n >> k;
    int logaritmo = (int)ceil(log2(n));

    if (k >= logaritmo) {
        cout << logaritmo << endl;
        return;
    }

    dp.resize(MAXN, vector<int>(MAXN, -1));
    cout << minTests(n, k) << endl;
}

int32_t main() { _
	
	int t = 1; // cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
