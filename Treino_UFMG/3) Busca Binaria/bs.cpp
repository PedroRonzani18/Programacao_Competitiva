#include <bits/stdc++.h>

using namespace std;

int posicao_primeiro_elemento_y_maiorigual_x(vector<int> v, int x)
{
    int l=0, r = v.size();

    while(l < r) {
        int m = (l + r)/2;

        if(m < x) l = m+1;
        else r = m;
    }

    return l;

    // Lower bound: iterador para o peimeiro elemento não menor que x
    // Upper bound: iterador para o primeiro elemento maior que x
    // Lower -- = numero imediatamente menor
    // upper - lower = count(v, x)
}

int main()
{
    vector<int> v = {1,1,2,2,2,3,3,7,8,8};

    cout << (lower_bound(v.begin(), v.end(), 4) - v.begin()) << endl;
    cout << (upper_bound(v.begin(), v.end(), 4) - v.begin()) << endl;
}