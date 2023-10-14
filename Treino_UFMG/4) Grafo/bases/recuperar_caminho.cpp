// Recupera caminho feito em uma lista de adjacencia

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+10;

vector<vector<int>> graph;
vector<bool> vis;
vector<int> pai(MAX, -1); // diz o primeiro vertice que foi chamado na BFS

void bfs(int s) 
{
   queue <int> q;
   q.push(s); vis[s] = 1;

   pai[s] = s;
   while(!q.empty()) {
      int v = q.front(); q.pop();

      for(auto u : graph[v]) if(!vis[u]) {
         q.push(u); vis[u] = 1;
         pai[u] = v;
      }
   }
}

// aparentemente tem que fazer BFS antes de rodar path
vector<int> caminho_por_bfs(int v)
{
    vector<int> path;

    if(!vis[v]) return path; // significa que nao tem um caminho

    while(pai[v] != v) // v != source
    {
        v = pai[v];
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    return path;
    // se path.empty() => nao tem caminho
}
