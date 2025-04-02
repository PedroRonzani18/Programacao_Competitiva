// BIT
//
// BIT de soma 0-based
// 
// upper_bound(x) retorna o menor p tal que pref(p) > x 
//
// Complexidades:
// build - O(n)
// update - O(log(n))
// query - O(log(n))
// upper_bound - O(log(n))

struct Bit {
	int n;
	vector<int> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, int x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	int pref(int i) { // soma [0, i]
		int ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	int query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
	int upper_bound(int x) {
		int p = 0;
		for (int i = __lg(n); i+1; i--) 
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};

void solve() {

	vector<int> v(n);

	Bit bit (v);
}
