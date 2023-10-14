// https://codeforces.com/group/xR6OpxQBMc/contest/215144/problem/F

#include <bits/stdc++.h>

using namespace std;
 
#define _   ios_base::sync_with_stdio(0); cin.tie(0);
#define f first
#define s second
#define pb push_back
 
typedef long long ll;
 
typedef pair<int, int> Edge; // num vertice e peso
typedef vector<vector<Edge>> Graph; // lista de addjacencia

const int INF = 0x7f3f3f3f;

int n, m, x;

vector<int> dijkstra(Graph &g, int source)
{
   priority_queue<Edge> pq;
   pq.push({-0, source}); // -1 pq tem q virar zero based

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

int main() { _

   cin >> n >> m >> x;

   Graph grp = Graph(n, vector<Edge>());

   for(int i=0; i<m; i++) {
      int a, b, w;
      cin >> a >> b >> w;
      add_edge(grp, a, b, w);
   }
   vector<int> friends(x); // conjunto de vertices que começa dijksrta

   for(int& i : friends)
      cin >> i;

   vector<int> dist_to_friends = dijkstra(grp, 0);
   vector<int> dist_to_icecream = dijkstra(grp, n-1);

   int ans = INF;
   for(int fr : friends){
      int w = dist_to_friends[fr-1] + dist_to_icecream[fr-1];
      ans = min(ans, w);
   }

   cout << ans << endl;

   exit(0);
}
