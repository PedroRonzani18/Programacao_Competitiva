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

void printVis(vector<vector<bool>>& vis) {
	for(auto x : vis) {
		for(auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	cout << endl;

}

void solve() {

	int n, g; cin >> n >> g;

	vector<vi> mat(n, vi(n));
	vector<vector<bool>> vis(n, vector<bool>(n, false));

	f(i,0,n) {
		f(j,0,n) {
			cin >> mat[i][j];
		}
	}

	int ans = 0;

	unordered_map<int, unordered_map<int, int>> dp;

	vector<pair<int,int>> currentPath(n*n); 

	f(x_0,0,n) {
		f(y_0,0,n) {
			
			int pathIndex = 0;
			if(vis[x_0][y_0]) continue;

			for(int sz = 1; sz <= n-max(x_0, y_0); sz++) {

				int sum = dp[x_0][y_0];
				bool goalReached = false;
				bool prohibied = false;

				f(y,y_0,y_0+sz) {
					
					if(vis[x_0+sz-1][y])  prohibied = true;
					else 				  vis[x_0+sz-1][y] = true;

					if(!goalReached and !prohibied) {
						sum += mat[x_0+sz-1][y];
						if(sum >= g) goalReached = true;
					}
				}

				f(x,x_0,x_0+sz-1) {

					if(vis[x][y_0+sz-1])  prohibied = true;
					else                  vis[x][y_0+sz-1] = true;

					if(!goalReached and !prohibied) {
						sum += mat[x][y_0+sz-1];
						if(sum >= g) goalReached = true;
					} 
				}
				
				if (goalReached and !prohibied) {
					ans++;
					break;
				}

				dp[x_0][y_0] = sum;

			}
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
