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

vector<vector<int>> mat;

bool val(int i, int j, int n) {
	return 0 <= i and i < n and 0 <= j and j < n and not mat[i][j];
}

bool cmp(tuple<int,int,int> a, tuple<int,int,int> b) {
	auto [a1, a2, a3] = a;
	auto [b1, b2, b3] = b;

	if(a1 != b1) return a1 < b1;
	if(a2 != b2) return a2 < b2;
	return a3 < b3;
}

void solve() {

	int n; cin >> n;

	vector<tuple<int,int,int>> ans;
	mat.clear();
	mat.resize(n, vi(n, 0));
	rf(x_0,n,0) {
		rf(y_0,n,0) {

			cout << '['<<x_0<<','<<y_0<<']'<<endl;

			if(mat[x_0][y_0]) continue;

			f(i,0,n) {
				print_v(mat[i]);
			}
			cout << endl;


			int sz = 0, i=0;

			f(i,0,n-1) {
				if(!val(x_0-i, y_0-i, n))
					break;
				sz++;
			}

			dbgl(sz);

			f(i,0,sz) {
				f(j,0,sz) {
					mat[x_0-i][y_0-j] = 1;
				}
			}

			ans.push_back({sz, x_0-sz-1, y_0-sz-1 });
		}
	}

	sort(all(ans), cmp);

	for(auto [a, b, c] : ans) {
		cout << a << " " << b << " " << c << endl;
	}
}

int32_t main() { _
	
	clock_t z = clock();

	int t = 1; cin >> t;
	while (t--) {
		solve();
	}

	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
