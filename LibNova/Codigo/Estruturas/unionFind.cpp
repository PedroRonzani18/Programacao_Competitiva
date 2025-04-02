// Union-Find (Disjoint Set Union)

const int MAXN = 1e3+10;

struct UnionFind {
    int numSets;
    int id[MAXN], sz[MAXN];

    UnionFind(int N) {
        numSets = N;
        for (int i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
    }

    int find(int a) { 
        return id[a] = (id[a] == a ? a : find(id[a]));
    }

    void uni(int a, int b) { 
        a = find(a), b = find(b);
        if(a == b) return;
        if(sz[a] > sz[b]) swap(a, b);
        id[a] = b;
        sz[b] += sz[a];
        --numSets;
    }
    
    int sizeOfSet(int a) { return sz[find(a)]; }
    int numDisjointSets() { return numSets; }
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
