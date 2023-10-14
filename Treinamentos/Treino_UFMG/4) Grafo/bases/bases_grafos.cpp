#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3+10;
const int INF = 0x7f3f3f3f;

vector<bool> vis(MAX);
vector<vector<int>> g(MAX);


// Breadth First Search | Busca em Largura
void bfs(int s) // Parte da fonte 
{ 
    queue<int> q;

    q.push(s), vis[s] = 1; // Coloca fonte na fila, e marca como visitada

    while(!q.empty()) // enquanto tiverem vertices a serem processados
    {
        int v = q.front(); // v é a frente
        q.pop(); // tira a frente

        for(auto u : g[v]) if (!vis[u]) { // para cada vizinho u de v, se u nao tiver sido visitado
            q.push(u), vis[u] = 1; // coloca u na fila e visita u
        }
    }
}

void dfs(int v){
    vis[v] = true; // viistei esse vertice

    for(auto w : g[v]) {// para todo vizinho de V | para todo vertice W na lista de adjacencia de V
        if(!vis[w]){ // se esse cara nao foi visitado, eu vou pra ele
            dfs(w);
        }
    }
}


bool vis_m[MAX][MAX];
int dist[MAX][MAX];
vector<pair<int, int>> mov = {{-1, 0}, {1,0}, {0,-1}, {0,1}};
int m, n;

bool val(pair<int, int> u) {
   return u.first >= 0 and u.second >= 0 and u.first < n and u.second < m;
}

void bfs_ms(vector<pair<int, int>> mult_s){
    queue<pair<int, int>> q;
    for(auto s: mult_s) q.push(s), vis_m[s.first][s.second]=1, dist[s.first][s.second]=0;

    while(!q.empty()){
        pair<int, int> v = q.front(); q.pop();
        for(auto u : mov)
        {
            u.first += v.first, u.second += v.second;

            if(val(u))
                q.push(u), vis_m[u.first][u.second]=1, dist[u.first][u.second]=dist[v.first][v.second]+1;
        }
    }
}



