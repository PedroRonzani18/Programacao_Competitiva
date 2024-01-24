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
const int MAX = 1e8+10; // 10^6 + 10

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

void solve(int n) {

	if(n == 0) return;

	queue<int> q;

	f(i,0,n) q.push(i+1);

	vi remov;

	int ans;

	while(!q.empty()) {

		if(q.size() == 1) {
			ans = q.front();
			q.pop();
		} else {
			remov.push_back(q.front());
			q.pop();
			q.push(q.front());
			q.pop();
		}	
	}

	cout << "Discarded cards: "; 
	f(i,0,remov.size()-1)
		cout << remov[i] << ", ";
	cout << remov.back() << endl;
	
	cout << "Remaining card: " << ans << endl;

}

int32_t main() { _
	
	clock_t z = clock();

	int a;
	while(cin >> a)
		solve(a);


	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
