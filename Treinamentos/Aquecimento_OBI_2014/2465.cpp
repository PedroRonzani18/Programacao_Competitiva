#include <bits/stdc++.h>
using namespace std;

#define _   ios_base::sync_with_stdio(0); cin.tie(0);

#define int            long long int
#define double         long double
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)    for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << endl;
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

const int INF = 0x7f3f3f3f;
const int MAX = 1e8+10; // 10^6 + 10

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

vector<vector<int>> mat;
vector<vector<bool>> visited (false);

bool valid(int x, int y, int size) {
	if(x == size || y == size || x == -1 || y == -1) return false;

	if(visited[x][y] == true) return false;

	return true;
}

void solve() {
	
	int n; cin >> n;
	pair<int,int> pos; cin >> pos.first >> pos.second;
	
	visited = vector<vector<bool>> (n);
	for(int i=0; i<n; i++)
		visited[i] = vector<bool>(n, false);
	mat = vector<vector<int>> (n);
	for(int i=0; i<n; i++)
		mat[i] = vector<int>(n, false);

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> mat[i][j];
		}
	}

	pos.first--;
	pos.second--;

	bool available = true;
	int counter = 1;

	vector<pair<int,int>> positions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

	queue<pair<int,int>> q; q.push(pos);

	while (!q.empty()) 	{
	
		pos = q.front();
		q.pop();
		visited[pos.first][pos.second] = true;

		for(auto u : positions) {

			if(valid(pos.first + u.first, pos.second + u.second, n)){


				if(mat[pos.first + u.first][pos.second + u.second] >= mat[pos.first][pos.second]) {

					counter++;
					q.push({pos.first + u.first, pos.second + u.second});
					visited[pos.first + u.first][pos.second + u.second] = true;

				}
			}
		}
	}

	cout << counter << endl;
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
