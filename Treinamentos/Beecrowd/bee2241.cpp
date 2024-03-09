#include <bits/stdc++.h>
using namespace std;

#define _   ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)         a.begin(), a.end()
#define int            long long int
#define double         long double
#define vi 			   vector<int>
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " ";
#define print_vp(a)    for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)
#define CEIL(a, b)     ((a) + (b - 1))/b
#define TRUNC(x) 	   floor(x * 100) / 100

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF =  0x7f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const int MAX = 1e6+10; // 10^6 + 10

void solve() {
	
    int n, p; cin >> n >> p;

    vector<vi> mat(n, vi(n)), distB(n, vi(n)), distP(n, vi(n));

    f(i,0,p) { // pretas
        int x, y; cin >> x >> y; x--, y--;
        mat[x][y] = -1;
    }

    f(i,0,p) { // brancas
        int x, y; cin >> x >> y; x--, y--;
        mat[x][y] = 1;
    }

    int pretas=0, brancas=0;

    f(i,0,n) {

        switch (mat[i][n-1]) {
            case -1:
                distP[i][n-1] = 0;
                distB[i][n-1] = 1;
                break;
            case 1:
                distB[i][n-1] = 0;
                distP[i][n-1] = 1;
                break;
            default:
                distP[i][n-1] = 1;
                distB[i][n-1] = 1;
                break;
        }

    }

    f(i,0,n-1) {

        switch (mat[n-1][i]) {
            case -1:
                distP[n-1][i] = 0;
                distB[n-1][i] = 1;
                break;
            case 1:
                distB[n-1][i] = 0;
                distP[n-1][i] = 1;
                break;
            default:
                distP[n-1][i] = 1;
                distB[n-1][i] = 1;
                break;
        }
    }

    vector<pair<int,int>> mov = {{1,1}, {1,0}, {0,1}};

    for(int sz = n-1; sz >= 1; sz--) {

        f(i,0,sz) {
            
            if(mat[sz-1-i][sz-1] == -1) 
                distP[sz-1][sz-1-i] = 0;
            
            else {
                int miniP = INT_MAX;
                for(auto [x, y] : mov) 
                    miniP = min(miniP, distP[sz-1-i+x][sz-1+y]);
                
                miniP++;
                distP[sz-1-i][sz-1]  = miniP;
            }

            if(mat[sz-1-i][sz-1] == 1) 
                distB[sz-1-i][sz-1] = 0;
            
            else {
                int miniB = INT_MAX;
                for(auto [x, y] : mov) 
                    miniB = min(miniB, distB[sz-1-i+x][sz-1+y]);
                
                miniB++;
                distB[sz-1-i][sz-1] = miniB;
            }
        }

        f(i,1,sz) {

            if(mat[sz-1][sz-1-i] == -1) 
                distP[sz-1][sz-1-i] = 0;
            
            else {
                int miniP = INT_MAX;
                for(auto [x, y] : mov) 
                    miniP = min(miniP, distP[sz-1+x][sz-1-i+y]);
                
                miniP++;
                distP[sz-1][sz-1-i] = miniP;
            }

            if(mat[sz-1][sz-1-i] == 1) 
                distB[sz-1][sz-1-i] = 0;
            
            else {
                int miniB = INT_MAX;
                for(auto [x, y] : mov) 
                    miniB = min(miniB, distB[sz-1+x][sz-1-i+y]);
                
                miniB++;
                distB[sz-1][sz-1-i] = miniB;
            }
        }
    }

    f(i,0,n) {
        f(j,0,n) {
            pretas += max((int)0, distB[i][j] - distP[i][j]);
            brancas += max((int)0, distP[i][j] - distB[i][j]);
        }
    }

    cout << pretas << ' ' << brancas << endl;
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
