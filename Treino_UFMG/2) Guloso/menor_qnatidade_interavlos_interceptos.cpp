// https://codeforces.com/problemset/problem/597/B

#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int>a, pair<int, int> b){
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}

int main()
{
    int n; cin >> n;

    vector<pair<int, int>> v;

    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), cmp);

    int ans = 0;
    int fim = -1;
    for(int i=0; i<n; i++)
    {
        if(v[i].first > fim){
            fim = v[i].second;
            ans ++;
        }
    }
    cout << ans << endl;

    exit(0);
}