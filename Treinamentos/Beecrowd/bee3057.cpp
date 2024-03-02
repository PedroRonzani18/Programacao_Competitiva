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

vector<vector<int>> adj;
unordered_set<int> axiomas;
vector<unordered_set<int>> fullPath;
vector<bool> ansVec;

void dfs(int v) {

	if(!fullPath[v].empty()) 
		return;

	for(auto u : adj[v]) {
		dfs(u);
		fullPath[v].insert(all(fullPath[u]));
		fullPath[v].insert(u);
	}
}

bool allContainsTarget(int target, vector<unordered_set<int>*>& sets) {
	for(auto s : sets) 
		if(!s->count(target))
			return false;
	return true;
}

void eventoIsTrue(int statement) {

	vector<unordered_set<int>*> axiomasComVerdade;

	for(auto axiom : axiomas) 
		if(fullPath[axiom].count(statement))
			axiomasComVerdade.push_back(&fullPath[axiom]);

	for(auto implicacao : fullPath[statement])
		ansVec[implicacao] = true;

	for(int i = 0; i<fullPath.size(); i++)
		if(!ansVec[i] and allContainsTarget(i, axiomasComVerdade))
			ansVec[i] = true;
}

set<int> vecBoolToSet() {
	set<int> s;
	f(i,0,ansVec.size()) {
		if(ansVec[i]) s.insert(i);
	}
	return s;
}

void printSet(const set<int>& set) {

	if(!set.empty()) {
		cout << *set.begin() + 1;

		if(set.size() > 1) {
			for(auto it = next(set.begin()); it != set.end(); it++)  {
				cout << " " << *it + 1;
			}
		}

		cout << endl;
	}
}

void solve() {

	int n, edg, verdades; cin >> n >> edg >> verdades;

	adj.resize(n);
	fullPath.resize(n);

	f(i,0,n) {
		axiomas.insert(i);
	}

	f(i,0,edg) {
		int a, b; cin >> a >> b; a--, b--;
		adj[a].push_back(b);
		axiomas.erase(b);
	}

	for(auto axioma : axiomas) {
		dfs(axioma);
		fullPath[axioma].insert(axioma);
	}

	ansVec.resize(n, false);

	f(i,0,verdades) {
		int verdade; cin >> verdade; verdade--;
		eventoIsTrue(verdade);
	}

	printSet(vecBoolToSet());
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
