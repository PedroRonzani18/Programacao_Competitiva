// Description: Union-Find (Disjoint Set Union)

typedef vector<int> vi;

struct UnionFind {
    vi p, rank, setSize;
    int numSets;
    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i)
            p[i] = i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
        numSets = N;
    }

    // Retorna o numero de sets disjuntos (separados)
    int numDisjointSets() { return numSets; }
    // Retorna o tamanho do set que contem o elemento i
    int sizeOfSet(int i) { return setSize[find(i)]; }

    int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }
    bool same(int i, int j) { return find(i) == find(j); }
    void uni(int i, int j) {
        if (same(i, j))
            return;
        int x = find(i), y = find(j);
        if (rank[x] > rank[y])
            swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y])
            ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
};

void solve() {
    int n; cin >> n;
    UnionFind UF(n);
    UF.uni(0, 1);
}