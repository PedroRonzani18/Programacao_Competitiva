/*--------------------------------------------------------
Nomes (email):
Pedro Augusto (pedroaugustogabironzani@gmail.com)
Ulisses Andrade (carvalhoandradeulisses@gmail.com)
Lucas Andrade (andradelucasbrandao@gmail.com)
----------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;

#define _ std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(a)       a.begin(), a.end()
#define int          long long int
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

const int INF = 1e9;    // 2^31-1
const int LLINF = 4e18; // 2^63-1
const double EPS = 1e-9;
const int MAX = 1e6+10; // 10^6 + 10

void solve(int m1, int v1, int m2, int v2)
{
    if(m1 + v2 > m2 + v1)
        cout << "Time 1" << endl;
    else if(m1 + v2 < m2 + v1)
        cout << "Time 2" << endl;
    else 
    {
        if(v1 > v2)
            cout << "Time 2" << endl;
        else if(v1 < v2)
            cout << "Time 1" << endl;
        else 
            cout << "Penaltis" << endl;
    }
}

int32_t main()
{
    _

        clock_t z = clock();

    int t; 
    cin >> t;
    int m1, v1, m2, v2;
    char c;
    while (t--)
    {
        cin >> m1 >> c >> v1 >> m2 >> c >> v2;
        solve(m1, v1, m2, v2);
    }

    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}