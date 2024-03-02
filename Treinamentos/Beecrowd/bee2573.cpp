#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define endl         "\n"
#define print_v(a)   for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)  for(auto x : a) cout << x.first << " " << x.second << endl
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

pair<double, double> lineFromPoints(pair<double, double> P, pair<double, double> Q) {

    double a = Q.second - P.second;
    double b = P.first - Q.first;
    double c = a * (P.first) + b * (P.second);
    if (b < 0) b *= -1;

    return {(-1 * a)/b, c/b};
}

void solve() {

	int l, c, xa, ya, xb, yb; cin >> l >> c >> xa >> ya >> xb >> yb;    
    if(xa == xb and ya == yb) { // x = xa and y = ya
        cout << "0.500000 0.500000" << endl;
        return;
    }

    cout << fixed << setprecision(6);

    if(ya == yb) { // x = xa

        double mid = (ya + yb)/2.0;

        dbgl(mid);

        dbg(l); dbg(mid); dbgl(l-mid);

        if(xa > mid) {
            cout << (double)(l - mid)/(l-1) << " " <<(double) (mid-1)/(l-1) << endl;
        } else {
            cout << (double)(mid-1)/(l-1) << " " << (double)(l - mid)/(l-1) << endl;
        }

    } else if (xa == xb) { // y = ya

        double mid = (xa + xb)/2.0;

        if(ya > mid) {
            cout << (double)(c - mid)/(c-1) << " " <<(double) (mid-1)/(c-1) << endl;
        } else {
            cout << (double)(mid-1)/(c-1) << " " << (double)(c - mid)/(c-1) << endl;
        }

    } else {

        double a = (double) (ya - yb)/(xa - xb);

        double midx = (xa + xb)/2.0;
        double midy = (ya + yb)/2.0;
        
        double a1 = (-1.)/a;
        double b1 = midy - a1*midx;

        double bmenor = (-1 * b1)/a1;
        double bmaior = c - bmenor;

        double area1 = (bmaior + bmenor) * l / 2.0;

        cout << area1 / (l * c) << " " << (l*c - area1) / (l * c) << endl;

    }

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
