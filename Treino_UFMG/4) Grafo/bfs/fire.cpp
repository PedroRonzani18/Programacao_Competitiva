//https://open.kattis.com/problems/fire2

// codigo explicado 1:00:00

#include <bits/stdc++.h>

using namespace std;
 
#define _   ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define pb push_back
 
typedef long long ll;
 
const int INF = 0x7f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1010;
char M[MAX][MAX];

int n, m;

bool vis[MAX][MAX];
int dist[MAX][MAX];

vector<pair<int, int>> mov = {{-1, 0}, {1,0}, {0,-1}, {0,1}};

bool val(pair<int, int> u) {
   return u.first >= 0 and u.second >= 0 and u.first < n and u.second < m
      and M[u.first][u.second] != '#' and !vis[u.first][u.second];
}


int bfs(pair<int, int> s) // só se move para as coordenadas se nao tiver fogo nelas
{
   memset(vis, 0, sizeof vis);

   queue<pair<int, int>> q;
   q.push(s); vis[s.first][s.second] = 1; dist[s.first][s.second] = 0;

   while(!q.empty()) 
   {
      pair<int, int> v = q.front(); q.pop();

      if(v.first == 0 or v.second == 0 or v.first == n-1 or v.second == m-1) // posição na borda
         return dist[v.first][v.second] + 1; // distancia da borda + 1

      for(auto u : mov)
      {
         u.first += v.first, u.second += v.second;

         if(val(u) and dist[v.first][v.second] + 1 < dist[u.first][u.second]) // essa distancie é o tmepo que o fogo demorou pra chegar na coordenada
         {
            q.push(u), vis[u.first][u.second] = 1;
            dist[u.first][u.second] = dist[v.first][v.second] + 1;
         }
      }
   }

   return -1;
}

void bfs_ms(vector<pair<int, int>> ms) // para saber quais posições o fogo se alastrou
{
   // como sao testados t casos, e bfs n e recursiva, tem que resetar tudo
   memset(vis, 0, sizeof vis); // setta tudo como 0
   memset(dist, INF, sizeof dist);

   queue<pair<int, int>> q;

   for(auto s : ms) q.push(s), vis[s.first][s.second]=1, dist[s.first][s.second]=0; //.. distancia dos elementos da multicsourcce ate a fonte é 0

   while (!q.empty())
   {
      pair<int, int> v = q.front(); q.pop();

      for(auto u: mov)
      {
         u.first += v.first, u.second += v.second; // vizinho de v

         if(val(u)) 
         {
            q.push(u); // coloca u na fila
            vis[u.first][u.second] = 1; // u ja foi visto
            dist[u.first][u.second] = dist[v.first][v.second]+1; // dist de u é a dist de quem o chamou + 1 por ser seu vizinho
         }
      }
   }
}



int main() { _
 
   int t; cin >> t;

   while(t--) 
   {
      cin >> m >> n;

      vector<pair<int, int>> ms; // multi-source
      pair<int, int> s; // source

      for(int i=0; i<n; i++) for(int j=0; j<m; j++) 
      {
         cin >> M[i][j];
         if(M[i][j] == '*') ms.push_back({i,j});
         if(M[i][j] == '@') s = {i,j};
      }

      bfs_ms(ms);

      int ans = bfs(s);
      if (ans == -1) cout << "IMPOSSIBLE\n";
      else cout << ans << endl;
   }

   exit(0);
}
