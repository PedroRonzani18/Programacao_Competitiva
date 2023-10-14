//https://neps.academy/br/course/algoritmos-em-grafos-(codcad)/lesson/gincana-(obi-2011)

#include <bits/stdc++.h>

using namespace std;
 
#define _   ios_base::sync_with_stdio(0); cin.tie(0);

vector<vector<int>> g(1000);
vector<bool> vis(1000);

void dfs(int v) {
   vis[v] = true;

   for(auto w : g[v]) if (!vis[w]) {
      dfs(w);
   }
}

int main() { _

   int n, m; cin >> n >> m;

   for(int k=0; k<m; k++){
      int i, j; cin >> i >> j; i--; j--;

      g[i].push_back(j); // i é amg do j
      g[i].push_back(j); // j é amg do i
   }

   int times = 0;

   // Conta quantas vezes a dfs rodou, encontrando todos os conjuntos de amizades
   for(int i=0; i<n; i++) {
      if(!vis[i]) { // se n visitou aquele ainda
         dfs(i); // encontra todos os seus amigos
         times ++;
      }
   }

   cout << times << endl;

   exit(0);
}
