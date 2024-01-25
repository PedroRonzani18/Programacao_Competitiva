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
#define CEIL(a, b)     ((a) + (b - 1))/b
#define TRUNC(x) 	   floor(x * 100) / 100

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

const int INF =  0x7f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const int MAX = 1e6+10; // 10^6 + 10

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

int n;

pair<int,int> realNewPos(pair<int,int> pos, char c) {

	switch (c)
	{
		case 'V': return { pos.first + 1, pos.second };
		case 'A': return { pos.first - 1, pos.second };
		case '<': return { pos.first, pos.second - 1 };
		default : return { pos.first, pos.second + 1 };
	}
}

bool valid(pair<int,int> pos) {
	auto [x,y] = pos;

	return (0 <= x and x < n and 0 <= y and y < n); 
}

void travel(vector<vector<bool>>& visited, vector<vector<char>>& tab, int& ans, pair<int,int> current) {

	vector<pair<int,int>> move = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	int size = 1;

	queue<pair<int,int>> q; q.push(current); visited[current.first][current.second] = true; 

	while(!q.empty()) {

		pair<int,int> top = q.front(); q.pop();

		for(auto [x,y] : move) {

			auto [t1, t2] = top;

			if(valid({t1 + x, t2 + y})) {
				if(realNewPos({t1 + x, t2 + y}, tab[t1 + x][t2 + y]) == top && !visited[t1 + x][t2 + y]){
					q.push({t1 + x, t2 + y});
					size++;
				}
			}

		}
	}

	ans -= size;
}

void solve() {
	
	cin >> n;

	int ans = n * n;
	vector<vector<char>> tab(n, vector<char>(n));
	f(i,0,n) f(j,0,n) cin >> tab[i][j];

	vector<vector<bool>> visited(n+1, vector<bool>(n+1));

	f(i,0,n) {
		if(tab[0][i] == 'A' && !visited[0][i]) {
			travel(visited, tab, ans, {0,i});
		}
	}

	f(i,0,n) {
		if(tab[n-1][i] == 'V' && !visited[n-1][i]) {
			travel(visited, tab, ans, {n-1,i});
		}
	}

	f(i,0,n) {
		if(tab[i][0] == '<' && !visited[i][0]) {
			travel(visited, tab, ans, {i,0});
		}
	}

	f(i,0,n) {
		if(tab[i][n-1] == '>' && !visited[i][n-1]) {
			travel(visited, tab, ans, {i,n-1});
		}
	}

	cout << ans << endl;

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
