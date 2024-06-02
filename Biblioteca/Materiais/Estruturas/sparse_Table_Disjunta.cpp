// Description: Sparse Table Disjunta para soma de intervalos
// Complexity Temporal: O(n log n) para construir e O(1) para consultar
// Complexidade Espacial: O(n log n)

#include <bits/stdc++.h>
using namespace std;

#define MAX 100010
#define MAX2 20 // log(MAX)

namespace SparseTable {
	int m[MAX2][2*MAX], n, v[2*MAX];
	int op(int a, int b) { return a + b; }
	void build(int n2, int* v2) {
		n = n2;
		for (int i = 0; i < n; i++) v[i] = v2[i];
		while (n&(n-1)) n++;
		for (int j = 0; (1<<j) < n; j++) {
			int len = 1<<j;
			for (int c = len; c < n; c += 2*len) {
				m[j][c] = v[c], m[j][c-1] = v[c-1];
				for (int i = c+1; i <  c+len; i++) m[j][i] = op(m[j][i-1], v[i]);
				for (int i = c-2; i >= c-len; i--) m[j][i] = op(v[i], m[j][i+1]);
			}
		}
	}
	int query(int l, int r) {
		if (l == r) return v[l];
		int j = __builtin_clz(1) - __builtin_clz(l^r);
		return op(m[j][l], m[j][r]);
	}
}

void solve() {
	int n = 9;
	int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	SparseTable::build(n, v);
	cout << SparseTable::query(0, n-1) << endl; // sparse[0] + sparse[1] + ... + sparse[n-1] = 45
}