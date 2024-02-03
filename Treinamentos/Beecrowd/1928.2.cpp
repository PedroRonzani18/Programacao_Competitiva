#include <bits/stdc++.h>
using namespace std;

#define _   ios_base::sync_with_stdio(0); cin.tie(0);

#define all(a)         a.begin(), a.end()
#define int            long long int
#define double         long double
#define vi 			   vector<int>
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)    for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << " ";
#define dbgl(x) cout << #x << " = " << x << endl;

const int INF = 0x7f3f3f3f;
const int MAX = 50010;

vector<vector<int>> adj(MAX), sparseTable;
vector<pair<int,int>> cardPair(MAX/2, {-1,-1});
vector<int> distRoot(MAX), entryTime(MAX), exitTime(MAX);
int timeStemp = 0, bound;

void dfs(int u, int parent) {

    entryTime[u] = timeStemp++; // marca o tempo de entrada de u
    sparseTable[u][0] = parent; // o pai de u é o nó anterior

    f(i, 1, bound+1)
        sparseTable[u][i] = sparseTable[sparseTable[u][i-1]][i-1]; 
            // o i-ésimo ancestral de u é o i-1-ésimo ancestral do i-1-ésimo ancestral de u

    for(auto v : adj[u]) { // para cada vizinho de u
        if(v != parent) { // se o vizinho não for o pai de u
            distRoot[v] = distRoot[u] + 1; // a distância do vizinho para a raiz é a distância de u para a raiz + 1
            dfs(v, u); // chama a dfs para o vizinho
        }
    }

    exitTime[u] = timeStemp++;
}

bool anc(int x, int y){
    return ((entryTime[x]<=entryTime[y]) && (exitTime[y]<=exitTime[x])); 
}

int lca(int x, int y) {

    if(anc(x, y)) return x; // se x for ancestral de y, retorna x
    if(anc(y, x)) return y; // se y for ancestral de x, retorna y

    for(int j=bound; j>=0; --j)
        if(!anc(sparseTable[x][j], y)) // se o j-ésimo ancestral de x não for ancestral de y
            x = sparseTable[x][j]; // x recebe o j-ésimo ancestral de x

    return sparseTable[x][0]; // retorna o pai de x
}

int32_t main() { _
    
    int n; cin >> n;
    long maxDist = 0;

    f(i,0,n) {
        int ct; cin >> ct; ct--;
        if(cardPair[ct].first == -1)
            cardPair[ct].first = i;
        else 
            cardPair[ct].second = i;
    }

    f(i,0,n-1) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bound = ceil(log2(n));
    sparseTable.assign(n+1,vector<int>(bound+1));
    
    dfs(0,0);

    f(i,0,n/2) { // para cada par de cartas

        auto [c1, c2] = cardPair[i]; // pega o primeiro e o segundo cartão do par
        int ances = lca(c1,c2);

        maxDist += distRoot[c1] + distRoot[c2] - 2 * distRoot[ances];
    }

    cout << maxDist << "\n";

    return 0;
}