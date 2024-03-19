// Segment Tree with Lazy Propagation
// Update Range: O(log(n))
// Querry Range: O(log(n))
// Memory: O(n)
// Build: O(n)

typedef vector<int> vi;

class SegmentTree {
    private:
        int n; 
        vi A, st, lazy;
        int defaultVar; // min: INT_MIN | max: INT_MIN | sum: 0 | multiply: 1

        int l(int p) { return  p<<1; }
        int r(int p) { return (p<<1)+1; }

        int conquer(int a, int b) {
            if(a == defaultVar) return b;
            if(b == defaultVar) return a;
            return min(a, b);
        }

        void build(int p, int L, int R) {
            if (L == R) st[p] = A[L];
            else {
                int m = (L+R)/2;
                build(l(p), L  , m);
                build(r(p), m+1, R);
                st[p] = conquer(st[l(p)], st[r(p)]);
            }
        }

        void propagate(int p, int L, int R) {
            if (lazy[p] != defaultVar) {
                st[p] = lazy[p];
                if (L != R) lazy[l(p)] = lazy[r(p)] = lazy[p];
                else        A[L] = lazy[p];
                lazy[p] = defaultVar;
            }
        }

        int querry(int p, int L, int R, int i, int j) { 
            propagate(p, L, R);
            if (i > j) return defaultVar;
            if ((L >= i) && (R <= j)) return st[p];
            int m = (L+R)/2;
            return conquer(querry(l(p), L  , m, i, min(m, j)), 
                           querry(r(p), m+1, R, max(i, m+1), j));
        }

        void update(int p, int L, int R, int i, int j, int val) { 
            propagate(p, L, R);
            if (i > j) return;
            if ((L >= i) && (R <= j)) {
                lazy[p] = val;
                propagate(p, L, R);
            }
            else {
                int m = (L+R)/2;
                update(l(p), L  , m, i          , min(m, j), val);
                update(r(p), m+1, R, max(i, m+1), j        , val);
                int lsubtree = (lazy[l(p)] != defaultVar) ? lazy[l(p)] : st[l(p)];
                int rsubtree = (lazy[r(p)] != defaultVar) ? lazy[r(p)] : st[r(p)];
                st[p] = conquer(lsubtree, rsubtree);
            }
        }

    public:
        SegmentTree(int sz, int defaultVal) : n(sz), A(n), st(4*n), lazy(4*n, defaultVal), defaultVar(defaultVal) {}

        // vetor referencia, valor default (min: INT_MIN | max: INT_MIN | sum: 0 | multiply: 1)
        SegmentTree(const vi &initialA, int defaultVal) : SegmentTree((int)initialA.size(), defaultVal) {
            A = initialA;
            build(1, 0, n-1);
        }

        // A[i..j] = val | 0 <= i <= j < n  | O(log(n))
        void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }

        // max(A[i..j]) | 0 <= i <= j < n  | O(log(n))
        int querry(int i, int j) { return querry(1, 0, n-1, i, j); }
};

void solve() {
    vi A = {18, 17, 13, 19, 15, 11, 20, 99};       // make n a power of 2
    int defaultVar = INT_MIN; // default value for max query
    SegmentTree st(A, defaultVar);
    int i = 1, j = 3;
    int ans = st.querry(i, j);
    int newVal = 77;
    st.update(i, j, newVal);
    ans = st.querry(i, j);
}