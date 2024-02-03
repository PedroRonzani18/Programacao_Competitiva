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

string decimal_to_binary(int dec) {
    string binary = "";
    while (dec > 0) {
        int bit = dec % 2;
        binary = to_string(bit) + binary;
        dec /= 2;
    }
    return binary;
}

void solve() {

	string str; cin >> str;
	int n; cin >> n;
	string str2 = decimal_to_binary(n);

	reverse(all(str2));

	while(str2.size() < str.size()) str2+= '0';

	f(i,0,str2.size()) {
		if(str2[i] == '1') str2[i] = 'O';
		else 			   str2[i] = 'X';
	}

	string ansBin = "";

	int vai1 = 0;
	f(i,0,str.size()) {

		if(str[i] == 'X' && str2[i] == 'X') {
			
			if(vai1 == 1) {
				ansBin += 'O';
				vai1 = 0;
			}
			else
				ansBin += 'X';
		}

		else if((str[i] == 'O' && str2[i] == 'X') || (str2[i] == 'O' && str[i] == 'X')) {
			
			if(vai1 == 1) ansBin += 'X';
			else 		  ansBin += 'O';
		}
		else {
			if(vai1 == 1) ansBin += 'O';
			else 		  {
				ansBin += 'X';
				vai1 = 1;
			}
		}

	}

	while (ansBin.size() < str.size())
				ansBin += 'O';

	cout << ansBin << endl;
}

int32_t main() { _
	
	clock_t z = clock();

	int t = 1; cin >> t;
	while (t--) 
	//while(cin >> a >> b)
		solve();


	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}