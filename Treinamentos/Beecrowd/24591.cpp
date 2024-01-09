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
const int MAXN = 1010; 

string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A'; return a; }
bool prime(int a) { if (a==1) return 0; for (int i=2;i<=round(sqrt(a));++i) if (a%i==0) return 0; return 1; }

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

vector<pair<int, pair<int, int>>> kruskadj;

int cost;

void kruskal(vector<pair<int,int>> adjF[], vector<pair<int,int>> adjR[], int cidades) {

    for(int i = 1;i<MAXN;i++) {
        for(auto j: adjF[i]) {
            kruskadj.push_back({j.first,{i,j.second}});
        }
    }

    sort(kruskadj.begin(),kruskadj.end());

    vector<int> id(cidades);

    for (int i = 0; i < cidades; i++) 
		id[i] = i;

    for (auto p : kruskadj) {

        int x = p.second.first;
        int y = p.second.second;
        int w = p.first;

        if (id[x] != id[y]) {

            cost += w;
            int old_id = id[x], new_id = id[y];
            for (int i = 0; i < cidades; i++)
                if (id[i] == old_id) 
					id[i] = new_id;
        }
    }

	kruskadj.clear();

	for(int i = 1;i<MAXN;i++) {
        for(auto j: adjR[i]) {
            kruskadj.push_back({j.first,{i,j.second}});
        }
    }

    sort(kruskadj.begin(),kruskadj.end());

	for (auto p : kruskadj) {

        int x = p.second.first;
        int y = p.second.second;
        int w = p.first;

        if (id[x] != id[y]) {

            cost += w;
            int old_id = id[x], new_id = id[y];
            for (int i = 0; i < cidades; i++)
                if (id[i] == old_id) id[i] = new_id;
        }
    }
}

void solve() {

	int n, f, r; cin >> n >> f >> r;

	cost = 0;

	vector<pair<int,int>> adjR[MAXN];
	vector<pair<int,int>> adjF[MAXN];

	for(int i=0; i<f; i++) {
		int a, b, c; cin >> a >> b >> c;
		adjF[a].push_back({c, b});
	}

	for(int i=0; i<f; i++) {
		int a, b, c; cin >> a >> b >> c;
		adjR[a].push_back({c, b});
	}

	kruskal(adjF, adjR, n+1);

	cout << cost << endl;
}

int32_t main() { _
	
	solve();

	return 0;
}