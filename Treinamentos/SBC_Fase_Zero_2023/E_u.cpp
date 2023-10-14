    #include <bits/stdc++.h>

    using namespace std;

    #define _                             \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);

    #define int long long int
    #define double long double
    #define endl "\n"
    #define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
    #define print_v(a)     for(auto x : a) cout << x << endl;
    #define print_vp(a)  \
        for (auto x : a) \
        cout << x.F << " " << x.S << endl
    #define print2(a, x, y)         \
        for (int i = x; i < y; i++) \
            cout << a[i] << " ";    \
        cout << endl
    #define f(i, s, e) for (int i = s; i < e; i++)
    #define rf(i, e, s) for (int i = e - 1; i >= s; i--)

    const int INF = 0x7f3f3f3f;
    const int MAX = 1e8 + 10; // 10⁶ + 10

    template <typename Arg1>
    void __f(const char *name, Arg1 &&arg1) { cout << name << " : " << arg1 << endl; }
    template <typename Arg1, typename... Args>
    void __f(const char *names, Arg1 &&arg1, Args &&...args)
    {
        const char *comma = strchr(names + 1, ',');
        cout.write(names, comma - names) << " : " << arg1 << " | ";
        __f(comma + 1, args...);
    }

    vector<int> tentativas;
    vector<int> erros;
    vector<pair<int, int>> possiveis;
    set<int> valores;
    int pos1, pos2;

    void solve()
    {
        int b, t;
        cin >> t;

        for (int i = 0; i < t; i++)
        {
            cin >> b;
            tentativas.push_back(b);
        }

        for (int i = 0; i < t; i++)
        {
            cin >> b;
            erros.push_back(b);
        }


        do
        {
            pos1 = tentativas.at(0) + erros.at(0);
            pos2 = tentativas.at(0) - erros.at(0);

            for (int i = 1; i < t; i++)
            {

                if (pos1 != tentativas.at(i) + erros.at(i) && pos1 != tentativas.at(i) - erros.at(i))
                {
                    pos1 = -1;
                }
                if (pos2 != tentativas.at(i) + erros.at(i) && pos2 != tentativas.at(i) - erros.at(i))
                {
                    pos2 = -1;
                }

                if(pos1 == -1 && pos2 == -1)
                    break;
            }

            if(pos1 != -1) valores.insert(pos1);
            
            if(pos2 != -1) valores.insert(pos2);
        } while (next_permutation(erros.begin(), erros.end()));

        for(auto it : valores) {
            cout << it << endl;
        }
    }

    int32_t main()
    {
        _

        clock_t z = clock();

        solve();

        cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
        return 0;
    }
