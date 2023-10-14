#include <bits/stdc++.h>

using namespace std;
 
#define _   ios_base::sync_with_stdio(0); cin.tie(0);
 
typedef long long ll;
 
const int INF = 0x7f3f3f3f;

int n, k;
vector<int> h;
const int MAX = 1e5+10;
int memo[MAX];

int dp(int i) {
   if(i == 0) return 0;
   if(memo[i] != -1) return memo[i];

   int ret = INF;

   for(int j = max(0, i-k); j<i; j++) // max(0, i-k) => para todos os k's que eu possa ter vindo, e nao-negativos, ..
      ret = min(ret, dp(j) + abs(h[j] - h[i]));

   return memo[i] = ret;
}

int main() { _

   cin >> n >> k;
   h.resize(n);

   for(int& i : h) cin >> i;

   memset(memo, -1, sizeof memo);

   cout << dp(n-1) << endl;

   exit(0);
}
