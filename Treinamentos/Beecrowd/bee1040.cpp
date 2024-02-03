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
	
    vector<double> nums(4);
    vector<double> pesos = {2, 3, 4, 1};
    double sum = 0;

    f(i,0,4) {
        cin >> nums[i];
        sum += nums[i] * pesos[i];
    }

    double media = sum /10.;

    cout << fixed << setprecision(1) << "Media: " << media << endl;
    if(media >= 7) cout << "Aluno aprovado.\n";
    else if (media < 5) cout << "Aluno reprovado.\n";
    else {
        
        cout << "Aluno em exame." << endl;
        double nota; cin >> nota;
        cout << "Nota do exame: " << nota << endl;
        media += nota; media /= 2;

        if(media >= 5) cout << "Aluno aprovado." << endl;
        else cout << "Aluno reprovado." << endl;

        cout << "Media final: " << fixed << setprecision(1) << media << endl;

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
