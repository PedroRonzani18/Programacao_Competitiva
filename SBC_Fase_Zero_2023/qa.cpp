#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define int            long long int
#define double         long double
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl

int32_t main() { _


    char a,b,c;

    cin >> a >> b >> c;

    if ((a == 'O' && b == 'O') ||
        (a == 'O' && c == 'O') ||
        (b == 'O' && c == 'O') ||
        (a == 'X' && b == 'X' && c == 'X')){

        cout << "?" << endl;

    }else if ((a == 'X' && b == 'X') ||
        (b == 'X' && c == 'X') ){

        cout << "Alice" << endl;

    }else {

        cout << "*" << endl;
    }



	return 0;
}

