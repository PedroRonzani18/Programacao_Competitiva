#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define endl         "\n"
#define print_v(a)   for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)  for(auto x : a) cout << x.first << ", " << x.second << " | "; cout << endl;
#define f(i,s,e) 	 for(int i=s;i<e;i++)
#define rf(i,e,s) 	 for(int i=e-1;i>=s;i--)
#define CEIL(a, b)   ((a) + (b - 1))/b   // Arredonda para cima
#define TRUNC(x, n)  floor(x * pow(10, n))/pow(10, n) // Trunca n casas
#define ROUND(x, n)  round(x * pow(10, n))/pow(10, n) // Arreddonda n c 

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF =  0x7f3f3f3f; // 0x7f com 3 3f's (10^9)
const int LINF = 0x3f3f3f3f3f3f3f3f; // 0x com 7 3f's (10^18)
const int MAX = 500;

vector<vector<int>> linhasDoTerminal; // linhas[terminal_A] = ...
vector<vector<int>> terminaisDaLinha; // linhas[terminal_A] = ...
vector<int> dist;
vector<bool> vis; 

void dijkstra(int s, int n) {
	dist.resize(n+1, LINF-10);
	vis.resize(n+1, false);
	dist[s] = 0;

	priority_queue<pair<int, int>> q;
	q.push({0, s});

	while (!q.empty()) {
		int a = q.top().second;
		q.pop();

		if (vis[a]) continue;
		vis[a] = true;

		for(auto linha : linhasDoTerminal[a]) {

			for(auto b : terminaisDaLinha[linha]) {

				if (dist[a] + 1 < dist[b]) {
					dist[b] = dist[a] + 1;
					q.push({-dist[b], b});
				}
			}
		}
	}
}

void solve() {
    int n, l, o, d; 
    cin >> n >> l >> o >> d; 
    o--, d--; 
	linhasDoTerminal.resize(n+1);
	terminaisDaLinha.resize(l+1);

	f(i,0,l) {
		int quant; cin >> quant;

        f(j,0,quant) {
			int aux; cin >> aux; aux--;  
			linhasDoTerminal[aux].push_back(i);
			terminaisDaLinha[i].push_back(aux);
        }
    }

	dijkstra(o, n);

	cout << dist[d] << endl;
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
