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

void findPrefixCount(vector<vector<int>>& p_arr, vector<vector<bool>>& arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {

            if (!arr[i][j]) continue;

            if (j != n - 1) p_arr[i][j] += p_arr[i][j + 1];

            p_arr[i][j] += (int)arr[i][j];
        }
    }
}

int matrixAllOne(vector<vector<bool>>& arr) {
    int n = arr.size();
    vector<vector<int>> p_arr(n, vector<int>(n, 0));

    findPrefixCount(p_arr, arr);

    int ans = 0;

    for (int j = 0; j < n; j++) {

        int i = n - 1;

        stack<pair<int, int> > q;

        int to_sum = 0;

        while (i >= 0) {

            int c = 0;

            while (q.size() != 0 and q.top().first > p_arr[i][j]) {

                to_sum -= (q.top().second + 1) *
                    (q.top().first - p_arr[i][j]);

                c += q.top().second + 1;
                q.pop();
            }

            to_sum += p_arr[i][j];

            ans += to_sum;

            q.push({ p_arr[i][j], c });

            i--;
        }
    }

    return ans;
}

void solve() {

	int l, c; cin >> l >> c;
    vector<vi> mat(l, vi(c, 0));

    f(i,0,l) {
        f(j,0,c) {
            cin >> mat[i][j];
        }
    }

    vector<vector<int>> aux(l, vector<int>(c, 0));

   int ans = 0;

    f(x_0,0,l) {
        f(y_0,0,c) {
            f(x_siz, 1, l - x_0) {
                f(y_siz, 1, c - y_0) {

                    if(mat[x_0][y_0] + mat[x_0 + x_siz][y_0 + y_siz] <= mat[x_0][y_0 + y_siz] + mat[x_0 + x_siz][y_0]) {
                        ans++;

                        aux[x_0][y_0]++;
                        aux[x_0 + x_siz][y_0 + y_siz]++;
                        aux[x_0][y_0 + y_siz]++;
                        aux[x_0 + x_siz][y_0]++;

                        for(auto v : aux) {
                            print_v(v);
                        }
                        cout << endl;

                        for(int i = 0; i < l; i++) {
                            for(int j = 0; j < c; j++) {
                                aux[i][j] = 0;
                            }
                        }

                    }
                }
            }
        }
    }

    cout << ans << endl;
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
