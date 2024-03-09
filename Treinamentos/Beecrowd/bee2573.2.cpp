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

double extractY(double x, double xa, double xb, double ya, double yb) {
    return (-(x - xb)*(x - xb) + (x - xa)*(x - xa) + ya*ya - yb*yb ) / (-2 * yb + 2 * ya);
}

double extractX(double y, double xa, double xb, double ya, double yb) {
    return ((y - yb) * (y - yb) - (y - ya) * (y - ya) + xb*xb - xa*xa) / (2 * xb - 2 * xa);
}

double truangulo(double b, double h) {
    return (b*h) / 2.;
}

double trapezio(double b, double B, double h) {
    return (b+B) * h / 2.;
}

void solve() {

    int L, A, xa, ya, xb, yb; cin >> L >> A >> xa >> ya >> xb >> yb;

    double l1 = extractY(0, xa, xb, ya, yb);
    double l2 = extractX(A, xa, xb, ya, yb);
    double l3 = extractY(L, xa, xb, ya, yb);
    double l4 = extractX(0, xa, xb, ya, yb);

    double resultado;

    if((0 < l1 and l1 < A) and (0 < l2 and l2 < L))
        resultado = truangulo((A-l1), l2);

    else if((0 < l1 and l1 < A) and (0 < l3 and l3 < A))
        resultado = trapezio(l1, l3, L);

    else if((0 < l1 and l1 < A) and (0 < l4 and l4 < L))
        resultado = truangulo(l1, l4);

    else if((0 < l2 and l2 < L) and (0 < l4 and l4 < L))
        resultado = trapezio(l2, l4, A);

    else if((0 < l2 and l2 < L) and (0 < l3 and l3 < A))
        resultado = truangulo(L - l2, A - l3);

    else if((0 < l3 and l3 < A) and (0 < l4 and l4 < L))
        resultado = truangulo(L - l4, l3);
        
    else {
        cout << "0.500000 0.500000" << endl;
        return;
    }

    double ans = resultado / (L * A);

    double xc = L/2, yc = A/2;
    double dCentroA = pow(xa - xc, 2) + pow(ya - yc, 2);
    double dCentroB = pow(xb - xc, 2) + pow(yb - yc, 2);

    cout << fixed << setprecision(6);
    if(dCentroA > dCentroB) {
        if(ans <= 0.5)
            cout<<ans<<" "<<1 - ans;
        else 
            cout<<1 - ans<<' '<<ans;
    } else {
        if(ans >= 0.5)
            cout<<ans<<" "<<1 - ans;
        else 
            cout<<1 - ans<<' '<<ans;
    }
    cout << endl;
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
