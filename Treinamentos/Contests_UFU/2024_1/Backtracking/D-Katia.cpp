/*--------------------------------------------------------
Nomes (email):
Pedro Augusto (pedroaugustogabironzani@gmail.com)
Ulisses Andrade (carvalhoandradeulisses@gmail.com)
Lucas Andrade (andradelucasbrandao@gmail.com)
----------------------------------------------------------*/
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

void overlap(vector<pair<int, int> > v)
{
    int ans = 0;
    int count = 0;
    vector<pair<int, char> > data;
 
    for (int i = 0; i < v.size(); i++) {
 
        data.push_back({ v[i].first, 'x' });
 
        data.push_back({ v[i].second, 'y' });
    }
 
    sort(data.begin(), data.end());
 
    for (int i = 0; i < data.size(); i++) {
 
        if (data[i].second == 'x')
            count++;
 
        if (data[i].second == 'y')
            count--;
 
        ans = max(ans, count);
    }
 
    cout << ans << endl;
}

void solve() {

	int n; cin >> n;

	vector<pair<int,int>> inp(n);
	f(i,0,n) {
		pair<int,int> aux;
		cin >> aux.first >> aux.second;
		inp[i] = aux;
	}

	overlap(inp);
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
