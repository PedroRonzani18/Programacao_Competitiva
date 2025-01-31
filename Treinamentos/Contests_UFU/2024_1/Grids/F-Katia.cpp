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
vector<pair<int,int>> mov = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int l, c;

bool valid(int x, int y) {
	return (0 <= x and x < l and 0 <= y and y < c and mat[x][y] == 1);
}

void bfs(int i, int j) {
    pair<int, int> r;

	queue<pair<int,int>> q; 
    q.push({i, j});

	while(!q.empty()) {

		auto [u, v] = q.front(); q.pop();
		mat[u][v] = 0;
        r.first = u;
        r.second = v;

		for(auto [x, y]: mov) {
			if(valid(u+x, v+y)) {
				q.push({u+x,v+y});
				mat[u][v] = 0;
                r.first = u;
                r.second = v;
			}
		}
	}

    cout << r.first + 1 << " " << r.second + 1 << endl;
}

void solve(int a, int b)
{
    mat.resize(l, vi(c));

    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            cin >> mat[i][j];
        }
    }

    bfs(a, b);
}

int32_t main()
{
    _

    clock_t z = clock();

    int a, b;
    cin >> l >> c >> a >> b;
    
    solve(a - 1, b - 1);

    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}