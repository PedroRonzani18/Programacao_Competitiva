#include <bits/stdc++.h>
using namespace std;

#define _   ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)         a.begin(), a.end()
#define int            long long int
#define double         long double
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)    for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << endl;
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

const int INF = 0x7f3f3f3f;
const int MAX = 1e8+10; // 10^6 + 10

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

int alvo(vector<vector<int>> mat, int n) {

	vector<int> p = vector<int>(5,0);

	f(i,0,n) {
		p[0] += mat[i][1];
	}

	f(i,0,n) {
		p[1] += mat[0][i];
	}

	f(i,0,n) {
		p[2] += mat[n-1][i];
	}

	f(i,0,n) {
		p[3] += mat[i][0];
	}

	f(i,0,n) {
		p[4] += mat[i][n-1];
	}

	set<int> s;
	for(int n : p)
		s.insert(n);

	vector<int> ans;
	for(int n : s) {
		ans.push_back(n);
	}

	if(count(all(p), ans[0]) > count(all(p), ans[1])) return ans[0];

	return ans[1];

}

void solve() {
	
	int n; cin >> n;

	vector<vector<int>> mat = vector<vector<int>>(n);
	f(i,0,n) {
		mat[i] = vector<int>(n);
		f(j,0,n) {
			cin >> mat[i][j];
		}
	}

	int alv = alvo(mat, n);

	f(i,0,n) { // itera pelas linhas pera encontrar a linha com o valor errado

		int aux_sum = 0;
		f(j,0,n) {
			aux_sum += mat[i][j];
		}

		if(aux_sum != alv) { // encontrei a linha com o valor errado, encontrar qual deles

			f(j, 0, n) { // itera pelos valores

				int subSum = 0;

				f(k, 0, n)  {// soma a coluna daquele valor
					subSum += mat[k][j];
				}


				if(subSum != alv) {

					cout << alv - subSum + mat[i][j] << " " << mat[i][j] << endl;

					exit(0);
				}
			}
		}
	}
}

int32_t main() { _
	
	clock_t z = clock();

	int t = 1; // cin >> t;
	while (t--) 
	//while(cin >> a >> b)
		solve();


	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
