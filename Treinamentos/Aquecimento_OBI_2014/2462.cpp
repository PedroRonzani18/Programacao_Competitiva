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

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

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

void solve() {

	string a, b, c, d; cin >> a >> b >> c >> d;
	int t1, t2, t3, t4;
	vector<string> time;
	
	time = split(a, ":");
	t1 = (60 * stoi(time[0]) + stoi(time[1]));

	time = split(b, ":");
	t2 = (60 * stoi(time[0]) + stoi(time[1]));

	time = split(c, ":");
	t3 = (60 * stoi(time[0]) + stoi(time[1]));

	time = split(d, ":");
	t4 = (60 * stoi(time[0]) + stoi(time[1]));

	int d1 = (t1 > t2) ? 1440 - t1 + t2 : t2 - t1;
    int d2 = (t3 > t4) ? 1440 - t3 + t4 : t4 - t3;
    
	int minutos = (d1 + d2) / 2; 
	if (minutos > 720) { // se ultrapassar 12 horas (720 minutos)
		minutos -= 720; // subtrai 12 horas
	}

	int horas = d1 - minutos;
	if (horas > 720) { // se ultrapassar 12 horas (720 minutos)
		horas -= 1440; // subtrai 24 horas
	}

	cout << minutos << " " << horas / 60 << endl;
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