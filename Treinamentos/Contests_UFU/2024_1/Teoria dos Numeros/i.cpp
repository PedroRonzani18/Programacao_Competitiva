#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int            long long int
#define double         long double
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << endl;

int a, b;

bool isPalindrome(string str) {
    for (int i = 0; i < str.length() / 2; i++) {
        if (str[i] != str[str.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

bool isLychrel(int n) {
    for (int i = 0; i < 20; i++) {
        string str = to_string(n);
        string rev_str = str;
        reverse(rev_str.begin(), rev_str.end());
        n += stoll(rev_str);
        if (isPalindrome(to_string(n))) return false;
    }
    return true;
}

void solve() {
    cin >> a;
    cout << (isLychrel(a) ? 1 : 0) << endl;
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