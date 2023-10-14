#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <ctime>

using namespace std;

#define int long long int

const int MAX = 1e8 + 10; // 10⁶ + 10

vector<int> tentativas;
vector<int> erros;
set<int> valores;
int pos1, pos2;

void solve()
{
    int t;
    cin >> t;

    tentativas.resize(t);
    erros.resize(t);

    for (int i = 0; i < t; i++)
        cin >> tentativas[i];

    for (int i = 0; i < t; i++)
        cin >> erros[i];

    do
    {
        pos1 = abs(tentativas[0] + erros[0]);
        pos2 = abs(tentativas[0] - erros[0]);

        for (int i = 1; i < t; i++)
        {
            if (pos1 != tentativas[i] + erros[i] && pos1 != tentativas[i] - erros[i])
            {
                pos1 = -1;
            }
            if (pos2 != tentativas[i] + erros[i] && pos2 != tentativas[i] - erros[i])
            {
                pos2 = -1;
            }

            if (pos1 == -1 && pos2 == -1)
                break;
        }

        if (pos1 != -1)
            valores.insert(pos1);

        if (pos2 != -1)
            valores.insert(pos2);

    } while (next_permutation(erros.begin(), erros.end()));

    for (auto it : valores)
    {
        cout << it << endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    clock_t z = clock();

    solve();

    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}
