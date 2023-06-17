#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define int            long long int
#define double         long double
#define endl           "\n"
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)    for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

const int INF = 0x7f3f3f3f;
const int MAX = 1e8+10; // 10⁶ + 10

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

int a, b;

void solve() {

    cin >> a;

	vector<int> tentativas(a);
    vector<int> erros(a);

    for(int i=0; i<a; i++) {
        cin >> tentativas[i];
    }


    for(int i=0; i<a; i++) {
        cin >> erros[i];
    }

    int max1 = -1;
    int max2 = -2;

    do {

        bool encontrado = true;

        for(int i=0; i<a-1; i++) {

            int pos1 = tentativas[i] - erros[i];
            int pos2 = tentativas[i] + erros[i];
        

            int pos3 = tentativas[i+1] - erros[i+1];
            int pos4 = tentativas[i+1] + erros[i+1];

            if(pos1 == pos3) max1 = pos1;
            else if(pos1 == pos4) max1 = pos1;

            else if(pos2 == pos3) max2 = pos2;
            else if(pos2 == pos4) max2 = pos2;
            else encontrado = false;

            if(!encontrado) break;
        }

    } while (next_permutation(erros.begin(), erros.end()));

}

int32_t main() { _

	clock_t z = clock();

    solve();

	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}

