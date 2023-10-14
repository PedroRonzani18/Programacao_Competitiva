#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;
const int INF = 0x7f3f3f3f;

const int n = 10; // numero de arestas

int dist[MAX];
bool vis[MAX];

vector<tuple<int, int, int>> edges;

void menor_caminho_ballman_ford(int s) // encontra a menor distancia entre uma source e todos os nodes do grafo
{
    memset(dist, INF, sizeof dist);

    dist[s] = 0;

    for(int i=0; i<n; i++) {
        for(auto e : edges) {
            int a, b, w;
            tie(a, b, w) = e;
            dist[b] = min(dist[b], dist[a]+w);
        }
    }
}