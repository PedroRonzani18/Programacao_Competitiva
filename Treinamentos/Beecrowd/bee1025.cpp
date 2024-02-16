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

void solve(int n, int q, int casenum) {

	unordered_map<int,int> indexes;

	vi nums(n);

	f(i,0,n) {
		cin >> nums[i];
	}

	sort(all(nums));

	f(i,0,n) {
		if(!indexes.count(nums[i]))
			indexes[nums[i]] = i+1;
	}

	cout << "CASE# "<<casenum<<":"<<endl;

	f(i,0,q) {
		int aux; cin >> aux;

		if(!indexes.count(aux)) {
			cout << aux << " not found" << endl;
		} else {
			cout << aux << " found at " << indexes[aux] << endl;
		}
	}


}

int32_t main() { _
	
	clock_t z = clock();

	int n, q, casenum=1;
	while (cin >> n >> q) {
		if(n==0 and q==0) break;
		solve(n,q,casenum);
		casenum++;
	}

	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
