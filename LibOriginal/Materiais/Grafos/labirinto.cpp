// Verifica se eh possivel sair de um labirinto
// Complexidade: O(4^(n*m))

vector<pair<int,int>> mov = {{1,0}, {0,1}, {-1,0}, {0,-1}};
vector<vector<int>> labirinto, sol;
vector<vector<bool>> visited;
int L, C;

bool valid(const int& x, const int& y) {
    return x >= 0 and x < L and y >= 0 and y < C and labirinto[x][y] != 0 and !visited[x][y];
}

bool condicaoSaida(const int& x, const int& y) {
    return labirinto[x][y] == 2;
}

bool search(const int& x, const int& y) {

    if(!valid(x, y))
        return false;

    if(condicaoSaida(x,y)) {
        sol[x][y] = 2;
        return true;
    }

    sol[x][y] = 1;
    visited[x][y] = true;

    for(auto [dx, dy] : mov) 
        if(search(x+dx, y+dy)) 
            return true;

    sol[x][y] = 0;
    return false;
}

int main() {
    
    labirinto = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
        {1, 1, 1, 2}
    };

    L = labirinto.size(), C = labirinto[0].size();
    sol.resize(L, vector<int>(C, 0));
    visited.resize(L, vector<bool>(C, false));

    cout << search(0, 0) << endl;
}