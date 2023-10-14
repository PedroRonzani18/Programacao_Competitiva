// recuperar caminho dentro d euma grid

#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;

const int MAX = 110;

int M[MAX][MAX];
bool vis_d[MAX][MAX];
vector<vector<pair<int, int>>> pai_d(MAX, vector<pair<int, int>>(MAX, {-1, -1}));
vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int m, n;

bool val(pair<int, int> u) {
   return u.f >= 0 and u.s >= 0 and u.f < n and u.s < m and !vis_d[u.f][u.s] 
   and (M[u.f][u.s] == 1 or M[u.f][u.s] == 7);
}

pair<int, int> destiny;

void bfs_d(pair<int, int> s) 
{
   queue<pair<int,int>> q;
   q.push(s); vis_d[s.f][s.s] = 1;

    getchar();

   pai_d[s.f][s.s] = s;

   while(!q.empty()) {
        pair<int, int> v = q.front(); q.pop();

        for(auto u : mov){
            u.f += v.f;
            u.s += v.s;

            if(val(u))
            {
                if(M[u.f][u.s] == 7) destiny.f = u.f, destiny.s = u.s;
                
                q.push(u);
                vis_d[u.f][u.s] = 1;
                pai_d[u.f][u.s] = v;
            }
        }
   }
}

// retorna coordenadas dos nodes do caminho em questão
vector<pair<int, int>> caminho_por_bfs_grid(pair<int,int> v)
{
    vector<pair<int, int>> path;

    pair<int, int> origem = v;

    if(!vis_d[v.f][v.s]) return path; // significa que nao tem um caminho

    while(pai_d[v.f][v.s] != v) // v != source
        v = pai_d[v.f][v.s], path.push_back(v);
    
    path.push_back(origem); /// adicionei pq senao nao contabiliza o ponto final

    reverse(path.begin(), path.end());

    return path;
}

vector<vector<int>> matriz_menor_caminho(pair<int, int> source)
{
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) cin >> M[i][j];
    
    bfs_d(source);

    vector<pair<int, int>> dist = caminho_por_bfs_grid(destiny);

    if(dist.empty()) {cout << "IMPOSSIBLE\n"; exit(0);}

    std::vector<std::vector<int>> retorno(MAX, std::vector<int>(MAX, 0));

    for(auto i : dist) retorno[i.f][i.s] = 1; // menor caminho percorrido no labirinto

    return retorno;
}

int main() { 

    cin >> m >> n;

    vector<vector<int>> caminho = matriz_menor_caminho({1, 0});

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) 
            cout << caminho[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}