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

const int INF = 0x7f3f3f3f;
const int MAX = 1e5+10; 

void solve() {

	int n, q; cin >> n >> q;
	
	vector<vector<int>> tab(n, vector<int>(n, 0)); 
	vector<int> freq(MAX, 0);

	while (q--) {
		int num, x, r;
		cin >> num >> x;
		x--;
		int max_count = 0, res = -1;

		switch (num) {
			case 1:
				cin >> r;
				f(i, 0, n)
					tab[x][i] = r;
				break;

			case 2:
				cin >> r;
				f(i, 0, n)
					tab[i][x] = r;
				break;

			case 3:
				fill(freq.begin(), freq.end(), 0);
				f(i, 0, n) {
					int count = ++freq[tab[x][i]];
					if (count > max_count || (count == max_count && tab[x][i] > res)) {
						max_count = count;
						res = tab[x][i];
					}
				}
				cout << res << endl;
				break;

			case 4:
				fill(freq.begin(), freq.end(), 0);
				f(i, 0, n) {
					int count = ++freq[tab[i][x]];
					if (count > max_count || (count == max_count && tab[i][x] > res)) {
						max_count = count;
						res = tab[i][x];
					}
				}
				cout << res << endl;
				break;
		}
	}
}


int32_t main() { _
	
	clock_t z = clock();

	int t = 1; // cin >> t;
	while (t--) 
	//while(cin >> a >> b)
		solve();


	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
