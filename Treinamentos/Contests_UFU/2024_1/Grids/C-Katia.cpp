 /*--------------------------------------------------------
Nomes (email):
Pedro Augusto (pedroaugustogabironzani@gmail.com)
Ulisses Andrade (carvalhoandradeulisses@gmail.com)
Lucas Andrade (andradelucasbrandao@gmail.com)
----------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define pii	         pair<int,int>
#define endl         "\n"
#define print_v(a)   for(auto x : a)cout<<x<<" ";cout<<endl
#define print_vp(a)  for(auto x : a)cout<<x.first<<" "<<x.second<< endl
#define f(i,s,e) 	 for(int i=s;i<e;i++)
#define rf(i,e,s) 	 for(int i=e-1;i>=s;i--)
#define CEIL(a, b)   ((a) + (b - 1))/b
#define TRUNC(x, n)  floor(x * pow(10, n))/pow(10, n)
#define ROUND(x, n)  round(x * pow(10, n))/pow(10, n)
#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF = 1e9;    // 2^31-1
const int LLINF = 4e18; // 2^63-1
const double EPS = 1e-9;
const int MAX = 1e6+10; // 10^6 + 10

vector<vector<char>> mat;
vector<vector<bool>> vis;
vector<pair<int,int>> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int l, c;

bool valid(int x, int y) {
	return (0 <= x and x < l and 0 <= y and y < c and !vis[x][y] and mat[x][y] == 'A');
}

void bfs(queue<pair<int,int>> q) {

	while(!q.empty()) {

		auto [u, v] = q.front(); q.pop();
		vis[u][v] = true;

		for(auto [x, y]: mov) {
			if(valid(u+x, v+y)) {
				q.push({u+x,v+y});
				vis[u+x][v+y] = true;
				mat[u+x][v+y] = 'T';
			}
		}
	}
}

void solve(int a, int b) {
	l = a, c = b;
	mat.clear(); mat.resize(l, vector<char>(c));
	vis.clear(); vis.resize(l, vector<bool>(c, false));

	queue<pair<int,int>> origem;

	f(i,0,l) {
		f(j,0,c) {
			cin >> mat[i][j];
			if(mat[i][j] == 'T') origem.push({i,j});
		}
	}

	bfs(origem);

	f(i,0,l) {
		f(j,0,c) {
			cout << mat[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

int32_t main() { _
	
	clock_t z = clock();
	int a, b; 
	while (cin >> a >> b) {
		if(a == 0 and b == 0) break;
		solve(a,b);
	}
	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
