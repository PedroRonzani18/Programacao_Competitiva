/*--------------------------------------------------------
Nomes (email):
Pedro Augusto (pedroaugustogabironzani@gmail.com)
Ulisses Andrade (carvalhoandradeulisses@gmail.com)
Lucas Andrade (andradelucasbrandao@gmail.com)
----------------------------------------------------------*/

#include <bits/stdc++.h>
using namespace std;

#define _                         \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

#define all(a) a.begin(), a.end()
#define int long long int
#define double long double
#define vi vector<int>
#define endl "\n"
#define print_v(a)        \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl
#define print_vp(a)  \
    for (auto x : a) \
    cout << x.F << " " << x.S << endl
#define print2(a, x, y)         \
    for (int i = x; i < y; i++) \
        cout << a[i] << " ";    \
    cout << endl
#define f(i, s, e) for (int i = s; i < e; i++)
#define rf(i, e, s) for (int i = e - 1; i >= s; i--)
#define CEIL(a, b) ((a) + (b - 1)) / b
#define TRUNC(x) floor(x * 100) / 100

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)

const int INF = 0x7f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const int MAX = 1e6 + 10; // 10^6 + 10

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

double distancia(double x1, double y1, double x2, double y2)
{
    double dist_x = abs(x1 - x2), dist_y = abs(y1 - y2);
    return sqrt(dist_x * dist_x + dist_y * dist_y);
}

void solve(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double dist1 = distancia(x1, y1, x2, y2);
    double dist2 = distancia(x2, y2, x3, y3);
    double dist3 = distancia(x3, y3, x1, y1);

    if ((abs(dist1 - dist2) < dist3) && (dist3 < (dist1 + dist2)) &&
        (abs(dist2 - dist3) < dist1) && (dist1 < (dist2 + dist3)) &&
        (abs(dist3 - dist1) < dist2) && (dist2 < (dist3 + dist1)) &&
        ((sqrt(dist1 * dist1 + dist2 * dist2) == dist3) || (sqrt(dist2 * dist2 + dist3 * dist3) == dist1) || (sqrt(dist3 * dist3 + dist1 * dist1) == dist2)))
        cout << "sim" << endl;
    else
        cout << "nao" << endl;
}

int32_t main()
{
    _

        clock_t z = clock();

    int t;
    cin >> t;
    double x1, x2, x3, y1, y2, y3;
    while (t--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        solve(x1, y1, x2, y2, x3, y3);
    }
    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}