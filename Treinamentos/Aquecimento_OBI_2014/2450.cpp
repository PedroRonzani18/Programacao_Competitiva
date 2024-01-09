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


void solve() {
	
	int l, c; cin >> l >> c;

	int mat[l][c];
	for(int i=0; i<l; i++) {
		for(int j=0; j<c; j++) {
			cin >> mat[i][j];
		}
	}

	f(i,0,l) {

		bool fullZero = true;
		bool firstZero = false;
		pair<int,int> fzeropos = {-1,-1};

		f(j,0,c) {

			if(!firstZero) {
				if(mat[i][j] != 0) {
					fzeropos.first = i;
					fzeropos.second = j;
					firstZero = true;
				}
			}
			if(mat[i][j] != 0) {
				fullZero = false;
				if(firstZero) break;
			}
		}

		if(fullZero) {

			bool allZeros = true;
			f(k,i+1, l) {
				f(p, 0, c) {
					if(mat[k][p] != 0) {
						allZeros = false;
						break;
					}
				}
				if(!allZeros) 
					break;
			}
			if(!allZeros) {
				cout << "N\n";
				return;
			}
			cout << "S" << endl;
			return;

		} else {

			if(fzeropos.first != -1) {

				bool squareZeros = true;
				f(k, fzeropos.first+1, l) {
					f(p, 0, fzeropos.second + 1) {
						if(mat[k][p] != 0) {
							squareZeros = false;
							break;
						}
					}
					if(!squareZeros) break;
				}

				if(!squareZeros) {
					cout << "N\n";
					return;
				}
			}
		}
	}

	cout << "S" << endl;

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
