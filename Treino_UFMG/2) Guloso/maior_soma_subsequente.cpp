#include <bits/stdc++.h>

using namespace std;


int maior_soma_subarray(vector<int> v)
{
    int ans = INT_MIN, soma_ant = INT_MIN;

    for(int i=0; i<v.size(); i++) {
        if(soma_ant < 0)
            soma_ant = v[i]; // começa nova soma
        
        else
            soma_ant += v[i]; // realiza nova soma
            ans = max(soma_ant, ans); // compara qual soma é maior
    }

    return ans;
}

int main()
{
    int n; cin >> n;

    vector<int> v;

    for(int i=0; i<n; i++) {
        int a; cin >> a; v.push_back(a);
    }


    cout << maior_soma_subarray(v) << endl;
    exit(0);
}