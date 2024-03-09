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

int maiorTrianguloEmHistograma(const vector<int>& histograma) {

	int n = histograma.size();
	vector<int> esquerda(n), direita(n);

    esquerda[0] = 1;
	f(i,1,n) {
        esquerda[i] = min(histograma[i], esquerda[i - 1] + 1);
    }

    direita[n - 1] = 1;
	rf(i,n-1,0) {
		direita[i] = min(histograma[i], direita[i + 1] + 1);
	}

    int ans = 0;
	f(i,0,n) {
		ans = max(ans, min(esquerda[i], direita[i]));
	}

    return ans;

}

void solve() {

	int n; cin >> n;
	vi v(n);
	f(i,0,n) {
		cin >> v[i];
	}

	cout << maiorTrianguloEmHistograma(v) << endl;

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
