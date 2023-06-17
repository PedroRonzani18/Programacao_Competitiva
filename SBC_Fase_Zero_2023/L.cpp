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

int x, y, r, l, c;

int x_tras, x_frente, y_tras, y_frente, l_range, c_range;

int sub_total, total = 0;


void solve() {
	x_tras = r >= x ? x-1 : r;
    x_frente = r > l-x ? l-x : r;

    y_tras = r >= y ? y-1 : r;
    y_frente = r > c-y ? c-y : r;


    l_range = x_tras + x_frente + 1;
    c_range = y_tras + y_frente + 1;

    sub_total = l_range*c_range;

    total += sub_total;
}


int32_t main() { _

	clock_t z = clock();

    cin >> l >> c;

	int s;
    cin >> s;
	while (s--) {
        cin >> x >> y >> r;
	    solve();
    }

    cout << (int) (total/(l*c)) << endl;


	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
