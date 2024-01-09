#include <bits/stdc++.h>
using namespace std;

#define _   ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)         a.begin(), a.end()
#define int            long long int
#define double         long double
#define vi 			   vector<int>
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)    for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;
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

	int n; cin >> n;

	char mat[n+1][n+1];
	f(i,0,n) 
		f(j,0,n) 
			cin >> mat[i][j];

	int situation [n+1][n+1];
	f(i,0,n) 
		f(j,0,n) 
			situation [i][j] = 0;

	int safe = 0;

	f(i,0,n) {
		f(j,0,n) {

			bool valid = true;

			vector<pair<int,int>> track;
			track.push_back({i,j});

			while(valid) {

				pair<int,int> lastpos = track.back();

				if(lastpos.first < 0 || lastpos.second < 0 || n <= lastpos.first || n <= lastpos.second) {

					track.pop_back();
					for(auto x : track)
						situation[x.first][x.second] = -1;
					valid = false;	
					break;
				}

				switch (situation[lastpos.first][lastpos.second])
				{
					case 0: // nao passei por aq ainda

						situation[lastpos.first][lastpos.second] = 1;

						switch (mat[lastpos.first][lastpos.second])
						{
							case '>': track.push_back({ lastpos.first, lastpos.second+1 }); break;
							case '<': track.push_back({ lastpos.first, lastpos.second-1 }); break;
							case 'A': track.push_back({ lastpos.first-1, lastpos.second }); break;
							case 'V': track.push_back({ lastpos.first+1, lastpos.second }); break;
						}						

						break;

					case -1:
						for(auto x : track)
							situation[x.first][x.second] = -1;
						valid = false;	
						break;

					case 1:
						safe += track.size()-1;
						valid = false;	
						break;
				}
			}
		}
	}

	cout << safe << endl;
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