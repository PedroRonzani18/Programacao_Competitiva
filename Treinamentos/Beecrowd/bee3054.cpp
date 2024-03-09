#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
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

tuple<int, int, int> maximalRectangle(vector<vector<int>> mat) {
    int r = mat.size();
    if(r == 0) return make_tuple(0, 0, 0);
    int c = mat[0].size();

    vector<vector<int>> dp(r+1, vector<int>(c));

    int mx = 0;
    int area = 0, height = 0, length = 0;
    for(int i=1; i<r; ++i) {
        int leftBound = -1;
        stack<int> st;
        vector<int> left(c);

        for(int j=0; j<c; ++j) {
            if(mat[i][j] == 1) {
                mat[i][j] = 1+mat[i-1][j];
                while(!st.empty() and mat[i][st.top()] >= mat[i][j])
                    st.pop();

                int val = leftBound;
                if(!st.empty())
                    val = max(val, st.top());

                left[j] = val;
            } else {
                leftBound = j;
                left[j] = 0;
            }
            st.push(j);
        }
        while(!st.empty()) st.pop();

        int rightBound = c;
        for(int j=c-1; j>=0; j--) {
            if(mat[i][j] != 0) {

                while(!st.empty() and mat[i][st.top()] >= mat[i][j])
                    st.pop();

                int val = rightBound;
                if(!st.empty())
                    val = min(val, st.top());

                dp[i][j] = (mat[i][j]+1) * (((val-1)-(left[j]+1)+1)+1);
                if (dp[i][j] > mx) {
                    mx = dp[i][j];
                    area = mx;
                    height = mat[i][j];
                    length = (val-1)-(left[j]+1)+1;
                }
                st.push(j);
            } else {
                dp[i][j] = 0;
                rightBound = j;
            }
        }
    }

    return make_tuple(area, height, length);
}

void solve() {

	int l, c; cin >> l >> c;
    vector<vi> mat(l, vi(c, 0));

    f(i,0,l) {
        f(j,0,c) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> aux(l-1, vector<int>(c-1, 0));

    f(i,0,l-1) {
        f(j,0,c-1) {
            if(mat[i][j] + mat[i+1][j+1] <= mat[i][j+1] + mat[i+1][j]) {
                aux[i][j] = 1;
            }
        }
    }

    for(auto v : aux) {
        print_v(v);
    }

    auto [area, alt, leng] = maximalRectangle(aux);

    cout << max(c, area) << endl;

}

int32_t main() { _
	
	clock_t z = clock();

	int t = 1; // cin >> t;
	while (t--) {
		solve();
	}

	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
