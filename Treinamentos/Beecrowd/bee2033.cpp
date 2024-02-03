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

void solve(double c, double i, int t) {
	
    double js = c * i * t;
    double jc = c * pow(1+i,t) - c;
    cout.precision(2);

    cout << fixed << "DIFERENCA DE VALOR = "<< abs(jc - js) << endl;
    cout <<fixed <<  "JUROS SIMPLES = " << js << endl;
    cout <<fixed <<  "JUROS COMPOSTO = " << jc << endl;

}

int32_t main() { _
	
	clock_t z = clock();

    double c, i; int t; 
	while (cin >> c >> i >> t) 
	//while(cin >> a >> b)
		solve(c,i,t);

	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
