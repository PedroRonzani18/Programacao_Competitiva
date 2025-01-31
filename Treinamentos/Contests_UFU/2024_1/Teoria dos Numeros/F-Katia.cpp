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

int lowestPrimeFactor(int n, int startPrime = 2) {
    if (startPrime <= 3) {
        if (not (n & 1))
            return 2;
        if (not (n % 3))
            return 3;
        startPrime = 5;
    }

    for (int i = startPrime; i * i <= n; i += (i + 1) % 6 ? 4 : 2)
        if (not (n % i))
            return i;
    return n;
}

map<int, int> factorize(int n) {
    map<int, int> factorsOfN;
    int lowestPrimeFactorOfN = 2;

    while (n != 1) {
        lowestPrimeFactorOfN = lowestPrimeFactor(n, lowestPrimeFactorOfN);
        factorsOfN[lowestPrimeFactorOfN] = 1;
        n /= lowestPrimeFactorOfN;
        while (not (n % lowestPrimeFactorOfN)) {
            factorsOfN[lowestPrimeFactorOfN]++;
            n /= lowestPrimeFactorOfN;
        }
    }

    return factorsOfN;
}

bool isPerfect(int n) {

	int sum = 0;
	f(i,1,n) {
		if(n % i == 0) 
			sum += i;
	}
	return sum == n;

}

void solve() {

	int n; cin >> n;

	set<int> nums;
	int index = 0;

	f(i,1,n+1) {

		if(isPerfect(i)) nums.insert(i);

	}

	nums.erase(1);

	if(nums.count(n)) cout << "sim" << endl; 
	else cout << "nao" << endl;

	if(!nums.empty()) {
		cout << *nums.begin();
		if(nums.size() > 1) {
			for(auto it = next(nums.begin()); it != nums.end(); it++) {
				cout << " " << *it;
			}
		}
		cout << endl;
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
