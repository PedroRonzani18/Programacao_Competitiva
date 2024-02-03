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

void solve() {

    int n; cin >> n; cin.ignore();
    string current; getline(cin, current);
    bool printed = false;

    f(i,1,n) {

        string aux; getline(cin, aux);

        if(aux != current && !printed) {
            cout << "ingles" << endl;
            printed = true;
        }

        current = aux;

    }

    if(!printed) cout << current << endl;

}

int32_t main() { _
	
	int t; cin >> t; cin.ignore();
	while (t--) {
	//while(cin >> a >> b)
    	solve();
    }

	return 0;
}
