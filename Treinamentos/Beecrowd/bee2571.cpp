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

void solve() {

	cout << fixed;

	double m, x, p, j; cin >> m >> p >> j >> x; 
	double jurosAcumulados = m * j / 100.;
	int ans = (int) floor(log(x/jurosAcumulados) / log(1-p/100.));

	cout << (ans > 0 ? ans : 0) << endl;
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
/*
No primeiro caso, Dilson começa com um montante de R$1,000,000.00 recebendo um juros de 5% desse valor, no total de R$50,000.00. Em seguida, doa 10% desse valor, ficando com apenas R$900000.00. No mês seguinte, recebe do juros o valor de R$45000.00 que é o mínimo que ele precisa. Então Dilson pára de doar, pois se continuasse, no mês seguinte ele iria receber apenas R$40500.00 o que não é o suficiente para ele.

No segundo caso, Dilson começa com um montante de R$1000000.00. Ele termina o primeiro mês com R$900000.00, termina o segundo mês com R$810000.00 e o terceiro mês com R$729000.00. No quarto mês, Dilson atinge a quantia de R$656100.00 e rendimentos de R$32805.00, que pela primeira vez são insuficientes para pagar as contas.*/
