#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define int            long long int
#define double         long double
#define endl           "\n"

int32_t main() { _

    int a;
    cin >> a;

    while(true) {

        if(a < 14) {
            cout << a << endl;
            break;
        }

        cout << a << endl;
        a = ((int)(a / 10) * 3 + a % 10);
    }


	return 0;
}
