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
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

const int INF =  0x7f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const int MAX = 1e6+10; // 10^6 + 10

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

vector<string> split(string s, string del = " ") {
   vector<string> retorno;
   int start, end = -1*del.size();
   do {
       start = end + del.size();
       end = s.find(del, start);
       retorno.push_back(s.substr(start, end - start));
   } while (end != -1);
   return retorno;
}

bool comp(tuple<string, string, string> a, tuple<string, string, string> b) {

    auto [a1, a2, a3] = a;
    auto [b1, b2, b3] = b;

    vector<string> data = split(a1, "/");
    vector<string> data2 = split(b1, "/");

    if(data[2] != data2[2]) return data[2] < data2[2];
    if(data[1] != data2[1]) return data[1] < data2[1];
    if(data[0] != data2[0]) return data[0] < data2[0];

    vector<string> hora = split(a2, ":");
    vector<string> hora2 = split(b2, ":");

    if(hora[0] != hora2[0]) return hora[0] < hora2[0];
    if(hora[1] != hora2[1]) return hora[1] < hora2[1];
    if(hora[2] != hora2[2]) return hora[2] < hora2[2];

    return a3 < b3;

}

void solve() {
	
    vector<string> vs;
    string s;
    while(getline(cin, s)) {
        vs.push_back(s);
    }

    vector<tuple<string, string, string>> tuplas;

    for(string v : vs) {
        vector<string> aux = split(v, " ");

        string frase = "";

        f(i,2,aux.size()-1) {
            frase += (aux[i] + " ");
        }
        frase += aux.back();


        tuplas.push_back({aux[0], aux[1], frase});
    }

    sort(all(tuplas), comp);

    for(auto t : tuplas) {
        auto [a, b, c] = t;
        cout<<a<<" "<<b<<" "<<c<<endl;
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
