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

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

int mdc_util(const int& a,const int& b)
{
 if (a == 0)
   return b;
 return mdc_util(b % a, a);
}


void solve(int index) {
    int s1, s2;

    cin >> s1 >> s2;

    int n1 = binaryToDecimal(s1);
    int n2 = binaryToDecimal(s2);

    if(mdc_util(n1,n2) != 1) {
        cout << "Pair #" << index << ": All you need is love!\n";
    } else {
        if(n1 == 1 || n2 == 1)
        cout << "Pair #" << index << ": All you need is love!\n";
        else 
        cout << "Pair #" << index << ": Love is not all you need!\n";
    }
}

int a, b;

int32_t main() { _
	
	int t; cin >> t;
    for(int i=0; i<t; i++)
		solve(i+1);

	return 0;
}

