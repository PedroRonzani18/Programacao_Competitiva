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

vector<vector<pair<int, int>>> adj1, adj2; // adj[a] = [{b, w}]
vector<unordered_set<int>> adjs1, adjs2;
vector<int> dist, parent;
vector<bool> vis; 

void dijkstra(int s, int n, vector<vector<pair<int, int>>> &adj) {

	dist.resize(n+1, LINF);
	vis.resize(n+1, false);
	parent.resize(n+1, -1);

    dist[s] = 0;
    
    priority_queue<pair<int, int>> q;
    q.push({0, s});

   while (!q.empty()) {
        int a = q.top().second; q.pop();

        if (vis[a]) continue;
        vis[a] = true;
        for (auto [b, w] : adj[a]) {

            if (dist[a] + w < dist[b]) {
                dist[b] = dist[a] + w;
				parent[b] = a;
                q.push({-dist[b], b});
            }
        }
    }
	
}

vector<int> restorePath(int v) {
    vector<int> path;
    for (int u = v; u != -1; u = parent[u])
        path.push_back(u);
    reverse(path.begin(), path.end());
    return path;
}

void solve() {

	int n, ed, a, b; cin >> n >> ed >> a >> b; a--, b--;

	adj1.resize(n);
	adj2.resize(n);
	adjs1.resize(n);
	adjs2.resize(n);


	f(i,0,ed) {
        int x, y; cin >> x >> y; x--,y--;
		
		adj1[x].push_back({y, 1});
        adj1[y].push_back({x, 0});
		
		adj2[x].push_back({y, 0});
        adj2[y].push_back({x, 1});
		
		adjs1[x].insert(y);
		adjs2[y].insert(x);
    }

	dijkstra(a, n, adj1);
 	vi p1 = restorePath(b);

	parent.clear();
	dist.clear();
	vis.clear();

	dijkstra(a, n, adj2);
 	vi p2 = restorePath(b);

	int bibi = 0,  bibica = 0;
	
	f(i,0,p1.size()-1) {
		if(adjs1[p1[i]].count(p1[i+1])) bibica++;
	}

	f(i,0,p1.size()-1) {
		if(adjs2[p2[i]].count(p2[i+1])) bibi++;
	}


	if(bibi > bibica) {
		cout << "Bibika: " << bibica << endl;
	} else if(bibica > bibi) {
		cout << "Bibi: " << bibi << endl;
	} else cout << "Bibibibika\n";
	
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
