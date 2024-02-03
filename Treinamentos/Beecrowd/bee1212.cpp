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

void solve(string a, string b) {
	
    int carryCount = 0, carry = 0;
    int s1 = a.size(), s2 = b.size();
    int sz = min(s1, s2);

    f(i,0,sz) {

        int num1 = a[s1-i-1] - 48;
        int num2 = b[s2-i-1] - 48;


        carry = (num1 + num2 + carry) / 10;


        if(carry > 0) carryCount++;
    } 

    if(sz < s1) {

        int num1 = a[s1-sz-1] - 48;
        carry = (num1 + carry) / 10;
        if(carry > 0) carryCount++;

    } else if(sz < s2) {
        int num1 = b[s1-sz] - 48;
        carry = (num1 + carry) / 10;
        if(carry > 0) carryCount++;
    }

    if(carryCount) cout << carryCount << " carry operation" << (carryCount > 1 ? "s." : ".") << endl;
    else cout << "No carry operation." << endl;

}

int32_t main() { _

    clock_t z = clock();

    string a, b; 
    while (cin >> a >> b) {
        if(a == "0" and b == "0") break;
        solve(a,b);
    } 

    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}
