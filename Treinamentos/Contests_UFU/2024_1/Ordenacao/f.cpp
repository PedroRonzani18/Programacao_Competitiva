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

vector<string> split(string s, string del = " ")
{
    vector<string> retorno;
    int start, end = -1 * del.size();
    do
    {
        start = end + del.size();
        end = s.find(del, start);
        retorno.push_back(s.substr(start, end - start));
    } while (end != -1);
    return retorno;
}

bool compara(vector<string> a, vector<string> b)
{
    if (a[1] == b[1])
        return a[0] < b[0];

    return a[1] > b[1];
}

void solve(vector<vector<string>> vvs)
{

    sort(vvs.begin(), vvs.end(), compara);

    for (vector<string> vs : vvs)
    {
       cout << vs[0] << endl;
    }
}

int32_t main()
{
    _

    clock_t z = clock();

    vector<vector<string>> vvs;
    vector<string> vs;
    string s;

    string st;
    int t; getline(cin, st); t = stoi(st);
    while (t--)
    {
        getline(cin, s);
        vs = split(s, ",");
        vvs.push_back(vs);
    }
    solve(vvs);

    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}