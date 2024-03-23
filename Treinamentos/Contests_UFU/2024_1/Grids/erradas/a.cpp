/*--------------------------------------------------------
Nomes (email):
Pedro Augusto (pedroaugustogabironzani@gmail.com)
Ulisses Andrade (carvalhoandradeulisses@gmail.com)
Lucas Andrade (andradelucasbrandao@gmail.com)
----------------------------------------------------------*/
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int            long long int
#define double         long double
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << endl;

vector<vector<char>> grid;
vector<vector<bool>> vis;
vector<pair<int,int>> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int l, c;

bool valid(int x, int y, int w) {
	return (0 <= x and x < l and 0 <= y and y < c and !vis[x][y] and w > 0);
}

void bfs(queue<tuple<int,int,int>> q) {

	while(!q.empty()) {
		auto [u, v, w] = q.front(); q.pop();
		vis[u][v] = true;

		for(auto [x, y]: mov) {
			if(valid(u+x, v+y, w)) {
				q.push({u+x,v+y,w-1});
				vis[u+x][v+y] = true;
				if(grid[u+x][v+y] == 'o')
					grid[u+x][v+y] = '#';
				else 
					grid[u+x][v+y] = '*';
			} 
		}
	}
}

void printfGrid(vector<vector<char>> grid) {
	for(auto v : grid) {
		cout << *v.begin();
		for(auto it = next(v.begin()); it != v.end(); it++) {
			cout << " " << *it;
		}
		cout << endl;
	}
}

void solve(int test) {

	if(test != 0) cout << endl;

	int size; cin >> size; l = size, c = size;
	grid.clear(); grid.resize(size, vector<char>(size, '.'));	
	vis.clear(); vis.resize(size, vector<bool>(size, false));

	int buildings; cin >> buildings;
	while(buildings--) {
		int a, b; cin >> a >> b;
		grid[a][b] = 'o';
	}

	queue<tuple<int,int,int>> q;

	int bombs; cin >> bombs;
	while(bombs--) {
		int a, b, r; cin >> a >> b >> r;
		grid[a][b] = '*';
		q.push({a, b, r});
	}

	bfs(q);

	printfGrid(grid);
}

int32_t main() { _
	
	clock_t z = clock();

	int t = 1; cin >> t;
	for(int i=0; i<t; i++)
		solve(i);

	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}