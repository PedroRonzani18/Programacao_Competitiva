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

pair<int, vector<int>> maxFreqn(vector<int> v) 
{ 
    unordered_map<int, int> hash; 
    for (int i = 0; i < v.size(); i++) 
        hash[v[i]]++; 

    int max_count = 0, res = -1; 
    for (auto i : hash) { 
        if (max_count < i.second) { 
            res = i.first; 
            max_count = i.second; 
        } 
    } 

    vector<int> ans;
    for (auto i : hash) { 
        if (max_count == i.second) { 
            ans.push_back(i.first); 
        } 
    }

    return { max_count, ans }; 
} 

void solve() {
	
    int n; cin >> n;

    vi v(n); f(i, 0, n) cin >> v[i];

    auto [fre, v2 ] = maxFreqn(v);

    sort(all(v2));

    cout << v2.back() << " " << fre << endl;

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
