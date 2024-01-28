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

vector<int> preOrder(const vector<int>& arr, int rootIndex) {
    vector<int> result;
    if (rootIndex < arr.size()) {
        result.push_back(arr[rootIndex]);
        auto left = preOrder(arr, 2 * rootIndex + 1);
        result.insert(result.end(), left.begin(), left.end());
        auto right = preOrder(arr, 2 * rootIndex + 2);
        result.insert(result.end(), right.begin(), right.end());
    }
    return result;
}

vector<int> inOrder(const vector<int>& arr, int rootIndex) {
    vector<int> result;
    if (rootIndex < arr.size()) {
        auto left = inOrder(arr, 2 * rootIndex + 1);
        result.insert(result.end(), left.begin(), left.end());
        result.push_back(arr[rootIndex]);
        auto right = inOrder(arr, 2 * rootIndex + 2);
        result.insert(result.end(), right.begin(), right.end());
    }
    return result;
}

vector<int> postOrder(const vector<int>& arr, int rootIndex) {
    vector<int> result;
    if (rootIndex < arr.size()) {
        auto left = postOrder(arr, 2 * rootIndex + 1);
        result.insert(result.end(), left.begin(), left.end());
        auto right = postOrder(arr, 2 * rootIndex + 2);
        result.insert(result.end(), right.begin(), right.end());
        result.push_back(arr[rootIndex]);
    }
    return result;
}


void solve() {
	
    vi v; int aux; while(cin >> aux) v.push_back(aux);
    vi pre = preOrder(v, 0);
    vi in = inOrder(v, 0);
    vi post = postOrder(v, 0);
    int n = v.size();

    f(i,0,n-1) {
        cout << pre[i] << " ";
    }
    cout << pre.back() << endl;

    f(i,0,n-1) {
        cout << in[i] << " ";
    }
    cout << in.back() << endl;

    f(i,0,n-1) {
        cout << post[i] << " ";
    }

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
