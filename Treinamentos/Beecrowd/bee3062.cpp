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

void printSet(set<int>& s) {
    cout << *s.begin();
    for(auto it = next(s.begin()); it != s.end(); it++) {
        cout << " " << *it;
    }
    cout << endl;
}

void solve() {

	int upas, n; cin >> upas >> n;
	
	vector<set<int>> adj(upas+1);
	set<int> ans;

	f(i,0,upas) ans.insert(i+1);

	f(i,0,n) {
		int a, b; cin >> a >> b;
		if(a > b) swap(a, b);
		adj[a].insert(b); // adj[a] eh banido por {b1, b2, ...}
	}

	rf(i,upas,1) {
		for(auto x : adj[i]) {
			if(ans.count(i) and ans.count(x)) {
				ans.erase(i);
				break;
			}
		}
	}

	cout << ans.size() << endl;

	printSet(ans);
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
