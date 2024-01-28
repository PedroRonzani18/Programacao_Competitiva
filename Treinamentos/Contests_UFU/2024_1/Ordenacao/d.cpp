#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);

#define int            long long int
#define double         long double
#define endl           "\n"
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define f(i,s,e)        for(int i=s;i<e;i++)
#define rf(i,e,s)        for(int i=e-1;i>=s;i--)

#define dbg(x) cout << #x << " = " << x << endl;

int a, b;

struct Marca {
    string nome;
    int pontuacao;
    int ordemOcorrencia;
};

unordered_map<string, int> mapaPontuacao;

bool comparaMarcas(const Marca& a, const Marca& b) {
    if (mapaPontuacao[a.nome] == mapaPontuacao[b.nome]) {
        return a.ordemOcorrencia < b.ordemOcorrencia;
    }
    return mapaPontuacao[a.nome] > mapaPontuacao[b.nome];
}

void solve() {
    int N;
    cin >> N;

    vector<Marca> marcas;

    int ordem = 1;

    for (int i = 0; i < N; i++) {
        string nomeMarca;
        cin >> nomeMarca;

        if (mapaPontuacao.count(nomeMarca) == 0) {
            Marca novaMarca;
            novaMarca.nome = nomeMarca;
            novaMarca.ordemOcorrencia = ordem;
			ordem++;

            marcas.push_back(novaMarca);
        }

		
		mapaPontuacao[nomeMarca]++;

    }


    sort(marcas.begin(), marcas.end(), comparaMarcas);

    for (int i = 0; i < marcas.size(); i++) {
        cout << marcas[i].nome << endl;
    }
}

int32_t main() { 

    clock_t z = clock();

    int t = 1; // cin >> t;
    while (t--) 
    //while(cin >> a >> b)
        solve();


    cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}