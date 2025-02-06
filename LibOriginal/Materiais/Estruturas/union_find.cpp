// Description: Union-Find (Disjoint Set Union)
const int MAX = 5e4+10;

int p[MAX], ranking[MAX], setSize[MAX];

struct UnionFind {
    int numSets;

    UnionFind(int N) {
		iota(p,p+N+1,0);
		memset(ranking, 0, sizeof ranking);
		memset(setSize, 1, sizeof setSize);
        numSets = N;
    }

    int numDisjointSets() { return numSets; }
    int sizeOfSet(int i) { return setSize[find(i)]; }

    int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }
    bool same(int i, int j) { return find(i) == find(j); }
    void uni(int i, int j) {
        if (same(i, j))
            return;
        int x = find(i), y = find(j);
        if (ranking[x] > ranking[y])
            swap(x, y);
        p[x] = y;
        if (ranking[x] == ranking[y])
            ++ranking[y];
        setSize[y] += setSize[x];
        --numSets;
    }
};

void solve() {

	int n, ed; cin >> n >> ed;
	UnionFind uni(n);

	f(i,0,ed) {
		int a, b; cin >> a >> b; a--, b--;
		uni.uni(a,b);
	}

	cout << uni.numDisjointSets() << endl;
}