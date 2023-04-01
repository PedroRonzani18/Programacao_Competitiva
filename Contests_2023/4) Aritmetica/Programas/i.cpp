#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define int            long long int
#define double         long double
#define endl           "\n"
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)    for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

const int INF = 0x7f3f3f3f;
const int MAX = 1e8+10; // 10⁶ + 10

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

void solve() {
	double a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	double ma[2][3];

	ma[0][0] = a;
	ma[0][1] = b;
	ma[0][2] = c;
	ma[1][0] = d;
	ma[1][1] = e;
	ma[1][2] = f;

	double fator = ma[1][0]/ma[0][0];

	for(int j = 0; j < 3; j++)
	{
		ma[1][j] -= ma[0][j]*fator;
	}

	double y = ma[1][2]/ma[1][1];

	double x = (ma[0][2] - ma[0][1]*y)/ma[0][0];

	cout.precision(2);
	cout << fixed << x << " " << y << endl;
}

int32_t main() { _
	
	clock_t z = clock();


	int t = 1; // cin >> t;
	while (t--) solve();


	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}

