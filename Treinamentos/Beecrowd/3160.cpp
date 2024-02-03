#include <bits/stdc++.h>
using namespace std;

#include <unordered_map> // Add this line to include the unordered_map library

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define all(a) a.begin(), a.end()
#define int long long int
#define double long double
#define vi vector<int>
#define endl "\n"
#define print_v(a)        \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define print_vp(a)  \
    for (auto x : a) \
    cout << x.F << " " << x.S << endl
#define print2(a, x, y)         \
    for (int i = x; i < y; i++) \
        cout << a[i] << " ";    \
    cout << endl
#define f(i, s, e) for (int i = s; i < e; i++)
#define rf(i, e, s) for (int i = e - 1; i >= s; i--)
#define CEIL(a, b) ((a) + (b - 1)) / b
#define TRUNC(x) floor(x * 100) / 100

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF = 0x7f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const int MAX = 1e6 + 10; // 10^6 + 10

unordered_map<string, int> posicao;

unordered_set<string> split(string s, string del = " ") {
   vector<string> retorno;
   unordered_multiset<string> ret;
   int start, end = -1*del.size();
   int ind = 0;
   do {
       start = end + del.size();
       end = s.find(del, start);
       string push = s.substr(start, end - start);
       // retorno.push_back(push);
       ret.insert(push); 
       posicao[push] = ind;
       ind++;
       print_v(ret);
   } while (end != -1);
   return ret;
}


void solve() {
    
    string l; getline(cin, l); unordered_set<string> vl = split(l);
    string n; getline(cin, n); unordered_set<string> vn = split(n);

    string nome; getline(cin, nome);

    vector<string> ans;

    if(nome == "nao") {
        
        for(string s : vl) {
            cout << s << " ";
        }

        string st = *vn.begin(); cout << st;
        for(auto it = ++vn.begin(); it != vn.end(); it++) {
            cout << " " << *it;
        }
        cout << endl;
    }
}

int32_t main() {
    _

        clock_t z = clock();

    int t = 1; // cin >> t;
    while (t--)
        // while(cin >> a >> b)
        solve();

    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}
