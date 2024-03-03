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

vector<vector<pair<char, int>>> mat;
vector<vector<bool>> vis;
vector<pair<int,int>> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int linhas, colunas; 

bool valid(int x, int y) {
	return (0 <= x and x < linhas and 0 <= y and y < colunas and !vis[x][y] and mat[x][y].first == '#');
}

int bfs(int i, int j, int& index) {

	if(vis[i][j]) return -1;

	queue<pair<int,int>> q; q.push({i, j});

	index++;

	int counter = 1;

	while(!q.empty()) {

		auto [u, v] = q.front(); q.pop();
		vis[u][v] = true;
		mat[u][v].second = index;

		for(auto [x, y]: mov) {
			if(valid(u+x, v+y)) {
				q.push({u+x,v+y});
				vis[u+x][v+y] = true;
				mat[i][j].second = index;
				counter++;
			}
		}
	}

	return counter;
}

void solve() {

	cin >> linhas >> colunas;

	int index = 0;

	mat.resize(linhas, vector<pair<char, int>> (colunas));
	vis.resize(linhas, vector<bool> (colunas));

	queue<pair<int,int>> q;
	f(i,0,linhas) {
		f(j,0,colunas) {
			cin >> mat[i][j].first;
			if(mat[i][j].first == '#')
				q.push({i,j});
		}
	}

	vector<int> quantidades(1);

	while(!q.empty()) {
		auto top = q.front(); q.pop();

		int counter = bfs(top.first, top.second, index);

		if(counter != -1) {
			quantidades.push_back(counter);
		}
	}

	int ans=0;
	int ataques; cin >> ataques;
	while(ataques--) {
		int a, b; cin >> a >> b; a--, b--;

		if(mat[a][b].first == '#') {
			mat[a][b].first = '.';
			quantidades[mat[a][b].second]--;
			if(quantidades[mat[a][b].second] == 0) {
				ans++;	
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
