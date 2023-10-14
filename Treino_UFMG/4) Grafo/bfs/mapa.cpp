// https://neps.academy/br/exercise/26

#include <bits/stdc++.h>

using namespace std;
 
#define _   ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define pb push_back
 
typedef long long ll;

const int MAX = 110;

int n, m;

char M[MAX][MAX];
bool vis[MAX][MAX];

vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool val(pair<int, int> u) {
   return u.first >= 0 and u.second >= 0 and u.first < n and u.second < m
      and M[u.first][u.second]=='H' and !vis[u.first][u.second];
}

pair< int, int> bfs(pair<int, int> s) 
{
   queue<pair<int, int>> q;
   q.push(s), vis[s.first][s.second] = 1;

   pair<int, int> v; // ultima posição de hermione
   while (!q.empty()) 
   {
      v = q.front(); q.pop();

      for(auto u : mov) // como é uma copia, pode fazer: 
      { 
         u.first += v.first, u.second += v.second;

         if(val(u)) 
         {
            q.push(u), vis[u.first][u.second] = 1;
         }
      }
   }
   return v;
}


int main() { _

   cin >> n >> m;

   for(int i=0; i<n; i++) for(int j=0; j<m; j++)
      cin >> M[i][j];

   pair<int, int> s;

   for(int i=0; i<n; i++) for(int j=0; j<m; j++)
      if(M[i][j] == 'o') s = {i, j};

   pair<int, int> ans = bfs(s);

   cout << ans.first+1 << " " << ans.second+1 << endl;

   exit(0);
}
