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

const int INF = 0x7f3f3f3f;
const int MAX = 1e5+10; 

struct SegTree {

	int seg[5*MAX];
    vector<int> v;
	int n;

    SegTree(int n) {
        this->n = n;
        memset(seg, 0, sizeof seg);
    }

    SegTree(vector<int> v) {
        this->n = v.size();
        build(v);
    }

	int build(int p, int l, int r) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = op(build(2*p, l, m), build(2*p+1, m+1, r));
	}

	void build(vector<int> v) {
		n = v.size(), this->v = v;
		build(1, 0, n-1);
	}

	int op(int a, int b) { return a + b; }

	int query(int a, int b, int p, int l, int r) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return op(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}

	int query(int a, int b) {
		return query(a, b, 1, 0, n-1);
	}

    int update(int i, int x, int p, int l, int r) {
        if (i < l or r < i) return seg[p];
        if (l == r) return seg[p] = x;
        int m = (l+r)/2;
        return seg[p] = min(update(i, x, 2*p, l, m), update(i, x, 2*p+1, m+1, r));
    }

	int update(int i, int x) {
		return update(i, x, 1, 0, n-1);
	}
};



void solve() {

	int n, q; cin >> n >> q;
	
    vector<SegTree> linhas(n, SegTree(n)), colunas(n, SegTree(n));

	while (q--) {
		int num, x, r;
		cin >> num >> x;
		x--;
		int max_count = 0, res = -1;

		switch (num) {
			case 1:
				cin >> r;
                linhas[x] = SegTree(vector<int>(n, r));

				f(i, 0, n) {
                    colunas[i].update(x, r);
                }
				break;

			case 2:
				cin >> r;
                colunas[x] = SegTree(vector<int>(n, r));

				f(i, 0, n) {
                    linhas[i].update(x, r);
                }
				break;

			case 3:

				cout << linhas[x].query(0, n) << endl;
				break;

			case 4:

				break;
		}
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
