#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)       a.begin(), a.end()
#define int          long long int
#define double       long double
#define vi 			 vector<int>
#define endl         "\n"
#define print_v(a)   for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)  for(auto x : a) cout << x.F << " " << x.S << endl
#define f(i,s,e) 	 for(int i=s;i<e;i++)
#define rf(i,e,s) 	 for(int i=e-1;i>=s;i--)
#define CEIL(a, b)   ((a) + (b - 1))/b   // Arredonda para cima
#define TRUNC(x, n)  floor(x * pow(10, n))/pow(10, n) // Trunca n casas
#define ROUND(x, n)  round(x * pow(10, n))/pow(10, n) // Arreddonda n c 

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF =  0x7f3f3f3f; // 0x7f com 3 3f's (10^9)
const int LINF = 0x3f3f3f3f3f3f3f3f; // 0x com 7 3f's (10^18)
const int MAX = 1e6+10; // 10^6 + 10

void solve() {

	vector<pair<int,int>> v(15);
	f(i,0,15) {
		cin >> v[i].first >> v[i].second;
	}

	vector<char> p1(16);
	vector<char> p2;
	vector<char> p3;
	vector<char> p4;
	char ans;

	f(i,0,16) {
		p1[i] = 'A' + i;
	}

	for(int i=0; i<8; i++) {
		if(v[i].first > v[i].second) {
			p2.push_back(p1[2 * i]);
		} else {
			p2.push_back(p1[2 * i + 1]);
		}
	}
	for(int i=8; i <12; i++) {
		if(v[i].first > v[i].second) {
			p3.push_back(p2[2 * (i-8)]);
		} else {
			p3.push_back(p2[2 * (i-8) + 1]);
		}
	}
	for(int i=12; i<14; i++) {
		if(v[i].first > v[i].second) {
			p4.push_back(p3[2 * (i-12)]);
		} else {
			p4.push_back(p3[2 * (i-12)+ 1]);
		}
	}
	for(int i=14; i<15; i++) {

		if(v[i].first > v[i].second) {
			cout << p4[0] << endl;
		} else {
			cout << p4[1] << endl;
		}
	}
}

int32_t main() { _
	
	clock_t z = clock();

	int t = 1; // cin >> t;
	while (t--) {
		solve();
	}

	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}
