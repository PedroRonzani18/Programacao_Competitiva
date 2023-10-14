#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3+10;

vector<bool> vis(MAX); // vector que indica se node x foi visitado
vector<vector<int>> g(MAX); // grafo de lista de adjacência
vector<int> dist(MAX); // vector com distancia entre um node source e o resto dos outros nodes


// Breadth First Search | Busca em Largura
void bfs(int s) // Parte da fonte 
{ 
    queue<int> q;

    dist[s] = 0;
    q.push(s); // Coloca fonte na fila,
    vis[s] = 1; // marca como visitada

    while(!q.empty()) // enquanto tiverem vertices a serem processados
    {
        int v = q.front(); // v é a frente
        q.pop(); // tira a frente

        for(auto u : g[v]) if (!vis[u]) { // para cada vizinho u de v, se u nao tiver sido visitado
            q.push(u); // coloca u na fila 
            vis[u] = 1; // visita u
            dist[u] = dist[s] + 1;
        }
    }
}

