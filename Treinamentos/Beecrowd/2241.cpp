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

    vector<vector<int>> mat(n, vector<int> (n, 0));

    f(i,0,p) {

        int x, y; cin >> x >> y; x--, y--;

        mat[x][y] = -1;
    }

    f(i,0,p) {

        int x, y; cin >> x >> y; x--, y--;

        mat[x][y] = 1;
    }

    int pretas=p, brancas=p;

    f(sz,2,n+1) { // tamanho do quadrado
        f(posX,0,n-sz+1) { // posicao inicial x
            f(posY,0,n-sz+1) { // posicao inicial y
                bool hasBlack = false, hasWhite = false;

                f(i,posX, posX+sz) {
                    f(j,posY, posY+sz) {
                        if(mat[i][j] == -1) {
                            hasBlack = true;
                            break;
                        } else if (mat[i][j] == 1) {
                            hasWhite = true;
                        }
                    }
                    if(hasBlack) 
                        break;
                }

                if(!hasBlack && hasWhite)
                    brancas++;

            }
        }
    }

    f(sz,2,n+1) { // tamanho do quadrado
        f(posX,0,n-sz+1) { // posicao inicial x
            f(posY,0,n-sz+1) { // posicao inicial y
                bool hasBlack = false, hasWhite = false;

                f(i,posX, posX+sz) {
                    f(j,posY, posY+sz) {
                        if(mat[i][j] == -1) {
                            hasBlack = true;
                        } else if (mat[i][j] == 1) {
                            hasWhite = true;
                            break;
                        }
                    }
                    if(hasWhite) 
                        break;
                }

                if(!hasWhite && hasBlack)
                    pretas++;

            }
        }
    }

    cout << pretas << " " << brancas << endl;

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
