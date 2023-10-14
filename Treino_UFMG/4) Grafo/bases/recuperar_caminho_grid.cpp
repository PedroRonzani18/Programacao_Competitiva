// recuperar caminho dentro d euma grid

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+10;

bool vis_d[MAX][MAX];
vector<vector<pair<int, int>>> pai_d(MAX);
vector<pair<int, int>> mov = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int m, n;

bool val(pair<int, int> u) {
   return u.first >= 0 and u.second >= 0 and u.first < n and u.second < m and !vis_d[u.first][u.second];
      //and M[u.first][u.second]=='H' ;
      // alteravel para situações especificas de uma matriz de char
}

void bfs_d(pair<int, int> s) 
{
   queue<pair<int,int>> q;
   q.push(s); vis_d[s.first][s.second] = 1;

   pai_d[s.first][s.second] = s;
   while(!q.empty()) 
   {
        pair<int, int> v = q.front(); q.pop();

        for(auto u : mov)
        {
            u.first += v.first;
            u.second += v.second;

            if(val(u))
            {
                q.push(u);
                vis_d[u.first][u.second] = 1;
                pai_d[u.first][u.second] = v;
            }
        }
   }
}

vector<pair<int, int>> caminho_por_bfs_grid(pair<int,int> v)
{
    vector<pair<int, int>> path;

    if(!vis_d[v.first][v.second]) return path; // significa que nao tem um caminho

    while(pai_d[v.first][v.second] != v) // v != source
    {
        v = pai_d[v.first][v.second];
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    return path;
    // se path.empty() => nao tem caminho
}
