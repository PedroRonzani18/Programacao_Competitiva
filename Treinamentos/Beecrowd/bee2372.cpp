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
const int MAX = 110; // 10^6 + 10

int n;
int dist[MAX][MAX];

void floydist_warshall() {
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	for (int k = 0; k < n; k++)
		dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
}

void solve() {

	int edg; cin >> n >> edg;

	memset(dist, INF, sizeof(dist));

	for (int i = 0; i < n; i++)
		dist[i][i] = 0;

	for (int i = 0; i < edg; i++) {
		int a, b, w; cin >> a >> b >> w;
		dist[a][b] = dist[b][a] = w;
	}

	floydist_warshall();
	
	int menor = INF;

	f(i,0,n) {

		int maior = -1;
		f(j,0,n) {
			if (dist[i][j] > maior and dist[i][j] != INF)
				maior = dist[i][j];
		}

		if (menor > maior and maior > 0)
			menor = maior;
	}

	cout << menor  << endl;
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
