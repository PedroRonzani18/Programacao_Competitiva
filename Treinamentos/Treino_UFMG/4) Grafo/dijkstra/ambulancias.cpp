// https://www.beecrowd.com.br/judge/pt/problems/view/2359

#include <bits/stdc++.h>

using namespace std;
 
#define _   ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define pb push_back
 
typedef long long ll;
 
const int INF = 0x3f3f3f3f;

typedef pair<int, int> Edge; // num vertice e peso
typedef vector<vector<Edge>> Graph; // lista de addjacencia

int n, m, q;

vector<int> dijkstra(Graph &g, vector<int> hosp)
{
   priority_queue<Edge> pq;
   for(int amb : hosp)
      pq.push({-0, amb-1}); // -1 pq tem q virar zero based

   vector<int> dist(n, INF);

   while(!pq.empty()) {
      int w = -pq.top().first; // tamanho do caminho até u
      int u = pq.top().second; // indice de u
      pq.pop();
      
      if(dist[u] <= w) continue; // ja visitamos vertice u inicialmente

      dist[u] = w;

      for(auto [v, n_w] : g[u]) {
         if(dist[v] > w + n_w) {// n_w = tamanho da aresta de u para v
            pq.push({-(w + n_w), v});
         }
      }
   }

   return dist;
}

void add_edge(Graph &g, int a, int b, int w)
{
   a--; b--;
   g[a].push_back({b,w});
   g[b].push_back({a,w});
}

void solve()
{
   Graph grp = Graph(n, vector<Edge>());

   for(int i=0; i<m; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      add_edge(grp, a, b, w);
   }
   vector<int> hosp(q); // conjunto de vertices que começa dijksrta

   for(int& i : hosp)
      cin >> i;

   vector<int> dist = dijkstra(grp, hosp);

   int ans = -1;
   for(int x : dist)
      ans = max(ans, x);

   cout << ans << endl;
}

int main() { _
   // vertices, arestas, vertices iniciais
   while(cin >> n >> m >> q)
      solve();

   exit(0);
}
