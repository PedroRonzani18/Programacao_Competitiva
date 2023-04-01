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

int palindromo(int num)
{
	string a = to_string(num);
	int tam = a.size();
	for(int i = 0; i < tam/2; i++)
	{
		if(a[i] != a[tam-i-1])
			return 0;
	}
	return 1;
}

void solve() {
	int a, b;
	while(cin >> a >> b)
	{
		int min = 0, max = 0;
		for(int i = a+1; i < b; i++)
		{
			if(palindromo(i))
			{
				min = i;
				break;
			}
		}
		if(min == 0)
		{
			cout << -1 << endl;
		}
		else
		{
			for(int i = b-1; i > a; i--)
			{
				if(palindromo(i))
				{
					max = i;
					break;
				}
			}
			cout << min << " " << max << endl;
		}
	}
}

int32_t main() { _
	
	clock_t z = clock();


	int t = 1; // cin >> t;
	while (t--) solve();


	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}

