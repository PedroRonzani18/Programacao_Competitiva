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

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

const int INF = 0x7f3f3f3f;
const int MAXN = 1e5+10; // 10^6 + 10

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

struct PairHash {
    template<typename T1, typename T2>
    std::size_t operator()(const std::pair<T1, T2>& p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        // Combining hashes of both elements
        return hash1 ^ hash2;
    }
};

unordered_set<pair<int,int>, PairHash> colors;
vector<vector<int>> adj; // adjacency list

void bfs(int s, vi& p, vector<bool>& used) {
	queue<int> q;
	q.push(s);
	used[s] = true;
	p[s] = -1;

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int u : adj[v]) {
			if (!used[u]) {
				used[u] = true;
				q.push(u);
				p[u] = v;
			}
		}
	}
}

vector<int> getPath(int v, const vi& p) {
	vector<int> path;
	while (v != -1) {
		path.push_back(v);
		v = p[v];
	}
	return path;
}

void solve() {

	int n; cin >> n;
	int ans = 0;

	adj.assign(n + 1, vector<int>());

	f(i, 0, n - 1) {
		int a, b, c; cin >> a >> b >> c;
		if(c == 1) {
			colors.insert({a, b});
			colors.insert({b, a});
		}
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	f(i, 1, n) {
		// cout << "["  << i << "]" << endl;
		vector<int> p(n + 1, -1);
		vector<bool> used(n + 1, false);
		bfs(i, p, used);

		f(j, i+1, n + 1) {

			vi path = getPath(j, p);
			// cout << "{ " << i << " " << j << " } = "; print_v(path);
			int size = path.size();
			if (size > 1) {
				f(k, 0, size - 1) {
					if (colors.count({path[k], path[k + 1]}) == 1) {
						ans++;
						break;
					}
				}
			}
		}
	}

	cout << ans << endl;
}

int32_t main() {
	_

	clock_t z = clock();

	int t = 1; // cin >> t;
	while (t--) 
		solve();

	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
