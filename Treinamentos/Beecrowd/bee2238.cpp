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

// Calcudla os divisores de c, sem incluir c, sem ser fatorado
set<int> calculaDivisores(int c) {
	int lim = sqrt(c);
	set<int> divisors;
	
	for(int i = 1; i <= lim; i++) {
		if (c % i == 0) {
			if(c/i != i) 
				divisors.insert(c/i);
			divisors.insert(i);
		}
	}

	return divisors;
}

bool valid(int n, int a, int b, int d){
	return (n % a == 0 && n % b != 0 && d % n != 0);
}

void solve() {

	int a, b, c, d; cin >> a >> b >> c >> d;

	set<int> divisors = calculaDivisores(c);
	int ans = -1;
	
	for(const int& num : divisors) {
		if(valid(num, a, b, d)) {
			ans = num;
			break;
		}
	}

	cout << ans << endl;

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