#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+10;

vector<vector<int>> graph;
vector<bool> vis;
vector<int> dist (MAX, -1); // distancia de source até vertice s

void dist_por_bfs(int source)
{
    queue<int> q;

    dist[source] = 0;

    while(!q.empty()) {
        int v = q.front();
        q.pop();

        for(auto u : graph[v]) if(!vis[u]) {
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }
}
