/*--------------------------------------------------------
Nomes (email):
Pedro Augusto (pedroaugustogabironzani@gmail.com)
Ulisses Andrade (carvalhoandradeulisses@gmail.com)
Lucas Andrade (andradelucasbrandao@gmail.com)
----------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define all(a) a.begin(), a.end()
#define int long long int
#define double long double
#define vi vector<int>
#define endl "\n"
#define print_v(a)        \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define print_vp(a)  \
    for (auto x : a) \
    cout << x.F << " " << x.S << endl
#define print2(a, x, y)         \
    for (int i = x; i < y; i++) \
        cout << a[i] << " ";    \
    cout << endl
#define f(i, s, e) for (int i = s; i < e; i++)
#define rf(i, e, s) for (int i = e - 1; i >= s; i--)
#define CEIL(a, b) ((a) + (b - 1)) / b
#define TRUNC(x) floor(x * 100) / 100

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)

const int INF = 0x7f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const int MAX = 1e6 + 10; // 10^6 + 10

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

vector<vi> mat;
vector<vector<bool>> vis;
vector<pair<int,int>> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int l, c;

bool valid(int x, int y) {
	return (0 <= x and x < l and 0 <= y and y < c and !vis[x][y] and mat[x][y] == 0);
}

void bfs(int i, int j) {
    bool tr = false;

	queue<pair<int,int>> q; 
    q.push({i, j});

	while(!q.empty()) {

		auto [u, v] = q.front(); 
        q.pop();
		vis[u][v] = true;
        if(u == 4 && v == 4)
        {
            tr = true;
            cout << 1 << endl;
            return;
        }

		for(auto [x, y]: mov) {
			if(valid(u+x, v+y)) {
				q.push({u+x,v+y});
				vis[u+x][v+y] = true;
                if(u == 4 && v == 4)
                {
                    tr = true;
                    cout << 1 << endl;
                    return;
                }
			}
		}
	}

    if(tr == false)
        cout << 0 << endl;
}

void solve()
{
    mat.resize(l, vi(c));
    vis.clear();
    vis.resize(l, vector<bool>(c, false));

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> mat[i][j];
        }
    }

    bfs(0, 0);
}

int32_t main()
{
    _

        clock_t z = clock();

    int t; 
    cin >> t;
    l = 5;
    c = 5;
    while (t--)
        solve();

    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}