// Description: BFS para uma matriz (n x m)
// Complexidade: O(n * m)

vector<vi> mat;
vector<vector<bool>> vis;
vector<pair<int,int>> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int l, c;

bool valid(int x, int y) {
	return (0 <= x and x < l and 0 <= y and y < c and !vis[x][y] /*and mat[x][y]*/);
}

void bfs(int i, int j) {

	queue<pair<int,int>> q; q.push({i, j});

	while(!q.empty()) {

		auto [u, v] = q.front(); q.pop();
		vis[u][v] = true;

		for(auto [x, y]: mov) {
			if(valid(u+x, v+y)) {
				q.push({u+x,v+y});
				vis[u+x][v+y] = true;
			}
		}
	}
}

int main() {
	cin >> l >> c;
	mat.resize(l, vi(c));
	vis.resize(l, vector<bool>(c, false));
	/*preenche matriz*/
	bfs(0,0);
}