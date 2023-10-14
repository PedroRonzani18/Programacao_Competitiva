#include <bits/stdc++.h>

using namespace std;

const int INF = 0x7f3f3f3f;
const int MAX = 10;

vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);

void dijkstra(int s) 
{
    priority_queue<pair<int, int>> pq;
    pq.push({-0, s}); // coloca dist s como 0

    while(!pq.empty()) 
    {
        int u = pq.top().second; // pega vertice do menor caminho
        int d = -pq.top().first; // tamanho do menor caminho

        pq.pop(); // tiro caminho da fila

        if(d > dist[u]) continue; // mesma coisa de verificar se ja foi visitado
        dist[u] = d;

        for(pair<int, int> pv : graph[u]) { // visita todos os vertices vizinhos de u
            int w = d + pv.first; // tamanho do novo caminho = tamanho do caminho ate U + aresta de u ate pv

            if(dist[pv.second] > w) // se distancia ate vertice pv > calculada no momento, significa q n calculei a dist do vertice pv
                pq.push({w, pv.second}); // ent eu adiciono na lista de prioridade
        }
    }
}