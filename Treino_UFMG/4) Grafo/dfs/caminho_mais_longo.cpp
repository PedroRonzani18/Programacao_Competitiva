// https://www.spoj.com/problems/PT07Z/

#include <bits/stdc++.h>

using namespace std;
 
#define _   ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define pb push_back
 
typedef long long ll;

const int MAX = 1e4+10;
 
vector<vector<int>> graph (MAX);

int dist[MAX];

void dfs(int v)
{
   for(auto w : graph[v] ) if(dist[w] = -1){ // se a distancia do vizinho de w for -1
      dist[w] = dist[v] + 1; // dist dele é a minha + 1
      dfs(w);
   }
}


int main() { _

   int n; cin >> n;

   for(int i=0; i<n-1; i++){
      int u, v; cin >> u >> v; u--; v--;

      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   memset(dist, -1, sizeof dist); // preenche com -1

   dist[0] = 0;
   dfs(0); // preenche dist com distancias de todos os vertices com 0

   int pos = -1, distmax = -1;

   for(int i=0; i<n; i++)
   {
      if(dist[i] > distmax){
         distmax = dist[i];
         pos = i;
      }
   } // encontra spocição do vertice mais longe de 0

   memset(dist, -1, sizeof dist); // preenche com -1

   dist[pos] = 0; // como ele é a nova origem, sua dist é 0
   dfs(pos); // preenche dist dnv com posições

   int diametro = 0;

   for(int i=0; i<n; i++) {
      diametro = max(diametro, dist[i]); // encontra maior distancia
   }

   cout << diametro << endl;

   exit(0);
}
