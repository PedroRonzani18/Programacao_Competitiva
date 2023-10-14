#include <bits/stdc++.h>

using namespace std;


const int MAX = 1e5 + 10; // numero maximo de vertices

vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

void dfs(int v){
    vis[v] = true; // viistei esse vertice

    for(auto w : g[v]) {// para todo vizinho de V | para todo vertice W na lista de adjacencia de V
        if(!vis[w]){ // se esse cara nao foi visitado, eu vou pra ele
            dfs(w);
        }
    }
}