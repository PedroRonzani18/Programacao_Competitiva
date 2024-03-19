// Query: soma do range [a, b]
// Update: soma x em cada elemento do range [a, b]
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))
namespace SegTree {

	int seg[4*MAX];
	int n, *v;

	int op(int a, int b) { return a + b; }

	int build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = op(build(2*p, l, m), build(2*p+1, m+1, r));
	}

	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}

	int query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return op(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}

	int update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = op(update(a, b, x, 2*p, l, m), update(a, b, x, 2*p+1, m+1, r));
	}
};
