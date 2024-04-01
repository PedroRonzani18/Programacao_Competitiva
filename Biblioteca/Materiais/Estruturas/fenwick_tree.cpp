#define LSOne(S) ((S) & -(S)) // the key operation

class FenwickTree { // index 0 is not used
    private:
        vi ft;

        void build(const vi &f) {
            int m = (int)f.size() - 1; // note f[0] is always 0
            ft.assign(m + 1, 0);
            for (int i = 1; i <= m; ++i) {
                ft[i] += f[i];
                if (i + LSOne(i) <= m)
                    ft[i + LSOne(i)] += ft[i];
            }
        }

public:
    // empty FT
    FenwickTree(int m) { ft.assign(m + 1, 0); } 

    // FT based on f
    FenwickTree(const vi &f) { build(f); } 

    // FT based on s, and m = max(s)
    FenwickTree(int m, const vi &s) {
        vi f(m + 1, 0);
        for (int i = 0; i < (int)s.size(); ++i)
            ++f[s[i]];
        build(f);
    }

    // RSQ(1, j)
    int rsq(int j)     {  
        int sum = 0;
        for (; j; j -= LSOne(j))
            sum += ft[j];
        return sum;
    }

    // RSQ(i, j)
    int rsq(int i, int j) { return rsq(j) - rsq(i - 1); }

    // v[i] += v
    void update(int i, int v) {
        for (; i < (int)ft.size(); i += LSOne(i))
            ft[i] += v;
    }

    // n-th element >= k
    int select(int k) {
        int p = 1;
        while (p * 2 < (int)ft.size())
            p *= 2;
        int i = 0;
        while (p) {
            if (k > ft[i + p]) {
                k -= ft[i + p];
                i += p;
            }
            p /= 2;
        }
        return i + 1;
    }
};

// Range Update Point Query
class RUPQ { 
    private:
        FenwickTree ft;
    public:

        // empty FT
        RUPQ(int m) : ft(FenwickTree(m)) {} 
        
        // v[ui,...,uj] += v
        void range_update(int ui, int uj, int v) {
            ft.update(ui, v);
            ft.update(uj + 1, -v);
        }

        // rsq(i) = v[1] + v[2] + ... + v[i]
        int point_query(int i) { return ft.rsq(i); }
};

// Range Update Range Query
class RURQ {
    private:
        RUPQ rupq;
        FenwickTree purq;
    public:
        // empty structures
        RURQ(int m) : rupq(RUPQ(m)), purq(FenwickTree(m)) {} 

        // v[ui,...,uj] += v
        void range_update(int ui, int uj, int v) {
            rupq.range_update(ui, uj, v);
            purq.update(ui, v * (ui - 1));
            purq.update(uj + 1, -v * uj);
        }

        // rsq(j) = v[1]*j - (v[1] + ... + v[j])
        int rsq(int j) {
            return rupq.point_query(j) * j -
                purq.rsq(j);
        }

        // rsq(i, j) = rsq(j) - rsq(i - 1)
        int rsq(int i, int j) { return rsq(j) - rsq(i - 1); }
};

int32_t main() {

    vi f = {0, 0, 1, 0, 1, 2, 3, 2, 1, 1, 0}; // index 0 is always 0
    FenwickTree ft(f);
    printf("%lli\n", ft.rsq(1, 6));  // 7 => ft[6]+ft[4] = 5+2 = 7
    printf("%lld\n", ft.select(7));    // index 6, rsq(1, 6) == 7, which is >= 7
    ft.update(5, 1);                 // update demo
    printf("%lli\n", ft.rsq(1, 10)); // now 12
    printf("=====\n");
    RUPQ rupq(10);
    RURQ rurq(10);
    rupq.range_update(2, 9, 7); // indices in [2, 3, .., 9] updated by +7
    rurq.range_update(2, 9, 7); // same as rupq above
    rupq.range_update(6, 7, 3); // indices 6&7 are further updated by +3 (10)
    rurq.range_update(6, 7, 3); // same as rupq above
    // idx = 0 (unused) | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10
    // val = -          | 0 | 7 | 7 | 7 | 7 |10 |10 | 7 | 7 | 0
    for (int i = 1; i <= 10; i++)
        printf("%lld -> %lli\n", i, rupq.point_query(i));
    printf("RSQ(1, 10) = %lli\n", rurq.rsq(1, 10)); // 62
    printf("RSQ(6, 7) = %lli\n", rurq.rsq(6, 7));   // 20
    return 0;
}