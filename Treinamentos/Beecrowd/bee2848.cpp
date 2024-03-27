#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define pii          pair<int,int> 
#define endl         "\n"
#define print_v(a)   for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)  for(auto x : a) cout << x.F << " " << x.S << endl
#define f(i,s,e) 	 for(int i=s;i<e;i++)
#define rf(i,e,s) 	 for(int i=e-1;i>=s;i--)
#define CEIL(a, b)   ((a) + (b - 1))/b   // Arredonda para cima
#define TRUNC(x, n)  floor(x * pow(10, n))/pow(10, n) // Trunca n casas
#define ROUND(x, n)  round(x * pow(10, n))/pow(10, n) // Arreddonda n c 

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF =  0x7f3f3f3f; // 0x7f com 3 3f's (10^9)
const int LINF = 0x3f3f3f3f3f3f3f3f; // 0x com 7 3f's (10^18)
const int MAX = 1e6+10; // 10^6 + 10

int kthSmallest(vector<int>::iterator begin, vector<int>::iterator end, int k) {
    
    multiset<int> s;
    
    for (auto it = begin; it != end; ++it) {
        s.insert(*it);
    }
 
    int count = 1;
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (count == k) {
            return *it;
        }
        count++;
    }
    return -1;
}

class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> valueToIndices;

public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i) {
            valueToIndices[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        auto& indices = valueToIndices[value];
        auto i = lower_bound(indices.begin(), indices.end(), left);
        auto j = upper_bound(indices.begin(), indices.end(), right);
        return distance(i, j);
    }
};

void solve() {

	int n, q; cin >> n >> q;

	vi nums(n);
	f(i,0,n) {
		int aux; cin >> aux;
		nums[i] = aux;
	}

	RangeFreqQuery rq(nums);

	f(i,0,q) {
		int l, r, k, g, d; cin >> l >> r >> k >> g >> d; l--;
		
        int kesimo = kthSmallest(nums.begin()+l, nums.begin()+r, k);
		int frequencia = rq.query(l, r, kesimo);

        int dd = abs(frequencia - d);
        int dg = abs(frequencia - g);

		char ch;
        if(dd == dg) ch = 'E';
        else if(dd < dg) ch = 'D';
        else ch = 'G';

		cout << kesimo << ' ' << frequencia << " " << ch << endl;
	}
}

int32_t main() { _
	
	// clock_t z = clock();
	int t = 1; // cin >> t;
	while (t--) {
		solve();
	}
	// cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
