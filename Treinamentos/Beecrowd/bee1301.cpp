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
const int MAX = 1e5+10; // 10^6 + 10

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

namespace seg {

	int seg[4*MAX];
	int n;
    vector<int> v;

	int op(int a, int b) { 
        
        if(a == 200) return b;
        if(b == 200) return a;
        if(a == 0 || b == 0) return 0;
        if((a<0 && b > 0) || (a>0 && b<0)) return -1;
        return 1;
    }

	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = op(build(2*p, l, m), build(2*p+1, m+1, r));
	}

	void build(vector<int> v2) {
        v = v2;
        n = v2.size();
		build();
	}

	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 200;
		int m = (l+r)/2;
		return op(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}

    int update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] = x;
        int m = (l+r)/2;
        return seg[p] = op(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
    }

	int update(int i, int x) {
		return update(i, x, 1, 0, n-1);
	}
};

void solve(int n, int k) {

    vector<int> nums(n);
    f(i,0,n) {
        cin >> nums[i];
    }

    seg::build(nums);

    while(k--) {
        char c; cin >> c;

        if(c == 'C') {
            int i, v; cin >> i >> v; i--;
            seg::update(i, v);
        } else {
            int i, j; cin >> i >> j; i--, j--;
            int ans = seg::query(i,j);

            if(ans == 0) cout << 0;
            else if(ans < 0) cout << '-';
            else if (ans > 0) cout << '+';
        }

    }
    cout << endl;

}

int32_t main() { _
	
	clock_t z = clock();

    int n, k;
	while(cin >> n >> k)
		solve(n, k);


	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
