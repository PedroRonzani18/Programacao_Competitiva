#include <bits/stdc++.h>

using namespace std;

#define _                             \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long int
#define double long double
#define endl "\n"
#define print_v(a)        \
    for (auto x : a)      \
        cout << x << " "; \
    cout << endl

int32_t main()
{
    _

        /*
            3 grafo = 2 pd
            2 geom = 5pd

            3A = 2B
            2C = 5A

            A = 2C / 5
            A = 2B / 3

            B = 3A / 2

            C = 5A / 2
        */
        int a,
        b, c, sum = 1;
    cin >> a >> b >> c;

    char x;
    cin >> x;

    switch (x)
    {
    case 'A':

        sum += a;

        sum += (3 / 2) * b;

        sum += (5  / 2) * c;

        break;
    case 'B':

        sum += (2  / 5) * a;

        sum += b;

        sum += (5 * ((2 ) / 3) / 2) * c;

        break;
    case 'C':

        sum += (2  / 5) * a;

        sum += (3 * ((2)/5) / 2) *b;

        sum += c;

        break;

    default:
        break;
    }


    cout << sum << endl;


    return 0;
}
