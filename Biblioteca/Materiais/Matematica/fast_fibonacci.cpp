#include <bits/stdc++.h>
using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define pii	         pair<int,int>
#define endl         "\n"
#define print_v(a)   for(auto x : a)cout<<x<<" ";cout<<endl
#define print_vp(a)  for(auto x : a)cout<<x.first<<" "<<x.second<< endl
#define f(i,s,e) 	 for(int i=s;i<e;i++)
#define rf(i,e,s) 	 for(int i=e-1;i>=s;i--)
#define CEIL(a, b)   ((a) + (b - 1))/b
#define TRUNC(x, n)  floor(x * pow(10, n))/pow(10, n)
#define ROUND(x, n)  round(x * pow(10, n))/pow(10, n)
#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;
using namespace std;

string decimal_to_bin(int n) {
	string bin = bitset<sizeof(int) * 8>(n).to_string();
	auto loc = bin.find('1');
	// remove leading zeros
	if (loc != string::npos)
		return bin.substr(loc);
	return "0";
}

int fastfib(int n) {
	string bin_of_n = decimal_to_bin(n); 

	int f[] = { 0, 1 };

	for (auto b : bin_of_n) {
		int f2i1 = f[1] * f[1] + f[0] * f[0];
		int f2i = f[0] * (2 * f[1] - f[0]);

		if (b == '0') {
			f[0] = f2i;
			f[1] = f2i1;
		} else {
			f[0] = f2i1;
			f[1] = f2i1 + f2i;
		}
	}

	return f[0];
}

int main() {
	int n = 13;
	int fib = fastfib(n);
	cout << "F(" << n << ") = " << fib << "\n";
}
    