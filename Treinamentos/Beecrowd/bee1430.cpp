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

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

unordered_map<char,float> conv = {{'W', 1}, {'H', 1/2.}, {'Q', 1/4.}, {'E', 1/8.}, {'S', 1/16.}, {'T', 1/32.}, {'X', 1/64.}};

void solve(string s) {

    s.erase(s.begin());

    int ans = 0;
    double counter = 0;

    for(char c : s) {
        if(c == '/') {
            if(counter == 1) ans++;
            counter = 0;
        }
        counter += conv[c];
    }

    cout << ans << endl;

}

int32_t main() { _
	
	clock_t z = clock();

    while(true) {
        string s; getline(cin, s);
        if(s[0] == '*') break;
		solve(s);

    }


	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
